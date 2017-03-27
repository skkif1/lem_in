/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paralel_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 15:55:10 by omotyliu          #+#    #+#             */
/*   Updated: 2017/03/25 15:55:11 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_list *g_all_p;

int if_parallel(t_path *path1, t_path *path2)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (path1->ssteps[i])
    {
        if (ft_strstr(path2->steps, path1->ssteps[i]))
            return 0;
        i++;
    }
    return 1;
}

void sort_path(t_list *list)
{
    t_list *temp;
    t_list *to_compare;

    if (!list->next)
        return;
    temp = list;
    t_path* p;
    t_path* p1;
    to_compare = list->next;
    while (temp)
    {
        while (to_compare)
        {
            p = to_compare->content;
            p1 = temp->content;

            if (if_parallel(temp->content, to_compare->content))
                ft_lstadd(&((t_path*)temp->content)->parallel_packadge, ft_lstnew(((t_path*)to_compare->content)->name, sizeof(((t_path*)to_compare->content)->name)));
            to_compare = to_compare->next;
        }
        temp = temp->next;
    }
//
//    t_path *path = list->content;
//    t_list *lst = path->parallel_packadge;
//    t_path *temp1;
//    while (lst)
//    {
//        temp1 = get_path_by_name(list, lst->content);
//        printf("%s ", temp1->name);
//        printf("%d\n", temp1->length);
//        lst = lst->next;
//    }

}
static t_list *get_all_len(t_path *path)
{
    t_list *res;
    t_list *parallel_paths;
    t_path *temp_path;
    int temp;
    char *num;

    //printf("%d\n", path->length);
    res = NULL;
    if (!path->parallel_packadge)
        return res;
    parallel_paths = path->parallel_packadge;
//    while (parallel_paths)
//    {
//        temp_path = get_path_by_name(g_all_p, parallel_paths->content);
//        printf("%d\n", temp_path->length);
//        parallel_paths = parallel_paths->next;
//    }
    return res;
}

void count_steps(t_path *path)
{
    t_list *parall_len;

    parall_len = get_all_len(path);


}