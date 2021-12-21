/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmompart <mmompart@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:17:19 by mmompart          #+#    #+#             */
/*   Updated: 2021/12/21 21:37:25 by rlopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	free_mallocs(char ***map, int i)
{
	i--;
	while (i >= 0)
	{
		free(*map[i]);
		i--;
	}
	free(*map);
}

int	create_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	map->map = malloc(map->rows * sizeof(char *));
	if (map->map == NULL)
		return (1);
	while (i < map->rows)
	{
		map->map[i] = malloc (map->cols * sizeof(char));
		if (map->map[i] == NULL)
		{
			free_mallocs(&map->map, i);
			return (1);
		}
		i++;
	}
	map->start_x = 0;
	map->start_y = 0;
	map->max = 0;
	return (0);
}
