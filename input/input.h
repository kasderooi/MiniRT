/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-rooi <kde-rooi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/04 10:49:20 by kde-rooi      #+#    #+#                 */
/*   Updated: 2021/02/05 09:54:33 by kas           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

# define RESOLUTION -3
# define AMBIANT -2
# define CAMERA -1
# define LIGHT 0
# define SPHERE 1
# define PLANE 2
# define SQUARE 3
# define CYLINDER 4
# define TRIANGLE 5

# include "../libft/libft.h"
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct		s_vector
{
	double			x;
	double			y;
	double			z;
}					t_vector;

typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

typedef struct		s_res
{
	size_t			x;
	size_t			y;
}					t_res;

typedef struct		s_ambiant
{
	float			lighting_ratio;
	t_color			color;
}					t_ambiant;

typedef struct		s_camera
{
	t_vector		origin;
	t_vector		normal;
	size_t			fov;
}					t_camera;

typedef struct		s_light
{
	t_vector		origin;
	float			brightness_ratio;
	t_color			color;
}					t_light;

typedef struct		s_shape
{
	t_vector		origin;
	t_vector		normal;
	double			diameter;
	double			size;
	t_color			color;
	t_vector		point0;
	t_vector		point1;
	t_vector		point2;
}					t_shape;

typedef struct		s_env
{
	t_res			resolution;
	t_ambiant		ambiant;
}					t_env;

typedef struct		s_input
{
	t_env			env;
	t_camera		*camera;
	t_list			**lightlist;
	t_list			**shapelist;
	struct s_input	*previous;
	struct s_input	*next;
}					t_input;

t_input				*input_init(void);
void				free_input(t_input *input);

int					get_next_line(char **line, int fd);
void				clean_up(char *str);

t_input				*read_file(char *filename, t_input *input);

t_color				make_color(char *input);
t_vector			make_vector(char *input);

void				make_resolution(char **split, t_input *input);
void				make_ambiant(char **split, t_input *input);
void				make_camera(char **split, t_list **cameralist);
void				make_light(char **split, t_input *input);

void				make_plane(char **split, t_input *input);
void				make_sphere(char **split, t_input *input);
void				make_square(char **split, t_input *input);
void				make_cylinder(char **split, t_input *input);
void				make_triangle(char **split, t_input *input);

t_list				*translate_plane(t_shape *old, t_vector camera);
t_list				*translate_sphere(t_shape *old, t_vector camera);
t_list				*translate_square(t_shape *old, t_vector camera);
t_list				*translate_cylinder(t_shape *old, t_vector camera);
t_list				*translate_triangle(t_shape *old, t_vector camera);

t_input				*translate_camera(t_input *input, t_list **cameralist);
void				error_message_arguments(const char *str, char **line);
void				error_message_argument(const char *str, char *line);
void				error_message(const char *str);
int					filename_check(int argc, char **argv);

#endif
