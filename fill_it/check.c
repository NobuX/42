/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 10:15:54 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/13 09:17:31 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		ft_error(void)
{
	ft_putendl("error");
	return (0);
}

int		list_valid2(char *str, int i, int tetrimino, int count_blocks)
{
	while (str[i])
	{
		count_blocks = 0;
		while (str[i] && i < tetrimino * 21)
		{
			if (str[i] == '\n' && ((i - tetrimino) % 5 == 3
						|| (i - tetrimino) % 20 == 19))
				i++;
			else
			{
				if (str[i] != '.' && str[i] != '#')
					return (ft_error());
				if (str[i] == '#')
					count_blocks++;
				i++;
			}
		}
		if (count_blocks != 4)
			return (ft_error());
		tetrimino++;
	}
	if (i % 21 != 20)
		return (ft_error());
	return (1);
}

int		list_valid(char *str)
{
	int i;
	int tetrimino;
	int	count_blocks;

	i = 0;
	tetrimino = 1;
	count_blocks = 0;
	return (list_valid2(str, i, tetrimino, count_blocks));
}

int		tetrimino_valid2(char *str, int i, int tetrimino, int connections)
{
	while (str[i])
	{
		connections = 0;
		while (i < tetrimino * 21)
		{
			if (str[i] == '#')
			{
				if (i % 21 > 3 && str[i - 5] == '#')
					connections++;
				if (i % 21 < 15 && str[i + 5] == '#')
					connections++;
				if (i % 5 - tetrimino + 1 != 0 && str[i - 1] == '#')
					connections++;
				if (i % 5 - tetrimino + 1 != 3 && str[i + 1] == '#')
					connections++;
				if (!connections)
					return (ft_error());
			}
			i++;
		}
		if (connections < 6)
			return (ft_error());
		tetrimino++;
	}
	return (1);
}

int		tetrimino_valid(char *str)
{
	int i;
	int tetrimino;
	int	connections;

	i = 0;
	connections = 0;
	tetrimino = 1;
	return (tetrimino_valid2(str, i, tetrimino, connections));
}
