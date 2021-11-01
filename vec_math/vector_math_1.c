/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_math_1.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-rooi <kde-rooi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/18 11:43:46 by kde-rooi      #+#    #+#                 */
/*   Updated: 2021/02/05 09:31:16 by kas           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vec_math.h"

t_vector	vec_add(t_vector v, t_vector u)
{
	t_vector	sum;

	sum.x = (v.x + u.x);
	sum.y = (v.y + u.y);
	sum.z = (v.z + u.z);
	return (sum);
}

t_vector	vec_sub(t_vector v, t_vector u)
{
	t_vector	sum;

	sum.x = (v.x - u.x);
	sum.y = (v.y - u.y);
	sum.z = (v.z - u.z);
	return (sum);
}

t_vector	vec_mul(t_vector v, double multiplier)
{
	t_vector	product;

	product.x = (v.x * multiplier);
	product.y = (v.y * multiplier);
	product.z = (v.z * multiplier);
	return (product);
}

t_vector	vec_dev(t_vector v, double devider)
{
	t_vector	product;

	product.x = (v.x / devider);
	product.y = (v.y / devider);
	product.z = (v.z / devider);
	return (product);
}

t_vector	vec_set(double x, double y, double z)
{
	t_vector	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}
