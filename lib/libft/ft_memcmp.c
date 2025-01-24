/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlorenz <frlorenz@student.42madrid.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:42:55 by frlorenz          #+#    #+#             */
/*   Updated: 2023/12/04 12:32:41 by frlorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*t1;
	unsigned char	*t2;

	t1 = (unsigned char *) s1;
	t2 = (unsigned char *) s2;
	while (n > 0 && (*t1 == *t2))
	{
		t1++;
		t2++;
		n--;
	}
	if (n == 0)
	{
		return (0);
	}
	return ((unsigned char)(*t1) - (unsigned char)(*t2));
}
