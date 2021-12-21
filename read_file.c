/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfort-pe <mfort-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:24:35 by mfort-pe          #+#    #+#             */
/*   Updated: 2021/12/21 21:38:40 by rlopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	print_error(int error);

int	read_file(char *filename, char **str)
{
	int		fd;
	char	buff[SIZE];
	int		count;
	int		aux_count;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (print_error(1));
	count = 0;
	aux_count = 1;
	while (aux_count)
	{
		aux_count = read(fd, buff, SIZE);
		count += aux_count;
	}
	*str = malloc(sizeof(char) * count);
	if (!*str || close(fd))
		return (print_error(1));
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (print_error(1));
	read(fd, *str, count);
	if (close(fd))
		return (print_error(1));
	return (0);
}
