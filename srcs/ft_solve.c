/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 14:21:54 by oespion           #+#    #+#             */
/*   Updated: 2018/04/14 14:06:06 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

void	ft_print(char **map)
{
	int	r;
	int	i;

	r = 0;
	i = 0;
	while (map[r])
	{
		while (map[r][i])
		{
			ft_putchar(map[r][i]);
			i++;
		}
		ft_putchar('\n');
		i = 0;
		r++;
	}
}

void	ft_mod_tab(char **map, t_shapes *shapes, int we, int p_nbr, int x, int y)
{
	if (we == 1)
	{
		shapes[p_nbr].x = x;
		shapes[p_nbr].y = y;
	}
	while (shapes[p_nbr].letter)
	{
		if (shapes[p_nbr].shape == 0)
			ft_wrtI(shapes[p_nbr].x , shapes[p_nbr].y, map, shapes, p_nbr, we);
		if (shapes[p_nbr].shape == 1)
			ft_wrtJ(shapes[p_nbr].x, shapes[p_nbr].y, map, shapes, p_nbr, we);
		if (shapes[p_nbr].shape == 2)
			ft_wrtL(shapes[p_nbr].x, shapes[p_nbr].y, map, shapes, p_nbr, we);
		if (shapes[p_nbr].shape == 3)
			ft_wrtO(shapes[p_nbr].x, shapes[p_nbr].y, map, shapes, p_nbr, we);
		if (shapes[p_nbr].shape == 4)
			ft_wrtS(shapes[p_nbr].x, shapes[p_nbr].y, map, shapes, p_nbr, we);
		if (shapes[p_nbr].shape == 5)
			ft_wrtT(shapes[p_nbr].x, shapes[p_nbr].y, map, shapes, p_nbr, we);
		if (shapes[p_nbr].shape == 6)
			ft_wrtZ(shapes[p_nbr].x, shapes[p_nbr].y, map, shapes, p_nbr, we);
		p_nbr++;
	}
//	ft_print(map);
}

void	ft_solve(char **map, t_shapes *shapes, int p_nbr, int x, int y)
{
	if (!shapes[p_nbr].letter)
		return (ft_print(map));
	if (ft_trypiece(shapes, map, p_nbr, x, y) == 0 && shapes[p_nbr].letter)
	{
		x++;
		if (x <= 5)
		{
			x = 0;
			y++;
		}
		if (shapes[p_nbr].letter == 'A' && y == 5)
		{
			map = ft_bigger_pg(map);
			x = 0;
			y = 0;
		}
		if (y == 5)
		{
			p_nbr--;
			ft_mod_tab(map, shapes, 0, p_nbr, x, y);
			ft_solve(map, shapes, p_nbr, shapes[p_nbr].x, shapes[p_nbr].y);
		}
		ft_trypiece(shapes, map, p_nbr, x, y);
	}
	if (ft_trypiece(shapes, map, p_nbr, x, y) == 1 && shapes[p_nbr].letter)
	{
		ft_mod_tab(map, shapes, 1, p_nbr, x, y);
		ft_solve(map, shapes, p_nbr + 1, 0 , 0);
	}
}
