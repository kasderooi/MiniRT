/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   translate_camera.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: kas <kas@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/01 09:41:15 by kas           #+#    #+#                 */
/*   Updated: 2021/02/05 12:07:58 by kas           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include "../vec_math/vec_math.h"

void	translate_light(t_list **lst, t_list **lightlist, t_vector camera)
{
	t_list	*copy;
	t_light	*light;
	t_list	*buffer;

	copy = *lightlist;
	while (copy)
	{
		light = (t_light*)ft_calloc(1, sizeof(t_light));
		if (!light)
			error_message("Malloc fail!");
		light->origin = vec_sub(((t_light *)copy->content)->origin, camera);
		light->brightness_ratio = ((t_light *)copy->content)->brightness_ratio;
		light->color = ((t_light *)copy->content)->color;
		buffer = ft_lstnew(light, LIGHT);
		if (buffer->content)
			lstadd_back(lst, buffer);
		copy = copy->next;
	}
}

void	translate_shape(t_list **lst, t_list **shapelist, t_vector camera)
{
	t_list	*copy;
	t_shape	*shape;
	t_list	*buffer;

	copy = *shapelist;
	while (copy)
	{
		shape = (t_shape*)ft_calloc(1, sizeof(t_shape));
		if (!shape)
			error_message("Malloc fail!");
		shape->origin = vec_sub(((t_shape*)copy->content)->origin, camera);
		shape->normal = ((t_shape*)copy->content)->normal;
		shape->diameter = ((t_shape*)copy->content)->diameter;
		shape->size = ((t_shape*)copy->content)->size;
		shape->color = ((t_shape*)copy->content)->color;
		shape->point0 = vec_sub(((t_shape*)copy->content)->point0, camera);
		shape->point1 = vec_sub(((t_shape*)copy->content)->point1, camera);
		shape->point2 = vec_sub(((t_shape*)copy->content)->point2, camera);
		buffer = ft_lstnew(shape, copy->type);
		if (buffer->content)
			lstadd_back(lst, buffer);
		copy = copy->next;
	}
}

void	camera_loop(t_input *input, t_list *copy, t_input *adr, t_input **new)
{
	t_input	*next;
	t_input	*prev;
	t_input	*element;

	next = adr;
	prev = NULL;
	while (copy)
	{
		element = next;
		element->env = input->env;
		element->camera->fov = ((t_camera *)copy->content)->fov;
		element->camera->normal = ((t_camera *)copy->content)->normal;
		translate_light(element->lightlist, input->lightlist,
							((t_camera *)copy->content)->origin);
		translate_shape(element->shapelist, input->shapelist,
							((t_camera *)copy->content)->origin);
		element->camera->normal = vec_nrm(element->camera->normal);
		element->previous = prev;
		prev = element;
		copy = copy->next;
		if (copy)
			next = input_init();
		element->next = next;
	}
	*new = element;
}

t_input	*translate_camera(t_input *input, t_list **cameralist)
{
	t_input	*new;
	t_input	*adress;
	t_list	*copy;

	copy = *cameralist;
	adress = input_init();
	camera_loop(input, copy, adress, &new);
	adress->previous = new;
	new->next = adress;
	free_input(input);
	lst_clear(cameralist);
	free(cameralist);
	return (adress);
}
