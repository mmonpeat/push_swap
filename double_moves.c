/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:48:38 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/07/05 15:48:40 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swaps(t_stack *a, t_stack *b)
{
	ft_swap(a, 'c');
	ft_swap(b, 'c');
	ft_printf("ss\n");
}

void	ft_rotates(t_stack *a, t_stack *b)
{
	ft_rotate(a, 'c');
	ft_rotate(b, 'c');
	ft_printf("rr\n");
}

void	ft_rrotates(t_stack *a, t_stack *b)
{
	ft_rrotate(a, 'c');
	ft_rrotate(b, 'c');
	printf("rr\n");
}
