/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlopez-m <rlopez-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 16:26:36 by rlopez-m          #+#    #+#             */
/*   Updated: 2021/12/21 17:39:10 by gpujol-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	print_error(int error)
{
	if (error == 1)
		write(1, "File error\n", 11);
	else if (error == 2)
		write(1, "Memory error\n", 13);
	return (error);
}

int	main(int argc, char *argv[])
{
	t_map	*map;
	int		i;
	char	*str;

	if (argc > 1)
	{
		i = 1;
		while (i < argc - 1)
		{
			if (validate_map(read_file(argv[i], &str), map))
				return (free(str));
			if (!resolve_map(map))
				print_map(map);
			free(str);
		}
	}
	else if (argc == 1)
	{
		if (validate_map(read_input(&str), map))
			return (free(str));
		if (!resolve_map(map))
			print_map(map);
		free(str);
	}
	return (0);
}
