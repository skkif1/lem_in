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

char *g_path;
t_list *g_rooms;
t_list *g_all_p;

int main(int argc, char **argv)
{
    t_room *room;

    argc = 0;
    argv = 0;

    read_data();

    room = get_end_start(g_rooms, 2);
    set_weight(room, 100);



 find_all_path(get_end_start(g_rooms, 1), ft_strnew(1));


}