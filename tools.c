/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelmrabe <nelmrabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 01:21:23 by nelmrabe          #+#    #+#             */
/*   Updated: 2023/08/25 23:08:14 by nelmrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_tab(t_map *map)
{
	(void)map;
	exit(0);
}

void	end_game(void)
{
	write(1, "CONGRATS YOU DID IT !\n", 22);
	exit(0);
}

int	ft_close(t_map *map)
{
	(void)map;
	exit(0);
}
void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-', fd);
		n = -n;
	}
	if (n >= 0 && n <= 9)
		ft_putchar((n + '0'), fd);
	if (n >= 10)
	{
		ft_putnbr(n / 10, fd);
		ft_putnbr(n % 10, fd);
	}
}

