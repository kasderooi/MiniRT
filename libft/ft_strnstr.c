/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-rooi <kde-rooi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/30 18:01:11 by kde-rooi      #+#    #+#                 */
/*   Updated: 2021/01/05 12:25:31 by kde-rooi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	n;
	size_t	h;

	i = 0;
	h = 0;
	while (i <= len)
	{
		n = 0;
		while (haystack[h] == needle[n] && needle[n] && h < len)
		{
			h++;
			n++;
		}
		if (!needle[n])
			return ((char*)&haystack[i]);
		i++;
		h = i;
	}
	return (NULL);
}
