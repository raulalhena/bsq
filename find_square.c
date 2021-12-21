/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpujol-r <gpujol-r@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:01:16 by gpujol-r          #+#    #+#             */
/*   Updated: 2021/12/21 13:47:27 by gpujol-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	create_map(t_map *map);

int	check_current_square(t_map map, int x, int y, int *square_size)
{
	int	i;
	int	j;

	while (x + *square_size <= map.rows && y + *square_size <= map.cols)
	{
		i = 0;
		while (i < *square_size)
		{
			j = 0;
			while (j < *square_size)
			{
				if (map.map[x + i][y + j] == map.obstacle)
					return (1);
				j++;
			}
			i++;
		}
		(*square_size)++;
	}
	return (1);
}

void	find_square(t_map *map)
{
	int	x;
	int	y;
	int	square_size;

	x = 0;
	map->start_x = 0;
	map->start_y = 0;
	map->max = 0;
	while (x < map->rows)
	{
		y = 0;
		while (y < map->cols)
		{
			square_size = 1;
			if (check_current_square(*map, x, y, &square_size))
				square_size--;
			if (square_size > map->max)
			{
				map->start_x = x;
				map->start_y = y;
				map->max = square_size;
				printf("start_x%i\n", map->start_x);
				printf("start_y%i\n", map->start_y);
				printf("max square%i\n", map->max);
			}
			y++;
		}
		x++;
	}
}

int	main(void)
{
	t_map map;
	int error;
	int	i = 0;
	int	j;

/*	map.map = malloc(sizeof(char *) * 10);
	while (i < 10)
	{
		map.map[i] = malloc(sizeof(char) * 15);
		i++;
	}
	*/
		map.rows = 10;
	map.cols = 15;
	error = create_map(&map);
	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 15)
		{
			map.map[i][j] = '.';
			j++;
		}
		i++;
	}

	printf("%i\n", map.rows);
	printf("%i\n", map.cols);
	map.map[1][4] = 'o';
	map.map[2][10] = 'o';
	map.map[4][5] = 'o';
	map.empty = '.';
	map.obstacle = 'o';
	find_square(&map);
	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 15)
		{
			write(1, &map.map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	printf("%i %i %i\n", map.start_x, map.start_y, map.max);
	printf("%p\n", &map);
	printf("%p\n", &map.max);
}
