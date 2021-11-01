/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   math_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-rooi <kde-rooi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/19 10:03:31 by kde-rooi      #+#    #+#                 */
/*   Updated: 2021/02/05 11:23:12 by kas           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "vec_math.h"

double	sqrd(double x)
{
	return (pow(x, 2));
}

double	abc_formula(double a, double b, double c)
{
	double x;
	double y;
	double discriminant;

	discriminant = sqrd(b) - (4 * a * c);
	if (discriminant < -EPSILON)
		return (-1);
	x = ((-b + sqrt(discriminant)) / (2 * a));
	y = ((-b - sqrt(discriminant)) / (2 * a));
	if (x > y)
		return (y);
	return (x);
}

double	check_margin(double x)
{
	if (x > -EPSILON && x < EPSILON)
		return (0);
	return (x);
}

double	min(double a, double b)
{
	if (a < b)
		return (a);
	return (b);
}

double	max(double a, double b)
{
	if (a > b)
		return (a);
	return (b);
}
