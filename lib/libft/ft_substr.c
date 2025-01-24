/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlorenz <frlorenz@student.42madrid.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:33:58 by frlorenz          #+#    #+#             */
/*   Updated: 2023/10/13 21:06:24 by frlorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (start >= (unsigned int) ft_strlen(s))
	{
		str = ft_calloc(1, 1);
		return (str);
	}
	if ((size_t) ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	str = ft_calloc(len + 1, 1);
	if (!str)
		return (0);
	while (i < len && s[start] != '\0')
	{
		str[i] = s[start];
		start++;
		i++;
	}
	return (str);
}
