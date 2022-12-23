/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-khay <del-khay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:35:36 by del-khay          #+#    #+#             */
/*   Updated: 2022/12/23 17:53:01 by del-khay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdio.h>
# define DSPL 1
# define N_DSPL 0

typedef struct s_stack
{
	int				nbr;
	struct s_stack	*next;
}					t_stack;

typedef struct s_chunk
{
	int				mid;
	int				mvs;
	int				tail;
	int				nose;
	int				s;
}					t_chunk;

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
	t_chunk			ch;

}					t_arr;

typedef struct s_utls
{
	char			*s;
	char			**s1;
	int				cnt;
	int				i;
}					t_utils;

typedef struct s_match
{
	char			*mvs[12];
	void			(*d[11])(t_arr *, int);
}					t_match;

/*-----------------push_swap_utils--------------------*/
void				getargs(int ac, char **av, t_arr *args);
int					alldigit(char *s);
int					countargs(char **s);
void				check_double(t_arr *args, int c);
void				ft_error(void);
int					ispart(int nbr, t_arr *args);
void				ft_catch(char *s);
/*-----------------stacks_utils--------------------*/
void				put_stack(t_arr *args);
void				ft_sort(t_arr *args);
/*------------------moves_util----------------------*/
t_stack				*ft_new(int nbr);
t_stack				*ft_last(t_stack *stack);
t_stack				*ft_outmost(t_stack *stack);
/*-----------------moves--------------------------*/
void				sa(t_arr *args, int c);
void				sb(t_arr *args, int c);
void				ss(t_arr *args, int c);
void				pa(t_arr *args, int c);
void				pb(t_arr *args, int c);
void				ra(t_arr *args, int c);
void				rb(t_arr *args, int c);
void				rr(t_arr *args, int c);
void				rra(t_arr *args, int c);
void				rrb(t_arr *args, int c);
void				rrr(t_arr *args, int c);
/*-----------------sorting------------------------*/
int					is_sorted(t_stack *list);
void				push_swap(t_arr *args);
void				high3(t_arr *args);
void				high16(t_arr *args);
void				ft_pop(t_arr *args);
void				ft_push(t_arr *args);
int					push_b(t_arr *args, int c);
void				push_a(t_arr *args, int c);
int					rotate(t_arr *args, int c);
int					rev_rotate(t_arr *args, int c);
void				push_it(t_arr *args, int i);
/*--------------------checker-------------------*/
void				check_moves(char *move, t_arr *args, char **mvs,
						void (**d)(t_arr *, int));
void				get_moves(t_arr *args, char **mvs, void (**d)(t_arr *,
							int));
void				ft_assign(t_match *p);
#endif
