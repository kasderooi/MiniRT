/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_freesplit.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-rooi <kde-rooi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/06 10:13:48 by kde-rooi      #+#    #+#                 */
/*   Updated: 2021/01/06 10:29:02 by kde-rooi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_freesplit(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	while (i >= 0)
	{
		free(split[i]);
		i--;
	}
	free(split);
}
