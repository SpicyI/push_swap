/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-khay <del-khay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:56:03 by del-khay          #+#    #+#             */
/*   Updated: 2022/12/21 23:08:31 by del-khay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	countargs(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	alldigit(char *s)
{
	if (!s || !ft_strlen(s))
		return (0);
	if (!ft_isdigit(*s) && *s != '+' && *s != '-')
		return (0);
	s++;
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

t_arr	getargs(int ac, char **av)
{
	t_arr	args;
	char	*s;
	char	**s1;
	int		cnt;
	int		i;

	i = 0;
	cnt = 0;
	s = 0;
	while (++cnt < ac)
	{
		s = ft_strjoin(s, av[cnt]);
		s = ft_strjoin(s, " ");
	}
	s1 = ft_split(s, ' ');
	args.size = countargs(s1);
	if (!args.size)
		ft_error();
	args.arr = (int *)ft_calloc(args.size, sizeof(int));
	while (i < args.size)
	{
		if (!alldigit(s1[i]))
			ft_error();
		args.arr[i] = ft_atoi(s1[i]);
		i++;
	}
	free(s);
	ft_free2(s1);
	return (args);
}

void	check_double(t_arr *args)
{
	int i;
	int j;

	i = 0;
	while (i < args->size)
	{
		j = i + 1;
		while (j < args->size)
		{
			if (args->arr[i] == args->arr[j])
				exit(20); // doubles
			j++;
		}
		i++;
	}
	put_stack(args);
	ft_sort(args);
}