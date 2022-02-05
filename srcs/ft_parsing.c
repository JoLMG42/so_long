/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:54:31 by jtaravel          #+#    #+#             */
/*   Updated: 2022/01/31 18:25:37 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	n;
	int	len;

	len = ft_strlen(to_find);
	i = 0;
	if (to_find[i] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		n = 0;
		while (str[i + n] == to_find[n])
		{
			if (n == len - 1)
				return (&str[i]);
			n++;
		}
		i++;
	}
	return (0);
}

int	ft_check_file(char *str)
{
	int	fd;

	fd = open(str, O_DIRECTORY);
	if (fd >= 0)
		return (0);
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (0);
	return (1);
}

int	ft_check_extension(char *str, t_global *global)
{
	if (!ft_strstr(str, ".ber") || !ft_check_file(str))
	{
		free(global);
		return (0);
	}
	return (1);
}
