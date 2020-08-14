/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:34:34 by jdussert          #+#    #+#             */
/*   Updated: 2020/08/14 11:08:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_first(char *haystack, char *needle, int *start)
{
	int	len_h;
	int	len_n;
	int	i;
	int	j;
	
	i = *start;
	j = 0;
	len_h = ft_strlen(haystack);
	len_n = ft_strlen(needle);
	while (j < len_n && i < len_h && haystack[i] == needle[j])
	{
		if (j + 1 == len_n)
			return (1);
		i++;
		j++;
	}
	return (0);
}
