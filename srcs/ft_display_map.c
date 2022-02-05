/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:26:59 by jtaravel          #+#    #+#             */
/*   Updated: 2022/02/04 19:13:10 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_aff_elem(t_global *global, int ligne, int colonne)
{
	if (global->map.map[ligne][colonne] == 'P')
		mlx_put_image_to_window(global->mlx, global->win,
			global->img2.img_p, colonne * 64, ligne * 64);
	else if (global->map.map[ligne][colonne] == '0')
		mlx_put_image_to_window(global->mlx, global->win,
			global->img2.img_0, colonne * 64, ligne * 64);
	else if (global->map.map[ligne][colonne] == '1')
		mlx_put_image_to_window(global->mlx, global->win,
			global->img2.img_1, colonne * 64, ligne * 64);
	else if (global->map.map[ligne][colonne] == 'C')
		mlx_put_image_to_window(global->mlx, global->win,
			global->img2.img_c, colonne * 64, ligne * 64);
	else if (global->map.map[ligne][colonne] == 'E')
		mlx_put_image_to_window(global->mlx, global->win,
			global->img2.img_e, colonne * 64, ligne * 64);
	else if (global->map.map[ligne][colonne] == 'M')
	{
		if (global->pos_enemy == 1)
			mlx_put_image_to_window(global->mlx, global->win,
				global->img2.img_m, colonne * 64, ligne * 64);
		if (global->pos_enemy == 2)
			mlx_put_image_to_window(global->mlx, global->win,
				global->img2.img_m2, colonne * 64, ligne * 64);
	}
}

void	ft_check_size_max(t_global *global)
{
	if (global->map.size.x > 30 || global->map.size.y > 18)
	{
		printf("Map size error");
		ft_free_struct(global);
	}
}

int	ft_display_map(t_global *global)
{
	int		i;
	int		j;

	i = 0;
	while (i < global->map.size.y)
	{
		j = 0;
		while (j < global->map.size.x)
		{
			ft_aff_elem(global, i, j);
			j++;
		}
		i++;
	}
	return (0);
}
