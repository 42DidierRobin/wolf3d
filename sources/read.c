/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 19:53:40 by rdidier           #+#    #+#             */
/*   Updated: 2016/04/01 18:21:34 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static int	read_help(int *lmap, int size, char *read)
{
	int		i;
	int		temp;
	char	**split_ret;

	i = -1;
	split_ret = ft_strsplit((char const*)read, SEPARATOR);
	while (split_ret[++i])
		;
	if (i != size)
		return (0);
	i = -1;
	while (++i < size)
	{
		temp = ft_atoi(split_ret[i]);
		if (temp < 0)
			return (0);
		lmap[i] = temp;
	}
	return (1);
}

static int	get_map_info(t_wolfd *d, char *line)
{
	int		i;
	char	**split_ret;

	i = -1;
	split_ret = ft_strsplit((char const*)line, SEPARATOR);
	while (split_ret[++i])
		;
	if (i != 3)
		return (0);
	if (!(d->size_map = ft_atoi(split_ret[0]))
						|| d->size_map < 4)
		return (0);
	d->player->pos->x = ft_atoi(split_ret[1]);
	d->player->pos->y = ft_atoi(split_ret[2]);
	d->player->pos->x += (d->player->pos->x <= d->size_map / 2) ? 0.4 : -0.6;
	d->player->pos->y += (d->player->pos->y <= d->size_map / 2) ? 0.4 : -0.6;
	if (d->player->pos->y < d->size_map / 2)
		d->player->pos->x += 0.5;
	if (d->player->pos->x > d->size_map
			|| d->player->pos->y > d->size_map
			|| d->player->pos->x < 0
			|| d->player->pos->y < 0)
		return (0);
	return (1);
}

static int	check_map(int **map, int size)
{
	int x;
	int y;

	x = 0;
	y = -1;
	while (++y < size)
		if (!(map[x][y] == 1))
			return (0);
	x = size - 1;
	y = -1;
	while (++y < size)
		if (!(map[x][y] == 1))
			return (0);
	y = 0;
	x = -1;
	while (++x < size)
		if (!(map[x][y] == 1))
			return (0);
	y = size - 1;
	while (++x < size)
		if (!(map[x][y] == 1))
			return (0);
	return (1);
}

int			read_it(char *file_name, t_wolfd *d)
{
	int		gnl_ret;
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(file_name, O_RDONLY);
	gnl_ret = get_next_line(fd, &line);
	if (!line || !line[0] || !(get_map_info(d, line)))
		return (0);
	d->map = (int**)malloc(sizeof(int*) * d->size_map);
	while ((gnl_ret = get_next_line(fd, &line)))
	{
		d->map[i] = (int*)malloc(sizeof(int) * d->size_map);
		if (!read_help(d->map[i], d->size_map, line))
			return (0);
		i++;
	}
	if (i == d->size_map
		&& !(d->map[(int)d->player->pos->x][(int)d->player->pos->y])
		&& check_map(d->map, d->size_map))
		return (1);
	return (0);
}
