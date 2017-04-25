/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 17:44:46 by omotyliu          #+#    #+#             */
/*   Updated: 2017/03/22 17:44:47 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_sorted_list *g_all_p;
t_list *g_rooms;

int	main(void)
{
	t_sorted_list	*max;
	char			**info;
	int				i;

	i = 0;
	info = read_data();
	find_all_path(get_end_start(1), ft_strnew(1));
	find_parallel(g_all_p, 0);
	set_max_path();
	max = find_max_parallel_path();
	while (info[i] != NULL)
	{
		ft_printf("%s\n", info[i]);
		free(info[i]);
		i++;
	}
	free(info);
	ft_printf("\n");
	add_parall(&max->parallel, new_parall(max->steps, max->len));
	set_ant_per_path(max);
	ant_mover(max, 1, NULL, get_end_start(2)->name);
	while (move_ants_in_list())
		;
}
