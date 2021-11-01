/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-rooi <kde-rooi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 13:22:07 by kde-rooi      #+#    #+#                 */
/*   Updated: 2021/02/07 14:55:03 by kas           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

typedef struct		s_var
{
	int				dest_i;
	int				src_i;
	int				count;
}					t_var;

typedef struct		s_list
{
	int				type;
	void			*content;
	struct s_list	*next;
}					t_list;

size_t				ft_strlen(const char *s);
size_t				ft_strnlen(char *str);
size_t				ft_nbrlen(long nbr);
size_t				ft_nbrlen_base(unsigned int nbr, size_t baselen);

size_t				ft_isdigit(int c);
size_t				ft_isspace(int c);
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, size_t c);
char				*ft_strnstr(const char *haystack, const char *needle,
																size_t len);
size_t				ft_strstr(const char *haystack, const char *needle);
size_t				ft_strncmp(const char *s1, const char *s2, size_t n);

char				**ft_split(char const *s, char c);
char				**ft_splitspace(char const *s);
void				ft_freesplit(char **split);

void				*ft_calloc(size_t count, size_t size);
char				*ft_strdup(const char *s1);
char				*ft_strndup(const char *s1, size_t len);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);

int					ft_atoi(const char *str);
float				ft_atof(const char *str);
char				*ft_itoa(size_t n);
char				*ft_itoa_base(unsigned int nbr, char *base);

void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putfloat_fd(float n, int fd);
void				ft_putdouble_fd(double n, int fd);

int					lstadd_back(t_list **lst, t_list *new);
t_list				*ft_lstnew(void *content, int type);
t_list				*lstlast(t_list *lst);
void				lst_clear(t_list **lst);

#endif
