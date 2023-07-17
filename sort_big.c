/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 12:27:25 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/07/17 12:11:26 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big(t_stack *a, t_stack *b, int total_size, int chunks)
{
	int	i;
	int	chunk_size;
	int	max_index;
	int	slice_chunk;

	i = 0;
	chunk_size = total_size / chunks;
	max_index = 0;
	if (probe_order(a))
		return ;
	while (a->first)
	{
		max_index = chunk_size * ++i;
		slice_chunk = ((i - 1) * chunk_size + i * chunk_size) / 2;
		while (b->size != max_index)
			order_chunks_b(a, b, max_index, slice_chunk);
		while (i == chunks && a->size != 0)
			ft_push(a, b, 'b');
	}
	push_a(a, b, b->size);
}

void	order_chunks_b(t_stack *a, t_stack *b, int max_index, int slice_chunk)
{
	if (a->first->index <= max_index)
	{
		ft_push(a, b, 'b');
		if (b->first->index < slice_chunk + 2)
			ft_rotate(b, 'b');
	}
	else
		ft_rotate(a, 'a');
}

void	push_a(t_stack *a, t_stack *b, int max_index)
{
	while (b->first)
	{
		while (less_moves(b, max_index / 2) != 0 && b->size > 2)
		{
			if (less_moves(b, max_index / 2) > max_index / 2)
				ft_rrotate(b, 'b');
			else
				ft_rotate(b, 'b');
		}
		if (b->size > 1)
			ft_push(b, a, 'a');
		while (max_loc(b) != 0)
		{
			if (max_loc(b) > max_index / 2)
				ft_rrotate(b, 'b');
			else
				ft_rotate(b, 'b');
		}
		ft_push(b, a, 'a');
		if (!probe_order(a))
			ft_swap(a, 'a');
		max_index -= 2;
	}
}

int	less_moves(t_stack *stack, int pos_max)
{
	int	moves_sec;
	int	moves_max;

	moves_sec = sec_max_loc(stack);
	moves_max = max_loc(stack);
	if (sec_max_loc(stack) > pos_max)
		moves_sec = stack->size - sec_max_loc(stack);
	if (max_loc(stack) > pos_max)
		moves_max = stack->size - max_loc(stack);
	if (moves_sec > moves_max)
		return (max_loc(stack));
	return (sec_max_loc(stack));
}
