/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 19:37:27 by dbelpaum          #+#    #+#             */
/*   Updated: 2022/04/08 12:20:36 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	is_rectangle_map(char **content)
{
	int	i;
	int	first_length;

	if (!content || !content[0])
		return (0);
	first_length = ft_strlen(content[0]);
	i = -1;
	while (content[++i])
		if ((int)ft_strlen(content[i]) != first_length)
			return (0);
	return (1);
}

static int	has_valid_borders(char **content)
{
	int	i;
	int	height;
	int	width;

	i = -1;
	while (content[0][++i])
		if (content[0][i] != '1')
			return (0);
	i = -1;
	while (content[++i] != NULL)
		;
	height = i - 1;
	i = -1;
	while (content[height][++i])
		if (content[height][i] != '1')
			return (0);
	i = 0;
	width = ft_strlen(content[0]);
	while (++i < height)
		if (content[i][0] != '1' || content[i][width - 1] != '1')
			return (0);
	return (1);
}

static int	has_valid_elements(char **content)
{
	int	i;
	int	element_counter[3];

	i = 0;
	element_counter[0] = 0;
	element_counter[1] = 0;
	element_counter[2] = 0;
	while (content[++i + 1])
	{
		if (ft_strchr(content[i], 'P') != NULL)
			element_counter[0]++;
		if (ft_strchr(content[i], 'E') != NULL)
			element_counter[1]++;
		if (ft_strchr(content[i], 'C') != NULL)
			element_counter[2]++;
	}
	if (element_counter[0] != 1 || element_counter[1] == 0
		|| element_counter[2] == 0)
		return (0);
	return (1);
}

char	**read_file(char *filename)
{
	int		fd;
	int		bytes_read;
	char	*read_buffer;
	char	*oneline_content;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	read_buffer = (char *)malloc(sizeof(char) * (READ_BUFFER_SIZE + 1));
	if (!read_buffer)
		return (NULL);
	bytes_read = 1;
	oneline_content = NULL;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, read_buffer, READ_BUFFER_SIZE);
		read_buffer[bytes_read] = 0;
		oneline_content = ft_strjoin(oneline_content, read_buffer);
		if (!oneline_content)
			return (free(read_buffer), NULL);
	}
	free(read_buffer);
	close(fd);
	return (ft_split(oneline_content, '\n'));
}

int	is_valid_map(char *filename)
{
	char	**content;
	int		i;
	int		j;

	if (!ft_strnstr(filename, ".ber", INT_MAX))
		return (0);
	content = read_file(filename);
	if (!content)
		return (0);
	if (!is_rectangle_map(content) || !has_valid_borders(content)
		|| !has_valid_elements(content))
		return (free_str_array(content), 0);
	if (!content)
		return (0);
	i = -1;
	while (content[++i])
	{
		j = -1;
		while (content[i][++j])
			if (content[i][j] != '0' && content[i][j] != '1' && content[i][j]
				!= 'E' && content[i][j] != 'P' && content[i][j] != 'C'
				&& content[i][j] != 'X')
				return (0);
	}
	return (free_str_array(content), 1);
}
