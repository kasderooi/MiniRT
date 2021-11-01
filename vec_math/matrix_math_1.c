/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   matrix_math_1.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kas <kas@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/03 09:11:58 by kas           #+#    #+#                 */
/*   Updated: 2021/02/05 12:15:18 by kas           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vec_math.h"

t_vector		vec_mtx_mul(t_matrix matrix, t_vector vec)
{
	t_vector new;

	new.x = vec.x * matrix.xx.x + vec.y * matrix.yy.x + vec.z * matrix.zz.x;
	new.y = vec.x * matrix.xx.y + vec.y * matrix.yy.y + vec.z * matrix.zz.y;
	new.z = vec.x * matrix.xx.z + vec.y * matrix.yy.z + vec.z * matrix.zz.z;
	return (new);
}

t_vector		translate_ray(t_vector dir, t_vector ray)
{
	t_matrix	matrix;
	t_vector	upguide;

	upguide.x = 0;
	upguide.y = (dir.z < EPSILON && dir.z > -EPSILON) ? 0 : 1;
	upguide.z = (dir.z < EPSILON && dir.z > -EPSILON) ? 1 : 0;
	matrix.zz = dir;
	if ((dir.x > EPSILON || dir.x < -EPSILON) &&
			(dir.z < EPSILON && dir.z > -EPSILON))
	{
		matrix.yy = cross_product(upguide, matrix.zz);
		matrix.xx = cross_product(matrix.yy, matrix.zz);
	}
	else
	{
		matrix.xx = cross_product(upguide, matrix.zz);
		matrix.yy = cross_product(matrix.zz, matrix.xx);
	}
	return (vec_mtx_mul(matrix, ray));
}
