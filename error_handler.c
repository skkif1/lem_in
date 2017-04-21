/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 14:11:33 by omotyliu          #+#    #+#             */
/*   Updated: 2017/04/19 14:11:35 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int g_ants;
t_list *g_rooms;

void check_number(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (!ft_isdigit(str[i]))
            error();
        i++;
    }
    g_ants = ft_atoi(str);
    if (g_ants == 0 || g_ants > 1000000000)
        error();
}

void check_room(char *str)
{
    int i;
    int j;
    char *mass_pos;

    j = 0;
    i = 0;
    mass_pos = ft_strchr(str, ' ') + 1;
    while (str[i] != '\0')
    {
        if (str[i] == ' ')
            j++;
        i++;
    }
    i = 0;
    if (j != 2)
        error();
    while (mass_pos[i] != '\0')
    {
        if (!ft_isdigit(mass_pos[i]) && mass_pos[i] != ' ')
            error();
        i++;
    }
}

void check_coord(t_room *room)
{
    t_list *lst;

    lst = g_rooms;
    if (room->coord == NULL)
        error();
    while(lst)
    {
        if (!ft_strcmp(((t_room*)lst->content)->coord, room->coord))
            error();
        lst = lst->next;
    }
}

void check_info(char **str)
{
    int i;
    int start;
    int end;

    i = 1;
    start = 0;
    end = 0;
    while (str[i] != NULL)
    {
        if (!strcmp(str[i], "##start"))
            start++;
        if (!strcmp(str[i], "##end"))
            end++;
        if (str[i][0] == '\0' || (!ft_strchr(str[i], ' ') && !ft_strchr(str[i], '-') && !ft_strchr(str[i], '#')))
            end = 10;
        i++;
    }
    if (start != 1 || end != 1)
    error();
}