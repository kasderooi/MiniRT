/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raytracing.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kas <kas@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/05 09:17:11 by kas           #+#    #+#                 */
/*   Updated: 2021/02/07 15:23:47 by kas           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACING_H
# define RAYTRACING_H

# include "../input/input.h"
# include "../libft/libft.h"
# include "../utils/minirt_utils.h"
# include "../vec_math/vec_math.h"

# define RADIANS 0.017453293
# define EPSILON 1.0E-6

typedef struct	s_ray
{
	t_vector	origin;
	t_vector	normal;
	size_t		height;
	size_t		width;
	double		ratio;
	double		fov;
}				t_ray;

typedef struct	s_hit
{
	t_vector	point;
	t_vector	normal;
	t_color		color;
	double		distance;
}				t_hit;

typedef struct	s_rt
{
	t_input		*input;
	t_data		*img;
	t_ray		ray;
	size_t		mult;
	size_t		mult2;
}				t_rt;

void			ray_tracing_bmp(t_data *img, t_input *input);
void			ray_tracing_img(t_data *img, t_input *input);
t_hit			cast_ray(t_ray ray, t_list *shapes);
void			cast_light(t_hit *hit, t_input *input, t_ray ray2);
double			switch_shapes(t_ray ray, t_list *shapes, t_hit *ret);
t_vector		is_normal(t_vector ray, t_vector shape);

double			intersect_plane(t_ray ray, t_shape *plane, t_hit *hit);
double			intersect_sphere(t_ray ray, t_shape *sphere, t_hit *hit);
double			intersect_triangle(t_ray ray, t_shape *triangle, t_hit *hit);
double			intersect_cylinder(t_ray ray, t_shape *cyl, t_hit *hit);
double			intersect_square(t_ray ray, t_shape *square, t_hit *hit);

#endif
