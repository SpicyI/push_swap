/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-khay <del-khay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:56:03 by del-khay          #+#    #+#             */
/*   Updated: 2022/12/22 22:28:56 by del-khay         ###   ########.fr       */
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
	if (ft_strlen(s) == 1 && *s == '+' && *s == '-')
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

void	getargs(int ac, char **av, t_arr *args)
{
	t_utils	m;

	m.i = 0;
	m.cnt = 0;
	m.s = 0;
	while (++m.cnt < ac)
	{
		ft_catch(av[m.cnt]);
		m.s = ft_strjoin(m.s, av[m.cnt]);
		m.s = ft_strjoin(m.s, " ");
	}
	m.s1 = ft_split(m.s, ' ');
	args->size = countargs(m.s1);
	if (!args->size)
		ft_error();
	args->arr = (int *)ft_calloc(args->size, sizeof(int));
	while (m.i < args->size)
	{
		if (!alldigit(m.s1[m.i]))
			ft_error();
		args->arr[m.i] = ft_atoi(m.s1[m.i]);
		m.i++;
	}
	free(m.s);
	ft_free2(m.s1);
}

void	check_double(t_arr *args)
{
	int	i;
	int	j;

	i = 0;
	while (i < args->size)
	{
		j = i + 1;
		while (j < args->size)
		{
			if (args->arr[i] == args->arr[j])
				ft_error();
			j++;
		}
		i++;
	}
	put_stack(args);
	if (is_sorted(args->a_head))
		exit(0);
	ft_sort(args);
}

void	ft_catch(char *s)
{
	int	c;

	c = 0;
	if (!s || !ft_strlen(s))
		ft_error();
	while (*s)
	{
		if (ft_isdigit(*s))
			c++;
		s++;
	}
	if (!c)
		ft_error();
}
