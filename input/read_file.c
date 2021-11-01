/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_file.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-rooi <kde-rooi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/05 10:09:36 by kde-rooi      #+#    #+#                 */
/*   Updated: 2021/02/05 11:15:07 by kas           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

static void	check_minimum(int check)
{
	if ((check & 50331648) != 50331648)
		error_message("You need to specify resolution and ambiant");
	check = check & 16777215;
	if (!(check & 16711680))
		error_message("No cameras are placed on the scene");
	check = check & 65535;
	if (!(check & 65280))
		printf("WARNING: No lights are placed on the scene\n");
	check = check & 255;
	if (!(check & 255))
		printf("WARNING: No shapes are placed on the scene\n");
}

static int	make_env(char **split, t_input *input, t_list **cameralist)
{
	if (split[0][0] == 'R')
	{
		make_resolution(split, input);
		return (1 << 25);
	}
	else if (split[0][0] == 'A')
	{
		make_ambiant(split, input);
		return (1 << 24);
	}
	else if (split[0][0] == 'c')
	{
		make_camera(split, cameralist);
		return (1 << 16);
	}
	else if (split[0][0] == 'l')
	{
		make_light(split, input);
		return (1 << 8);
	}
	else
		error_message_arguments("type", split);
	return (-1);
}

static int	make_shape(char **split, t_input *input)
{
	if (split[0][0] == 's' && split[0][1] == 'p')
		make_sphere(split, input);
	else if (split[0][0] == 'p' && split[0][1] == 'l')
		make_plane(split, input);
	else if (split[0][0] == 's' && split[0][1] == 'q')
		make_square(split, input);
	else if (split[0][0] == 't' && split[0][1] == 'r')
		make_triangle(split, input);
	else if (split[0][0] == 'c' && split[0][1] == 'y')
		make_cylinder(split, input);
	else
		error_message_arguments("type", split);
	return (1 << 1);
}

static int	split_input(char *line, t_input *input, t_list **cameralist)
{
	char		**split;
	static int	ret = 0;

	split = ft_splitspace(line);
	if (!split[0][1])
		ret += make_env(split, input, cameralist);
	else if (!split[0][2])
		ret += make_shape(split, input);
	else
		error_message_arguments("type", split);
	ft_freesplit(split);
	return (ret);
}

t_input		*read_file(char *filename, t_input *input)
{
	char	*line;
	t_list	**cameralist;
	int		ret;
	int		fd;
	int		check;

	ret = 1;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_message("Wrong file");
	cameralist = (t_list **)ft_calloc(sizeof(t_list *), 1);
	if (!cameralist)
		error_message("Malloc fail");
	while (ret)
	{
		ret = get_next_line(&line, fd);
		if (ret == -1)
			error_message("Read fail");
		if (ft_strlen(line) > 1)
			check = split_input(line, input, cameralist);
		free(line);
	}
	check_minimum(check);
	return (translate_camera(input, cameralist));
}
