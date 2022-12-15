/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-khay <del-khay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:35:45 by del-khay          #+#    #+#             */
/*   Updated: 2022/12/16 00:17:59 by del-khay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

int	main(int ac, char **av)
{
	t_arr	args;

	if (ac < 2)
		return (1); // not enough args and do nothing
	args.b_head = 0;
	args.b = args.b_head;
	args.b_size = 0;
	args = getstack(ac, av);
	check_double(args);
	//printArray(args.arr,args.size);
}

	// system("leaks push_swap");