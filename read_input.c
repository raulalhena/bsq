/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpujol-r <gpujol-r@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 16:28:59 by gpujol-r          #+#    #+#             */
/*   Updated: 2021/12/21 22:29:34 by rlopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include "utils1.h"
#include "utils2.h"

int	read_input(char **str)
{
	int		str_size;
	int		i;
	char	aux[SIZE + 1];

	str_size = 1;
	i = 0;
	*str = malloc(sizeof(char) * SIZE + 1);
	if (!*str)
		return (print_error(2));
	while (i < SIZE)
	{
		aux[i] = '\0';
		(*str)[i] = '\0';
		i++;
	}
	i = 0;
	while (str_size > 0)
	{
		str_size = read(0, aux, SIZE);
		aux[str_size] = '\0';
		ft_strcat(*str, aux);
	}
	return (0);
}
