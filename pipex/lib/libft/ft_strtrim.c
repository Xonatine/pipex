/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlorenz <frlorenz@student.42madrid.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:52:37 by frlorenz          #+#    #+#             */
/*   Updated: 2023/10/13 21:08:29 by frlorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	len;
	int	i;

	i = 0;
	if (!s1 || !set)
		return (0);
	if (s1[0] != '\0')
	{
		while (ft_strchr(set, s1[i]) != 0)
			i++;
		len = ft_strlen(s1);
		while (ft_strrchr(set, s1[len]) != 0)
			len--;
		return (ft_substr(s1, i, (len - i) + 1));
	}
	return (ft_strdup(s1));
}
