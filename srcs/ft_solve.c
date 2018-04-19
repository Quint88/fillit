/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 14:21:54 by oespion           #+#    #+#             */
/*   Updated: 2018/04/19 11:16:01 by oespion          ###   ########.fr       */
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

void	ft_mod_tab(char **map, t_shapes *shapes, int p_nbr)
{
	if (shapes[p_nbr].shape == 0)
		ft_wrtI(shapes[p_nbr].x, shapes[p_nbr].y, map, shapes, p_nbr);
	if (shapes[p_nbr].shape == 1)
		ft_wrtJ(shapes[p_nbr].x, shapes[p_nbr].y, map, shapes, p_nbr);
	if (shapes[p_nbr].shape == 2)
		ft_wrtL(shapes[p_nbr].x, shapes[p_nbr].y, map, shapes, p_nbr);
	if (shapes[p_nbr].shape == 3)
		ft_wrtO(shapes[p_nbr].x, shapes[p_nbr].y, map, shapes, p_nbr);
	if (shapes[p_nbr].shape == 4)
		ft_wrtS(shapes[p_nbr].x, shapes[p_nbr].y, map, shapes, p_nbr);
	if (shapes[p_nbr].shape == 5)
		ft_wrtT(shapes[p_nbr].x, shapes[p_nbr].y, map, shapes, p_nbr);
	if (shapes[p_nbr].shape == 6)
		ft_wrtZ(shapes[p_nbr].x, shapes[p_nbr].y, map, shapes, p_nbr);
}

void	ft_solve(char **map, t_shapes *shapes, int p_nbr, int x, int y)
{
	while (shapes[p_nbr].shape >= 0)
	{
		while (ft_trypiece(shapes, map, p_nbr, x, y) == 0)
		{
			x++;
			if ((size_t)x >= ft_strlen(map[0]))
			{
				y++;
				x = 0;
			}
			if ((size_t)y >= ft_strlen(map[0]) && p_nbr == 0)
			{
				map = ft_bigger_pg(map);
				x = 0;
				y = 0;
			}
			else if ((size_t)y == ft_strlen(map[0]))
			{
				p_nbr--;
				x = shapes[p_nbr].x + 1;
				y = shapes[p_nbr].y;
				ft_mod_tab(map, shapes, p_nbr);
			}
		}
		if (ft_trypiece(shapes, map, p_nbr, x, y))
		{
			shapes[p_nbr].x = x;
			shapes[p_nbr].y = y;
			ft_mod_tab(map, shapes, p_nbr);
			p_nbr++;
			x = 0;
			y = 0;
		}
	}
	ft_print(map);
}
