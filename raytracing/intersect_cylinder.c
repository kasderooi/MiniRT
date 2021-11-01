/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersect_cylinder.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: kas <kas@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 09:31:25 by kas           #+#    #+#                 */
/*   Updated: 2021/02/07 16:08:29 by kas           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing.h"

static void		make_hit(t_ray ray, t_hit *hit, t_shape *cyl, double t)
{
	t_vector	barier;
	double		dotproduct;

	hit->point = vec_add(ray.origin, vec_mul(ray.normal, t));
	dotproduct = dot_product(vec_sub(hit->point, cyl->origin), cyl->normal);
	barier = vec_add(cyl->origin, vec_mul(cyl->normal, dotproduct));
	hit->normal = vec_nrm(vec_sub(hit->point, barier));
	hit->color = cyl->color;
	hit->distance = t;
}

static double	make_t(t_shape n_cyl, t_ray ray, t_shape *cyl, double t)
{
	double		dotproduct1;
	double		dotproduct2;

	dotproduct1 = dot_product(cyl->normal,
					vec_add(n_cyl.point0, vec_mul(ray.normal, t)));
	dotproduct2 = dot_product(cyl->normal,
					vec_add(n_cyl.point1, vec_mul(ray.normal, t)));
	if (dotproduct1 > -EPSILON && dotproduct2 < EPSILON)
		return (t);
	return (-1);
}

static double	make_tt(t_shape n_cyl, t_shape *cyl, double *t1, double *t2)
{
	double		a;
	double		b;
	double		c;
	double		discriminant;

	a = vec_sqr(n_cyl.normal);
	b = 2 * dot_product(n_cyl.normal, n_cyl.origin);
	c = vec_sqr(n_cyl.origin) - pow(cyl->diameter / 2, 2);
	discriminant = sqrd(b) - (4 * a * c);
	if (discriminant < -EPSILON)
		return (-1);
	*t1 = ((-b + sqrt(discriminant)) / (2 * a));
	*t2 = ((-b - sqrt(discriminant)) / (2 * a));
	return (1);
}

double			intersect_cylinder(t_ray ray, t_shape *cyl, t_hit *hit)
{
	double		t1;
	double		t2;
	double		t;
	t_shape		n_cyl;

	n_cyl.point0 = vec_sub(ray.origin, cyl->origin);
	n_cyl.point1 = vec_sub(ray.origin, vec_add(cyl->origin,
					vec_mul(cyl->normal, cyl->size)));
	n_cyl.normal = vec_sub(ray.normal, vec_mul(cyl->normal,
					dot_product(ray.normal, cyl->normal)));
	n_cyl.origin = vec_sub(n_cyl.point0, vec_mul(cyl->normal,
					dot_product(n_cyl.point0, cyl->normal)));
	t = make_tt(n_cyl, cyl, &t1, &t2);
	if (t < 0)
		return (-1);
	t = make_t(n_cyl, ray, cyl, min(t1, t2));
	if (t < -2 * EPSILON)
		t = make_t(n_cyl, ray, cyl, max(t1, t2));
	if (t < -2 * EPSILON)
		return (-1);
	make_hit(ray, hit, cyl, t);
	return (t);
}
