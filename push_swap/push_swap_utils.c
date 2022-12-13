/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-khay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:56:03 by del-khay          #+#    #+#             */
/*   Updated: 2022/12/13 17:08:29 by del-khay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_arr	getstack(int ac, char **av)
{
	t_arr args;
	char	*s;
	char	**s1;
	int	cnt;
	int	i;
	
	i = 0;
	cnt = 0;
	s= 0;
	while (++cnt < ac)
	{
		s = ft_strjoin(s, av[cnt]);
		s = ft_strjoin(s," ");
	}
	printf("%s\n",s);
	s1 = ft_split(s, ' ');
	args.size = countargs(s1);
	if (!args.size)
		exit(12);
	args.arr = (int *) ft_calloc(args.size, sizeof(int));
	while(i < args.size)
	{
		if(!alldigit(s1[i]))
			exit(17); //not digit
		args.arr[i] = ft_atoi(s1[i]);
		i++;
	}
	printf("%d\n",args.size);
	return	(args);
}

int	countargs(char **s)
{
	int i;
	
	i = 0;
	while (s[i])
		i++;
	return(i);
}

int	alldigit(char *s)
{
	if (!s || !ft_strlen(s))
		return (0);
	if (!ft_isdigit(*s) &&  *s != '+' && *s != '-')
		return (0);
	s++;
	while(*s)
	{
		if(!ft_isdigit(*s))
			return(0);
		s++;
	}
	return (1);
}