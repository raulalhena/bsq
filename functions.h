/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpujol-r <gpujol-r@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 11:41:21 by gpujol-r          #+#    #+#             */
/*   Updated: 2021/12/21 17:27:05 by gpujol-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# define SIZE 4096

typedef struct s_map{
	char	**map;
	int		start_x;
	int		start_y;
	int		max;
	int		rows;
	int		cols;
	char	empty;
	char	obstacle;
	char	full;
}	t_map;

void	read_input(char **str); // Miguel
void	read_file(char *argv, char **str); // Miguel
int		validate_map(char *buff, t_map *map); // Albert
int		resolve_map(char *buff, t_map *map); // Gabriel
void	print_map(t_map map); // Julia
void	free_map(t_map *map); // Julia
int		ft_atoi(char *str); // to customize
int		ft_strlen(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);
char	*ft_strcpy(char *str1, char *str2);
char	*ft_strncpy(char *str1, char *str2, int size);
int		create_map(t_map *map);
void	map_string(char *buff, t_map map);
void	find_square(t_map *map);

#endif
