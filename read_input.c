/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpujol-r <gpujol-r@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 16:28:59 by gpujol-r          #+#    #+#             */
/*   Updated: 2021/12/21 16:29:38 by gpujol-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

char	*read_input(char **p)
{
	int	a;

	a = read(0, *p, SIZE);
	*p = malloc(sizeof(char) * a);
	if (!*p)
		return ("Memory error\n");
	return (*p);
}
