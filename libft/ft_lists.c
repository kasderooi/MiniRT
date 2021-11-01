/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lists.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-rooi <kde-rooi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/27 11:38:01 by kde-rooi      #+#    #+#                 */
/*   Updated: 2021/02/01 14:46:42 by kas           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	lst_clear(t_list **lst)
{
	t_list	*buffer;

	while (*lst)
	{
		buffer = (*lst)->next;
		free((*lst)->content);
		free((*lst));
		*lst = buffer;
	}
}

t_list	*lstlast(t_list *lst)
{
	while (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_list	*ft_lstnew(void *content, int type)
{
	t_list	*element;

	element = (t_list*)ft_calloc(1, sizeof(t_list));
	if (!element)
		return (NULL);
	element->type = type;
	element->content = content;
	element->next = NULL;
	return (element);
}

int		lstadd_back(t_list **lst, t_list *new)
{
	if (!new)
	{
		lst_clear(lst);
		return (0);
	}
	if (!*lst)
		*lst = new;
	else
		lstlast(*lst)->next = new;
	return (1);
}
