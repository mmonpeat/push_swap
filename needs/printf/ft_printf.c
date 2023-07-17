/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 19:18:00 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/03/16 16:07:08 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_errors(const char *str, va_list ptr, int *bytes, int i);

int	ft_printf(char const *str, ...)
{
	va_list	ptr;
	int		i;
	int		bytes;

	i = 0;
	bytes = 0;
	va_start (ptr, str);
	while (str[i] != '\0')
	{
		if (str[i] != '%')
		{
			if (write (1, &str[i++], 1) != 1)
				return (-1);
			bytes++;
		}
		else
		{
			if (ft_errors(str, ptr, &bytes, i) == -1)
				return (-1);
			i += 2;
		}
	}
	va_end (ptr);
	return (bytes);
}

int	print_percent(char *str, va_list ptr)
{
	int	i;

	i = 0;
	if (*str == 'c')
		i = ft_putchar (va_arg(ptr, int));
	else if (*str == 's')
		i = (ft_putstr (va_arg(ptr, char *)));
	else if (*str == 'p')
	{
		if (write(1, &"0x", 2) != 2)
			return (-1);
		i = ft_putvoid(va_arg(ptr, unsigned long));
		i += 2;
	}
	else if (*str == 'i' || *str == 'd')
		i = (ft_putnum (va_arg(ptr, int)));
	else if (*str == 'u')
		i = ft_putusnum(va_arg(ptr, unsigned int));
	else if (*str == 'x')
		i = ft_puthex(va_arg(ptr, unsigned int), "0123456789abcdef");
	else if (*str == 'X')
		i = ft_puthex(va_arg(ptr, unsigned int), "0123456789ABCDEF");
	else if (*str == '%')
		return (ft_putchar('%'));
	return (i);
}

static int	ft_errors(const char *str, va_list ptr, int *bytes, int i)
{
	int	x;

	x = print_percent((char *)(str + i + 1), ptr);
	if (x == -1)
		return (-1);
	*bytes += x;
	return (0);
}
