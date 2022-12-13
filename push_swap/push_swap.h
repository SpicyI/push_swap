/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-khay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:35:36 by del-khay          #+#    #+#             */
/*   Updated: 2022/12/13 00:04:03 by del-khay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdio.h>

typedef struct	s_arr
{
	int *arr;
	int size;
} t_arr;


t_arr	getstack(int ac, char **av);
int		countargs(char **s);
int		alldigit(char *s);
void	check_double(t_arr args);

#endif
