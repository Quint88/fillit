/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groussel <groussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 23:12:22 by groussel          #+#    #+#             */
/*   Updated: 2018/04/19 13:39:47 by groussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int		checkt(char **tab)
{
	if (checktn(tab))
		return (0);
	if (checkte(tab))
		return (1);
	if (checkts(tab))
		return (2);
	if (checktw(tab))
		return (3);
	return (-1);
}

/*
**  #
** ###
*/

int		checktn(char **tab)
{
	int		x;
	int		y;

	y = -1;
	while (++y < 3)
	{
		x = 0;
		while (++x < 3)
		{
			if (tab[y][x] == '#' && tab[y + 1][x - 1] == '#' &&
					tab[y + 1][x] == '#' && tab[y + 1][x + 1] == '#')
				return (1);
		}
	}
	return (0);
}

/*
** #
** ##
** #
*/

int		checkte(char **tab)
{
	int		x;
	int		y;

	y = -1;
	while (++y < 2)
	{
		x = -1;
		while (++x < 3)
		{
			if (tab[y][x] == '#' && tab[y + 1][x] == '#' &&
					tab[y + 1][x + 1] == '#' && tab[y + 2][x] == '#')
				return (1);
		}
	}
	return (0);
}

/*
** ###
**  #
*/

int		checkts(char **tab)
{
	int		x;
	int		y;

	y = -1;
	while (++y < 3)
	{
		x = -1;
		while (++x < 2)
		{
			if (tab[y][x] == '#' && tab[y][x + 1] == '#' &&
					tab[y + 1][x + 1] == '#' && tab[y][x + 2] == '#')
				return (1);
		}
	}
	return (0);
}

/*
**  #
** ##
**  #
*/

int		checktw(char **tab)
{
	int		x;
	int		y;

	y = -1;
	while (++y < 2)
	{
		x = 0;
		while (++x < 4)
		{
			if (tab[y][x] == '#' && tab[y + 1][x] == '#' &&
					tab[y + 1][x - 1] == '#' && tab[y + 2][x] == '#')
				return (1);
		}
	}
	return (0);
}
