/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:23:28 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/06/13 15:23:28 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		*all_int;

	all_int = (int *)malloc(sizeof(int) * argc - 1);
	if (!all_int)
		return (0);
	if (argc < 2)
		ft_error(0, all_int);
	else
	{
		if (!all_int)
			ft_error(0, all_int);
		inicialitar_stacks(&a, &b);
		all_int = check_all(argv, argc, all_int);
		organize_stacks(&a, &b, all_int, argc);
	}
	ft_free(&a);
	ft_free(&b);
	return (0);
}

//DELETE
void	mostra(t_stack *stack)
{
	t_stack	tmp;

	tmp = *stack;
	// printf("Stack size: %d\n\n", stack->size);
	if (stack->size == 0)
		return ;
	while (tmp.first)
	{
		// printf("<<<<< %d NODO >>>>>\n", tmp.first->position);
		printf("%d\n", tmp.first->num);
		// printf("Num:%d\nPosition: %d\nIndex: %d\n\n", tmp.first->num, tmp.first->position, tmp.first->index);
		tmp.first = tmp.first->next;
	}
}
