/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-rooi <kde-rooi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/30 18:01:11 by kde-rooi      #+#    #+#                 */
/*   Updated: 2021/01/05 12:25:53 by kde-rooi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	n;
	size_t	h;

	i = 0;
	h = 0;
	while (haystack[i])
	{
		n = 0;
		while (haystack[h] == needle[n] && needle[n])
		{
			h++;
			n++;
		}
		if (!needle[n])
			return (1);
		i++;
		h = i;
	}
	return (0);
}
