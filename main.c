/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlopez-m <rlopez-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 16:26:36 by rlopez-m          #+#    #+#             */
/*   Updated: 2021/12/21 16:31:38 by rlopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	main(int argc, char *argv[])
{
	t_map	*map;
	int		i;
	char	*p;

	if (argc > 1)
	{
		i = 1;
		while (i < argc - 1)
		{
			validate_map(read_file(argv[i], p), map);
			resolve_map(map);
			print_map(map);
			free(p);
		}
	}
	else if (argc == 1)
	{
		validate_map(read_input(argv[1], p), map);
		resolve_map(map);
		print_map(map);
		free(p);
	}
	return (0);
}
