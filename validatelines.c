/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validatelines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffusalba <ffusalba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:01:41 by ffusalba          #+#    #+#             */
/*   Updated: 2021/12/21 19:44:03 by rlopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include "utils2.h"

int	validate_command(char *str, t_map *map)
{
	int			size;
	const char	*last_three = &str[size - 3];

	size = ft_strlen(str);
	if (last_three[0] == last_three[1] || last_three[1] == last_three[2]
		|| last_three[0] == last_three[2])
	{
		ft_putstr("Error");
		return (0);
	}
	else
	{
		map = malloc(sizeof(t_map));
		map->empty = last_three[0];
		map->obstacle = last_three[1];
		map->full = last_three[2];
		return (1);
	}
}

unsigned int	validate_number(char *str, t_map *map)
{
	unsigned int	size;
	int				size3;
	int				i;
	char			*numrows;

	i = 0;
	size = ft_strlen(str);
	numrows = malloc(sizeof(char) * (size - 3));
	numrows = ft_strncpy(numrows, str, size - 3);
	size3 = size - 3;
	while (numrows[i])
	{
		if (ft_strlen(numrows) > 10 || numrows[i] < '0' || numrows[i] > '9')
		{
			ft_putstr("Error");
			return (0);
		}
		else if (validate_command(str, map))
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
	commandsize = ft_strlen(str);
	while (str[i] != '\0')
	{
		if (commandsize >= 4 && commandsize <= 13)
		{
			if (str[i] < ' ' || str[i] > '~')
			{
				ft_putstr("Error");
				return (0);
			}
		}
		else if (commandsize < 4 || commandsize > 13)
		{
			ft_putstr("Error");
			return (0);
		}
		i++;
	}
	return (validate_number(str, map));
}
