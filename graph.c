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
    node->len = j;
    node->steps = str;
    node->next = NULL;
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

int flow_cap(int a, int b)
{

}
