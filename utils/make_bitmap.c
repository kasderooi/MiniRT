/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_bitmap.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kas <kas@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/04 11:02:49 by kas           #+#    #+#                 */
/*   Updated: 2021/02/07 15:19:43 by kas           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../input/input.h"
#include "minirt_utils.h"

static void		init_header(
	uint8_t *bmp, uint32_t x, uint32_t y, uint32_t file_size)
{
	*((uint8_t *)&bmp[0]) = (uint8_t)0x42;
	*((uint8_t *)&bmp[1]) = (uint8_t)0x4D;
	*((uint32_t *)&bmp[2]) = (uint32_t)file_size;
	*((uint32_t *)&bmp[10]) = (uint32_t)HEADERSIZE;
	*((uint32_t *)&bmp[14]) = (uint32_t)0x28;
	*((uint32_t *)&bmp[18]) = (uint32_t)x;
	*((uint32_t *)&bmp[22]) = (uint32_t)y;
	*((uint16_t *)&bmp[26]) = (uint16_t)0x01;
	*((uint16_t *)&bmp[28]) = (uint16_t)0x18;
}

static size_t	bmp_size(size_t x, size_t y)
{
	if ((x * 3) % 4 != 0)
		x = x + 4 - ((x * 3) % 4);
	return (HEADERSIZE + (3 * y * x));
}

static void		write_color_pixel(uint8_t *bmp, uint8_t ***color, int x, int y)
{
	int xi;
	int i;
	int	array_i;

	array_i = HEADERSIZE;
	y--;
	while (y >= 0)
	{
		xi = 0;
		while (xi < x)
		{
			i = 0;
			while (i < 3)
			{
				bmp[array_i] = color[y][xi][i];
				array_i++;
				i++;
			}
			xi++;
		}
		y--;
	}
}

static char		*make_title(void)
{
	char		*title;
	static int	i = 1;
	int			len;
	char		*nbr;

	len = (int)ft_nbrlen(i);
	title = (char*)ft_calloc(sizeof(char), len + 12);
	nbr = ft_itoa(i);
	ft_memcpy(title, "miniRT_", 7);
	ft_memcpy(&title[7], nbr, len);
	ft_memcpy(&title[7 + len], ".bmp", 4);
	title[len + 11] = '\0';
	i++;
	free(nbr);
	return (title);
}

void			make_bmp(t_input *input, t_data *img)
{
	size_t	size;
	uint8_t	*bmp;
	int		fd;
	char	*title;

	size = bmp_size(input->env.resolution.x, input->env.resolution.y);
	bmp = ft_calloc(1, size);
	title = make_title();
	if (!bmp)
		error_message("Malloc fail!");
	init_header(bmp, input->env.resolution.x, input->env.resolution.y, size);
	fd = open(title, O_WRONLY | O_CREAT, 0777);
	if (fd < 0)
		error_message("Open bmp fail!");
	write_color_pixel(bmp, img->bmp, input->env.resolution.x,
							input->env.resolution.y);
	if (write(fd, bmp, size) != (ssize_t)size)
		error_message("Write bmp fail!");
	if (close(fd) < 0)
		error_message("File closing fail!");
	free(bmp);
	printf("File saved to %s\n", title);
	free(title);
}
