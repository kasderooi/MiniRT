/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minirt_error.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-rooi <kde-rooi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/04 14:16:12 by kde-rooi      #+#    #+#                 */
/*   Updated: 2021/01/05 15:05:47 by kde-rooi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int		filename_check(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("wrong nbr of arguments", 1);
		ft_putchar_fd('\n', 1);
		return (0);
	}
	if (!ft_strstr(argv[1], ".rt"))
	{
		ft_putstr_fd("wrong argument", 1);
		ft_putchar_fd('\n', 1);
		return (0);
	}
	return (1);
}
