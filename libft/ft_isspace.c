/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isspace.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-rooi <kde-rooi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/04 13:03:40 by kde-rooi      #+#    #+#                 */
/*   Updated: 2021/01/04 13:04:00 by kde-rooi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_isspace(int c)
{
	if ((char)c == '\t' || (char)c == '\n' || (char)c == '\v'
		|| (char)c == '\f' || (char)c == '\r' || (char)c == ' ')
		return (1);
	return (0);
}
