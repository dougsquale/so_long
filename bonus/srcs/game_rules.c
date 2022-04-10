/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 01:54:15 by dbelpaum          #+#    #+#             */
/*   Updated: 2022/03/20 13:38:18 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_valid_move(int keycode, t_settings *settings)
{
	if (keycode == UP_KEY && settings->py > 0
		&& settings->map[settings->py - 1][settings->px] != '1')
		return (1);
	else if (keycode == DOWN_KEY && settings->py < settings->height - 1
		&& settings->map[settings->py + 1][settings->px] != '1')
		return (1);
	else if (keycode == LEFT_KEY && settings->px > 0
		&& settings->map[settings->py][settings->px - 1] != '1')
		return (1);
	else if (keycode == RIGHT_KEY && settings->px < settings->width - 1
		&& settings->map[settings->py][settings->px + 1] != '1')
		return (1);
	return (0);
}
