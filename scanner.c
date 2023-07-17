/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:48:14 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/07/17 12:10:24 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	probe_order(t_stack *a)
{
	t_node	*tmp;

	tmp = a->first;
	while (tmp->next)
	{
		if (tmp->num > tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	max_loc(t_stack *a)
{
	t_node	*tmp;
	int		max_index;
	int		max_position;

	tmp = a->first;
	max_index = -1;
	max_position = -1;
	while (tmp)
	{
		if (tmp->index > max_index)
		{
			max_index = tmp->index;
			max_position = tmp->position;
		}
		tmp = tmp->next;
	}
	return (max_position);
}

int	sec_max_loc(t_stack *stack)
{
	t_node	*tmp;
	int		max_position;

	tmp = stack->first;
	max_position = -1;
	while (tmp)
	{
		if (tmp->index == stack->size - 1)
			max_position = tmp->position;
		tmp = tmp->next;
	}
	return (max_position);
}

int	min_location(t_stack *a)
{
	t_node	*tmp;

	tmp = a->first;
	while (tmp)
	{
		if (tmp->index == 1)
			return (tmp->position);
		tmp = tmp->next;
	}
	return (0);
}
