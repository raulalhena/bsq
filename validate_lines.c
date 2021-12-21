/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validatelines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffusalba <ffusalba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:01:41 by ffusalba          #+#    #+#             */
/*   Updated: 2021/12/21 21:40:31 by rlopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include "utils2.h"

int	validate_command(char last_three[3], t_map *map)
{
	if (last_three[0] == last_three[1] || last_three[1] == last_three[2]
		|| last_three[0] == last_three[2])
		return (1);
	else
	{
		map->empty = last_three[0];
		map->obstacle = last_three[1];
		map->full = last_three[2];
		return (0);
	}
}

unsigned int	validate_number(char *str, t_map *map)
{
	unsigned int	size;
	int				size3;
	int				i;
	char			*numrows;
	char			str2[3];

	i = 0;
	size = ft_strlen2(str);
	ft_strncpy(str2, (str + size - 4), 3);
	numrows = malloc(sizeof(char) * (size - 4));
	numrows = ft_strncpy(numrows, str, size - 4);
	size3 = size - 4;
	while (numrows[i])
	{
		if (size3 > 10 || numrows[i] < '0' || numrows[i] > '9')
			return (1);
		else if (!validate_command(str2, map))
			return (ft_atoi(numrows));
		i++;
	}
	return (0);
}

unsigned int	validate_print_char(char *str, t_map *map)
{
	int				commandsize;
	unsigned int	finalnumber;
	int				i;

	finalnumber = 0;
	i = 0;
	commandsize = ft_strlen2(str);
	while (str[i] != '\n')
	{
		if (commandsize >= 4 && commandsize <= 13)
		{
			if (str[i] < 32 || str[i] > 126)
				return (1);
		}
		else
			return (1);
		i++;
	}
	return (validate_number(str, map));
}
