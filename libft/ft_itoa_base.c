/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-rooi <kde-rooi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/30 13:48:55 by kde-rooi      #+#    #+#                 */
/*   Updated: 2021/01/04 13:08:11 by kde-rooi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa_base(unsigned int nbr, char *base)
{
	size_t		len;
	size_t		baselen;
	char		*ret;

	if (!base)
		return (NULL);
	baselen = ft_strlen(base);
	len = ft_nbrlen_base(nbr, baselen);
	ret = (char *)malloc(sizeof(char) * len + 1);
	if (!ret)
		return (NULL);
	ret[len] = '\0';
	if (nbr == 0)
		ret[0] = '0';
	len--;
	while (len)
	{
		ret[len] = base[nbr % baselen];
		nbr /= baselen;
		len--;
	}
	return (ret);
}
