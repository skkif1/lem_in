/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 18:35:06 by omotyliu          #+#    #+#             */
/*   Updated: 2017/03/24 18:35:07 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_path *new_path(char *str)
{
    t_path *path;
    int i;
    int j;

    i = 0;
    j = 0;
    path = (t_path*)malloc(sizeof(t_path));
    while (str[i])
    {
        if (str[i] == '#')
            j++;
        i++;
    }
    path->ssteps = ft_strsplit(str, '#');
    path->ssteps[j - 1] = NULL;
    path->length = j;
    path->steps = ft_strdup(str);
    return path;
}