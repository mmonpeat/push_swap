/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:23:46 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/07/17 12:21:00 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	organize_stacks(t_stack *a, t_stack *b, int *all_int, int argc)
{
	create_nodes(a, all_int, argc);
	if (argc < 4 && !probe_order(a))
		ft_swap(a, 'a');
	else if (argc == 4)
		three_nums(a);
	else if (argc <= 6)
		five_nums(a, b);
	else if (argc <= 22)
		sort_big(a, b, a->size, 2);
	else if (argc <= 201)
		sort_big(a, b, a->size, 4);
	else
		sort_big(a, b, a->size, 9);
	//mostra per pantalla el resultat
	printf("-------------STACK A------------\n");
	mostra(a);
	printf("-------------STACK B------------\n");
	mostra(b);
	return (1);
}

void	create_nodes(t_stack *a, int *all_int, int argc)
{
	int		i;
	t_node	*new_node;

	i = argc - 2;
	while (i >= 0)
	{
		new_node = (t_node *)malloc(sizeof(t_node));
		if (!new_node)
			return ;
		new_node->num = all_int[i];
		new_node->index = asign_index(all_int[i], all_int, argc);
		new_node->position = i;
		new_node->previous = NULL;
		new_node->next = a->first;
		if (a->first != NULL)
			a->first->previous = new_node;
		a->first = new_node;
		a->size++;
		if (a->last == NULL)
			a->last = new_node;
		i--;
	}
	free(all_int);
}

int	asign_index(int num, int *all_int, int argc)
{
	int	index;
	int	i;

	i = 0;
	index = 0;
	while (i < argc - 1)
	{
		if (all_int[i] < num && all_int[i] != num)
			index++;
		i++;
	}
	return (index + 1);
}
