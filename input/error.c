/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kas <kas@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 12:29:36 by kas           #+#    #+#                 */
/*   Updated: 2021/02/09 09:13:07 by kas           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

void	error_message_arguments(const char *str, char **line)
{
	int	i;

	i = 0;
	printf("ERROR:\tWrong %s input\n", str);
	printf("INPUT:\t");
	if (!line[0])
		printf("NONE");
	while (line[i])
	{
		printf("%s ", line[i]);
		i++;
	}
	printf("\n");
	exit(1);
}

void	error_message_argument(const char *str, char *line)
{
	int	i;

	i = 0;
	printf("ERROR:\tWrong %s input\n", str);
	printf("INPUT:\t");
	if (!line)
		printf("NONE\n");
	else
		printf("%s\n", line);
	exit(1);
}

void	error_message(const char *str)
{
	printf("ERROR:\t%s\n", str);
	exit(1);
}

int		filename_check(int argc, char **argv)
{
	if (argc < 2)
		error_message("Please specify a filename");
	if (!ft_strstr(argv[1], ".rt"))
		error_message("Please format you filename conform *.rt");
	if (argc == 3 && (!ft_strstr(argv[2], "--save") || ft_strlen(argv[2]) != 6))
		error_message_argument("running", argv[2]);
	if (argc > 3)
		error_message("Wrong number of arguments");
	if (argc == 3)
		return (2);
	return (1);
}
