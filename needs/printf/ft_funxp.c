/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funxp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:15:05 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/03/16 16:02:01 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int s, char *base)
{
	int	i;
	int	x;

	i = 0;
	if (s >= 16)
	{
		x = ft_puthex(s / 16, base);
		if (x == -1)
			return (-1);
		i += x;
	}
	if (write(1, &base[s % 16], 1) != 1)
		return (-1);
	i++;
	return (i);
}

int	ft_putvoid(unsigned long v)
{
	int	i;

	i = 0;
	if (v >= 16)
		i += ft_putvoid (v / 16);
	if (write(1, &"0123456789abcdef"[v % 16], 1) == -1)
		return (-1);
	i++;
	return (i);
}
