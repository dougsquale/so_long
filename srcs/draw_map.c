/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 21:59:04 by dbelpaum          #+#    #+#             */
/*   Updated: 2022/03/30 14:12:02 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	set_ptrs_null(t_settings *settings)
{
	settings->wall = NULL;
	settings->item = NULL;
	settings->exit = NULL;
	settings->character = NULL;
	settings->tile = NULL;
	settings->win_ptr = NULL;
}

void	init_window_16(t_settings *settings)
{
	set_ptrs_null(settings);
	settings->res = 16;
	settings->mlx_ptr = mlx_init();
	if (!settings->mlx_ptr)
		free_settings(settings, "Error\nmlx_init() failed\n");
	settings->wall = mlx_xpm_file_to_image(settings->mlx_ptr, WALL_16,
			&settings->res, &settings->res);
	settings->item = mlx_xpm_file_to_image(settings->mlx_ptr, ITEM_16,
			&settings->res, &settings->res);
	settings->exit = mlx_xpm_file_to_image(settings->mlx_ptr, EXIT_16,
			&settings->res, &settings->res);
	settings->character = mlx_xpm_file_to_image(settings->mlx_ptr,
			CHARACTER_16, &settings->res, &settings->res);
	settings->tile = mlx_xpm_file_to_image(settings->mlx_ptr, TILE_16,
			&settings->res, &settings->res);
	settings->win_ptr = mlx_new_window(settings->mlx_ptr, settings->width * 16,
			settings->height * 16, "so_long");
	if (!settings->mlx_ptr || !settings->wall || !settings->item
		|| !settings->exit || !settings->character || !settings->tile
		|| !settings->win_ptr)
		free_settings(settings, "Error\nfailed to fetch sprites\n");
}

void	init_window_32(t_settings *settings)
{
	set_ptrs_null(settings);
	settings->res = 32;
	settings->mlx_ptr = mlx_init();
	if (!settings->mlx_ptr)
		free_settings(settings, "Error\nmlx_init() failed\n");
	settings->wall = mlx_xpm_file_to_image(settings->mlx_ptr, WALL_32,
			&settings->res, &settings->res);
	settings->item = mlx_xpm_file_to_image(settings->mlx_ptr, ITEM_32,
			&settings->res, &settings->res);
	settings->exit = mlx_xpm_file_to_image(settings->mlx_ptr, EXIT_32,
			&settings->res, &settings->res);
	settings->character = mlx_xpm_file_to_image(settings->mlx_ptr,
			CHARACTER_32, &settings->res, &settings->res);
	settings->tile = mlx_xpm_file_to_image(settings->mlx_ptr, TILE_32,
			&settings->res, &settings->res);
	settings->win_ptr = mlx_new_window(settings->mlx_ptr, settings->width * 32,
			settings->height * 32, "so_long");
	if (!settings->mlx_ptr || !settings->wall || !settings->item
		|| !settings->exit || !settings->character || !settings->tile
		|| !settings->win_ptr)
		free_settings(settings, "Error\nfailed to fetch sprites\n");
}

void	draw_map(t_settings *settings)
{
	int	i;

	get_player_pos(settings);
	count_max_items(settings);
	if (settings->width > 100 || settings->height > 30)
		init_window_16(settings);
	else
		init_window_32(settings);
	i = -1;
	while (++i < settings->width * settings->height)
		draw_image((i % settings->width) * settings->res, (i / settings->width)
			* settings->res, settings,
			settings->map[i / settings->width][i % settings->width]);
	draw_move_counter(settings);
	mlx_key_hook(settings->win_ptr, key_hook, settings);
	mlx_hook(settings->win_ptr, 17, (0L), red_cross_exit, settings);
	mlx_loop(settings->mlx_ptr);
}

void	draw_image(int x, int y, t_settings *settings, char c)
{
	if (c == '1')
		mlx_put_image_to_window(settings->mlx_ptr, settings->win_ptr,
			settings->wall, x, y);
	if (c == 'C')
		mlx_put_image_to_window(settings->mlx_ptr, settings->win_ptr,
			settings->item, x, y);
	if (c == 'E')
		mlx_put_image_to_window(settings->mlx_ptr, settings->win_ptr,
			settings->exit, x, y);
	if (c == 'P')
		mlx_put_image_to_window(settings->mlx_ptr, settings->win_ptr,
			settings->character, x, y);
	if (c == '0')
		mlx_put_image_to_window(settings->mlx_ptr, settings->win_ptr,
			settings->tile, x, y);
}
