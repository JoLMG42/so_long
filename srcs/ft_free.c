/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:22:26 by jtaravel          #+#    #+#             */
/*   Updated: 2022/02/04 19:08:47 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_mini_free(t_global *global)
{
	int	i;

	i = 0;
	mlx_destroy_display(global->mlx);
	free(global->mlx);
	while (i < global->map.size.y)
	{
		free(global->map.map[i]);
		i++;
	}
	free(global->map.map);
	free(global);
	exit(0);
}

void	ft_free_struct(t_global *global)
{
	int	i;

	i = 0;
	mlx_destroy_image(global->mlx, global->img2.img_p);
	mlx_destroy_image(global->mlx, global->img2.img_e);
	mlx_destroy_image(global->mlx, global->img2.img_m);
	mlx_destroy_image(global->mlx, global->img2.img_m2);
	mlx_destroy_image(global->mlx, global->img2.img_c);
	mlx_destroy_image(global->mlx, global->img2.img_0);
	mlx_destroy_image(global->mlx, global->img2.img_1);
	mlx_destroy_display(global->mlx);
	free(global->mlx);
	while (i < global->map.size.y)
	{
		free(global->map.map[i]);
		i++;
	}
	free(global->map.map);
	free(global);
	exit(0);
}

int	ft_free_all(t_global *global)
{
	int	i;

	i = 0;
	mlx_destroy_image(global->mlx, global->img2.img_p);
	mlx_destroy_image(global->mlx, global->img2.img_e);
	mlx_destroy_image(global->mlx, global->img2.img_m);
	mlx_destroy_image(global->mlx, global->img2.img_m2);
	mlx_destroy_image(global->mlx, global->img2.img_c);
	mlx_destroy_image(global->mlx, global->img2.img_0);
	mlx_destroy_image(global->mlx, global->img2.img_1);
	mlx_destroy_window(global->mlx, global->win);
	mlx_destroy_display(global->mlx);
	free(global->mlx);
	while (i < global->map.size.y)
	{
		free(global->map.map[i]);
		i++;
	}
	free(global->map.map);
	free(global);
	exit(0);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
