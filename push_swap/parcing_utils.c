/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-khay <del-khay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 22:16:57 by del-khay          #+#    #+#             */
/*   Updated: 2022/12/16 00:19:42 by del-khay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_double(t_arr args)
{
	int	i;
	int	j;

	i = 0;
	while(i < args.size)
	{
		j = i + 1;
		while(j < args.size)
		{
			if (args.arr[i] == args.arr[j])
				exit(20); // doubles 
			j++;
		}
		i++;
	}
	/************/
	args.b = ft_new(10);
	args.b_head = args.b_head;
	args.b_size = 1;
	/************/
	put_stack(&args);
	ft_sort(&args);
	printf("stack A: ");
	printstack(args.a);
	printf("\n");
	printf("stack B: ");
	printstack(args.b);
	printf("\n");
	pb(&args);
	//pa(&args);
	printf("after pa:\n");
	printstack(args.a_head);
	printf("\n***********\n");
	printf("stack B: ");
	printstack(args.b);
}

void	ft_sort(t_arr *args)
{
	int temp;
	int	idx[2];
	int size;
	
	size = args->size/2;
	while(size > 0)
	{
		idx[0] = size;
		while (idx[0] < args->size)
		{
			temp = args->arr[idx[0]];
			idx[1] = idx[0];
			while(idx[1] >= size && args->arr[idx[1] - size] > temp)
			{
				args->arr[idx[1]] = args->arr[idx[1] - size];
				idx[1] -= size;
			}
			args->arr[idx[1]] = temp; 
			idx[0] += 1;
		}	
		size = size/2; 
	}
}

void	put_stack(t_arr *args)
{
	int		i;
	
	args->a_head = ft_new(args->arr[0]);
	args->a = args->a_head;
	i = 1;
	while(i < args->size)
	{
		args->a->next = ft_new(args->arr[i]);
		args->a = args->a->next; 
		i++;
	}
	args->a = args->a_head;
	args->a_size = args->size;
	//printstack(args->a_head);
}

void	printstack(t_stack *head)
{
	while (head)
	{
		printf("%d ",head->nbr);
		head = head->next;
	}
	
}

t_stack	*ft_new(int nbr)
{
	t_stack	*new_node;

	new_node = (t_stack *) malloc(sizeof(t_stack));
	if (!new_node)
		return (0);
	new_node->nbr = nbr;
	new_node->next = 0;
	return (new_node);
}
