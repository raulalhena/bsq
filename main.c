/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlopez-m <rlopez-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 16:26:36 by rlopez-m          #+#    #+#             */
/*   Updated: 2021/12/21 22:47:41 by rlopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	print_error(int error)
{
	if (error == 1)
		write(1, "File error\n", 11);
	else if (error == 2)
		write(1, "Memory error\n", 13);
	else if (error == 3)
		write(1, "Map error\n", 10);
	return (error);
}

void	solve_single_map(char *file)
{
	t_map	map;
	char	*str;

	if (file)
	{
		if (read_file(file, &str))
			return ;
	}
	else
	{
		if (read_input(&str))
			return ;
	}
	if (!validate_map(str, &map))
	{
		if (!resolve_map(str, &map))
			print_and_free_map(&map);
	}
	free(str);
}

int	main(int argc, char *argv[])
{
	int		i;

	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			solve_single_map(argv[i++]);
			if (argc > 2 && i == argc - 1)
				write(1, "\n", 1);
		}
	}
	else if (argc == 1)
		solve_single_map(NULL);
	return (0);
}
