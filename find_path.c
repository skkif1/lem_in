/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 16:13:24 by omotyliu          #+#    #+#             */
/*   Updated: 2017/03/23 16:13:25 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

char *g_path;
t_list *g_rooms;
t_list *g_all_p;

void set_weight(t_room *room, int weight)
{
    t_room *neigh;
    t_list *neighbours;

    room->weight = weight;
    if (room->head == 1)
        return;

    neighbours = room->neighbours;
    while (neighbours)
    {
        t_list *lst = get_node_by_name(neighbours->content);
        t_room *rooml = lst->content;
        neigh = rooml;
        if (neigh->weight < weight - 1)
            set_weight(neigh, weight - 1);
        neighbours = neighbours->next;

    }
}

static char* chose_beter_way(t_room *room)
{
    t_room *neighbour;
    t_list *neighbours;
    char *res;
    int maxweight;

    res = NULL;
    maxweight = 0;
    neighbours = room->neighbours;
    while (neighbours)
    {
        if (!ft_strcmp(neighbours->content, "LLLL"))
        {
            neighbours = neighbours->next;
            continue;
        }
        neighbour = get_node_by_name((char*)neighbours->content)->content;
        if (maxweight < neighbour->weight )
        {
            maxweight = neighbour->weight;
            res = neighbour->name;
        }
        neighbours = neighbours->next;
    }
    del_path(room, res);
    neighbour = get_node_by_name(res)->content;
    if (neighbour->head != 2)
        neighbour->visited = 1;
    return res;
}


void all_path(t_room *room)
{
    char *room_name;

    if (room->head == 2)
        return ;
    if (count_neighbours(room) == 1)
    {
        g_path = NULL;
        return ;
    }
    if (g_path == NULL)
        g_path = ft_strnew(1);
    room_name = chose_beter_way(room);
    g_path = ft_append(g_path, "#", ft_strlen(g_path), 1);
    g_path = ft_append(g_path, room_name, ft_strlen(g_path), ft_strlen(room_name));
    all_path(get_node_by_name(room_name)->content);
}

void find_all_path(t_room *room)
{
    t_list *neighbours;
    int i;

    i = 0;
    neighbours = room->neighbours;
    while (neighbours)
    {
        i++;
        neighbours = neighbours->next;
    }
    while (i > 0)
    {
        all_path(get_end_start(g_rooms, 1));
        if (g_path == NULL)
        {
            printf("NULL\n");
            return ;
        }
        printf("%s\n", g_path);
        ft_lstadd(&g_all_p, ft_lstnew(new_path(g_path), sizeof(t_path)));
        free(g_path);
        g_path = NULL;
        i--;
    }
}