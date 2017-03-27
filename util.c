/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 14:48:45 by omotyliu          #+#    #+#             */
/*   Updated: 2017/03/23 14:48:47 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_list *g_rooms;

t_list *get_node_by_name(char *name)
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
    return NULL;
}

t_room *get_end_start(t_list *list, int head)
{
    t_list *temp;
    t_room *room;

    temp = list;

    while (temp)
    {
        room = temp->content;
        if (room->head == head)
            return room;
        temp = temp->next;
    }
    return NULL;
}

void link_nodes(char *name1, char *name2)
{
    t_list *node;
    t_list *node2;
    t_room *room;
    t_room *room2;
    t_list *neighbours;


    if ((node = get_node_by_name(name1)) == NULL)
        printf("errrrrrr");
    if ((node2 = get_node_by_name(name2)) == NULL)
        printf("errrrrrr");

    room = node->content;
    room2 = node2->content;
    neighbours = room->neighbours;
    while (neighbours)
    {
        if (!ft_strcmp(name2, neighbours->content) || !ft_strcmp(name1, neighbours->content))
            return ;
        neighbours = neighbours->next;
    }
    ft_lstadd_end(&room->neighbours, ft_lstnew(name2, sizeof(char) * ft_strlen(name2) + 1));
    ft_lstadd_end(&room2->neighbours, ft_lstnew(name1, sizeof(char) * ft_strlen(name1) + 1));

}

t_path *get_path_by_name(t_list *list, char *name)
{
    t_list *temp;

    temp = list;

    while (temp)
    {
        if (!ft_strcmp(((t_path*)temp->content)->name, name))
            return temp->content;
        temp = temp->next;
    }
    return NULL;
}

char **split_link(char *str)
{
    int i;
    char **res;

    res = (char**)malloc(sizeof(char*) * 3);
    i = 0;
    while (str[i] != '-')
        i++;
    res[0] = ft_strsub(str, 0, i);
    res[1] = ft_strdup(ft_strchr(str, '-') + 1);
    res[2] = NULL;
    return res;
}