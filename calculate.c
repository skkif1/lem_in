/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 22:12:49 by omotyliu          #+#    #+#             */
/*   Updated: 2017/03/29 22:12:50 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void set_max_path()
{
    t_room *start;
    t_room *end;

    start = get_end_start(1);
    end = get_end_start(2);
    g_max_path = (count_neighbours(start) > count_neighbours(end)) ? count_neighbours(end) : count_neighbours(start);
}


static t_sorted_list *find_better()
{
    t_sorted_list *temp;
    t_sorted_list *res;
    int par_nam;
    int num_of_all;

    par_nam = g_max_path;
    num_of_all = 0;
    temp  = g_all_p;
    res = NULL;

        while (temp)
        {
            if (temp->num_of_paral == par_nam && temp->gen_len >= num_of_all)
            {
                num_of_all = temp->gen_len;
                res = temp;
                if (temp->next->gen_len > num_of_all)
                    break;
            }
            temp = temp->next;
        }
    if (res == NULL)
        return NULL;
    return res;
}

//t_sorted_list *find_max_parallel_path()
//{
//    while ()
//    {
//
//    }
//}