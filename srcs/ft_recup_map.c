/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recup_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:33:30 by jtaravel          #+#    #+#             */
/*   Updated: 2022/02/05 17:05:27 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	ft_check_i(int i, t_global *global, char **recup)
{
	if (i == 1)
	{
		ft_putstr("Error\n");
		ft_putstr("Map incorrect\n");
		free(global);
		ft_free(recup);
		exit(0);
	}
	return (1);
}

void	ft_check_map_all(char **str, t_global *global, int i)
{
	if (!ft_check_i(i, global, str) || !ft_check_map(str)
		|| !ft_check_wall(str) || !ft_check_wall_2(str))
	{
		ft_free(str);
		free(global);
		ft_putstr("Error\n");
		ft_putstr("Map incorrect\n");
		exit(0);
	}
	if (!ft_check_dep_exit(str))
	{
		ft_free(str);
		free(global);
		ft_putstr("Error\n");
		ft_putstr("Too much or no start or exit");
		exit(0);
	}
	if (!ft_check_coll(str))
	{
		ft_free(str);
		free(global);
		ft_putstr("Error\n");
		ft_putstr("No collectible");
		exit(0);
	}
}

char	**ft_recup_map(char *str, t_global *global)
{
	int		fd;
	char	**recup;
	char	*cpy;
	int		i;

	cpy = "";
	fd = open(str, O_RDONLY);
	i = 0;
	while (cpy != NULL)
	{
		cpy = get_next_line(fd);
		free(cpy);
		i++;
	}
	recup = malloc(sizeof(char *) * (i + 1));
	fd = open(str, O_RDONLY);
	i = 0;
	cpy = "";
	while (cpy != NULL)
	{
		cpy = get_next_line(fd);
		recup[i++] = cpy;
	}
	ft_check_map_all(recup, global, i);
	return (recup);
}
