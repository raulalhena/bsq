/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpujol-r <gpujol-r@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 11:41:21 by gpujol-r          #+#    #+#             */
/*   Updated: 2021/12/21 19:30:21 by rlopez-m         ###   ########.fr       */
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

int				read_input(char **str); // Miguel
int				read_file(char *argv, char **str); // Miguel
int				validate_map(char *buff, t_map *map); // Albert
int				resolve_map(char *buff, t_map *map); // Gabriel
int				create_map(t_map *map);
void			map_string(char *buff, t_map *map);
void			find_square(t_map *map);
void			print_and_free_map(t_map *map); // Julia
void			free_map(t_map *map); // Julia
unsigned int	ft_atoi(char *str); // to customize

#endif
