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

static void clear_two_dem(char **mass)
{
    int i = 0;

    while (mass[i])
    {
        free(mass[i]);
        i++;
    }
    free(mass);
}

static void del_ant_from_list(char *ant_name)
{
    t_list *temp;

    temp = g_walking_ants;
    if (!ft_strcmp(((t_ant*)temp->content)->name, ant_name))
    {
        g_walking_ants = temp->next;
        free(((t_ant*)temp->content)->name);
        clear_two_dem(((t_ant*)temp->content)->path);
        free(temp->content);
        free(temp);
    }
    while (temp)
    {
        if (temp->next)
        {
            if (!ft_strcmp(((t_ant*)temp->next->content)->name, ant_name))
            {
                free(((t_ant*)temp->next->content)->name);
                clear_two_dem(((t_ant*)temp->next->content)->path);
                free(temp->next->content);
                free(temp->next);
                temp->next = temp->next->next;
            }
        }
        temp = temp->next;
    }
}


void move_ant(t_ant *ant)
{
    if (ant == NULL)
        return;
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

void set_ant_per_path(t_sorted_list *package)
{
    t_parall_path *parallel;
    if (if_fool())
        return;
    parallel = package->parallel;
    while (parallel)
    {
        parallel->ants_num = package->flow_cap - (parallel->len - 1);
        parallel = parallel->next;
    }
}



void ant_mover(t_sorted_list *package)
{
    t_parall_path *parall_pack;
    t_ant *ant;
    char *end_name;
    int i;
    char *temp;

    i = 1;
    set_ant_per_path(package);
    end_name = get_end_start(2)->name;
    parall_pack = package->parallel;
    while (g_ants > 0)
    {
        while (parall_pack)
        {
            if (parall_pack->ants_num > 0)
            {
                temp = ft_itoa(i);
                ant = new_ant(ft_strjoin("L", temp), ft_strsplit(parall_pack->parallel_path, '#'), end_name);
                ft_lstadd_end(&g_walking_ants, ft_lstnew(ant, sizeof(t_ant)));
                free(ant);
                free(temp);
                parall_pack->ants_num--;
                g_ants--;
                i++;
               if (g_ants == 0)
                   break ;
            }
            parall_pack = parall_pack->next;
        }
        move_ants_in_list();
        printf("\n");
        parall_pack = package->parallel;
    }
    while (move_ants_in_list())
        printf("\n");

}
