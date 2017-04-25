/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paralel_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 15:55:10 by omotyliu          #+#    #+#             */
/*   Updated: 2017/03/25 15:55:11 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	if_list_parallel(t_parall_path *lst, t_sorted_list *path_to_add)
{
	t_parall_path	*temp;
	int				i;

	i = 1;
	temp = lst;
	if (!path_to_add->splited_steps)
		path_to_add->splited_steps = ft_strsplit(path_to_add->steps, '#');
	while (temp)
	{
		while (path_to_add->steps[i])
		{
			if (path_to_add->splited_steps[i + 1] == 0)
				break ;
			if (ft_strstr(temp->parallel_path, path_to_add->splited_steps[i]))
				return (0);
			i++;
		}
		i = 0;
		temp = temp->next;
	}
	return (1);
}

static int	if_parallel(t_sorted_list *path1, t_sorted_list *path2)
{
	int i;

	if (!path1->splited_steps)
		path1->splited_steps = ft_strsplit(path1->steps, '#');
	i = 1;
	while (path1->splited_steps[i])
	{
		if (path1->splited_steps[i + 1] == 0)
			break ;
		if (ft_strstr(path2->steps, path1->splited_steps[i]))
			return (0);
		i++;
	}
	if (!if_list_parallel(path1->parallel, path2))
		return (0);
	return (1);
}

static void	add_parallel(t_sorted_list *path1, t_sorted_list *path2)
{
	add_parall(&path1->parallel, new_parall(path2->steps, path2->len));
	path1->gen_len += path2->len;
	path1->num_of_paral++;
}

void		find_parallel(t_sorted_list *lst, int flow)
{
	t_sorted_list	*temp;
	t_sorted_list	*inner;

	temp = lst;
	while (temp)
	{
		inner = temp->next;
		while (inner)
		{
			if ((flow = calc_flow_cap(temp, inner)) < temp->flow_cap)
				if (if_parallel(temp, inner))
				{
					add_parallel(temp, inner);
					temp->flow_cap = flow;
				}
			if ((flow = calc_flow_cap(inner, temp)) < inner->flow_cap)
				if (if_parallel(inner, temp))
				{
					inner->flow_cap = flow;
					add_parallel(inner, temp);
				}
			inner = inner->next;
		}
		temp = temp->next;
	}
}
