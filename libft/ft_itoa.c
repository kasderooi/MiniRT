/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-rooi <kde-rooi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/30 13:48:55 by kde-rooi      #+#    #+#                 */
/*   Updated: 2021/01/04 13:25:36 by kde-rooi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(size_t n)
{
	size_t		len;
	long		nbr;
	char		*ret;

	nbr = (long)n;
	len = ft_nbrlen(nbr);
	ret = (char *)malloc(sizeof(char) * len + 1);
	if (!ret)
		return (NULL);
	if (nbr < 0)
	{
		ret[0] = '-';
		nbr *= -1;
	}
	ret[len] = '\0';
	if (nbr == 0)
		ret[0] = '0';
	while (nbr)
	{
		len--;
		ret[len] = (nbr % 10) + 48;
		nbr /= 10;
	}
	return (ret);
}
