/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpujol-r <gpujol-r@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 11:34:47 by gpujol-r          #+#    #+#             */
/*   Updated: 2021/12/21 12:11:06 by gpujol-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	create_map(t_map *map);

void  resolve_map(char *buff, t_map map)
{
	if (create_map(map))
		return (ft_putstr("Map error\n"));
	map_string(buff, map);
	find_square(map);
}
