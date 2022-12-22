/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-khay <del-khay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 22:37:24 by del-khay          #+#    #+#             */
/*   Updated: 2022/12/22 23:14:19 by del-khay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char **get_moves(t_arr *args)
{
    char *stash;
	char *line;
	
	line = get_next_line(0);
	while(line)
	{
		stash = ft_strjoin(stash, line);
		line = get_next_line(0);
	}
	
}

int main(int ac, char **av)
{
	t_arr   args;
    char    moves;
    
    if (ac < 2)
		exit(0);
	getargs(ac, av, &args);
	check_double(&args);
    moves = get_moves(&args);
}