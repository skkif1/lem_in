/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 17:45:20 by omotyliu          #+#    #+#             */
/*   Updated: 2017/03/22 17:45:21 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LEMIN_H
# define LEMIN_H

# include "libft/ft_printf.h"

typedef struct	s_room
{
    char *name;
    t_list *neighbours;
    int head;
    int weight;
    int visited;

}				t_room;

typedef struct	s_path
{
    char *steps;
    char **ssteps;
    int length;
    t_list *parallel_packadge;
}				t_path;


void read_data(void);
t_list *get_node_by_name(char *name);
void link_nodes(char *name1, char *name2);
char **split_link(char *str);
void set_weight(t_room *room, int weight);
t_room *get_end_start(t_list *list, int head);
void all_path(t_room *room);
void find_all_path(t_room *room);
void link_node(char **info);
t_path *new_path(char *steps);
int count_neighbours(t_room *room);
void del_path(t_room *room, char *neighbour);
void sort_path(t_list *list);

#endif
