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
struct s_sorted_list *g_all_p;
t_list *g_rooms;

int main(int argc, char **argv)
{
    t_room *room;

    argc = 0;
    argv = 0;


    read_data();

    room = get_end_start(2);

        find_all_path(get_end_start(1), ft_strnew(1));


    while (g_all_p)
    {
        printf("%s  --  %d\n", g_all_p->steps, g_all_p->len);

        g_all_p = g_all_p->next;
    }
}