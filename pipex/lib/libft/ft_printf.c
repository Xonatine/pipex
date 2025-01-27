/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlorenz <frlorenz@student.42madrid.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:57:31 by frlorenz          #+#    #+#             */
/*   Updated: 2024/01/29 19:06:42 by frlorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_print_pointer(va_list args);
static int	ft_select(char const *str, va_list args);

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;
	int		j;

	va_start(args, str);
	i = 0;
	while (*str)
	{
		if (*str == '%')
		{
			j = ft_select(str, args);
			if (j == -1)
				return (-1);
			i += j;
			str++;
		}
		else if (write(1, str, 1) != -1)
			i++;
		else
			return (-1);
		str++;
	}
	va_end(args);
	return (i);
}

static int	ft_select(char const *str, va_list args)
{
	int		i;
	size_t	n;

	i = 0;
	if (*(str +1) == '%')
		i = write(1, "%", 1);
	else if (*(str +1) == 'c' || *(str +1) == 's')
		i = ft_print_ascii(str, args);
	else if (*(str +1) == 'd' || *(str + 1) == 'i')
		i = ft_printdigits(args);
	else if (*(str +1) == 'u')
		i = ft_putunsigned(va_arg(args, unsigned int));
	else if (*(str +1) == 'x' || *(str +1) == 'X')
	{
		n = va_arg(args, unsigned int);
		if (n != 0)
			i = ft_print_hexa(n, *(str + 1));
		else
			i = write(1, "0", 1);
	}
	else if (*(str +1) == 'p')
		i = ft_print_pointer(args);
	else
		i = write(1, str + 1, 1);
	return (i);
}

static int	ft_print_pointer(va_list args)
{
	int		i;
	size_t	n;

	i = 0;
	if (write(1, "0x", 2) == -1)
		return (-1);
	i += 2;
	n = va_arg(args, size_t);
	if (n == 0)
		i += write(1, "0", 1);
	else
		i += ft_print_hexa(n, 'x');
	return (i);
}
