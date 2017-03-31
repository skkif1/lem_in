/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 13:52:40 by omotyliu          #+#    #+#             */
/*   Updated: 2017/03/25 13:52:41 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int g_ants;

t_sorted_list *new_node(char *str)
{
    t_sorted_list *node;
    int i;
    int j;

    i = 0;
    j = 0;
    node = (t_sorted_list*)malloc(sizeof(t_sorted_list));
    while (str[i])
    {
        if (str[i] == '#')
            j++;
     i++;
    }
    node->len = j - 1;
    node->splited_steps = NULL;
    node->steps = str;
    node->next = NULL;
    node->flow_cap = (node->len == 1) ? node->len + g_ants - 1 : node->len + g_ants;
    node->gen_len = node->len;
    node->parallel = NULL;
    node->num_of_paral = 1;
    return node;
}

void add(t_sorted_list **alst, t_sorted_list *new)
{
    t_sorted_list *lst;

    lst = *alst;
    if (!lst)
    {
        *alst = new;
        return;
    }
    if (lst->len > new->len)
    {
        new->next = lst;
        *alst = new;
        return;
    }
    while (lst->next)
    {
        if (lst->next->len > new->len)
        {
            new->next = lst->next;
            lst->next = new;
            return;
        }
        lst = lst->next;
    }
    lst->next = new;
}



static int if_list_parallel(t_parall_path *lst, t_sorted_list *path_to_add)
{
    t_parall_path *temp;
    int i;

    i = 1;
    temp = lst;
    if (!path_to_add->splited_steps)
        path_to_add->splited_steps = ft_strsplit(path_to_add->steps, '#');
    while (temp)
    {
        while (path_to_add->steps[i])
        {
            if (path_to_add->splited_steps[i + 1] == 0)
                break ;
            if (ft_strstr(temp->parallel_path, path_to_add->splited_steps[i]))
                return 0;
            i++;
        }
        i = 0;
        temp = temp->next;
    }
    return 1;
}

static int if_parallel(t_sorted_list *path1, t_sorted_list *path2)
{
    int i;

    if(!path1->splited_steps)
        path1->splited_steps = ft_strsplit(path1->steps, '#');
    i = 1;
    while (path1->splited_steps[i])
    {
        if (path1->splited_steps[i + 1] == 0)
            break ;
        if (ft_strstr(path2->steps, path1->splited_steps[i]))
            return 0;
        i++;
    }
    if (!if_list_parallel(path1->parallel, path2))
        return 0;
    return 1;
}

static void add_parallel(t_sorted_list *path1, t_sorted_list *path2)
{
        add_parall(&path1->parallel, new_parall(path2->steps));
        path1->gen_len += path2->len;
        path1->num_of_paral++;
        printf("to %s was added --> %s flow cap is - %d\n",path1->steps, path2->steps, path1->flow_cap);
}

void find_parallel(t_sorted_list *lst)
{
    t_sorted_list *temp;
    t_sorted_list *inner;
    int flow;

    temp = lst;
    while (temp)
    {
        inner = temp->next;
        while (inner)
        {
//            printf("%s count %d\n",temp->steps, temp->num_of_paral);
//            printf("--->>>%d\n", calc_flow_cap(temp, inner));
            if ((flow = calc_flow_cap(temp, inner)) <= temp->flow_cap)
            {
                temp->flow_cap = flow;
                if (if_parallel(temp, inner))
                {
                    add_parallel(temp, inner);
                }

            }
            if ((flow = calc_flow_cap(inner, temp)) <= temp->flow_cap)
            if (if_parallel(inner, temp))
            {
                inner->flow_cap = flow;
                add_parallel(inner, temp);
            }
            inner = inner->next;
        }
        temp = temp->next;
    }
}
