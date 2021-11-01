/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raytracing.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-rooi <kde-rooi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/19 13:56:18 by kde-rooi      #+#    #+#                 */
/*   Updated: 2021/02/07 15:20:16 by kas           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing.h"

static void		ray_init(t_ray *ray, t_camera *camera, t_input *input)
{
	ray->origin = camera->origin;
	ray->width = input->env.resolution.x;
	ray->height = input->env.resolution.y;
	ray->ratio = (float)ray->width / (float)ray->height;
	ray->fov = (float)camera->fov / 2;
	ray->fov = tan(ray->fov * RADIANS);
}

static void		make_ray(size_t x, size_t y, t_ray *ray, t_vector camera)
{
	ray->normal.x = (2 * ((x + 0.5) / ray->width) - 1) * ray->fov * ray->ratio;
	ray->normal.y = (1 - 2 * ((y + 0.5) / ray->height)) * ray->fov;
	ray->normal.z = 1;
	ray->normal = translate_ray(camera, ray->normal);
	ray->normal = vec_nrm(ray->normal);
}

void			ray_tracing_img(t_data *img, t_input *input)
{
	t_ray	ray;
	size_t	x;
	size_t	y;
	t_hit	hit;

	x = 0;
	y = 0;
	ray_init(&ray, input->camera, input);
	while (y < ray.height)
	{
		while (x < ray.width)
		{
			make_ray(x, y, &ray, input->camera->normal);
			hit = cast_ray(ray, (*input->shapelist));
			cast_light(&hit, input, ray);
			if (hit.distance > EPSILON)
				my_mlx_pixel_put(img, x, y, hit.color);
			else
				my_mlx_pixel_put(img, x, y, col_set(0, 0, 0));
			x++;
		}
		x = 0;
		y++;
	}
}
