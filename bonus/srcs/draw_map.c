/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 21:59:04 by dbelpaum          #+#    #+#             */
/*   Updated: 2022/04/09 14:05:14 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	set_ptrs_null(t_settings *settings)
{
	settings->wall = NULL;
	settings->item = NULL;
	settings->exit = NULL;
	settings->character[0] = NULL;
	settings->character[1] = NULL;
	settings->character[2] = NULL;
	settings->character[3] = NULL;
	settings->tile = NULL;
	settings->mob = NULL;
	settings->win_ptr = NULL;
}

void	init_window_16(t_settings *s)
{
	set_ptrs_null(s);
	s->res = 16;
	s->mlx_ptr = mlx_init();
	if (!s->mlx_ptr)
		free_settings(s, "Error\nmlx_init() failed\n");
	s->wall = mlx_xpm_file_to_image(s->mlx_ptr, WALL_16, &s->res, &s->res);
	s->item = mlx_xpm_file_to_image(s->mlx_ptr, ITEM_16, &s->res, &s->res);
	s->exit = mlx_xpm_file_to_image(s->mlx_ptr, EXIT_16, &s->res, &s->res);
	s->character[0] = mlx_xpm_file_to_image(s->mlx_ptr,
			CHARACTER_1_16, &s->res, &s->res);
	s->character[1] = mlx_xpm_file_to_image(s->mlx_ptr,
			CHARACTER_2_16, &s->res, &s->res);
	s->character[2] = mlx_xpm_file_to_image(s->mlx_ptr,
			CHARACTER_3_16, &s->res, &s->res);
	s->character[3] = mlx_xpm_file_to_image(s->mlx_ptr,
			CHARACTER_4_16, &s->res, &s->res);
	s->tile = mlx_xpm_file_to_image(s->mlx_ptr, TILE_16, &s->res, &s->res);
	s->mob = mlx_xpm_file_to_image(s->mlx_ptr, MOB_16, &s->res, &s->res);
	s->win_ptr = mlx_new_window(s->mlx_ptr, s->width * 16,
			s->height * 16, "so_long");
	if (!s->mlx_ptr || !s->wall || !s->item
		|| !s->exit || !s->tile || !s->win_ptr)
		free_settings(s, "Error\nfailed to fetch sprites\n");
}

void	init_window_32(t_settings *s)
{
	set_ptrs_null(s);
	s->res = 32;
	s->mlx_ptr = mlx_init();
	if (!s->mlx_ptr)
		free_settings(s, "Error\nmlx_init() failed\n");
	s->wall = mlx_xpm_file_to_image(s->mlx_ptr, WALL_32, &s->res, &s->res);
	s->item = mlx_xpm_file_to_image(s->mlx_ptr, ITEM_32, &s->res, &s->res);
	s->exit = mlx_xpm_file_to_image(s->mlx_ptr, EXIT_32, &s->res, &s->res);
	s->character[0] = mlx_xpm_file_to_image(s->mlx_ptr,
			CHARACTER_1_32, &s->res, &s->res);
	s->character[1] = mlx_xpm_file_to_image(s->mlx_ptr,
			CHARACTER_2_32, &s->res, &s->res);
	s->character[2] = mlx_xpm_file_to_image(s->mlx_ptr,
			CHARACTER_3_32, &s->res, &s->res);
	s->character[3] = mlx_xpm_file_to_image(s->mlx_ptr,
			CHARACTER_4_32, &s->res, &s->res);
	s->tile = mlx_xpm_file_to_image(s->mlx_ptr, TILE_32, &s->res, &s->res);
	s->mob = mlx_xpm_file_to_image(s->mlx_ptr, MOB_32, &s->res, &s->res);
	s->win_ptr = mlx_new_window(s->mlx_ptr, s->width * 32,
			s->height * 32, "so_long");
	if (!s->mlx_ptr || !s->wall || !s->item
		|| !s->exit || !s->tile || !s->win_ptr)
		free_settings(s, "Error\nfailed to fetch sprites\n");
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
	settings->map[settings->py][settings->px] = '0';
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
			settings->character[0], x, y);
	if (c == '0')
		mlx_put_image_to_window(settings->mlx_ptr, settings->win_ptr,
			settings->tile, x, y);
	if (c >= 1 && c <= 4)
		mlx_put_image_to_window(settings->mlx_ptr, settings->win_ptr,
			settings->character[c - 1], x, y);
	if (c == 'X')
		mlx_put_image_to_window(settings->mlx_ptr, settings->win_ptr,
			settings->mob, x, y);
}
