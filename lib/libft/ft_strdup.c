/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlorenz <frlorenz@student.42madrid.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:57:55 by frlorenz          #+#    #+#             */
/*   Updated: 2023/09/27 19:19:31 by frlorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*m;

	m = (char *)malloc(ft_strlen(s1) + 1);
	if (!m)
		return (0);
	ft_strlcpy(m, s1, ft_strlen(s1) + 1);
	return (m);
}
