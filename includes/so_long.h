/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:06:16 by jtaravel          #+#    #+#             */
/*   Updated: 2022/02/05 17:32:19 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"

# define RED	0xF7230C

typedef struct s_size
{
	int	x;
	int	y;
}	t_size;

typedef struct s_game
{
	int	collec;
	int	count_steps;
}	t_game;

typedef struct s_img2
{
	void	*img_p;
	void	*img_0;
	void	*img_e;
	void	*img_1;
	void	*img_m;
	void	*img_m2;
	void	*img_c;
	t_size	start_pos;
	t_size	size;
}	t_img2;

typedef struct s_map
{
	t_size	size;
	char	**map;
	int		startx;
	int		starty;
	int		collec;
	int		count_steps;
	int		steps_global;
}	t_map;

typedef struct s_global
{
	void	*win;
	void	*mlx;
	int		loop;
	int		pos_enemy;
	t_game	game;
	t_map	map;
	t_img2	img2;
}	t_global;

/* --- Classics --- */

int		ft_strlen(char *str);
void	ft_putstr(char *str);
char	*ft_strstr(char *str, char *to_find);
char	*ft_itoa(int n);

/* --- Parsing --- */

int		ft_key(int key, t_global *global);
int		ft_key_esc(t_global *global);
int		ft_check_file(char *str);
int		ft_check_extension(char *str, t_global *global);
int		ft_check_dep_exit(char **str);
int		ft_check_coll(char **str);
int		ft_check_wall(char **str);
int		ft_check_wall_2(char **str);
int		ft_check_map(char **str);
int		ft_free_all(t_global *global);
int		ft_display_map(t_global *global);
int		ft_down(t_global *global);
int		ft_up(t_global *global);
int		ft_right(t_global *global);
int		ft_left(t_global *global);
int		ft_moves(int key, t_global *global);
int		ft_check_collec(t_global *global);
void	ft_mini_free(t_global *global);
void	ft_get_size(t_global *global);
void	ft_check_size_max(t_global *global);
void	ft_free(char **str);
void	ft_get_start_position(t_global *global);
void	ft_nbr_collec(t_global *global);
void	ft_free_struct(t_global *global);
void	ft_recup_img(t_global *global);
void	ft_aff_elem(t_global *global, int ligne, int colonne);
void	ft_check_map_all(char **str, t_global *global, int i);
char	**ft_recup_map(char *str, t_global *global);

#endif
