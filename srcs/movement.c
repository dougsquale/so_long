/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 04:34:58 by dbelpaum          #+#    #+#             */
/*   Updated: 2022/03/30 14:03:44 by dbelpaum         ###   ########.fr       */
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

void	move_up(int keycode, t_settings *settings)
{
	if (!is_valid_move(keycode, settings))
		return ;
	if (settings->map[settings->py - 1][settings->px] == 'C')
	{
		settings->item_counter++;
		settings->map[settings->py - 1][settings->px] = '0';
	}
	if (settings->map[settings->py - 1][settings->px] == 'E'
		&& settings->item_counter == settings->max_items)
		free_settings(settings, "You have won the game!\n");
	if (settings->map[settings->py][settings->px] == 'E')
		draw_image(settings->px * settings->res,
			settings->py * settings->res, settings, 'E');
	else
		draw_image(settings->px * settings->res,
			settings->py * settings->res, settings, '0');
	draw_image(settings->px * settings->res,
		(settings->py - 1) * settings->res, settings, 'P');
	settings->py--;
	settings->move_count++;
	draw_move_counter(settings);
}

void	move_left(int keycode, t_settings *settings)
{
	if (!is_valid_move(keycode, settings))
		return ;
	if (settings->map[settings->py][settings->px - 1] == 'C')
	{
		settings->item_counter++;
		settings->map[settings->py][settings->px - 1] = '0';
	}
	if (settings->map[settings->py][settings->px - 1] == 'E'
		&& settings->item_counter == settings->max_items)
		free_settings(settings, "You have won the game!\n");
	if (settings->map[settings->py][settings->px] == 'E')
		draw_image(settings->px * settings->res,
			settings->py * settings->res, settings, 'E');
	else
		draw_image(settings->px * settings->res,
			settings->py * settings->res, settings, '0');
	draw_image((settings->px - 1) * settings->res,
		settings->py * settings->res, settings, 'P');
	settings->px--;
	settings->move_count++;
	draw_move_counter(settings);
}

void	move_down(int keycode, t_settings *settings)
{
	if (!is_valid_move(keycode, settings))
		return ;
	if (settings->map[settings->py + 1][settings->px] == 'C')
	{
		settings->item_counter++;
		settings->map[settings->py + 1][settings->px] = '0';
	}
	if (settings->map[settings->py + 1][settings->px] == 'E'
		&& settings->item_counter == settings->max_items)
		free_settings(settings, "You have won the game!\n");
	if (settings->map[settings->py][settings->px] == 'E')
		draw_image(settings->px * settings->res,
			settings->py * settings->res, settings, 'E');
	else
		draw_image(settings->px * settings->res,
			settings->py * settings->res, settings, '0');
	draw_image(settings->px * settings->res,
		(settings->py + 1) * settings->res, settings, 'P');
	settings->py++;
	settings->move_count++;
	draw_move_counter(settings);
}

void	move_right(int keycode, t_settings *settings)
{
	if (!is_valid_move(keycode, settings))
		return ;
	if (settings->map[settings->py][settings->px + 1] == 'C')
	{
		settings->item_counter++;
		settings->map[settings->py][settings->px + 1] = '0';
	}
	if (settings->map[settings->py][settings->px + 1] == 'E'
		&& settings->item_counter == settings->max_items)
		free_settings(settings, "You have won the game!\n");
	if (settings->map[settings->py][settings->px] == 'E')
		draw_image(settings->px * settings->res,
			settings->py * settings->res, settings, 'E');
	else
		draw_image(settings->px * settings->res,
			settings->py * settings->res, settings, '0');
	draw_image((settings->px + 1) * settings->res,
		settings->py * settings->res, settings, 'P');
	settings->px++;
	settings->move_count++;
	draw_move_counter(settings);
}
