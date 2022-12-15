/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-khay <del-khay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:35:36 by del-khay          #+#    #+#             */
/*   Updated: 2022/12/15 17:45:28 by del-khay         ###   ########.fr       */
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
	t_stack			**a;
	t_stack			**b;
}					t_arr;


t_arr				getstack(int ac, char **av);
int					countargs(char **s);
int					alldigit(char *s);
void				check_double(t_arr args);
void				ft_sort(t_arr *args);
void				put_stack(t_arr *args);
void				printArray(int array[], int size);
t_stack				*ft_new(int nbr);
void				printstack(t_stack **head);

#endif
