/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_codes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelmrabe <nelmrabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 01:21:23 by nelmrabe          #+#    #+#             */
/*   Updated: 2023/08/25 22:26:39 by nelmrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_game(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->land[i])
	{
		j = 0;
		while (map->land[i][j])
		{
			if (map->land[i][j] == 'C')
				mlx_put_image_to_window(map->mlx, map->m_window, map->p_coin, \
				(j * 60), (i * 60));
			else if (map->land[i][j] == 'E')
				mlx_put_image_to_window(map->mlx, map->m_window, map->p_exit, \
				(j * 60), (i * 60));
			else if (map->land[i][j] == '1')
				mlx_put_image_to_window(map->mlx, map->m_window, map->p_wall, \
				(j * 60), (i * 60));
			else if (map->land[i][j] == 'P')
				mlx_put_image_to_window(map->mlx, map->m_window, \
				map->p_player, (j * 60), (i * 60));
			j++;
		}
		i++;
	}
}

int	map_key_up(t_map *map)
{
	if (map->land[map->player_y - 1][map->player_x] != '1' && map->land[map->player_y
		- 1][map->player_x] != 'E')
	{
		if (map->land[map->player_y - 1][map->player_x] == 'C')
			map->check_coin--;
		map->land[map->player_y][map->player_x] = '0';
		map->land[map->player_y - 1][map->player_x] = 'P';
		map->player_y--;
		mlx_clear_window(map->mlx, map->m_window);
		draw_game(map);
		return (1);
	}
	if (map->land[map->player_y - 1][map->player_x] == 'E' && map->check_coin == 0)
		end_game();
	return (0);
}

int	map_key_down(t_map *map)
{
	if (map->land[map->player_y + 1][map->player_x] != '1' && map->land[map->player_y
		+ 1][map->player_x] != 'E')
	{
		if (map->land[map->player_y + 1][map->player_x] == 'C')
			map->check_coin--;
		map->land[map->player_y][map->player_x] = '0';
		map->land[map->player_y + 1][map->player_x] = 'P';
		map->player_y++;
		mlx_clear_window(map->mlx, map->m_window);
		draw_game(map);
		return (1);
	}
	if (map->land[map->player_y + 1][map->player_x] == 'E' && map->check_coin == 0)
		end_game();
	return (0);
}

int	map_key_left(t_map *map)
{
	if (map->land[map->player_y][map->player_x - 1] != '1' && map->land[map->player_y][map->player_x
		- 1] != 'E')
	{
		if (map->land[map->player_y][map->player_x - 1] == 'C')
			map->check_coin--;
		map->p_player = mlx_xpm_file_to_image(map->mlx,
				"maps/p_left.xpm", &map->img_width, &map->img_height);
		map->land[map->player_y][map->player_x] = '0';
		map->land[map->player_y][map->player_x - 1] = 'P';
		map->player_x--;
		mlx_clear_window(map->mlx, map->m_window);
		draw_game(map);
		return (1);
	}
	if (map->land[map->player_y][map->player_x - 1] == 'E' && map->check_coin == 0)
		end_game();
	return (0);
}

int	map_key_right(t_map *map)
{
	if (map->land[map->player_y][map->player_x + 1] != '1' && map->land[map->player_y][map->player_x
		+ 1] != 'E')
	{
		if (map->land[map->player_y][map->player_x + 1] == 'C')
			map->check_coin--;
		map->p_player = mlx_xpm_file_to_image(map->mlx,
				"maps/p_right.xpm", &map->img_width, &map->img_height);
		map->land[map->player_y][map->player_x] = '0';
		map->land[map->player_y][map->player_x + 1] = 'P';
		map->player_x++;
		mlx_clear_window(map->mlx, map->m_window);
		draw_game(map);
		return (1);
	}
	if (map->land[map->player_y][map->player_x + 1] == 'E' && map->check_coin == 0)
		end_game();
	return (0);
}
