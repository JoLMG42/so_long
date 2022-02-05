/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:29:02 by jtaravel          #+#    #+#             */
/*   Updated: 2022/02/04 19:12:53 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_down(t_global *global)
{
	if (global->map.map[global->map.starty + 1][global->map.startx] == 'M')
	{
		printf("nb de steps = %d\n", global->map.count_steps + 1);
		printf("perdu");
		ft_free_all(global);
	}
	mlx_destroy_image(global->mlx, global->img2.img_p);
	global->img2.img_p = mlx_xpm_file_to_image(global->mlx, "img/face2.xpm",
			&global->img2.size.x, &global->img2.size.y);
	global->map.map[global->map.starty][global->map.startx] = '0';
	mlx_put_image_to_window(global->mlx, global->win,
		global->img2.img_0, global->map.startx * 64, global->map.starty * 64);
	global->map.starty += 1;
	mlx_put_image_to_window(global->mlx, global->win,
		global->img2.img_p, global->map.startx * 64, global->map.starty * 64);
	global->map.map[global->map.starty][global->map.startx] = 'P';
	global->map.count_steps++;
	return (0);
}

int	ft_up(t_global *global)
{
	if (global->map.map[global->map.starty - 1][global->map.startx] == 'M')
	{
		printf("nb de steps = %d\n", global->map.count_steps + 1);
		printf("perdu");
		ft_free_all(global);
	}
	mlx_destroy_image(global->mlx, global->img2.img_p);
	global->img2.img_p = mlx_xpm_file_to_image(global->mlx, "img/back2.xpm",
			&global->img2.size.x, &global->img2.size.y);
	global->map.map[global->map.starty][global->map.startx] = '0';
	mlx_put_image_to_window(global->mlx, global->win,
		global->img2.img_0, global->map.startx * 64, global->map.starty * 64);
	global->map.starty -= 1;
	global->map.map[global->map.starty][global->map.startx] = 'P';
	mlx_put_image_to_window(global->mlx, global->win,
		global->img2.img_p, global->map.startx * 64, global->map.starty * 64);
	global->map.count_steps++;
	return (0);
}

int	ft_right(t_global *global)
{
	if (global->map.map[global->map.starty][global->map.startx + 1] == 'M')
	{
		printf("nb de steps = %d\n", global->map.count_steps + 1);
		printf("perdu");
		ft_free_all(global);
	}
	mlx_destroy_image(global->mlx, global->img2.img_p);
	global->img2.img_p = mlx_xpm_file_to_image(global->mlx, "img/right2.xpm",
			&global->img2.size.x, &global->img2.size.y);
	global->map.map[global->map.starty][global->map.startx] = '0';
	mlx_put_image_to_window(global->mlx, global->win,
		global->img2.img_0, global->map.startx * 64, global->map.starty * 64);
	global->map.startx += 1;
	mlx_put_image_to_window(global->mlx, global->win,
		global->img2.img_p, global->map.startx * 64, global->map.starty * 64);
	global->map.map[global->map.starty][global->map.startx] = 'P';
	global->map.count_steps++;
	return (0);
}

int	ft_left(t_global *global)
{
	if (global->map.map[global->map.starty][global->map.startx - 1] == 'M')
	{
		printf("nb de steps = %d\n", global->map.count_steps + 1);
		printf("perdu");
		ft_free_all(global);
	}
	mlx_destroy_image(global->mlx, global->img2.img_p);
	global->img2.img_p = mlx_xpm_file_to_image(global->mlx, "img/left2.xpm",
			&global->img2.size.x, &global->img2.size.y);
	global->map.map[global->map.starty][global->map.startx] = '0';
	mlx_put_image_to_window(global->mlx, global->win,
		global->img2.img_0, global->map.startx * 64, global->map.starty * 64);
	global->map.startx -= 1;
	global->map.map[global->map.starty][global->map.startx] = 'P';
	mlx_put_image_to_window(global->mlx, global->win,
		global->img2.img_p, global->map.startx * 64, global->map.starty * 64);
	global->map.count_steps++;
	return (0);
}

int	ft_moves(int key, t_global *global)
{
	if ((key == 97) && (global->map.map[global->map.starty]
			[global->map.startx - 1] == 'E'))
		ft_check_collec(global);
	else if ((key == 97) && (global->map.map[global->map.starty]
			[global->map.startx - 1] != '1'))
		ft_left(global);
	if ((key == 100) && (global->map.map[global->map.starty]
			[global->map.startx + 1] == 'E'))
		ft_check_collec(global);
	else if ((key == 100) && (global->map.map[global->map.starty]
			[global->map.startx + 1] != '1'))
		ft_right(global);
	if ((key == 119) && (global->map.map[global->map.starty - 1]
			[global->map.startx] == 'E'))
		ft_check_collec(global);
	else if ((key == 119) && (global->map.map[global->map.starty - 1]
			[global->map.startx] != '1'))
		ft_up(global);
	if ((key == 115) && (global->map.map[global->map.starty + 1]
			[global->map.startx] == 'E'))
		ft_check_collec(global);
	else if ((key == 115) && (global->map.map[global->map.starty + 1]
			[global->map.startx] != '1'))
		ft_down(global);
	return (0);
}
