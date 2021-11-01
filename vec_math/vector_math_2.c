/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_math_2.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-rooi <kde-rooi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/18 11:37:26 by kde-rooi      #+#    #+#                 */
/*   Updated: 2021/02/05 09:31:21 by kas           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vec_math.h"

double		vec_sqr(t_vector v)
{
	return (pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));
}

double		vec_len(t_vector v)
{
	return (sqrt(vec_sqr(v)));
}

t_vector	vec_nrm(t_vector v)
{
	double		length;
	t_vector	normal;

	length = vec_len(v);
	normal.x = (v.x / length);
	normal.y = (v.y / length);
	normal.z = (v.z / length);
	return (normal);
}

double		dot_product(t_vector v, t_vector u)
{
	double dotproduct;

	dotproduct = (v.x * u.x) + (v.y * u.y) + (v.z * u.z);
	return (dotproduct);
}

t_vector	cross_product(t_vector v, t_vector u)
{
	t_vector	product;

	product.x = (v.y * u.z) - (v.z * u.y);
	product.y = (v.z * u.x) - (v.x * u.z);
	product.z = (v.x * u.y) - (v.y * u.x);
	return (product);
}
