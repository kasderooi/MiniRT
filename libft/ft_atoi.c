/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-rooi <kde-rooi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/30 10:52:28 by kde-rooi      #+#    #+#                 */
/*   Updated: 2021/01/05 10:21:09 by kde-rooi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	size_t	i;
	int		sign;
	long	nbr;

	i = 0;
	nbr = 0;
	while (ft_isspace(str[i]) == 1)
		i++;
	sign = (str[i] == '-') ? -1 : 1;
	if (str[i] == '-')
		i++;
	if (str[i] == '+' && sign > 0)
		i++;
	while (i < ft_strlen(str) && ft_isdigit(str[i]) == 1)
	{
		nbr *= 10;
		nbr += str[i] - 48;
		if (nbr > 9223372036854775807 || i > 19)
			return ((sign > 0) ? -1 : 0);
		i++;
	}
	return (nbr * sign);
}
