/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelmrabe <nelmrabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 01:10:23 by nelmrabe          #+#    #+#             */
/*   Updated: 2023/08/26 22:02:54 by nelmrabe         ###   ########.fr       */
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

int	ft_keybord(int key, t_map *map)
{
	int	put;

	put = 0;
	if (key == 53)
		exit(0);
	else if (key == 126 || key == 13)
		put = map_key_up(map);
	else if (key == 125 || key == 1)
		put = map_key_down(map);
	else if (key == 124 || key == 2)
		put = map_key_right(map);
	else if (key == 123 || key == 0)
		put = map_key_left(map);
	if (put == 1)
	{
		map->moves = map->moves + 1;
		write(1, "Steps counting: ", 16);
		ft_putnbr(map->moves);
		write(1, "\r", 1);
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
	mlx_key_hook(map->m_window, &ft_keybord, map);
	mlx_hook(map->m_window, 17, 0, &ft_close, map);
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
