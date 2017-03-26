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

int count_neighbours(t_room *room)
{
    t_list *neighbours;
    int res;

    res = 0;
    neighbours = room->neighbours;

    while (neighbours)
    {
        if (ft_strcmp((char*)neighbours->content, "LLLL") && room->head != 2 && room->head != 1)
            res++;
        neighbours = neighbours->next;
    }
    return res;
}

void del_path(t_room *room, char *neighbour)
{

    t_list *neighbours;

    neighbours = room->neighbours;
    while (neighbours)
    {
        if (!ft_strcmp((char*)neighbours->content, neighbour))
        {
            printf("dell -> %s from -> %s\n", (char*)neighbours->content, room->name);
            neighbours->content = "LLLL";
            return ;
        }
        neighbours = neighbours->next;
    }
}