/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minirt_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-rooi <kde-rooi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/21 11:58:23 by kde-rooi      #+#    #+#                 */
/*   Updated: 2021/02/07 14:37:34 by kas           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_utils.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, t_color color)
{
	char	*dst;

	data->bmp[y][x][0] = (uint8_t)color.b;
	data->bmp[y][x][1] = (uint8_t)color.g;
	data->bmp[y][x][2] = (uint8_t)color.r;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = create_trgb_struct(0, color);
}

int		create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int		create_trgb_struct(int t, t_color color)
{
	return (create_trgb(t, color.r, color.g, color.b));
}

void	make_mlx(t_mlxwin *window)
{
	t_data		*img;
	int			x;
	int			y;

	x = window->input->env.resolution.x;
	y = window->input->env.resolution.y;
	img = ft_calloc(sizeof(t_data), 1);
	img->bmp = init_bmp_data(x, y);
	window->mlx = mlx_init();
	window->window = mlx_new_window(window->mlx, x, y, "MiniRT");
	img->img = mlx_new_image(window->mlx, x, y);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
						&img->line_length, &img->endian);
	window->img = img;
}

void	check_res(t_mlxwin *window)
{
	int	x;
	int y;

	mlx_get_screen_size(window->mlx, &x, &y);
	if (x < (int)window->input->env.resolution.x)
		window->input->env.resolution.x = x;
	if (y < (int)window->input->env.resolution.y)
		window->input->env.resolution.y = y;
}
