/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlopez-m <rlopez-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 16:34:39 by rlopez-m          #+#    #+#             */
/*   Updated: 2021/12/21 16:34:41 by rlopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int ft_atoi(char *str)
{
    int number;

    number = 0;
    while (*str >= '0' && *str <= '9')
    {
        number = number * 10;
        number = number + (*str - '0');
        str++;
    }
    return (number);
}