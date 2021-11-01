/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atof.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-rooi <kde-rooi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/05 12:12:47 by kde-rooi      #+#    #+#                 */
/*   Updated: 2021/01/06 10:30:25 by kde-rooi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

float		ft_atof(const char *str)
{
	char	**split;
	float	nbr1;
	float	nbr2;

	split = ft_split(str, '.');
	nbr1 = 0;
	nbr2 = 0;
	if (!split)
		return (0);
	if (split[0])
		nbr1 = (float)ft_atoi(split[0]);
	if (split[1])
		nbr2 = (float)ft_atoi(split[1]);
	if (split[0][0] == '-')
		nbr1 -= nbr2 / pow(10, (double)ft_nbrlen(nbr2));
	else
		nbr1 += nbr2 / pow(10, (double)ft_nbrlen(nbr2));
	ft_freesplit(split);
	return (nbr1);
}
