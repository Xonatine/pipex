/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlorenz <frlorenz@student.42madrid.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:42:41 by frlorenz          #+#    #+#             */
/*   Updated: 2024/01/29 19:06:32 by frlorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunsigned(unsigned int n)
{
	unsigned int	u;
	int				i;

	u = n;
	i = 0;
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, 1);
		ft_putchar_fd(n % 10 + '0', 1);
	}
	else
		ft_putchar_fd(n + '0', 1);
	while (u > 9)
	{
		u = u / 10;
		i++;
	}
	return (++i);
}

int	ft_printdigits(va_list args)
{
	char	*c;
	int		i;

	i = 0;
	c = ft_itoa(va_arg(args, int));
	if (!c)
		return (0);
	while (c[i] != '\0')
	{
		if (write(1, &c[i], 1) != -1)
			i++;
		else
			return (-1);
	}
	free (c);
	return (i);
}

int	ft_print_hexa(size_t n, char const c)
{
	int		i;
	size_t	h;

	i = 0;
	h = n;
	while (h / 16)
	{
		h = h / 16;
		i++;
	}
	if (n > 9)
	{
		ft_print_hexa(n / 16, c);
		if (((n % 16) > 9 && (n % 16) < 16) && c == 'x')
			ft_putchar_fd(n % 16 + ('0' + 39), 1);
		else if (((n % 16) > 9 && (n % 16) < 16) && c == 'X')
			ft_putchar_fd(n % 16 + ('0' + 7), 1);
		else
			ft_putchar_fd(n % 16 + '0', 1);
	}
	else if (n != 0)
		ft_putchar_fd(n + '0', 1);
	return (++i);
}

int	ft_print_ascii(const char *str, va_list args)
{
	int		i;
	char	*c;

	i = 0;
	c = va_arg(args, char *);
	if (*(str + 1) == 'c')
		i = write(1, &c, 1);
	if (*(str +1) == 's')
	{
		if (!c)
			c = "(null)";
		while (c[i] != '\0')
		{
			if ((write(1, &c[i], 1) == -1))
				return (-1);
			else
				i++;
		}
	}
	return (i);
}
