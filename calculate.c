/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 22:12:49 by omotyliu          #+#    #+#             */
/*   Updated: 2017/03/29 22:12:50 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_sorted_list	*find_better(void)
{
	t_sorted_list	*temp;
	t_sorted_list	*res;

	temp = g_all_p;
	res = g_all_p;
	while (temp)
	{
		if (temp->flow_cap < res->flow_cap)
			res = temp;
		temp = temp->next;
	}
	if (res == NULL)
		return (NULL);
	return (res);
}

void					set_max_path(void)
{
	t_room	*start;
	t_room	*end;

	start = get_end_start(1);
	end = get_end_start(2);
	g_max_path = (count_neighbours(start) > count_neighbours(end)) ?
	count_neighbours(end) : count_neighbours(start);
}

t_sorted_list			*find_max_parallel_path(void)
{
	t_sorted_list	*result;

	if ((result = find_better()) == 0)
		error();
	g_max_path--;
	return (result);
}

int						calc_flow_cap(t_sorted_list *pat1, t_sorted_list *pat2)
{
	int	steps;
	int	amount;
	int	potential_len;

	potential_len = pat1->gen_len + pat2->len;
	steps = 0;
	while (1)
	{
		steps++;
		amount = steps *
		(pat1->num_of_paral + 1) - potential_len + pat1->num_of_paral + 1;
		if (amount >= g_ants)
			break ;
	}
	return (steps);
}
