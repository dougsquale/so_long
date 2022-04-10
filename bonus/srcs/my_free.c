/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 21:08:19 by dbelpaum          #+#    #+#             */
/*   Updated: 2022/04/09 14:12:46 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_str_array(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
	str = NULL;
}

int	red_cross_exit(t_settings *settings)
{
	free_settings(settings, "You have exited the game.\n");
	return (0);
}

static void	kill_window(t_settings *settings)
{
	mlx_clear_window(settings->mlx_ptr, settings->win_ptr);
	mlx_destroy_window(settings->mlx_ptr, settings->win_ptr);
	mlx_destroy_display(settings->mlx_ptr);
	if (settings->mlx_ptr)
		free(settings->mlx_ptr);
}

void	free_settings(t_settings *settings, char *msg)
{
	int	i;

	i = -1;
	while (settings->map[++i])
		free(settings->map[i]);
	free(settings->map);
	if (settings->wall)
		mlx_destroy_image(settings->mlx_ptr, settings->wall);
	if (settings->item)
		mlx_destroy_image(settings->mlx_ptr, settings->item);
	if (settings->exit)
		mlx_destroy_image(settings->mlx_ptr, settings->exit);
	i = -1;
	while (++i < 4)
		mlx_destroy_image(settings->mlx_ptr, settings->character[i]);
	if (settings->tile)
		mlx_destroy_image(settings->mlx_ptr, settings->tile);
	if (settings->mob)
		mlx_destroy_image(settings->mlx_ptr, settings->mob);
	if (settings->mlx_ptr && settings->win_ptr)
		kill_window(settings);
	free(settings);
	write(1, msg, ft_strlen(msg));
	exit(1);
}
