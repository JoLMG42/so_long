/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:53:05 by jtaravel          #+#    #+#             */
/*   Updated: 2022/01/31 17:45:10 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_check_map(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[j])
		{
			if (ft_strlen(str[i]) != ft_strlen(str[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_wall_2(char **str)
{
	int	i;
	int	j;

	j = 0;
	i = ft_strlen(str[0]) - 1;
	while (str[j])
		j++;
	j--;
	while (--j != 0)
	{
		if (str[j][i - 1] != '1' || str[j][0] != '1')
			return (0);
	}
	return (1);
}

int	ft_check_wall(char **str)
{
	int	i;
	int	j;

	j = 0;
	i = ft_strlen(str[0]) - 1;
	while (i != 0)
	{
		if (str[0][i - 1] != '1')
			return (0);
		i--;
	}
	j = 0;
	while (str[j])
		j++;
	j--;
	i = ft_strlen(str[j]) - 1;
	while (i != 0)
	{
		if (str[j][i - 1] != '1')
			return (0);
		i--;
	}
	return (1);
}

int	ft_check_dep_exit(char **str)
{
	int	i;
	int	j;
	int	depart;
	int	exit;

	exit = 0;
	depart = 0;
	j = 0;
	while (str[j])
		j++;
	j--;
	while (--j != 0)
	{
		i = ft_strlen(str[0]);
		while (--i != 0)
		{
			if (str[j][i] == 'P')
				depart += 1;
			if (str[j][i] == 'E')
				exit += 1;
		}
	}
	if (depart != 1 || exit != 1)
		return (0);
	return (1);
}

int	ft_check_coll(char **str)
{
	int	c;
	int	i;
	int	j;

	j = 0;
	c = 0;
	while (str[j])
		j++;
	j--;
	while (--j != 0)
	{
		i = ft_strlen(str[0]) - 1;
		while (i != 0)
		{
			if (str[j][i] == 'C')
				c += 1;
			i--;
		}
	}
	if (c == 0)
		return (0);
	return (1);
}
