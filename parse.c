/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 17:58:21 by omotyliu          #+#    #+#             */
/*   Updated: 2017/03/22 17:58:22 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_list *g_rooms;

static char		*get_name(char *str)
{
	int		i;
	char	*res;

	res = NULL;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
		{
			res = ft_strsub(str, 0, i);
			break ;
		}
		i++;
	}
	return (res);
}

static void		new_room(char *str, int head)
{
	t_room	*room;

	room = (t_room*)malloc(sizeof(t_room));
	check_room(str);
	room->name = get_name(str);
	room->neighbours = NULL;
	room->coord = ft_strdup(ft_strchr(str, ' ') + 1);
	room->head = head;
	check_coord(room);
	ft_lstadd(&g_rooms, ft_lstnew(room, sizeof(t_room)));
	free(room);
}

static void		parse_room(char **info, int head)
{
	int		i;

	i = 1;
	while (info[i] != NULL)
	{
		if (info[i][0] == '#' && info[i][1] != '#')
		{
			i++;
			continue;
		}
		if (!ft_strcmp(info[i], "##start") || !ft_strcmp(info[i], "##end"))
			head = (!ft_strcmp(info[i++], "##start")) ? 1 : 2;
		if (!ft_strncmp(info[i], "##", 2))
		{
			i++;
			continue;
		}
		if (ft_strchr(info[i], ' '))
		{
			new_room(info[i], head);
			head = 0;
		}
		i++;
	}
}

void			link_node(char **info)
{
	int		i;
	char	**links;

	i = 0;
	while (info[i])
	{
		if (ft_strchr(info[i], '-') && !ft_strchr(info[i], '#')
			&& !ft_strchr(info[i], 'L'))
		{
			links = split_link(info[i]);
			if (links[2] != NULL)
				error();
			link_nodes(links[0], links[1]);
			free(links[0]);
			free(links[1]);
			free(links);
		}
		i++;
	}
}

char			**read_data(void)
{
	char	*line;
	char	**info;
	int		i;

	i = 0;
	line = NULL;
	info = (char **)malloc(sizeof(char *) * 1000);
	while (get_next_line(0, &line) > 0)
		info[i++] = line;
	free(line);
	info[i] = NULL;
	check_number(info[0]);
	parse_room(info, 0);
	link_node(info);
	check_info(info);
	return (info);
}
