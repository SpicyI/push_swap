/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-khay <del-khay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:35:45 by del-khay          #+#    #+#             */
/*   Updated: 2022/12/21 23:06:27 by del-khay         ###   ########.fr       */
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
void	ft_error(void)
{
	ft_putendl_fd("Error\n",2);
	exit (1);
}

int	main(int ac, char **av)
{
	t_arr	args;

	if (ac < 2)
		ft_error();
	args = getargs(ac, av);
	check_double(&args);
	push_swap(&args);
	return (0);
}
