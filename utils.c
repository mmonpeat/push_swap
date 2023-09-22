/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:52:20 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/07/17 16:21:49 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	inicialitar_stacks(t_stack *a, t_stack *b)
{
	a->first = NULL;
	a->last = NULL;
	a->size = 0;
	b->first = NULL;
	b->last = NULL;
	b->size = 0;
}

void	ft_error(int type, int *all_int)
{
	if (type == 1)
		write(2, "Error\n", 6);
	free(all_int);
	exit(type);
}

void	ft_free(t_stack *stack)
{
	t_node	*tmp;

	while (stack->first)
	{
		tmp = stack->first->next;
		free(stack->first);
		stack->first = tmp;
	}
}

void	new_position(t_stack *stack)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = stack->first;
	while (i < stack->size)
	{
		tmp->position = i;
		tmp = tmp->next;
		i++;
	}
}
