/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlorenz <frlorenz@student.42madrid.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:23:31 by frlorenz          #+#    #+#             */
/*   Updated: 2023/10/16 17:06:44 by frlorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lentoint(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		i = 11;
		return (i);
	}
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	if (n <= 9)
		i++;
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		l;

	l = ft_lentoint(n);
	if (n == -2147483648)
		str = ft_strdup("-2147483648");
	else
	{
		str = ft_calloc(l + 1, 1);
		if (!str)
			return (0);
		if (n < 0)
		{
			n = n * -1;
			str[0] = '-';
		}
		while (n > 9)
		{
			str[--l] = (char)(n % 10) + '0';
			n /= 10;
		}
		str[--l] = n + '0';
	}
	return (str);
}
