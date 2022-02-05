/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recup_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:34:10 by jtaravel          #+#    #+#             */
/*   Updated: 2022/02/04 15:07:56 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_check_path(t_global *global)
{
	if (open("img", O_DIRECTORY) < 0)
		ft_mini_free(global);
	if (open("img/face2.xpm", O_RDONLY) < 0)
		ft_mini_free(global);
	if (open("img/back2.xpm", O_RDONLY) < 0)
		ft_mini_free(global);
	if (open("img/right2.xpm", O_RDONLY) < 0)
		ft_mini_free(global);
	if (open("img/left2.xpm", O_RDONLY) < 0)
		ft_mini_free(global);
	if (open("img/exit.xpm", O_RDONLY) < 0)
		ft_mini_free(global);
	if (open("img/grey_floor.xpm", O_RDONLY) < 0)
		ft_mini_free(global);
	if (open("img/grey_wall.xpm", O_RDONLY) < 0)
		ft_mini_free(global);
	if (open("img/saphir.xpm", O_RDONLY) < 0)
		ft_mini_free(global);
	if (open("img/enemy2.xpm", O_RDONLY) < 0)
		ft_mini_free(global);
	if (open("img/enemy2flip.xpm", O_RDONLY) < 0)
		ft_mini_free(global);
}

void	ft_recup_img(t_global *global)
{
	ft_check_path(global);
	global->img2.img_p = mlx_xpm_file_to_image(global->mlx,
			"img/right2.xpm", &global->img2.size.x, &global->img2.size.y);
	global->img2.img_e = mlx_xpm_file_to_image(global->mlx,
			"img/exit.xpm", &global->img2.size.x, &global->img2.size.y);
	global->img2.img_0 = mlx_xpm_file_to_image(global->mlx,
			"img/grey_floor.xpm", &global->img2.size.x, &global->img2.size.y);
	global->img2.img_1 = mlx_xpm_file_to_image(global->mlx,
			"img/grey_wall.xpm", &global->img2.size.x, &global->img2.size.y);
	global->img2.img_c = mlx_xpm_file_to_image(global->mlx,
			"img/saphir.xpm", &global->img2.size.x, &global->img2.size.y);
	global->img2.img_m = mlx_xpm_file_to_image(global->mlx,
			"img/enemy2.xpm", &global->img2.size.x, &global->img2.size.y);
	global->img2.img_m2 = mlx_xpm_file_to_image(global->mlx,
			"img/enemy2flip.xpm", &global->img2.size.x, &global->img2.size.y);
}
