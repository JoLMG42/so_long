/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 13:58:12 by jtaravel          #+#    #+#             */
/*   Updated: 2022/02/05 17:31:35 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	ft_change_pos_enemy(t_global *global, void *img)
{
	int	i;
	int	j;

	(void)img;
	i = -1;
	while (global->map.map[++i])
	{
		j = -1;
		while (global->map.map[i][++j])
		{
			if (global->map.map[i][j] == 'M')
				mlx_put_image_to_window(global->mlx, global->win,
					img, j * 64, i * 64);
		}
	}
}

int	ft_animations(t_global *global)
{
	char	*count;

	count = ft_itoa(global->map.count_steps);
	mlx_string_put(global->mlx, global->win, global->map.size.x * 2,
		global->map.size.y * 2, RED, count);
	free(count);
	if (global->loop < 100000)
	{
		global->loop++;
		return (0);
	}
	global->loop = 0;
	if (global->pos_enemy == 1)
	{
		global->pos_enemy = 2;
		ft_change_pos_enemy(global, global->img2.img_m2);
	}
	else if (global->pos_enemy == 2)
	{
		global->pos_enemy = 1;
		ft_change_pos_enemy(global, global->img2.img_m);
	}
	return (0);
}

void	ft_init_struct(t_global *global)
{
	global->game.count_steps = 0;
	global->map.count_steps = 0;
	ft_get_size(global);
	global->mlx = mlx_init();
	if (!global->mlx)
	{
		free(global);
		exit(0);
	}
	global->loop = 0;
	global->pos_enemy = 1;
	ft_get_start_position(global);
	ft_nbr_collec(global);
	ft_recup_img(global);
	ft_check_size_max(global);
}

int	main(int ac, char **av)
{
	t_global	*global;

	global = malloc(sizeof(t_global));
	if (ac < 2)
	{
		free(global);
		return (0);
	}
	if (!ft_check_extension(av[1], global))
	{
		printf("Error\nExtension or map not found\n");
		return (0);
	}
	global->map.map = ft_recup_map(av[1], global);
	if (!global->map.map)
		free(global);
	ft_init_struct(global);
	global->win = mlx_new_window(global->mlx, global->map.size.x * 64,
			global->map.size.y * 64,
			"so_long");
	ft_display_map(global);
	mlx_hook(global->win, 2, 1L << 0, ft_key, global);
	mlx_hook(global->win, 17, 1L << 0, ft_key_esc, global);
	mlx_loop_hook(global->mlx, ft_animations, global);
	mlx_loop(global->mlx);
}	
