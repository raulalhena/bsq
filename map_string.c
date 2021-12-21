/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpujol-r <gpujol-r@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 11:59:59 by gpujol-r          #+#    #+#             */
/*   Updated: 2021/12/21 22:39:24 by rlopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

//guardar cada caracter a partir de la segunda fila en cada casilla del mapa

void	map_string(char *buff, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*buff != '\n')
		buff++;
	buff++;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			map->map[i][j] = *buff;
			buff++;
			j++;
		}
		buff++;
		i++;
	}
}
