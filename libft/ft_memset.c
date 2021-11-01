/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-rooi <kde-rooi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/30 17:59:09 by kde-rooi      #+#    #+#                 */
/*   Updated: 2020/11/23 15:05:09 by kde-rooi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*a;
	unsigned char	v;

	a = (unsigned char*)b;
	v = c;
	while (len > 0)
	{
		*a = v;
		a++;
		len--;
	}
	return (b);
}
