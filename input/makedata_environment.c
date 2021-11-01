/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   makedata_environment.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-rooi <kde-rooi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/05 10:48:55 by kde-rooi      #+#    #+#                 */
/*   Updated: 2021/02/09 09:15:48 by kas           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

void	make_camera(char **split, t_list **cameralist)
{
	t_camera	*camera;
	t_list		*buffer;

	if (!split[1] || !split[2] || !split[3] || split[4])
		error_message_arguments("camera", split);
	camera = (t_camera*)ft_calloc(1, sizeof(t_camera));
	if (!camera)
		error_message("Malloc fail");
	camera->origin = make_vector(split[1]);
	camera->normal = make_vector(split[2]);
	camera->fov = ft_atoi(split[3]);
	if (camera->fov <= 0 || camera->fov > 180)
		error_message("FOV should be between 1 and 180");
	buffer = ft_lstnew(camera, CAMERA);
	if (buffer->content)
		lstadd_back(cameralist, buffer);
}

void	make_light(char **split, t_input *input)
{
	t_light	*light;
	t_list	*buffer;
	double	ratio;

	if (!split[1] || !split[2] || !split[3] || split[4])
		error_message_arguments("light", split);
	light = (t_light*)ft_calloc(1, sizeof(t_light));
	if (!light)
		error_message("Malloc fail");
	light->origin = make_vector(split[1]);
	ratio = ft_atof(split[2]);
	if (ratio < 0 || ratio > 1)
		error_message("Lighting ratio needs to be between 0 and 1");
	light->brightness_ratio = ratio;
	light->color = make_color(split[3]);
	buffer = ft_lstnew(light, LIGHT);
	if (buffer->content)
		lstadd_back(input->lightlist, buffer);
}

void	make_resolution(char **split, t_input *input)
{
	int			x;
	int			y;
	static int	i = 0;

	if (i > 0)
		error_message("Resolution can only be defined once");
	i++;
	if (!split[1] || !split[2] || split[3])
		error_message_arguments("resolution", split);
	x = (size_t)ft_atoi(split[1]);
	y = (size_t)ft_atoi(split[2]);
	if (x <= 0 || y <= 0)
		error_message("Resolution values should be bigger than 0");
	input->env.resolution.x = x;
	input->env.resolution.y = y;
}

void	make_ambiant(char **split, t_input *input)
{
	double		ratio;
	static int	i = 0;

	if (i > 0)
		error_message("Ambiant light can only be defined once");
	i++;
	if (!split[1] || !split[2] || split[3])
		error_message_arguments("ambiant", split);
	ratio = ft_atof(split[1]);
	if (ratio < 0 || ratio > 1)
		error_message("Lighting ratio needs to be between 0 and 1");
	input->env.ambiant.lighting_ratio = ratio;
	input->env.ambiant.color = make_color(split[2]);
}
