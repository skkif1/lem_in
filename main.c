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
    g_ants = 10;

    read_data();

    t_ant *ant =new_ant("L1", ft_strsplit("#s#2#3#4#e", '#'), "e");


    room = get_end_start(2);
    find_all_path(get_end_start(1), ft_strnew(1));
    find_parallel(g_all_p);
    set_max_path();
    max = find_max_parallel_path();
    ant_mover(max);

//  ft_split("1#2#2#232", '#');

//    t_parall_path *par;
//    par = NULL;
//    while (g_all_p)
//    {
//        par = g_all_p->parallel;
//        printf("path ->%s --- %d ----> %d\n", g_all_p->steps, g_all_p->gen_len, g_all_p->num_of_paral);
//
//        while (par)
//        {
//            printf("parallell ->%s\n",((char*)par->parallel_path));
//            par = par->next;
//        }
////        printf("--------------------------------\n");
//        g_all_p = g_all_p->next;
//    }
    printf("\n%d\n", max->flow_cap);
    printf("\n%s\n", max->steps);
//    while (max->parallel)
//    {
//        printf("%s\n", max->parallel->parallel_path);
//        max->parallel = max->parallel->next;
//    }

}