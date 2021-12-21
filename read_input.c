/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpujol-r <gpujol-r@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 16:28:59 by gpujol-r          #+#    #+#             */
/*   Updated: 2021/12/21 21:58:20 by rlopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include "utils1.h"
#include "utils2.h"

int	read_input(char **str)
{
	int		str_size;
	char	aux[1];

	str_size = 1;
	*str = malloc(sizeof(char) * SIZE);
	if (!*str)
		return (print_error(2));
	while (str_size)
	{
		str_size = read(0, aux, 1);
	}
	printf("%s\n", *str);
	return (0);
}
