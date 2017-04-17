/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_mover.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:35:42 by omotyliu          #+#    #+#             */
/*   Updated: 2017/03/30 17:35:43 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_list *g_walking_ants;

t_ant *new_ant(char *name, char **path, char *end)
{
    t_ant *ant;

    ant = (t_ant*)malloc(sizeof(t_ant));
    ant->path = path;
    ant->pos = 1;
    ant->name = name;
    ant->end = end;
    return ant;
}

static void del_ant_from_list(char *ant_name)
{
    t_list *temp;

    temp = g_walking_ants;
    if (!ft_strcmp(((t_ant*)temp->content)->name, ant_name))
    {
        g_walking_ants = temp->next;
        free(temp);
    }
    while (temp)
    {
        if (temp->next)
        {
            if (!ft_strcmp(((t_ant*)temp->next->content)->name, ant_name))
                temp->next = temp->next->next;
        }
        temp = temp->next;
    }
}

void move_ant(t_ant *ant)
{
    ft_printf("%s-%s, ", ant->name, ant->path[ant->pos]);
    ant->pos++;
    if (ant->path[ant->pos] == 0)
        del_ant_from_list(ant->name);
}

static int move_ants_in_list()
{
    t_list *lst;

    lst = g_walking_ants;
    if (lst == 0)
        return 0;
    while (lst)
    {
        move_ant(lst->content);
        lst = lst->next;
    }
    return 1;
}

void ant_mover(t_sorted_list *package)
{
       
}
//}void ant_mover(t_sorted_list *package)
//{
//    int i;
//    char *end_name;
//    t_parall_path *parallel;
//    t_ant *ant;
//    i = 0;
//
//    parallel = package->parallel;
//    end_name = get_end_start(2)->name;
//    while (1)
//    {
//        ant = new_ant(ft_strjoin("L", ft_itoa(i)), ft_strsplit(package->steps, '#'), end_name);
//        if (i < g_ants)
//        ft_lstadd(&g_walking_ants, ft_lstnew(ant, sizeof(t_ant)));
//        i++;
//        if (i < g_ants)
//        while (parallel)
//        {
//            ant = new_ant(ft_strjoin("L", ft_itoa(i)), ft_strsplit(parallel->parallel_path, '#'), end_name);
//            if (i < g_ants)
//            ft_lstadd(&g_walking_ants, ft_lstnew(ant, sizeof(t_ant)));
//            i++;
//            parallel = parallel->next;
//        }
//        parallel = package->parallel;
//        printf("one step\n");
//        if (!move_ants_in_list())
//            break;
//    }
//}