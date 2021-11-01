/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   light.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kas <kas@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/27 10:52:22 by kas           #+#    #+#                 */
/*   Updated: 2021/02/07 15:29:52 by kas           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing.h"

static double	make_fr(t_vector normal, t_vector light)
{
	double	fr;

	fr = dot_product(normal, light);
	if (fr < 0)
		fr *= -1;
	return (max(EPSILON, min(1, fr)));
}

static double	intersect_light(t_ray ray, t_light *light, t_hit *hit,
									double *fc2)
{
	double		abc[3];
	double		t[2];
	t_vector	null_origin;
	double		discriminant;

	null_origin = vec_sub(ray.origin, light->origin);
	abc[0] = vec_sqr(ray.normal);
	abc[1] = 2 * dot_product(ray.normal, null_origin);
	abc[2] = vec_sqr(null_origin) - pow(light->brightness_ratio, 2);
	discriminant = sqrd(abc[1]) - (4 * abc[0] * abc[2]);
	if (discriminant < -EPSILON)
		return (-1);
	t[0] = ((-abc[1] + sqrt(discriminant)) / (2 * abc[0]));
	t[1] = ((-abc[1] - sqrt(discriminant)) / (2 * abc[0]));
	*fc2 = vec_len(vec_sub(vec_mul(ray.normal, t[0]),
							vec_mul(ray.normal, t[1])));
	if (*fc2 < -EPSILON)
		*fc2 *= -1;
	*fc2 = pow(*fc2, 4) / pow(2 * light->brightness_ratio, 4);
	t[0] = min(t[0], t[1]);
	hit->color = light->color;
	hit->distance = t[0];
	if (t[0] <= 2 * EPSILON && t[0] >= -2 * EPSILON)
		t[0] = 1;
	return (t[0]);
}

static void		hit_light(t_ray ray, t_list *lights, double dis, t_color *color)
{
	double	find;
	double	findnew;
	t_hit	ret;
	double	fc;
	t_color	light;

	find = INFINITY;
	while (lights)
	{
		findnew = intersect_light(ray, lights->content, &ret, &fc);
		if (findnew < dis && findnew > EPSILON)
		{
			if (find == INFINITY)
				light = col_mul(ret.color, fc);
			else
				light = col_add(light, col_mul(ret.color, fc));
			find = findnew;
		}
		lights = lights->next;
	}
	if (find == INFINITY || find <= EPSILON)
		return ;
	*color = col_add_cl(*color, light);
}

static t_color	cast_color(t_light *light, t_hit hit, t_input *input)
{
	t_ray		ray;
	t_color		ret;
	t_hit		hit_light;

	ret.r = 0;
	ret.g = 0;
	ret.b = 0;
	ray.normal = vec_nrm(vec_sub(light->origin, hit.point));
	ray.origin = vec_add(hit.point, vec_mul(ray.normal, EPSILON));
	hit_light = cast_ray(ray, (*input->shapelist));
	if (hit_light.distance < -2 * EPSILON || hit_light.distance >
		vec_len(vec_sub(light->origin, hit.point)) - 2 * EPSILON)
	{
		ret = col_mul(light->color, max(EPSILON, min(1,
			dot_product(ray.normal, hit.normal))) * light->brightness_ratio);
		ret = col_add_cl(ret, col_dev(col_mul(light->color,
				light->brightness_ratio), (pow(vec_len(vec_sub(
					light->origin, hit.point)), 2) / 10 * M_PI)));
	}
	return (ret);
}

void			cast_light(t_hit *hit, t_input *input, t_ray ray2)
{
	t_list		*copy;
	t_color		ret;
	int			i;
	t_color		ambiant;

	i = 0;
	copy = (t_list *)(*input->lightlist);
	ambiant = col_mul(input->env.ambiant.color, make_fr(ray2.normal,
			hit->normal) * input->env.ambiant.lighting_ratio);
	ret = col_set(0, 0, 0);
	while (copy)
	{
		ret = col_add(ret, cast_color(((t_light *)(copy->content)),
						*hit, input));
		i++;
		copy = copy->next;
	}
	if (i)
		ret = col_dev(ret, i);
	ret = col_add(ret, ambiant);
	ret = col_mix(hit->color, ret);
	ret = col_min(ret, col_mix(hit->color, ambiant));
	copy = (t_list *)(*input->lightlist);
	hit_light(ray2, copy, hit->distance, &ret);
	hit->color = ret;
}
