/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 11:19:04 by jdussert          #+#    #+#             */
/*   Updated: 2019/10/20 10:34:38 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t src_len;
	size_t dst_len;
	size_t i;

	src_len = 0;
	dst_len = 0;
	i = 0;
	while (dst[dst_len] && dst_len < dstsize)
		dst_len++;
	while (src[src_len])
	{
		if (dstsize > 0)
			if (dst_len + src_len < dstsize - 1)
				dst[dst_len + (i++)] = src[src_len];
		src_len++;
	}
	if (dstsize > 0 && dst_len < dstsize)
		dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
