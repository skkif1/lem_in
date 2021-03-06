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

int						g_ants;
int						g_max_path;
struct s_sorted_list	*g_all_p;

typedef struct		s_room
{
	char			*name;
	t_list			*neighbours;
	int				head;
	char			*coord;
}					t_room;

typedef struct		s_path
{
	char			*steps;
	int				len;
}					t_path;

typedef struct		s_ant
{
	char			*name;
	char			**path;
	int				pos;
	char			*end;
}					t_ant;

typedef struct		s_parall_path
{
	char					*parallel_path;
	int						len;
	int						ants_num;
	struct s_parall_path	*next;
}					t_parall_path;

typedef struct		s_sorted_list
{
	char					*steps;
	char					**splited_steps;
	int						gen_len;
	int						flow_cap;
	t_parall_path			*parallel;
	int						len;
	int						num_of_paral;
	struct s_sorted_list	*next;
}					t_sorted_list;

char				**read_data(void);
t_list				*get_node_by_name(char *name);
int					if_fool();
void				link_nodes(char *name1, char *name2);
char				**split_link(char *str);
t_room				*get_end_start(int head);
int					find_all_path(t_room *room, char *path);
void				link_node(char **info);
int					count_neighbours(t_room *room);
void				find_parallel(t_sorted_list *lst, int flow);
t_sorted_list		*find_max_parallel_path();
int					calc_flow_cap(t_sorted_list *path1, t_sorted_list *path2);
void				clear_two_dem(char **mass);
void				set_ant_per_path(t_sorted_list *package);
int					move_ants_in_list();
void				set_max_path();
void				move_ant(t_ant *ant);
void				ant_mover(t_sorted_list *package,
					int i, t_ant *ant, char *end_name);
void				add(t_sorted_list **list, t_sorted_list *node);
t_sorted_list		*new_node(char *str);
void				add_parall(t_parall_path **lst, t_parall_path *to_add);
t_parall_path		*new_parall(char *str, int i);
t_ant				*new_ant(char *name, char **path, char *end);
void				check_number(char *str);
void				check_room(char *str);
void				error();
void				check_info(char **str);
void				check_coord(t_room *room);

#endif
