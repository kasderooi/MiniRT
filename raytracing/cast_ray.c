/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cast_ray.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kas <kas@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/05 10:51:49 by kas           #+#    #+#                 */
/*   Updated: 2021/02/05 10:52:13 by kas           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing.h"

double			switch_shapes(t_ray ray, t_list *shapes, t_hit *ret)
{
	if (shapes->type == PLANE)
		return (intersect_plane(ray, shapes->content, ret));
	if (shapes->type == SPHERE)
		return (intersect_sphere(ray, shapes->content, ret));
	if (shapes->type == TRIANGLE)
		return (intersect_triangle(ray, shapes->content, ret));
	if (shapes->type == CYLINDER)
		return (intersect_cylinder(ray, shapes->content, ret));
	if (shapes->type == SQUARE)
		return (intersect_square(ray, shapes->content, ret));
	return (-1);
}

t_hit			cast_ray(t_ray ray, t_list *shapes)
{
	double	find;
	double	findnew;
	t_hit	ret;
	t_hit	hit;

	find = INFINITY;
	while (shapes)
	{
		findnew = switch_shapes(ray, shapes, &ret);
		if (findnew < find && findnew > EPSILON)
		{
			hit = ret;
			find = findnew;
		}
		shapes = shapes->next;
	}
	if (find == INFINITY || find <= EPSILON)
		hit.distance = -1;
	return (hit);
}
