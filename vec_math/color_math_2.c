/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color_math_2.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kas <kas@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/28 09:03:15 by kas           #+#    #+#                 */
/*   Updated: 2021/02/07 15:05:47 by kas           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vec_math.h"

t_color	col_product(t_color v, t_color u)
{
	t_color	product;

	product.r = (v.r * u.r);
	product.g = (v.g * u.g);
	product.b = (v.b * u.b);
	return (product);
}

t_color	color_root(t_color v)
{
	t_color	product;

	product.r = sqrt(v.r);
	product.g = sqrt(v.g);
	product.b = sqrt(v.b);
	return (product);
}

t_color	col_mix(t_color current, t_color new)
{
	t_color	color;

	color = col_dev(col_product(current, new), 255);
	return (color);
}

t_color	col_set(int r, int g, int b)
{
	t_color	col;

	col.r = r;
	col.g = g;
	col.b = b;
	return (col);
}

t_color	col_min(t_color color, t_color min)
{
	t_color	new;

	new.r = max(color.r, min.r);
	new.g = max(color.g, min.g);
	new.b = max(color.b, min.b);
	return (new);
}
