/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minirt.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-rooi <kde-rooi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/04 13:44:35 by kde-rooi      #+#    #+#                 */
/*   Updated: 2021/02/07 14:36:37 by kas           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "mlxmms/mlx.h"
# include "mlxogl/mlx.h"
# include "input/input.h"
# include "libft/libft.h"
# include "utils/minirt_utils.h"
# include "vec_math/vec_math.h"
# include "raytracing/raytracing.h"

int		pressed(int keycode, t_mlxwin *window);
int		clicked(int keycode, t_mlxwin *window);

#endif
