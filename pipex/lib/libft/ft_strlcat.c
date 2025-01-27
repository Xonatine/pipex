/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlorenz <frlorenz@student.42madrid.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:57:11 by frlorenz          #+#    #+#             */
/*   Updated: 2023/10/13 21:22:27 by frlorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	t;

	if (!dst && dstsize == 0)
		return (0);
	i = ft_strlen(dst);
	t = i + ft_strlen(src);
	j = 0;
	if (dstsize <= i)
		return (ft_strlen(src) + dstsize);
	while (i < (dstsize - 1) && src[j] != '\0')
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	return (t);
}
