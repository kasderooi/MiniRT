/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_splitspace.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-rooi <kde-rooi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/30 14:37:48 by kde-rooi      #+#    #+#                 */
/*   Updated: 2021/01/05 17:43:01 by kde-rooi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *str)
{
	size_t		index;
	size_t		count;

	index = 0;
	count = 1;
	while (ft_isspace(str[index]))
		index++;
	if (str[index] == '\0')
		count--;
	while (!ft_isspace(str[index]) && str[index] != '\0')
		index++;
	if (str[index] != '\0')
		count += ft_count_words(&str[index]);
	return (count);
}

static char		**ft_make_array(char **dst, char *s, struct s_var v)
{
	dst[v.count] = ft_substr(s, v.dest_i, v.src_i - v.dest_i);
	if (!dst)
	{
		while (v.count > 0)
		{
			v.count--;
			free(dst[v.count]);
		}
		return (NULL);
	}
	return (dst);
}

static char		**ft_fill_array(char **dst, char *s)
{
	t_var	v;

	v.src_i = 0;
	v.count = 0;
	while (s[v.src_i] != '\0')
	{
		v.dest_i = 0;
		while (ft_isspace(s[v.src_i]) && s[v.src_i] != '\0')
			v.src_i++;
		v.dest_i = v.src_i;
		while (!ft_isspace(s[v.src_i]) && s[v.src_i] != '\0')
			v.src_i++;
		if (v.count < (int)ft_count_words(s))
			dst = ft_make_array(dst, s, v);
		if (!dst)
			return (NULL);
		v.count++;
	}
	return (dst);
}

char			**ft_splitspace(char const *s)
{
	char	**dst;

	if (!s)
		return (NULL);
	dst = (char**)ft_calloc(ft_count_words(s) + 1, sizeof(char*));
	if (!dst)
		return (NULL);
	dst = ft_fill_array(dst, (char*)s);
	if (!dst)
		free(dst);
	return (dst);
}
