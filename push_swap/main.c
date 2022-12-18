/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-khay <del-khay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:35:45 by del-khay          #+#    #+#             */
/*   Updated: 2022/12/18 03:32:54 by del-khay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printArray(int array[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf("%d  ", array[i]);
	}
	printf("\n");
}

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

int	main(int ac, char **av)
{
	t_arr	args;

	if (ac < 2)
		return (1); // not enough args and do nothing
	args = getargs(ac, av);
	check_double(&args);
	printstack(args.a);
	printstack(args.b);
	push_swap(&args);
	printstack(args.a);
	printstack(args.b);
	// pb(&args);
	// printstack(args.a);
	// printstack(args.b);
	// ra(&args);
	// printstack(args.a);
	// printstack(args.b);
	// ra(&args);
	// printstack(args.a);
	// printstack(args.b);

	//printArray(args.arr,args.size);
	//system("leaks push_swap");
}
