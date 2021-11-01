/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_math.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-rooi <kde-rooi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/18 11:36:50 by kde-rooi      #+#    #+#                 */
/*   Updated: 2021/02/07 15:05:24 by kas           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_MATH_H
# define VEC_MATH_H

# include "../input/input.h"
# include "../raytracing/raytracing.h"
# include <math.h>

typedef struct	s_matrix
{
	t_vector	xx;
	t_vector	yy;
	t_vector	zz;
}				t_matrix;

double			dot_product(t_vector v, t_vector u);
t_vector		cross_product(t_vector v, t_vector u);

t_vector		vec_add(t_vector v, t_vector u);
t_vector		vec_sub(t_vector v, t_vector u);
t_vector		vec_mul(t_vector v, double multiplier);
t_vector		vec_dev(t_vector v, double devider);
t_vector		vec_set(double x, double y, double z);

double			vec_sqr(t_vector v);
double			vec_len(t_vector v);
t_vector		vec_nrm(t_vector v);

t_vector		vec_mtx_mul(t_matrix matrix, t_vector vec);
t_vector		translate_ray(t_vector dir, t_vector ray);

t_color			col_add(t_color v, t_color u);
t_color			col_add_cl(t_color v, t_color u);
t_color			col_sub(t_color v, t_color u);
t_color			col_mul(t_color v, double multiplier);
t_color			col_dev(t_color v, double devider);

t_color			col_product(t_color v, t_color u);
t_color			col_mix(t_color current, t_color new);
t_color			col_set(int r, int g, int b);
t_color			col_min(t_color color, t_color min);

double			sqrd(double x);
double			abc_formula(double a, double b, double c);
double			check_margin(double x);
double			max(double a, double b);
double			min(double a, double b);

#endif
