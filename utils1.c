/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlopez-m <rlopez-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 16:34:39 by rlopez-m          #+#    #+#             */
/*   Updated: 2021/12/21 21:48:55 by rlopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

unsigned int	ft_atoi(char *str)
{
	unsigned int	number;

	number = 0;
	while (*str != '\0' && *str >= '0' && *str <= '9')
	{
		number = number * 10;
		number = number + (*str - '0');
		str++;
	}
	return (number);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	aux;

	aux = 0;
	while (src[aux] && aux < n)
	{
		dest[aux] = src[aux];
		aux++;
	}
	while (aux < n)
	{
		dest[aux] = '\0';
		aux++;
	}
	return (dest);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	d;
	int	s;

	d = 0;
	while (dest[d])
		d++;
	s = 0;
	while (src[s])
		s++;
	i = 0;
	while (i < s)
	{
			dest[i + d] = src[i];
			i++;
	}
	dest[i + d] = '\0';
	return (dest);
}
