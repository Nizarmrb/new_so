/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelmrabe <nelmrabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:50:52 by nelmrabe          #+#    #+#             */
/*   Updated: 2023/08/25 23:08:39 by nelmrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
// # include <mlx.h>
#include <stdio.h>


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define KEY_LEFT 123

# define KEY_A 0
# define KEY_D 2
# define KEY_S 1
# define KEY_W 13

typedef struct s_map
{
	void	*p_wall;
	// int		pix;
	void	*p_coin;
	void	*p_player;
	void	*p_exit;
	char	*str;
	char	**tmp;
	char	**land;
	int		check_coin;
	int		player_x;
	void	*m_window;
	int		player_y;
	int		moves;
	void	*mlx;
	int		line;
	int		coin;
	int		length;
	int		player;
	int		exit;	
	int		img_width;
	int		img_height;
}t_map;

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(char *string, char c);
int		ft_strlen(char *str);
char	*invalid_fd(char *string, char **static_string);
char	**ft_split(char *s, char c);
char	*get_first(char *static_string);
char	*get_last(char *static_string);
void	ft_putnbr(int n, int fd);
int		valid_validation(t_map *map, int y, int x);
void	path(t_map *map, int y, int x);
void	valid_map(int ac, char **av);
void	error(t_map *map);
void	parsing_map(t_map *map);
void	free_tab(t_map *map);
void	end_game(void);
int		ft_close(t_map *map);
void	draw_game(t_map *map);
int		map_key_up(t_map *map);
int		map_key_down(t_map *map);
int		map_key_left(t_map *map);
int		map_key_right(t_map *map);

#endif