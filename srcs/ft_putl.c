/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 09:08:53 by oespion           #+#    #+#             */
/*   Updated: 2018/04/13 17:04:27 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int	ft_putLN(int x, int y, char **map)
{
	int	i;
	int	is_valid;

	is_valid = 1;
	i = 0;
	while (i < 3)
	{
		is_valid = ft_is_valid(map, x, y);
		y++;
		i++;
	}
	if (is_valid == 1)
		is_valid = ft_is_valid(map, x + 1, y - 1);
	if (is_valid == 1)
		return (1);
	return (0);
}

int	ft_putLE(int x, int y, char **map)
{
	int	is_valid;

	is_valid = ft_is_valid(map, x, y);
	if (is_valid == 1)
		is_valid = ft_is_valid(map, x, y + 1);
	if (is_valid == 1)
		is_valid = ft_is_valid(map, x + 1, y);
	if (is_valid == 1)
		is_valid = ft_is_valid(map, x + 2, y);
	if (is_valid == 1)
		return (1);
	return (0);
}

int	ft_putLS(int x, int y, char **map)
{
	int	i;
	int	is_valid;

	i = 0;
	is_valid = ft_is_valid(map, x, y);
	x += 1;
	while (i < 3)
	{
		is_valid = ft_is_valid(map, x, y);
		i++;
		y++;
	}
	if (is_valid == 1)
		return (1);
	return (0);
}

int	ft_putLW(int x, int y, char **map)
{
	int	is_valid;

	is_valid = ft_is_valid(map, x, y);
	if (is_valid == 1)
		is_valid = ft_is_valid(map, x, y + 1);
	if (is_valid == 1)
		is_valid = ft_is_valid(map, x - 1, y + 1);
	if (is_valid == 1)
		is_valid = ft_is_valid(map, x - 1, y + 1);
	if (is_valid == 1)
		return (1);
	return (0);
}

int	ft_putL(int x, int y, char **map, t_shapes *shapes, int p_nbr)
{
	int	is_valid;

	if (shapes[p_nbr].direction == 0)
		is_valid = ft_putLN(x, y, map);
	if (shapes[p_nbr].direction == 1)
		is_valid = ft_putLE(x, y, map);
	if (shapes[p_nbr].direction == 2)
		is_valid = ft_putLS(x, y, map);
	if (shapes[p_nbr].direction == 3)
		is_valid = ft_putLW(x, y, map);
	return (is_valid);
}