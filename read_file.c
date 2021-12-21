/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfort-pe <mfort-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:24:35 by mfort-pe          #+#    #+#             */
/*   Updated: 2021/12/21 16:31:00 by gpujol-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

char	*read_file(char *filename, char **p)
{
	int		fd;
	char	buff[SIZE];
	int		count;
	int		a;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return ("File error\n");
	count = 0;
	a = 1;
	while (a)
	{
		a = read(fd, buff, SIZE);
		count += a;
	}
	*p = malloc(sizeof(char) * count);
	if (!*p || close(fd))
		return ("Error\n");
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return ("File error\n");
	read(fd, *p, count);
	if (close(fd))
		return ("File error\n");
	return (*p);
}
