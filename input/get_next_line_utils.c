/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-rooi <kde-rooi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/04 11:24:35 by kde-rooi      #+#    #+#                 */
/*   Updated: 2021/01/05 18:54:26 by kde-rooi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	clean_up(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n' && i < BUFFER_SIZE - 1)
		i++;
	i++;
	while (i < BUFFER_SIZE)
	{
		str[j] = str[i];
		i++;
		j++;
	}
	while (j <= BUFFER_SIZE)
	{
		str[j] = '\0';
		j++;
	}
}
