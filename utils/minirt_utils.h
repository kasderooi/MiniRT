/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minirt_utils.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-rooi <kde-rooi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/04 14:20:39 by kde-rooi      #+#    #+#                 */
/*   Updated: 2021/02/07 14:35:46 by kas           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_UTILS_H
# define MINIRT_UTILS_H

# include "../mlxmms/mlx.h"
# include "../mlxogl/mlx.h"
# include "../input/input.h"

# define HEADERSIZE 54
# define LEFT 123
# define RIGHT 124
# define ESC 53
# define S 1

typedef struct	s_data {
	void		*img;
	char		*addr;
	uint8_t		***bmp;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct	s_mlxwin {
	void		*mlx;
	void		*window;
	t_input		*input;
	t_data		*img;
}				t_mlxwin;

void			make_bmp(t_input *input, t_data *img);
void			make_mlx(t_mlxwin *window);
void			save_bitmap(t_mlxwin window);
uint8_t			***init_bmp_data(int x, int y);

void			my_mlx_pixel_put(t_data *data, int x, int y, t_color color);
int				create_trgb(int t, int r, int g, int b);
int				create_trgb_struct(int t, t_color color);
void			check_res(t_mlxwin *window);

#endif
