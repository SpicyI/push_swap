/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-khay <del-khay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 22:16:57 by del-khay          #+#    #+#             */
/*   Updated: 2022/12/13 17:33:17 by del-khay         ###   ########.fr       */
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
}

