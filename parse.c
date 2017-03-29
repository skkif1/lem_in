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

#include <sys/stat.h>
#include "lemin.h"

t_list *g_rooms;
char *g_path;

static char *get_name(char *str)
{
    int i;
    char *res;

    res = NULL;
    i = 0;
    while (str[i] != '\0') {
        if (str[i] == ' ') {
            res = ft_strsub(str, 0, i);
            break;
        }
        i++;
    }
    return res;
}

void link_node(char **info)
{

    int i;
    char **links;
    i = 0;

    while (info[i])
    {
        if (ft_strchr(info[i], '-') && !ft_strchr(info[i], '#') && !ft_strchr(info[i], 'L'))
        {
            links = split_link(info[i]);
            link_nodes(links[0], links[1]);
        }
        i++;
    }
    printf("\n");

}
static void parse_room(char **info)
{
    int i;

    t_room *room;
    i = 1;
    while(info[i] != NULL)
    {
        room = (t_room*)malloc(sizeof(t_room));
        room->head = 0;
        if (!ft_strcmp(info[i], "##start") || !ft_strcmp(info[i], "##end"))
        {
            room->head = (!ft_strcmp(info[i], "##start")) ? 1 : 2;
            i++;
        }
        if (ft_strchr(info[i], ' '))
        {
            room->name = get_name(info[i]);
            room->neighbours = NULL;
            room->visited = 0;
            room->weight = 0;
            ft_lstadd(&g_rooms, ft_lstnew(room, sizeof(t_room)));
        }
        i++;
    }
}

void read_data(void)
{
    char *line;
    char **info;
    int i;

    i = 0;
    line = NULL;
    info = (char **) malloc(sizeof(char *) * 1000);
    int fd = open("/nfs/2016/o/omotyliu/git/lem-in/rec", O_RDONLY);
    while (get_next_line(fd, &line) > 0)
        info[i++] = line;
    info[i] = NULL;
    parse_room(info);
    link_node(info);
}