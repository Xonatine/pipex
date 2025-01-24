/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlorenz <frlorenz@student.42madrid.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:03:39 by frlorenz          #+#    #+#             */
/*   Updated: 2023/10/16 17:08:14 by frlorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s[i] != c && s[i] != '\0')
		j++;
	while (s[i] != '\0')
	{
		if (i != 0)
		{
			if (s[i] != c && s[i - 1] == c)
				j++;
		}
		i++;
	}
	j++;
	return (j);
}

static char	**memfree(char **array, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (0);
}

static char	**mem(char const *s, char c, int n)
{
	char	**array;
	int		l;
	int		i;

	array = (char **) ft_calloc(n, sizeof(char *));
	if (!array)
		return (0);
	i = 0;
	while (i < n)
	{
		l = 0;
		while (*s == c && c != '\0')
			s++;
		while (s[l] != c && s[l] != '\0')
			l++;
		if ((i + 1) != n)
		{
			array[i] = (char *) ft_substr(s, 0, l);
			if (!array[i])
				return (memfree(array, n));
			s = s + l;
		}
		i++;
	}
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		j;

	if (!s)
		return (0);
	j = count(s, c);
	array = mem(s, c, j);
	return (array);
}
