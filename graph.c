/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 13:52:40 by omotyliu          #+#    #+#             */
/*   Updated: 2017/03/25 13:52:41 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int g_ants;
t_list *g_rooms;

t_sorted_list	*new_node(char *str)
{
	t_sorted_list	*node;
	int				i;
	int				j;

	i = 0;
	j = 0;
	node = (t_sorted_list*)malloc(sizeof(t_sorted_list));
	while (str[i])
	{
		if (str[i] == '#')
			j++;
		i++;
	}
	node->len = j - 1;
	node->splited_steps = NULL;
	node->steps = str;
	node->next = NULL;
	node->flow_cap = node->len + g_ants - 1;
	node->gen_len = node->len;
	node->parallel = NULL;
	node->num_of_paral = 1;
	return (node);
}

void			add(t_sorted_list **alst, t_sorted_list *new)
{
	t_sorted_list *lst;

	lst = *alst;
	if (!lst)
	{
		*alst = new;
		return ;
	}
	if (lst->len > new->len)
	{
		new->next = lst;
		*alst = new;
		return ;
	}
	while (lst->next)
	{
		if (lst->next->len > new->len)
		{
			new->next = lst->next;
			lst->next = new;
			return ;
		}
		lst = lst->next;
	}
	lst->next = new;
}

t_list			*get_node_by_name(char *name)
{
	t_list *temp;
	t_room *room;

	temp = g_rooms;
	while (temp)
	{
		room = temp->content;
		if (!ft_strcmp(room->name, name))
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

t_room			*get_end_start(int head)
{
	t_list *temp;
	t_room *room;

	temp = g_rooms;
	while (temp)
	{
		room = temp->content;
		if (room->head == head)
			return (room);
		temp = temp->next;
	}
	return (NULL);
}
