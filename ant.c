/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 18:35:06 by omotyliu          #+#    #+#             */
/*   Updated: 2017/03/24 18:35:07 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_ant	*new_ant(char *name, char **path, char *end)
{
	t_ant *ant;

	ant = (t_ant*)malloc(sizeof(t_ant));
	ant->path = path;
	ant->pos = 1;
	ant->name = name;
	ant->end = end;
	return (ant);
}

int		count_neighbours(t_room *room)
{
	t_list	*neighbours;
	int		res;

	res = 0;
	neighbours = room->neighbours;
	while (neighbours)
	{
		res++;
		neighbours = neighbours->next;
	}
	return (res);
}
