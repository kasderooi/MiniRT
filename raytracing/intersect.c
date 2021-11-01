/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersect.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-rooi <kde-rooi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/18 14:12:20 by kde-rooi      #+#    #+#                 */
/*   Updated: 2021/02/07 16:02:16 by kas           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing.h"

t_vector		is_normal(t_vector ray, t_vector shape)
{
	if (dot_product(ray, shape) > EPSILON)
		return (vec_mul(shape, -1));
	else
		return (shape);
}

double			intersect_plane(t_ray ray, t_shape *plane, t_hit *hit)
{
	double		t;
	double		dotproduct;

	dotproduct = dot_product(ray.normal, plane->normal);
	if (dotproduct >= -EPSILON && dotproduct <= EPSILON)
		return (-1);
	t = dot_product(vec_sub(plane->origin, ray.origin), plane->normal)
		/ dotproduct;
	hit->point = vec_add(ray.origin, vec_mul(ray.normal, t));
	hit->normal = is_normal(ray.normal, plane->normal);
	hit->color = plane->color;
	hit->distance = t;
	return (t);
}

double			intersect_sphere(t_ray ray, t_shape *sphere, t_hit *hit)
{
	double		a;
	double		b;
	double		c;
	double		t;
	t_vector	null_origin;

	null_origin = vec_sub(ray.origin, sphere->origin);
	a = vec_sqr(ray.normal);
	b = 2 * dot_product(ray.normal, null_origin);
	c = vec_sqr(null_origin) - pow(sphere->diameter / 2, 2);
	t = abc_formula(a, b, c);
	hit->point = vec_add(ray.origin, vec_mul(ray.normal, t));
	hit->normal = vec_nrm(vec_sub(hit->point, sphere->origin));
	hit->normal = is_normal(ray.normal, hit->normal);
	hit->color = sphere->color;
	hit->distance = t;
	if (t <= 2 * EPSILON && t >= -2 * EPSILON)
		t = 1;
	return (t);
}

double			intersect_triangle(t_ray ray, t_shape *triangle, t_hit *hit)
{
	double	t;
	double	u;
	t_shape	tri;
	t_shape	edge;
	double	dotproduct;

	edge.point0 = vec_sub(triangle->point1, triangle->point0);
	edge.point1 = vec_sub(triangle->point2, triangle->point0);
	tri.point0 = cross_product(ray.normal, edge.point1);
	dotproduct = dot_product(edge.point0, tri.point0);
	tri.point1 = vec_sub(ray.origin, triangle->point0);
	u = (1 / dotproduct) * dot_product(tri.point1, tri.point0);
	if (u <= -EPSILON || u > 1 + EPSILON)
		return (-1);
	tri.point2 = cross_product(tri.point1, edge.point0);
	t = (1 / dotproduct) * dot_product(ray.normal, tri.point2);
	if (t <= -EPSILON || u + t > 1 + EPSILON)
		return (-1);
	t = (1 / dotproduct) * dot_product(edge.point1, tri.point2);
	hit->point = vec_add(ray.origin, vec_mul(ray.normal, t));
	hit->normal = vec_nrm(cross_product(edge.point0, edge.point1));
	hit->normal = is_normal(ray.normal, hit->normal);
	hit->color = triangle->color;
	hit->distance = t;
	return (t);
}

double			intersect_square(t_ray ray, t_shape *sqr, t_hit *hit)
{
	double		p[2];
	t_vector	v[3];
	t_vector	upguide;
	t_vector	new_origin;

	hit->distance = intersect_plane(ray, sqr, hit);
	if (hit->distance < 0)
		return (-1);
	upguide.x = 0;
	upguide.y = (sqr->normal.z < EPSILON && sqr->normal.z > -EPSILON) ? 0 : 1;
	upguide.z = (sqr->normal.z < EPSILON && sqr->normal.z > -EPSILON) ? 1 : 0;
	v[1] = vec_nrm(cross_product(upguide, sqr->normal));
	v[2] = vec_nrm(cross_product(sqr->normal, v[1]));
	v[1] = vec_nrm(cross_product(v[2], sqr->normal));
	new_origin = vec_sub(sqr->origin, vec_mul(v[1], sqr->size / 2));
	new_origin = vec_sub(new_origin, vec_mul(v[2], sqr->size / 2));
	v[0] = vec_sub(hit->point, new_origin);
	p[0] = dot_product(v[0], vec_mul(v[1], sqr->size)) / sqr->size;
	p[1] = dot_product(v[0], vec_mul(v[2], sqr->size)) / sqr->size;
	if (p[0] > sqr->size || p[0] < 0 || p[1] > sqr->size || p[1] < 0)
		return (-1);
	hit->normal = is_normal(ray.normal, sqr->normal);
	hit->color = sqr->color;
	return (hit->distance);
}
