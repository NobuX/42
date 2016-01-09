/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 22:43:39 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/09 02:48:42 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "libft.h"

int		buffer_full_return_line(char **line)
{
	int i;

	i = -1;
	while ((*line)[++i])
	{
		if ((*line)[i] != '\n')
			return (0);
	}
	return (1);
}

int		get_next_line(int const fd, char **line)
{
	int				ret;
	static t_struct	t_stock = {NULL, 0};
	int				line_to_skip;

	if (t_stock.split && t_stock.split[t_stock.i + 1])
	{
		ft_putstr(t_stock.split[t_stock.i + 1]);
		t_stock.i++;
		if (t_stock.split[t_stock.i + 1])
			return (1);
	}
	while ((ret = read(fd, *line, BUFF_SIZE)) > 0)
	{
		line_to_skip = 1;
		(*line)[ret] = '\0';
		if (buffer_full_return_line(line))
		{
			while (buffer_full_return_line(line))
			{
				line_to_skip = 0;
				if ((ret = read(fd, *line, BUFF_SIZE)) > 0)
					(*line)[ret] = '\0';
				else if (ret == 0)
					return (0);
				else
					return (-1);
			}
			if (ret == BUFF_SIZE && t_stock.i != -1)
			{
				t_stock.split = ft_strsplit(*line, '\n');
				t_stock.i = -1;
				return (1);
			}
		}
		t_stock.split = ft_strsplit(*line, '\n');
		if (!t_stock.split)
			return (-1);
		if (line_to_skip && (*line)[0] == '\n' && t_stock.i != -1)
		{
			t_stock.i = -1;
			return (1);
		}
		t_stock.i = 0;
		ft_putstr(t_stock.split[0]);
		if (t_stock.split[1])
			return (1);
		if ((*line)[ret - 1] == '\n')
		{
			if ((ret = read(fd, *line, BUFF_SIZE)) > 0)
			{
				t_stock.split = ft_strsplit(*line, '\n');
				t_stock.i = -1;
				return (1);
			}
			return (0);
		}
	}
	return (ret);
}
