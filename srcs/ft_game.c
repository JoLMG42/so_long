/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:32:27 by jtaravel          #+#    #+#             */
/*   Updated: 2022/02/05 17:02:20 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_check_collec(t_global *global)
{
	ft_nbr_collec(global);
	if (global->map.collec != 0)
		write(1, "Not all collectibles were found\n", 32);
	else if (global->map.collec == 0)
	{
		global->map.count_steps++;
		printf("nb de steps = %d\n", global->map.count_steps);
		printf ("fini");
		ft_free_all(global);
	}
	return (0);
}

int	ft_key_esc(t_global *global)
{
	printf("Fermeture de la fenetre...");
	ft_free_all(global);
	return (0);
}

int	ft_key(int key, t_global *global)
{
	int	start_steps;

	start_steps = global->map.count_steps;
	if (key == 65307)
	{
		printf("ESC PRESSED");
		ft_free_all(global);
	}
	else
		ft_moves(key, global);
	if (start_steps != global->map.count_steps)
		printf("nb de steps = %d\n", global->map.count_steps);
	ft_display_map(global);
	return (0);
}
