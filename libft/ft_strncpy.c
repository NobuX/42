/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 23:42:15 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/06 23:06:16 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t count;

	count = 0;
	if (!dst && !src)
		return (NULL);
	while (src[count] && count < n)
	{
		dst[count] = src[count];
		count++;
	}
	while (count <= n)
	{
		dst[count] = '\0';
		count++;
	}
	return (dst);
}
