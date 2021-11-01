/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bitmap_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kas <kas@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/05 10:54:49 by kas           #+#    #+#                 */
/*   Updated: 2021/02/07 14:22:06 by kas           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_utils.h"
#include "../raytracing/raytracing.h"

uint8_t	***init_bmp_data(int x, int y)
{
	int		i;
	int		j;
	uint8_t	***bmp;

	i = 0;
	bmp = (uint8_t***)ft_calloc(sizeof(uint8_t**), y);
	while (i < y)
	{
		j = 0;
		bmp[i] = (uint8_t**)ft_calloc(sizeof(uint8_t*), x);
		while (j < x)
		{
			bmp[i][j] = (uint8_t*)ft_calloc(sizeof(uint8_t), 3);
			j++;
		}
		i++;
	}
	return (bmp);
}
