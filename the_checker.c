/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelmrabe <nelmrabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 01:21:23 by nelmrabe          #+#    #+#             */
/*   Updated: 2023/08/26 13:11:41 by nelmrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	wall_checker(t_map *map, int i, int j)
{
	if (map->tmp[0][j] != '1' || map->tmp[i][0] != '1'
				|| map->tmp[map->line - 1][j] != '1' || map->tmp[i][map->length
				- 1] != '1')
		return (1);
	return (0);
}

void	map_checker(t_map *map, int i, int j)
{
	while (map->tmp[i])
	{
		j = 0;
		while (map->tmp[i][j] != '\n' && map->tmp[i][j] != '\0')
		{
			if (wall_checker(map, i, j))
				error(map);
			if (map->tmp[i][j] == 'C')
				map->coin++;
			else if (map->tmp[i][j] == 'P')
			{
				map->player_y = i;
				map->player_x = j;
				map->player++;
			}
			else if (map->tmp[i][j] == 'E')
				map->exit++;
			else if (map->tmp[i][j] != '0' && map->tmp[i][j] != 'P'
					&& map->tmp[i][j] != 'C' && map->tmp[i][j] != 'E'
					&& map->tmp[i][j] != '1')
				error(map);
			j++;
		}
		i++;
	}
}

void	parsing_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->tmp[map->line - 1][map->length] != '\0')
		map->length++;
	map_checker(map, i, j);
	map->check_coin = map->coin;
	if (map->player != 1 || map->coin < 1 || map->exit != 1)
		error(map);
	if (!path_validation(map, map->player_y, map->player_x))
		error(map);
}
