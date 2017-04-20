/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 17:44:46 by omotyliu          #+#    #+#             */
/*   Updated: 2017/03/22 17:44:47 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
t_sorted_list *g_all_p;
t_list *g_rooms;

int main(int argc, char **argv)
{
    t_room *room;
    t_sorted_list *max;
    argc = 0;
    argv = 0;
    g_ants = 9;

    read_data();
    room = get_end_start(2);
    find_all_path(get_end_start(1), ft_strnew(1));
    find_parallel(g_all_p);
    set_max_path();
    max = find_max_parallel_path();
    add_parall(&max->parallel, new_parall(max->steps, max->len));
    ant_mover(max);
    
    printf("\n%d\n", max->flow_cap);
    printf("\n%s\n", max->steps);
    while (max->parallel)
    {
        printf("%s\n", max->parallel->parallel_path);
        printf("%d\n", max->parallel->ants_num);
        max->parallel = max->parallel->next;
    }

}