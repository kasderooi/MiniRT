/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putdouble_fd.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: kas <kas@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/27 08:16:38 by kas           #+#    #+#                 */
/*   Updated: 2021/02/05 10:41:33 by kas           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putdouble_fd(double n, int fd)
{
	long	new;
	long	dec;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	new = n;
	dec = (n * 1000000000000000) - (new * 1000000000000000);
	ft_putnbr_fd(new, fd);
	if (dec)
	{
		ft_putchar_fd('.', fd);
		while (dec % 10 == 0)
			dec /= 10;
		ft_putnbr_fd(dec, fd);
	}
}
