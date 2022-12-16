/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-khay <del-khay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:35:36 by del-khay          #+#    #+#             */
/*   Updated: 2022/12/16 04:10:30 by del-khay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdio.h>

typedef struct s_stack
{
	int				nbr;
	struct s_stack	*next;
}					t_stack;

typedef struct s_arr
{
	int				*arr;
	int				size;
	t_stack			*a;
	t_stack			*a_head;
	int				a_size;
	t_stack			*b;
	t_stack			*b_head;
	int				b_size;
}					t_arr;


/*-----------------to filter--------------------*/
t_arr				getstack(int ac, char **av);
int					countargs(char **s);
int					alldigit(char *s);
void				check_double(t_arr args);
void				ft_sort(t_arr *args);
void				put_stack(t_arr *args);
void				printArray(int array[], int size);
t_stack				*ft_new(int nbr);
void				printstack(t_stack *head);
t_stack				*ft_last(t_stack *stack);
t_stack				*ft_before_last(t_stack *stack);
/*-----------------moves--------------------*/

void    sa(t_arr *args);
void    sb(t_arr *args);
void    ss(t_arr *args);
void    pa(t_arr *args);
void    pb(t_arr *args);
void    ra(t_arr *args);
void    rb(t_arr *args);
void    rr(t_arr *args);
void    rra(t_arr *args);
void    rrb(t_arr *args);
void    rrr(t_arr *args);


#endif
