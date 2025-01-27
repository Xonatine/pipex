/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlorenz <frlorenz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:42:51 by frlorenz          #+#    #+#             */
/*   Updated: 2024/05/13 12:18:54 by frlorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	l;

	if (!haystack && len == 0)
		return (0);
	i = 0;
	l = len;
	if (needle[0] == '\0')
		return ((char *) haystack);
	if (len <= 0)
		return ((char *) haystack);
	while (haystack[i] != '\0' && len > 0)
	{
		j = 0;
		while (needle[j] == haystack[i + j] && haystack[i + j] != '\0')
		{
			j++;
			if (needle[j] == '\0' && l >= (i + j))
				return ((char *) haystack + i);
		}
		i++;
		len--;
	}
	return (0);
}
