/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 11:38:26 by amantara          #+#    #+#             */
/*   Updated: 2021/12/21 20:18:22 by gpujol-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

//Valida que todas las lineas tienen la misma logitud
//Devuelve el numero de caracteres por linea en caso de ser correcto. 
int	validate_row_count(char *map)
{
	int	i;
	int	count;
	int	count2;

	count = 0;
	count2 = 0;
	i = 0;
	while (map[i] != '\n')
		i++;
	i++;
	while (map[i])
	{
		while (map[i] != '\n' && map[i])
		{
			count2++;
			i++;
		}
		if (count == 0)
			count = count2;
		else if (count2 != count)
			return (-1);
		count2 = 0;
		i++;
	}
	return (count);
}

// Valida que almenos hay un caracter vacio para rellenar.
int	validate_at_least_one_empty(char *map, char empty)
{
	int	i;

	i = 0;
	while (map[i] != '\n')
		i++;
	i++;
	while (map[i])
	{
		if (map[i] == empty)
			return (1);
		i++;
	}
	return (-1);
}

// Validamos si tiene los valores correctos el mapa.
int	check_char(char *map, char obstacle, char empty, char number)
{
	int	i;

	i = 0;
	while (map[i] != '\n')
		i++;
	i++;
	while (map[i])
	{
		if (map[i] != obstacle && map[i] != empty && map[i] != '\n' )
			return (-1);
		i++;
	}
	return (1);
}

// Valida el numero de filas que tiene el mapa.
int	validate_row_number(char *map, int number)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		if (map[i] == '\n')
			count++;
		i++;
	}
	if (count != number)
		return (-1);
	return (1);
}

int	validate_map(char *buff, t_map *map)
{
	int	num_rows;
	int	num_cols;
	char *first_line;

	first_line = malloc(ft_strlen2(buff) * sizeof(char));
	if (!first_line)
		return (print_error(2));
	num_rows = validate_print_char(first_line, map);
	if (validate_row_number(buff, num_rows) == -1)
	{
		write(1, "A", 1);
		return (print_error(3));
	}
	else if (check_char(buff, map->obstacle, map->empty, num_rows) == -1)
		return (print_error(3));
	else if (validate_at_least_one_empty(buff, map->empty) == -1)
		return (print_error(3));
	num_cols = validate_row_count(buff);
	if (num_cols == -1)
		return (print_error(3));
	map->rows = num_rows;
	map->cols = num_cols;
	return (0);
}
