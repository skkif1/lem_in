/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parallel_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 17:53:35 by omotyliu          #+#    #+#             */
/*   Updated: 2017/03/29 17:53:36 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_parall_path	*new_parall(char *str, int len)
{
	t_parall_path	*path;

	if (!(path = (t_parall_path*)malloc(sizeof(t_parall_path))))
		return (NULL);
	path->parallel_path = str;
	path->len = len;
	path->ants_num = 0;
	path->next = NULL;
	return (path);
}

void			add_parall(t_parall_path **lst, t_parall_path *to_add)
{
	if (*lst == NULL)
		*lst = to_add;
	else
	{
		to_add->next = *lst;
		*lst = to_add;
	}
}
