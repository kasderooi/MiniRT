/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color_math_1.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kas <kas@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/28 09:03:15 by kas           #+#    #+#                 */
/*   Updated: 2021/02/05 15:21:29 by kas           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vec_math.h"

t_color	col_add(t_color v, t_color u)
{
	t_color	sum;

	sum.r = (v.r + u.r);
	sum.g = (v.g + u.g);
	sum.b = (v.b + u.b);
	return (sum);
}

t_color	col_add_cl(t_color v, t_color u)
{
	t_color	sum;

	sum.r = min(255, (v.r + u.r));
	sum.g = min(255, (v.g + u.g));
	sum.b = min(255, (v.b + u.b));
	return (sum);
}

t_color	col_sub(t_color v, t_color u)
{
	t_color	sum;

	sum.r = max(0, (v.r - u.r));
	sum.g = max(0, (v.g - u.g));
	sum.b = max(0, (v.b - u.b));
	return (sum);
}

t_color	col_mul(t_color v, double multiplier)
{
	t_color	product;

	product.r = (v.r * multiplier);
	product.g = (v.g * multiplier);
	product.b = (v.b * multiplier);
	return (product);
}

t_color	col_dev(t_color v, double devider)
{
	t_color	product;

	product.r = min(255, (v.r / devider));
	product.g = min(255, (v.g / devider));
	product.b = min(255, (v.b / devider));
	return (product);
}
