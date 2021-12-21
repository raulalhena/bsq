/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpujol-r <gpujol-r@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 16:28:59 by gpujol-r          #+#    #+#             */
/*   Updated: 2021/12/21 19:33:38 by rlopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	print_error(int error);

int	read_input(char **str)
{
	int	str_size;

	str_size = read(0, *str, SIZE);
	*str = malloc(sizeof(char) * str_size);
	if (!*str)
		return (print_error(2));
	return (0);
}
