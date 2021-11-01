/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-rooi <kde-rooi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/30 17:58:22 by kde-rooi      #+#    #+#                 */
/*   Updated: 2020/10/30 17:58:46 by kde-rooi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*b;
	int				i;

	b = (unsigned char*)dst;
	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i < (int)n)
	{
		b[i] = *(unsigned char*)src;
		src++;
		i++;
	}
	return (b);
}
