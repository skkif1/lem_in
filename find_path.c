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
        neighbour = get_node_by_name((char*)neighbours->content)->content;
        if (maxweight < neighbour->weight && neighbour->visited != 1)
        {
                maxweight = neighbour->weight;
                res = neighbour->name;
        }
        neighbours = neighbours->next;
    }
    neighbour = get_node_by_name(res)->content;
    if (count_neighbours(room) <= 2)
    {
        room->visited = 1;
    }
    if (neighbour->head == 1)
        return NULL;
    return res;
}


void all_path(t_room *room)
{
    char *room_name;

    if (room->head == 2)
    {
        ft_lstadd(&g_all_p, ft_lstnew(g_path, sizeof(g_path)));
        printf("%s\n", g_path);
        return ;
    }
    room_name = chose_beter_way(room);
    if (!room_name)
    {
        g_path = NULL;
        return ;
    }
    if (g_path == NULL)
        g_path = ft_strnew(1);
    g_path = ft_append(g_path, "#", ft_strlen(g_path), 1);
    g_path = ft_append(g_path, room_name, ft_strlen(g_path), ft_strlen(room_name));


    all_path(get_node_by_name(room_name)->content);
}

int find_all_path(t_room *room, char *path)
{
    t_list *neighbours;
    t_room *neighbour;
    static int count = 0;
    int i;

    neighbours = room->neighbours;
    path = ft_append(path, "#", ft_strlen(path), 1);
    path = ft_append(path, ft_strdup(room->name), ft_strlen(path), ft_strlen(room->name));

    if (room->head == 2)
    {
        ft_lstadd(&g_all_p, ft_lstnew(path, sizeof(path)));
        printf("%s\n", path);
        count = 0;
        return  1;
    }
//    t_list *lst = neighbours;
//    while (lst)
//    {
//        printf("%s\n", ((t_room*)get_node_by_name(lst->content)->content)->name);
//        lst = lst->next;
//    }
//    printf("______%s______\n", room->name);
    while (neighbours)
    {
        neighbour = get_node_by_name(neighbours->content)->content;
        if (ft_strstr(path, neighbour->name))
        {
            neighbours = neighbours->next;
            continue ;
        }
        neighbours = neighbours->next;
        find_all_path(neighbour, ft_strdup(path));
    }
    //printf("%d\n", count);
    return 0;
}
