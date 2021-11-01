/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-rooi <kde-rooi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/30 17:59:39 by kde-rooi      #+#    #+#                 */
/*   Updated: 2021/01/04 13:28:58 by kde-rooi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, size_t c)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char*)s;
	if (str[i] == (char)c)
		return (&str[i]);
	while (str[i] != (char)c && i < ft_strlen(s))
	{
		i++;
		if (str[i] == (char)c)
			return (&str[i]);
	}
	return (NULL);
}
