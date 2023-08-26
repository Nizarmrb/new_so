/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelmrabe <nelmrabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 01:40:23 by nelmrabe          #+#    #+#             */
/*   Updated: 2023/08/26 13:42:36 by nelmrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	valid_map(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac != 2)
	{
		write(1, "Error args\n", 11);
		exit(1);
	}
	while (av[1][i])
		i++;
	if (av[1][i - 1] != 'r' || av[1][i - 2] != 'e' || av[1][i - 3] != 'b'
		|| av[1][i - 4] != '.')
	{
		write(1, "error map name\n", 15);
		exit(1);
	}
}

void	error(t_map *map)
{
	(void)map;
	write(1, "Error in map\n", 13);
	exit(1);
}

void	path(t_map *map, int y, int x)
{
	path_validation(map, y, x - 1);
	path_validation(map, y, x + 1);
	path_validation(map, y + 1, x);
	path_validation(map, y - 1, x);
}

int	path_validation(t_map *map, int y, int x)
{
	if (map->tmp[y][x] == 'P')
	{
		map->tmp[y][x] = '1';
		path(map, y, x);
	}
	if (map->tmp[y][x] == 'E')
	{
		map->tmp[y][x] = '1';
		map->exit--;
	}
	else if (map->tmp[y][x] == '0')
	{
		map->tmp[y][x] = '1';
		path(map, y, x);
	}
	else if (map->tmp[y][x] == 'C')
	{
		map->coin--;
		map->tmp[y][x] = '1';
		path(map, y, x);
	}
	if (map->coin == 0 && map->exit == 0)
		return (1);
	return (0);
}
