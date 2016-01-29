/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 22:35:23 by mpressen          #+#    #+#             */
/*   Updated: 2016/01/25 04:47:14 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** The ft_strnew() allocates memory for a string.
** Character's value are set to 0.
** If allocation fails, the function returns NULL.
** If not, ft_strnew() returns a pointer to the string.
*/

char	*ft_strnew(size_t size)
{
	char	*str;

	str = (char *)malloc(sizeof(*str) * size + 1);
	if (str)
	{
		ft_bzero(str, size + 1);
		return (str);
	}
	return (NULL);
}