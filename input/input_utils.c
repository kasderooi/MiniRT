/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kas <kas@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 11:22:37 by kas           #+#    #+#                 */
/*   Updated: 2021/02/02 15:21:02 by kas           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

t_input	*input_init(void)
{
	t_input	*input;

	input = (t_input*)ft_calloc(sizeof(t_input), 1);
	if (!input)
		error_message("Malloc fail");
	input->camera = (t_camera*)ft_calloc(sizeof(t_camera), 1);
	input->lightlist = (t_list**)ft_calloc(sizeof(t_list*), 1);
	input->shapelist = (t_list**)ft_calloc(sizeof(t_list*), 1);
	if (!input->camera || !input->lightlist || !input->shapelist)
		error_message("Malloc fail");
	return (input);
}

void	free_input(t_input *input)
{
	lst_clear(input->shapelist);
	free(input->shapelist);
	lst_clear(input->lightlist);
	free(input->lightlist);
	free(input->camera);
	free(input);
}
