/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelmrabe <nelmrabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 01:21:23 by nelmrabe          #+#    #+#             */
/*   Updated: 2023/08/26 21:18:47 by nelmrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count_split(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && c != s[i])
			i++;
		if (c == 0)
		{
			count++;
			break ;
		}
		while (c && c == s[i])
			i++;
		count++;
	}
	return (count);
}

int	ft_count_word(char *s, char c)
{
	int	count;

	count = 0;
	while (*s && c != *s)
	{
		count++;
		s++;
	}
	return (count);
}

char	*ft_word(char *s, char c, char **word)
{
	int	count;
	int	i;

	count = ft_count_word(s, c);
	*word = malloc((count + 1) * sizeof(char));
	if (!word)
		return (0);
	(*word)[count] = 0;
	i = 0;
	while (i < count)
		(*word)[i++] = *s++;
	while (c == *s)
		s++;
	return (s);
}

int	_free(char **res, int size)
{
	while (size--)
	{
		free(res[size]);
	}
	free(res);
	return (0);
}

char	**ft_split(char *s, char c)
{
	int		i;
	char	**res;
	int		count;

	if (s == 0)
		return (NULL);
	i = 0;
	while (c && *s && c == (char) *s)
		s++;
	count = ft_count_split((char *)s, c);
	res = malloc((count + 1) * sizeof(char *));
	if (!res)
		return (0);
	res[count] = 0;
	i = 0;
	while (i < count)
	{
		s = ft_word((char *)s, c, res + i);
		if (!s)
			_free(res, i);
		i++;
	}
	return (res);
}
