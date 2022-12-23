/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-khay <del-khay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 22:37:24 by del-khay          #+#    #+#             */
/*   Updated: 2022/12/23 17:46:17 by del-khay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_moves(char *move, t_arr *args, char **mvs, void (**d)(t_arr *, int))
{
	int	i;

	i = 0;
	while (args->size && mvs[i])
	{
		if (!ft_strncmp(move, mvs[i], ft_strlen(mvs[i])))
		{
			(*d[i])(args, N_DSPL);
			return ;
		}
		i++;
	}
	ft_error();
}

void	get_moves(t_arr *args, char **mvs, void (**d)(t_arr *, int))
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		check_moves(line, args, mvs, d);
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(args->a_head) && !args->b_size)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}
void	ft_assign(t_match *p)
{
	p->d[0] = &ra;
	p->d[1] = &rb;
	p->d[2] = &rr;
	p->d[3] = &pa;
	p->d[4] = &pb;
	p->d[5] = &sa;
	p->d[6] = &sb;
	p->d[7] = &ss;
	p->d[8] = &rra;
	p->d[9] = &rrb;
	p->d[10] = &rrr;
	p->mvs[0] = "ra\n";
	p->mvs[1] = "rb\n";
	p->mvs[2] = "rr\n";
	p->mvs[3] = "pa\n";
	p->mvs[4] = "pb\n";
	p->mvs[5] = "sa\n";
	p->mvs[6] = "sb\n";
	p->mvs[7] = "ss\n";
	p->mvs[8] = "rra\n";
	p->mvs[9] = "rrb\n";
	p->mvs[10] = "rrr\n";
	p->mvs[11] = 0;
}


int	main(int ac, char **av)
{
	t_arr	args;
	t_match p;
	
	
	ft_assign(&p);
	if (ac < 2)
		exit(0);
	getargs(ac, av, &args);
	check_double(&args, DSPL);
	get_moves(&args, p.mvs, p.d);
}
