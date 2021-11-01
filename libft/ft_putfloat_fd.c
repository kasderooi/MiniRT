/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putfloat_fd.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-rooi <kde-rooi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/05 14:17:48 by kde-rooi      #+#    #+#                 */
/*   Updated: 2021/01/05 17:10:35 by kde-rooi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putfloat_fd(float n, int fd)
{
	long	new;
	long	dec;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	new = n;
	dec = (n * 1000000) - (new * 1000000);
	ft_putnbr_fd(new, fd);
	if (dec)
	{
		ft_putchar_fd('.', fd);
		while (dec % 10 == 0)
			dec /= 10;
		ft_putnbr_fd(dec, fd);
	}
}
