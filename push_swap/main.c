/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-khay <del-khay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:35:45 by del-khay          #+#    #+#             */
/*   Updated: 2022/12/22 18:25:22 by del-khay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printstack(t_stack *head)
{
	printf("stack :   ");
	while (head)
	{
		printf("%d ", head->nbr);
		head = head->next;
	}
	printf("\n");
}

void high16(t_arr *args)
{
	int		i;
	t_stack	*temp;

	i = 0;
	while (args->a_size > 3)
	{
		temp = args->a_head;
		args->ch.mvs = 0;
		while (temp)
		{
			if (args->arr[i] == temp->nbr)
			{
				do_it(args, i);
				break ;
			}
			args->ch.mvs += 1;
			temp = temp->next;
		}
		i++;
	}
	high3(args);
	while(args->b_size)
		pa(args);
}

void do_it(t_arr *args, int i)
{
	if (args->ch.mvs <= args->a_size / 2)
	{
		while (args->a_head->nbr != args->arr[i])
			ra(args);
	}
	else if (args->ch.mvs > args->a_size / 2)
	{
		while (args->a_head->nbr != args->arr[i])
			rra(args);
	}
	pb(args);
}

void	rrr(t_arr *args)
{
	rra(args);
	rrb(args);
}

void	ft_error(void)
{
	ft_putendl_fd("Error\n", 2);
	exit(1);
}

int	main(int ac, char **av)
{
	t_arr	args;

	if (ac < 2)
		ft_error();
	getargs(ac, av, &args);
	check_double(&args);
	push_swap(&args);
	return (0);
}
