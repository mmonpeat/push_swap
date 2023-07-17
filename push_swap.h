/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:23:40 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/06/13 15:23:40 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*includes*/
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"
# include <string.h> /*BORRAR*/
# include <ctype.h> /*BORRAR*/

/*defineix cadascun dels elements que componen stack*/
typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*previous;
	int				num;
	int				index;
	int				position;
}	t_node;

typedef struct s_stack
{
	t_node	*first;
	t_node	*last;
	int		size;
}	t_stack;

/*PRINCIPAL*/
int		main(int argc, char **argv);

/*BORRAR*/
void	mostra(t_stack *stack);

/*CLEANERS*/
int		check_args(char *s);
int		*check_all(char **s, int argc, int *all_int);
int		check_rep(int *nums, int argc);
void	ft_error(int type, int *all_int);
void	ft_free(t_stack *stack);

void	inicialitar_stacks(t_stack *a, t_stack *b);
int		organize_stacks(t_stack *a, t_stack *b, int *all_int, int argc);
int		asign_index(int num, int *all_int, int argc);
void	create_nodes(t_stack *a, int *all_int, int argc);

/*OPERATIONS*/
void	new_position(t_stack *stack);
void	ft_swap(t_stack *stack, int from);
void	ft_swaps(t_stack *a, t_stack *b);
void	ft_rotate(t_stack *stack, int from);
void	ft_rotates(t_stack *stack, t_stack *b);
void	ft_rrotate(t_stack *stack, int from);
void	ft_rrotates(t_stack *a, t_stack *b);
void	ft_push(t_stack *a, t_stack *b, int from);

/*SCANNERS*/
int		max_loc(t_stack *a);
int		sec_max_loc(t_stack *stack);
int		min_location(t_stack *a);
int		probe_order(t_stack *a);

/*ALGORITMS*/
void	three_nums(t_stack *a);
void	five_nums(t_stack *a, t_stack *b);
void	sort_big(t_stack *a, t_stack *b, int total_size, int chunks);
void	order_chunks_b(t_stack *a, t_stack *b, int max_index, int slice_chunk);
void	push_a(t_stack *a, t_stack *b, int max_index);
int		less_moves(t_stack *stack, int pos_max);

#endif