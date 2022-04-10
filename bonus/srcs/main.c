/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:37:18 by dbelpaum          #+#    #+#             */
/*   Updated: 2022/03/30 14:28:34 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_settings	*get_settings(char *filename)
{
	t_settings	*settings;
	int			height;

	settings = (t_settings *)malloc(sizeof(t_settings));
	if (!settings)
		return (NULL);
	settings->map = read_file(filename);
	if (!settings->map)
		return (free(settings), NULL);
	height = -1;
	while (settings->map[++height])
		;
	settings->height = height;
	settings->width = ft_strlen(settings->map[0]);
	settings->move_count = 0;
	settings->item_counter = 0;
	settings->max_items = 0;
	return (settings);
}

int	main(int argc, char **argv)
{
	t_settings	*settings;

	if (argc != 2)
		return (write(1, "Error\nusage : ./so_long map.ber\n", 32), 1);
	if (!is_valid_map(argv[1]))
		return (write(1, "Error\ninvalid map\n", 18), 1);
	settings = get_settings(argv[1]);
	if (!settings)
		return (write(1, "Error\nfailed to read file\n", 26), 1);
	draw_map(settings);
	free_settings(settings, "");
	return (0);
}
