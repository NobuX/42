/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 02:14:05 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/08 01:42:35 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*tmp;
	char	*dst1;
	char	*src1;
	size_t	i;

	dst1 = (char *)dst;
	src1 = (char *)src;
	tmp = (char *)malloc(sizeof(*tmp) * len);
	if (!(tmp))
		return (NULL);
	i = 0;
	while (i < len)
	{
		tmp[i] = src1[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		dst1[i] = tmp[i];
		i++;
	}
	return (dst);
}
