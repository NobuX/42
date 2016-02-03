/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 12:34:29 by mpressen          #+#    #+#             */
/*   Updated: 2016/02/03 14:14:47 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	print_tab(char **tab)
{
	int j;

	j = -1;
	if (tab)
		while (tab[++j])
		{
			write(1, tab[j], ft_strlen(tab[j]));
			write(1, "\n", 1);
		}
}

int		is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char	**ft_split_whitespaces(char *str)
{
	char		**tab;
	int			i;
	int			j;

	j = -1;
	i = -1;
	if(!(tab = (char**)malloc(sizeof(*tab) * (ft_strlen(str) / 2 + 1))))
		return (NULL);
	while (str[++i])
	{
		while (str[i] && is_space(str[i]))
			i++;
		tab[++j] = str + i;
		while (str[i] && !(is_space(str[i])))
			i++;
		if (!str[i])
			break ;
		str[i] = '\0';
	}
	tab[++j] = 0;
	return (tab);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		print_tab(ft_split_whitespaces(av[1]));
	return (0);
}
