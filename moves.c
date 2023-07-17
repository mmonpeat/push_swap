/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:48:28 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/07/17 12:10:12 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack *send, t_stack *rec, int from)
{
	t_node	*tmp;

	if (!send->first)
		return ;
	tmp = send->first;
	send->first = send->first->next;
	if (send->size == 1)
		send->last = NULL;
	else
		send->first->previous = NULL;
	tmp->next = rec->first;
	tmp->previous = NULL;
	if (rec->size != 0)
		rec->first->previous = tmp;
	else
		rec->last = tmp;
	rec->first = tmp;
	send->size--;
	rec->size++;
	new_position(send);
	new_position(rec);
	ft_printf("p%c\n", from);
}

void	ft_swap(t_stack *stack, int from)
{
	t_node	*tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->first;
	stack->first = stack->first->next;
	stack->first->previous = NULL;
	tmp->next = stack->first->next;
	tmp->previous = stack->first;
	stack->first->next = tmp;
	stack->first->position = 0;
	tmp->position = 1;
	if (stack->size == 2)
		stack->last = tmp;
	else
		tmp->next->previous = tmp;
	if (from != 'c')
		ft_printf("s%c\n", from);
}

void	ft_rotate(t_stack *stack, int from)
{
	t_node	*tmp;
	int		i;

	i = 0;
	if (stack->size < 2)
		return ;
	tmp = stack->first;
	stack->first = stack->first->next;
	stack->first->previous = NULL;
	tmp->previous = stack->last;
	tmp->next = NULL;
	stack->last->next = tmp;
	stack->last = tmp;
	new_position(stack);
	if (from != 'c')
		ft_printf("r%c\n", from);
}

void	ft_rrotate(t_stack *stack, int from)
{
	t_node	*tmp;
	int		i;

	i = 0;
	if (stack->size < 2)
		return ;
	tmp = stack->last;
	stack->last = stack->last->previous;
	if (stack->last)
		stack->last->next = NULL;
	tmp->next = stack->first;
	stack->first->previous = tmp;
	tmp->previous = NULL;
	stack->first = tmp;
	new_position(stack);
	if (from != 'c')
		ft_printf("rr%c\n", from);
}
