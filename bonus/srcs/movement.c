/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 04:34:58 by dbelpaum          #+#    #+#             */
/*   Updated: 2022/04/08 16:47:27 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_hook(int keycode, t_settings *settings)
{
	if (keycode == UP_KEY)
		move_up(keycode, settings);
	else if (keycode == LEFT_KEY)
		move_left(keycode, settings);
	else if (keycode == DOWN_KEY)
		move_down(keycode, settings);
	else if (keycode == RIGHT_KEY)
		move_right(keycode, settings);
	else if (keycode == ESC_KEY)
		free_settings(settings, "You have exited the game.\n");
	return (0);
}

void	move_up(int keycode, t_settings *s)
{
	if (!is_valid_move(keycode, s))
		return ;
	if (s->map[s->py - 1][s->px] == 'C')
	{
		s->item_counter++;
		s->map[s->py - 1][s->px] = '0';
	}
	if (s->map[s->py - 1][s->px] == 'E' && s->item_counter == s->max_items)
		free_settings(s, "You have won the game!\n");
	else if (s->map[s->py - 1][s->px] == 'X')
		free_settings(s, "You have died.\n");
	if (s->map[s->py][s->px] == 'E')
		draw_image(s->px * s->res, s->py * s->res, s, 'E');
	else
		draw_image(s->px * s->res, s->py * s->res, s, '0');
	draw_image(s->px * s->res, (s->py - 1) * s->res, s, 4);
	s->py--;
	s->move_count++;
	mob_moves(s);
	draw_move_counter(s);
}

void	move_left(int keycode, t_settings *s)
{
	if (!is_valid_move(keycode, s))
		return ;
	if (s->map[s->py][s->px - 1] == 'C')
	{
		s->item_counter++;
		s->map[s->py][s->px - 1] = '0';
	}
	if (s->map[s->py][s->px - 1] == 'E' && s->item_counter == s->max_items)
		free_settings(s, "You have won the game!\n");
	else if (s->map[s->py][s->px - 1] == 'X')
		free_settings(s, "You have died.\n");
	if (s->map[s->py][s->px] == 'E')
		draw_image(s->px * s->res, s->py * s->res, s, 'E');
	else
		draw_image(s->px * s->res, s->py * s->res, s, '0');
	draw_image((s->px - 1) * s->res, s->py * s->res, s, 2);
	s->px--;
	s->move_count++;
	mob_moves(s);
	draw_move_counter(s);
}

void	move_down(int keycode, t_settings *s)
{
	if (!is_valid_move(keycode, s))
		return ;
	if (s->map[s->py + 1][s->px] == 'C')
	{
		s->item_counter++;
		s->map[s->py + 1][s->px] = '0';
	}
	if (s->map[s->py + 1][s->px] == 'E' && s->item_counter == s->max_items)
		free_settings(s, "You have won the game!\n");
	else if (s->map[s->py + 1][s->px] == 'X')
		free_settings(s, "You have died.\n");
	if (s->map[s->py][s->px] == 'E')
		draw_image(s->px * s->res, s->py * s->res, s, 'E');
	else
		draw_image(s->px * s->res, s->py * s->res, s, '0');
	draw_image(s->px * s->res, (s->py + 1) * s->res, s, 1);
	s->py++;
	s->move_count++;
	mob_moves(s);
	draw_move_counter(s);
}

void	move_right(int keycode, t_settings *s)
{
	if (!is_valid_move(keycode, s))
		return ;
	if (s->map[s->py][s->px + 1] == 'C')
	{
		s->item_counter++;
		s->map[s->py][s->px + 1] = '0';
	}
	if (s->map[s->py][s->px + 1] == 'E' && s->item_counter == s->max_items)
		free_settings(s, "You have won the game!\n");
	else if (s->map[s->py][s->px + 1] == 'X')
		free_settings(s, "You have died.\n");
	if (s->map[s->py][s->px] == 'E')
		draw_image(s->px * s->res, s->py * s->res, s, 'E');
	else
		draw_image(s->px * s->res, s->py * s->res, s, '0');
	draw_image((s->px + 1) * s->res, s->py * s->res, s, 3);
	s->px++;
	s->move_count++;
	mob_moves(s);
	draw_move_counter(s);
}
