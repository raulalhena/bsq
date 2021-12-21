/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpujol-r <gpujol-r@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:01:16 by gpujol-r          #+#    #+#             */
/*   Updated: 2021/12/21 18:28:29 by gpujol-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

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
			}
			y++;
		}
		x++;
	}
}
