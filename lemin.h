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
    int len;
}				t_path;

typedef struct	s_sorted_list
{
    char *steps;
    int len;
    struct s_sorted_list *next;

}				t_sorted_list;



void read_data(void);
t_list *get_node_by_name(char *name);
void link_nodes(char *name1, char *name2);
char **split_link(char *str);
t_room *get_end_start(int head);
int find_all_path(t_room *room, char *path);
void link_node(char **info);
t_path *new_path(char *steps);
int count_neighbours(t_room *room);
void del_path(t_room *room, char *neighbour);


void add(t_sorted_list **list, t_sorted_list *node);
t_sorted_list *new_node(char *str);

#endif
