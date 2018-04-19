/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 17:42:19 by groussel          #+#    #+#             */
/*   Updated: 2018/04/19 10:02:39 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** TODO:	[X] Set loop functions pointer in checkshape
**			[X] Free all malloc in strerror
**			[X] Check chars in square (4# 4\n 12.)
**			[X] Check I shape
**			[X] Check J shape
**			[X] Check L shape
**			[X] Check O shape
**			[X] Check S shape
**			[X] Check T shape
**			[X] Check Z shape
**			[X] Set letter
**
** FUNC:	exit
**			open / close
**			malloc / free
**			write / read
**
** FIXME:	[X] Segv l45 for 3rd struct
*/

#include "fillit.h"
#include "libft.h"

int		checkfile(t_shapes *shapes, char **square, int fd)
{
	int		bytes;
	char	space;
	int		i;

	i = -1;
	while ((bytes = read(fd, *square, 20)) > 0)
	{
		if ((shapes[++i].shape = checkshape(*square)) >= 0)
		{
			shapes[i].x = 0;
			shapes[i].y = 0;
			shapes[i].direction = checkdir(*square);
			shapes[i].set = 0;
			shapes[i].letter = 'A' + i;
		}
		else
			ft_strerror(shapes, *square, fd, 2);
		if ((bytes = read(fd, &space, 1)) > 0)
			;
	}
	shapes[++i].shape = -1;
	return (1);
}

int		checkshape(char *square)
{
	int		(*f[7])(char **tab);
	char	**tab;
	int		i;

	if (!checkchars(square))
		return (-1);
	tab = ft_strsplit(square, '\n');
	f[0] = checkI;
	f[1] = checkJ;
	f[2] = checkL;
	f[3] = checkO;
	f[4] = checkS;
	f[5] = checkT;
	f[6] = checkZ;
	i = -1;
	while (++i < 7)
		if (f[i](tab) >= 0)
			return (i);
	return (-1);
}

int		checkdir(char *square)
{
	int		(*f[7])(char **tab);
	char	**tab;
	int		i;
	int		result;

	tab = ft_strsplit(square, '\n');
	f[0] = checkI;
	f[1] = checkJ;
	f[2] = checkL;
	f[3] = checkO;
	f[4] = checkS;
	f[5] = checkT;
	f[6] = checkZ;
	i = -1;
	while (++i < 7)
		if ((result = f[i](tab)) >= 0)
			return (result);
	return (-1);
}

int		checkchars(char *square)
{
	int		i;
	int		dot;
	int		rl;
	int		sharpe;

	i = -1;
	dot = 12;
	rl = 4;
	sharpe = 4;
	while (square[++i])
	{
		if (square[i] == '.')
			dot--;
		if (square[i] == '\n')
			rl--;
		if (square[i] == '#')
			sharpe--;
	}
	if (dot == 0 && rl == 0 && sharpe == 0 && square[4] == '\n'
			&& square[9] == '\n' && square[14] == '\n' && square[19] == '\n')
		return (1);
	return (0);
}
