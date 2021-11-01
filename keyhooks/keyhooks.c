/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keyhooks.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kas <kas@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/07 15:06:40 by kas           #+#    #+#                 */
/*   Updated: 2021/02/07 15:16:20 by kas           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int		pressed(int keycode, t_mlxwin *window)
{
	int	ret;

	ret = 0;
	if (keycode == LEFT)
		window->input = window->input->previous;
	if (keycode == RIGHT)
		window->input = window->input->next;
	if (keycode == LEFT || keycode == RIGHT)
	{
		ray_tracing_img(window->img, window->input);
		mlx_put_image_to_window(window->mlx,
			window->window, window->img->img, 0, 0);
	}
	if (keycode == ESC)
		exit(0);
	if (keycode == S)
		make_bmp(window->input, window->img);
	return (ret);
}

int		clicked(int keycode, t_mlxwin *window)
{
	(void)window;
	(void)keycode;
	exit(0);
	return (0);
}
