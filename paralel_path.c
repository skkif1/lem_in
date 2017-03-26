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

int if_parallel(t_path *path1, t_path *path2)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (path1->ssteps[i])
    {
        if (ft_strstr(path2->steps, path1->ssteps[i]))
            return 0;
        i++;
    }
    return 1;
}

void sort_path(t_list *list)
{
    t_list *temp;
    t_list *to_compare;

    if (!list->next)
        return;
    temp = list;
    t_path* p;
    t_path* p1;
    to_compare = list->next;
    while (temp)
    {
        while (to_compare)
        {
            p = to_compare->content;
            p1 = temp->content;

            if (if_parallel(temp->content, to_compare->content))
                ft_lstadd(&((t_path*)temp->content)->parallel_packadge, ft_lstnew(to_compare->content, sizeof(to_compare->content)));
            to_compare = to_compare->next;
        }
        temp = temp->next;
    }

//    while (((t_path*)list->content)->parallel_packadge)
//    {
//        t_path *path;
//        path = (t_path*)list->content;
//
//        printf("%s", ((t_path*)path->parallel_packadge->content)->steps);
//        ((t_path*)list->content)->parallel_packadge = ((t_path*)list->content)->parallel_packadge->next;
//    }
}

void count_steps(t_path *path)
{
    t_list *parall_path;

    parall_path = ;
}