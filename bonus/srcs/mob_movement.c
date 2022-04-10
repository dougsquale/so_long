/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mob_movement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:40:30 by dbelpaum          #+#    #+#             */
/*   Updated: 2022/04/09 14:16:08 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_v_mob_mv(t_settings *s, int y, int x, int keycode)
{
	if (keycode == MOB_UP && (y < 1 || s->map[y - 1][x] != '0'
		|| y - 1 == s->py))
		return (0);
	if (keycode == MOB_DOWN && (y >= s->height || s->map[y + 1][x] != '0'
		|| y + 1 == s->py))
		return (0);
	if (keycode == MOB_LEFT && (x < 1 || s->map[y][x - 1] != '0'
		|| x - 1 == s->px))
		return (0);
	if (keycode == MOB_RIGHT && (x >= s->width || s->map[y][x + 1] != '0'
		|| x + 1 == s->px))
		return (0);
	return (1);
}

int	rng(int max, unsigned long addr)
{
	srand(time(NULL) * addr);
	return (rand() % max);
}

void	try_mob_mv(t_settings *s, int y, int x)
{
	int	dir;

	dir = rng(4, 1);
	if (!is_v_mob_mv(s, y, x, dir))
		return ;
	if (dir == MOB_UP)
	{
		draw_image(x * s->res, y * s->res, s, '0');
		draw_image(x * s->res, (y - 1) * s->res, s, 'X');
		s->map[y][x] = '0';
		s->map[y - 1][x] = 'T';
	}
	else if (dir == MOB_RIGHT)
	{
		draw_image(x * s->res, y * s->res, s, '0');
		draw_image((x + 1) * s->res, y * s->res, s, 'X');
		s->map[y][x] = '0';
		s->map[y][x + 1] = 'T';
	}
	else if (dir == MOB_DOWN || dir == MOB_LEFT)
		try_mob_mv_2(s, y, x, dir);
}

void	try_mob_mv_2(t_settings *s, int y, int x, int dir)
{
	if (dir == MOB_DOWN)
	{
		draw_image(x * s->res, y * s->res, s, '0');
		draw_image(x * s->res, (y + 1) * s->res, s, 'X');
		s->map[y][x] = '0';
		s->map[y + 1][x] = 'T';
	}
	else if (dir == MOB_LEFT)
	{
		draw_image(x * s->res, y * s->res, s, '0');
		draw_image((x - 1) * s->res, y * s->res, s, 'X');
		s->map[y][x] = '0';
		s->map[y][x - 1] = 'T';
	}
}

void	mob_moves(t_settings *s)
{
	int	i;

	i = -1;
	while (++i < s->width * s->height)
		if (s->map[i / s->width][i % s->width] == 'X' && rng(2,
			(unsigned long)&(s->map[i / s->width][i % s->width])) == 0)
			try_mob_mv(s, i / s->width, i % s->width);
	i = -1;
	while (++i < s->width * s->height)
		if (s->map[i / s->width][i % s->width] == 'T')
			s->map[i / s->width][i % s->width] = 'X';
}
