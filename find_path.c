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

t_sorted_list *g_all_p;

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
        add(&g_all_p, new_node(path));
//        printf("%s\n", path);
        count++;
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
    printf("%d\n", count);
    return 0;
}
