/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:55:31 by smarin-a          #+#    #+#             */
/*   Updated: 2023/10/16 20:39:50 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*final_s;

	s1_len = 0;
	s2_len = 0;
	if (s1 != NULL)
		s1_len = ft_strlen(s1);
	if (s2 != NULL)
		s2_len = ft_strlen(s2);
	final_s = (char *)malloc(s1_len + s2_len + 1);
	if (final_s == NULL)
		return (NULL);
	if (s1 != NULL)
		ft_memcpy(final_s, s1, s1_len);
	if (s2 != NULL)
		ft_memcpy(final_s + s1_len, s2, s2_len);
	final_s[s1_len + s2_len] = '\0';
	return (final_s);
	free(final_s);
}
