/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   makedata_shape.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-rooi <kde-rooi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/05 10:09:41 by kde-rooi      #+#    #+#                 */
/*   Updated: 2021/02/05 16:44:18 by kas           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include "../vec_math/vec_math.h"

void	make_plane(char **split, t_input *input)
{
	t_shape	*plane;
	t_list	*buffer;

	if (!split[1] || !split[2] || !split[3] || split[4])
		error_message_arguments("plane", split);
	plane = (t_shape*)ft_calloc(1, sizeof(t_shape));
	if (!plane)
		error_message("Malloc fail");
	plane->origin = make_vector(split[1]);
	plane->normal = vec_nrm(make_vector(split[2]));
	plane->color = make_color(split[3]);
	buffer = ft_lstnew(plane, PLANE);
	if (buffer->content)
		lstadd_back(input->shapelist, buffer);
}

void	make_sphere(char **split, t_input *input)
{
	t_shape	*sphere;
	t_list	*buffer;

	if (!split[1] || !split[2] || !split[3] || split[4])
		error_message_arguments("sphere", split);
	sphere = (t_shape*)ft_calloc(1, sizeof(t_shape));
	if (!sphere)
		error_message("Malloc fail");
	sphere->origin = make_vector(split[1]);
	sphere->diameter = ft_atof(split[2]);
	sphere->color = make_color(split[3]);
	buffer = ft_lstnew(sphere, SPHERE);
	if (buffer->content)
		lstadd_back(input->shapelist, buffer);
}

void	make_square(char **split, t_input *input)
{
	t_shape	*square;
	t_list	*buffer;

	if (!split[1] || !split[2] || !split[3] || !split[4] || split[5])
		error_message_arguments("square", split);
	square = (t_shape*)ft_calloc(1, sizeof(t_shape));
	if (!square)
		error_message("Malloc fail");
	square->origin = make_vector(split[1]);
	square->normal = vec_nrm(make_vector(split[2]));
	square->size = ft_atof(split[3]);
	square->color = make_color(split[4]);
	buffer = ft_lstnew(square, SQUARE);
	if (buffer->content)
		lstadd_back(input->shapelist, buffer);
}

void	make_cylinder(char **split, t_input *input)
{
	t_shape	*cylinder;
	t_list	*buffer;

	if (!split[1] || !split[2] || !split[3] ||
		!split[4] || !split[5] || split[6])
		error_message_arguments("cylinder", split);
	cylinder = (t_shape*)ft_calloc(1, sizeof(t_shape));
	if (!cylinder)
		error_message("Malloc fail");
	cylinder->origin = make_vector(split[1]);
	cylinder->normal = vec_nrm(make_vector(split[2]));
	cylinder->diameter = ft_atof(split[3]);
	cylinder->size = ft_atof(split[4]);
	cylinder->color = make_color(split[5]);
	buffer = ft_lstnew(cylinder, CYLINDER);
	if (buffer->content)
		lstadd_back(input->shapelist, buffer);
}

void	make_triangle(char **split, t_input *input)
{
	t_shape	*triangle;
	t_list	*buffer;

	if (!split[1] || !split[2] || !split[3] || !split[4] || split[5])
		error_message_arguments("triangle", split);
	triangle = (t_shape*)ft_calloc(1, sizeof(t_shape));
	if (!triangle)
		error_message("Malloc fail");
	triangle->point0 = make_vector(split[1]);
	triangle->point1 = make_vector(split[2]);
	triangle->point2 = make_vector(split[3]);
	triangle->color = make_color(split[4]);
	buffer = ft_lstnew(triangle, TRIANGLE);
	if (buffer->content)
		lstadd_back(input->shapelist, buffer);
}
