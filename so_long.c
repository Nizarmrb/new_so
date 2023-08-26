/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelmrabe <nelmrabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 01:21:23 by nelmrabe          #+#    #+#             */
/*   Updated: 2023/08/25 22:26:54 by nelmrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*s;
	size_t	i;

	i = 0;
	s = (char *)malloc(count * size);
	if (!s)
		return (NULL);
	while (i < (count * size))
	{
		s[i] = 0;
		i++;
	}
	return (s);
}

int	calculator(int number)
{
	int	calculator;

	calculator = number * 60;
	return (calculator);
}

int	manage_keybord(int keycode, t_map *map)
{
	int	print;

	print = 0;
	if (keycode == 53)
		exit(0);
	else if (keycode == KEY_UP || keycode == KEY_W)
		print = map_key_up(map);
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		print = map_key_down(map);
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		print = map_key_right(map);
	else if (keycode == KEY_LEFT || keycode == KEY_A)
		print = map_key_left(map);
	if (print == 1)
	{
		map->moves = map->moves + 1;
		write(1, "Steps counting: ", 16);
		ft_putnbr(map->moves, 1);
		write(1, "\n", 1);
	}
	return (1);
}

void	mlx_window(t_map *map)
{
	map->mlx = mlx_init();
	map->m_window = mlx_new_window(map->mlx, \
	calculator(map->length), calculator(map->line), "so_long");
	map->p_coin = mlx_xpm_file_to_image(map->mlx, \
	"maps/coin.xpm", &map->img_width, &map->img_height);
	map->p_wall = mlx_xpm_file_to_image(map->mlx, \
	"maps/wall.xpm", &map->img_width, &map->img_height);
	map->p_exit = mlx_xpm_file_to_image(map->mlx, \
	"maps/exit.xpm", &map->img_width, &map->img_height);
	map->p_player = mlx_xpm_file_to_image(map->mlx, \
	"maps/p_right.xpm", &map->img_width, &map->img_height);
	draw_game(map);
	mlx_key_hook(map->m_window, &manage_keybord, map);
	mlx_hook(map->m_window, 17, 0, &close, map);
	mlx_loop(map->mlx);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_map	*map;
	char	*buffer;

	map = ft_calloc(1, sizeof(t_map));
	valid_map(argc, argv);
	fd = open(argv[1], O_RDONLY);
	// if (fd < 0 || !map)
	// 	return (0);
	while (1)
	{
		buffer = get_next_line(fd);
		if (buffer && (buffer[0] == '\0' || buffer[0] == '\n'))
			error(map);
		map->str = ft_strjoin(map->str, buffer);
		map->str = ft_strjoin(map->str, " ");
		if (!buffer)
			break ;
		free(buffer);
		map->line++;
	}
	map->tmp = ft_split(map->str, ' ');
	map->land = ft_split(map->str, ' ');
	parsing_map(map);
	mlx_window(map);
}
