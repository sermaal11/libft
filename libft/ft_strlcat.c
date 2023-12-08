/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:45:22 by smarin-a          #+#    #+#             */
/*   Updated: 2023/10/02 15:55:40 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	available_space;
	size_t	i;
	size_t	total_len;

	dst_len = 0;
	while (dst[dst_len] != '\0' && dst_len < dstsize)
	{
		dst_len++;
	}
	available_space = dstsize - dst_len;
	if (available_space > 1)
	{
		i = 0;
		while (src[i] != '\0' && i < available_space - 1)
		{
			dst[dst_len + i] = src[i];
			i++;
		}
		dst[dst_len + i] = '\0';
	}
	total_len = dst_len + ft_strlen(src);
	return (total_len);
}
