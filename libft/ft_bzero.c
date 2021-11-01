/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-rooi <kde-rooi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/30 10:53:57 by kde-rooi      #+#    #+#                 */
/*   Updated: 2020/11/04 15:25:24 by kde-rooi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char *t;

	t = (unsigned char*)s;
	while (n > 0)
	{
		*t = 0;
		t++;
		n--;
	}
}
