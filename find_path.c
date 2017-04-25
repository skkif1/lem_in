/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 16:13:24 by omotyliu          #+#    #+#             */
/*   Updated: 2017/03/23 16:13:25 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		find_all_path(t_room *room, char *path)
{
	t_list	*neighbours;
	t_room	*neighbour;

	neighbours = room->neighbours;
	path = ft_append(path, "#", ft_strlen(path), 1);
	path = ft_append(path, room->name,
		ft_strlen(path), ft_strlen(room->name) + 1);
	if (room->head == 2)
	{
		add(&g_all_p, new_node(path));
		return (1);
	}
	while (neighbours)
	{
		neighbour = get_node_by_name(neighbours->content)->content;
		if (ft_strstr(path, neighbour->name))
		{
			neighbours = neighbours->next;
			continue ;
		}
		neighbours = neighbours->next;
		find_all_path(neighbour, ft_strdup(path));
	}
	free(path);
	return (0);
}

void	link_nodes(char *name1, char *name2)
{
	t_list *node;
	t_list *node2;
	t_room *room;
	t_room *room2;
	t_list *neighbours;

	node2 = NULL;
	if ((node = get_node_by_name(name1)) == NULL ||
		(node2 = get_node_by_name(name2)) == NULL)
		error();
	room = node->content;
	room2 = node2->content;
	neighbours = room->neighbours;
	while (neighbours)
	{
		if (!ft_strcmp(name2, neighbours->content))
			return ;
		neighbours = neighbours->next;
	}
	ft_lstadd_end(&room->neighbours,
		ft_lstnew(name2, sizeof(char) * ft_strlen(name2) + 1));
	ft_lstadd_end(&room2->neighbours,
		ft_lstnew(name1, sizeof(char) * ft_strlen(name1) + 1));
}
