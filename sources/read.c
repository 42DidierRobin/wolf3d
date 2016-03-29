/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 19:53:40 by rdidier           #+#    #+#             */
/*   Updated: 2016/03/29 15:41:39 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static int	read_help(int *lmap, int size, char *read)
{
	int		i;
	char	**split_ret;

	i = -1;
	split_ret = ft_strsplit((char const*)read, SEPARATOR);
	while (split_ret[++i])
		;
	if (i != size)
		return (0);
	i = -1;
	while (++i < size)
		lmap[i] = ft_atoi(split_ret[i]);
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
	if (!line || !line[0] || !(d->size_map = ft_atoi(line)))
		return (0);
	d->map = (int**)malloc(sizeof(int*) * d->size_map);
	while ((gnl_ret = get_next_line(fd, &line)))
	{
		d->map[i] = (int*)malloc(sizeof(int) * d->size_map);
		if (!read_help(d->map[i], d->size_map, line))
			return (0);
		i++;
	}	
	return (1);
}
