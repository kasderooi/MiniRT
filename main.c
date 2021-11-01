/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-rooi <kde-rooi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/04 14:01:44 by kde-rooi      #+#    #+#                 */
/*   Updated: 2021/02/07 15:09:42 by kas           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		main(int argc, char **argv)
{
	t_mlxwin	window;
	int			save;

	save = filename_check(argc, argv);
	window.input = input_init();
	window.input = read_file(argv[1], window.input);
	check_res(&window);
	make_mlx(&window);
	ray_tracing_img(window.img, window.input);
	if (save == 2)
	{
		make_bmp(window.input, window.img);
		exit(0);
	}
	else
	{
		mlx_put_image_to_window(window.mlx,
			window.window, window.img->img, 0, 0);
		mlx_hook(window.window, 2, 1L << 0, pressed, &window);
		mlx_hook(window.window, 17, 1L << 2, clicked, &window);
		mlx_loop(window.mlx);
	}
	return (0);
}
