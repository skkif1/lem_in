/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 14:48:45 by omotyliu          #+#    #+#             */
/*   Updated: 2017/03/23 14:48:47 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_list *g_rooms;
int g_ants;

void	clear_two_dem(char **mass)
{
	int i;

	i = 0;
	while (mass[i])
	{
		free(mass[i]);
		i++;
	}
	free(mass);
}

int		if_fool(void)
{
	t_list	*start;
	char	*end_name;
	int		i;

	start = get_end_start(1)->neighbours;
	end_name = get_end_start(2)->name;
	i = 1;
	while (start)
	{
		if (!ft_strcmp((char*)start->content, end_name))
		{
			while (i <= g_ants)
			{
				ft_printf("L%d-e ", i);
				i++;
			}
			ft_printf("\n");
			exit(0);
		}
		start = start->next;
	}
	return (0);
}

char	**split_link(char *str)
{
	int		i;
	char	**res;

	res = (char**)malloc(sizeof(char*) * 3);
	i = 0;
	while (str[i] != '-')
		i++;
	res[0] = ft_strsub(str, 0, i);
	res[1] = ft_strdup(ft_strchr(str, '-') + 1);
	res[2] = NULL;
	return (res);
}

void	error(void)
{
	ft_printf("ERROR\n");
	exit(1);
}
