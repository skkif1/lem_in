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

t_path *new_path(char *str)
{
    t_path *path;
    static int name;
    int i;
    int j;

    i = 0;
    j = 0;
    path = (t_path*)malloc(sizeof(t_path));
    while (str[i])
    {
        if (str[i] == '#')
            j++;
        i++;
    }
    name++;
    return path;
}


int count_neighbours(t_room *room)
{
    t_list *neighbours;
    int res;

    res = 0;
    neighbours = room->neighbours;

    while (neighbours)
    {
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
            if (room->head != 1)
                room->visited = 1;
            return ;
        }
        neighbours = neighbours->next;
    }
}