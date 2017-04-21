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

int find_all_path(t_room *room, char *path)
{
    t_list *neighbours = NULL;
    t_room *neighbour = NULL;

    neighbours = room->neighbours;
    path = ft_append(path, "#", ft_strlen(path), 1);
    path = ft_append(path, room->name, ft_strlen(path), ft_strlen(room->name) + 1);


    if (room->head == 2)
    {
        add(&g_all_p, new_node(path));
        return  1;
    }

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
    free(path);
    return 0;
}
