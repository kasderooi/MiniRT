/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   makedata_basic.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-rooi <kde-rooi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/05 11:31:50 by kde-rooi      #+#    #+#                 */
/*   Updated: 2021/02/05 09:54:55 by kas           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

t_color		make_color(char *data)
{
	char		**split;
	t_color		color;

	split = ft_split(data, ',');
	if (!split[0] || !split[1] || !split[2] || split[3])
		error_message_arguments("color value", split);
	color.r = ft_atoi(split[0]);
	color.g = ft_atoi(split[1]);
	color.b = ft_atoi(split[2]);
	if (color.r < 0 || color.r > 255 || color.g < 0 ||
		color.g > 255 || color.b < 0 || color.b > 255)
		error_message("Color values should be between 0 and 255");
	ft_freesplit(split);
	return (color);
}

t_vector	make_vector(char *data)
{
	char		**split;
	t_vector	vector;

	split = ft_split(data, ',');
	if (!split[0] || !split[1] || !split[2] || split[3])
		error_message_arguments("vector value", split);
	vector.x = ft_atof(split[0]);
	vector.y = ft_atof(split[1]);
	vector.z = ft_atof(split[2]);
	ft_freesplit(split);
	return (vector);
}
