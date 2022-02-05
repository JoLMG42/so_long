/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:24:59 by jtaravel          #+#    #+#             */
/*   Updated: 2022/01/31 16:26:55 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_get_size(t_global *global)
{
	int	i;
	int	j;

	j = 0;
	while (global->map.map[j])
		j++;
	global->map.size.y = j;
	i = ft_strlen(global->map.map[0]) - 1;
	global->map.size.x = i;
}

void	ft_get_start_position(t_global *global)
{
	int	l;
	int	c;

	l = 0;
	while (global->map.map[l])
	{
		c = 0;
		while (global->map.map[l][c])
		{
			if (global->map.map[l][c] == 'P')
			{
				global->map.startx = c;
				global->map.starty = l;
			}
			c++;
		}
		l++;
	}
}

void	ft_nbr_collec(t_global *global)
{
	int	i;
	int	j;

	i = 0;
	global->map.collec = 0;
	while (global->map.map[i])
	{
		j = 0;
		while (global->map.map[i][j])
		{
			if (global->map.map[i][j] == 'C')
				global->map.collec += 1;
			j++;
		}
		i++;
	}
}
