/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:48:46 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/07/17 12:09:13 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*check_all(char **s, int argc, int *all_int)
{
	int				i;
	int				j;
	long long int	aux;

	i = 1;
	j = 0;
	aux = 0;
	while (i < argc)
	{
		if (check_args(s[i]) == 1)
		{
			aux = ft_atoi(s[i]);
			if (aux > 2147483647 || aux < -2147483648)
				ft_error(1, all_int);
			all_int[j] = aux;
			j++;
		}
		else
			ft_error(1, all_int);
		i++;
	}
	if (!check_rep(all_int, argc - 1))
		ft_error(1, all_int);
	return (all_int);
}

int	check_args(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_isdigit(s[i]) == 0)
		{
			if ((s[i] == '-' || s[i] == '+') && ft_isdigit(s[i + 1]) == 1)
				i++;
			else
				return (0);
		}
		else
			i++;
	}
	return (1);
}

int	check_rep(int *nums, int argc)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		while (j < argc)
		{
			if (nums[i] == nums[j] && i != j)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
