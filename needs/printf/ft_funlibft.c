/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funlibft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 19:18:51 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/03/16 18:35:53 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[i] != '\0')
	{
		if (ft_putchar (s[i]) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_putusnum(unsigned int u)
{
	char	digit;
	int		i;
	int		x;
	int		y;

	i = 0;
	if (u < 10)
	{
		digit = u + '0';
		if (write(1, &digit, 1) != 1)
			return (-1);
		return (1);
	}
	else if (u > 9)
	{
		x = ft_putusnum(u / 10);
		if (x == -1)
			return (-1);
		i += x;
		y = ft_putusnum(u % 10);
		if (y == -1)
			return (-1);
		i += y;
	}
	return (i);
}

int	ft_putnum(int n)
{
	int		i;
	int		j;

	i = 0;
	if (n == -2147483648)
	{
		if (write (1, "-2147483648", 11) != 11)
			return (-1);
		return (11);
	}
	else if (n < 0)
	{
		if (write (1, "-", 1) == -1)
			return (-1);
		n = -n;
		i++;
	}
	j = ft_putaux(n, 0);
	if (j == -1)
		return (-1);
	return (i + j);
}

int	ft_putaux(int n, int i)
{
	char	digit;
	int		x;
	int		y;

	if (n < 10 && n >= 0)
	{
		digit = n + '0';
		if (i == -1)
			return (-1);
		return (write(1, &digit, 1));
	}
	if (n >= 10)
	{
		x = ft_putaux(n / 10, i);
		if (x == -1)
			return (-1);
		i += x;
		y = ft_putaux(n % 10, i);
		if (y == -1)
			return (-1);
		i += y;
	}
	return (i);
}
