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
    char **info;
    argc = 0;
    argv = 0;
    int i;

    info = read_data();


    room = get_end_start(2);

    find_all_path(get_end_start(1), ft_strnew(1));

    find_parallel(g_all_p);

    set_max_path();

    max = find_max_parallel_path();

    i = 0;
    while (info[i] != NULL)
    {
        ft_printf("%s\n", info[i]);
        free(info[i]);
        i++;
    }
    free(info);
    printf("\n");

    add_parall(&max->parallel, new_parall(max->steps, max->len));

    ant_mover(max);
    sleep(5);
}