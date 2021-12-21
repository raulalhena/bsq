/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpujol-r <gpujol-r@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 11:34:47 by gpujol-r          #+#    #+#             */
/*   Updated: 2021/12/21 17:39:43 by gpujol-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	resolve_map(char *buff, t_map *map)
{
	if (create_map(map))
		return (print_error(2));
	map_string(buff, map);
	find_square(map);
	return (0);
}
