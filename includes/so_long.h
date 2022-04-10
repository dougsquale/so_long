/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:39:58 by dbelpaum          #+#    #+#             */
/*   Updated: 2022/03/30 14:08:19 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../../mlx_linux/mlx.h"
# include "../../mlx_linux/mlx_int.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define READ_BUFFER_SIZE 1024
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define WALL_16 "./sprites/16/wall.xpm"
# define ITEM_16 "./sprites/16/item.xpm"
# define CHARACTER_16 "./sprites/16/character.xpm"
# define EXIT_16 "./sprites/16/exit.xpm"
# define TILE_16 "./sprites/16/tile.xpm"
# define WALL_32 "./sprites/32/wall.xpm"
# define ITEM_32 "./sprites/32/item.xpm"
# define CHARACTER_32 "./sprites/32/character.xpm"
# define EXIT_32 "./sprites/32/exit.xpm"
# define TILE_32 "./sprites/32/tile.xpm"
# define UP_KEY 119
# define LEFT_KEY 97
# define DOWN_KEY 115
# define RIGHT_KEY 100
# define ESC_KEY 65307

typedef struct s_settings
{
	char	**map;
	int		width;
	int		height;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*wall;
	void	*item;
	void	*exit;
	void	*character;
	void	*tile;
	int		res;
	int		px;
	int		py;
	int		move_count;
	int		item_counter;
	int		max_items;
}	t_settings;

/*map_parsing.c*/
char	**read_file(char *filename);
int		is_valid_map(char *filename);

/*my_free.c*/
void	free_str_array(char **str);
int		red_cross_exit(t_settings *settings);
void	free_settings(t_settings *settings, char *msg);

/*draw_map.c*/
void	init_window_16(t_settings *settings);
void	init_window_32(t_settings *settings);
void	draw_image(int x, int y, t_settings *settings, char c);
void	draw_map(t_settings *settings);

/*utils.c*/
void	get_player_pos(t_settings *settings);
void	draw_move_counter(t_settings *settings);
void	count_max_items(t_settings *settings);

/*game_rules.c*/
int		is_valid_move(int keycode, t_settings *settings);

/*movement.c*/
int		key_hook(int keycode, t_settings *settings);
void	move_up(int keycode, t_settings *settings);
void	move_left(int keycode, t_settings *settings);
void	move_down(int keycode, t_settings *settings);
void	move_right(int keycode, t_settings *settings);

#endif