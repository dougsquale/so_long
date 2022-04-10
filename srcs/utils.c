/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 03:02:48 by dbelpaum          #+#    #+#             */
/*   Updated: 2022/04/08 10:29:21 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_player_pos(t_settings *settings)
{
	int	i;

	i = -1;
	while (++i < settings->width * settings->height)
	{
		if (settings->map[i / settings->width][i % settings->width] == 'P')
		{
			settings->px = i % settings->width;
			settings->py = i / settings->width;
			return ;
		}
	}
}

void	draw_move_counter(t_settings *settings)
{
	char	*counter;

	counter = ft_itoa(settings->move_count);
	if (!counter)
		free_settings(settings, "Error\nmalloc failed\n");
	write(1, "Move counter: ", 14);
	write(1, counter, ft_strlen(counter));
	write(1, "\r", 1);
	draw_image(0, 0, settings, '1');
	draw_image(settings->res, 0, settings, '1');
	draw_image(settings->res * 2, 0, settings, '1');
	if (settings->res == 16)
	{
		draw_image(settings->res * 3, 0, settings, '1');
		draw_image(settings->res * 4, 0, settings, '1');
	}
	mlx_string_put(settings->mlx_ptr, settings->win_ptr,
		settings->res / 4, settings->res / 1.5, 0xFFFFFFFF, counter);
	free(counter);
}

void	count_max_items(t_settings *settings)
{
	int	i;

	i = -1;
	while (++i < settings->width * settings->height)
		if (settings->map[i / settings->width][i % settings->width] == 'C')
			settings->max_items++;
}
