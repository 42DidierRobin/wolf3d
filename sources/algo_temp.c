/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_temp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 15:52:30 by rdidier           #+#    #+#             */
/*   Updated: 2016/03/29 18:29:07 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		super_main(t_wolfd *d)
{
	int			x;
	int			cam_x;
	int			hit;
	int			side;
	int			map_x;
	int			map_y;
	t_point		*step;
	t_point		*ray_pos;
	t_point		*ray_dir;
	t_point		*side_dist;
	t_point		*delt_dist;
	double		ray_size;

	step = new_point(0,0);
	ray_pos = new_point(0,0);
	ray_dir = new_point(0,0);
	side_dist = new_point(0,0);
	delt_dist = new_point(0,0);
	ray_size = 0;
	hit = 0;
	x = -1;
	while (++x < WINDOW_W)
	{
		cam_x = 2 * x / WINDOW_W - 1;
		ray_pos->x = d->player->pos->x;
		ray_pos->y = d->player->pos->y;
		ray_dir->x = d->player->dir->x;
		ray_dir->y = d->player->dir->y;
		delt_dist->x = sqrt(1 + (ray_dir->y * ray_dir->y) / (ray_dir->x * ray_dir->x));
		delt_dist->y = sqrt(1 + (ray_dir->x * ray_dir->x) / (ray_dir->y * ray_dir->y));
		map_x = (int)ray_pos->x;
		map_y = (int)ray_pos->y;
		if (ray_dir->x < 0)
		{
			step->x = -1;
			side_dist->x = (ray_pos->x - (double)map_x) * delt_dist->x;
		}
		else
		{
			step->x = 1;
			side_dist->x = ((double)map_x + 1 - ray_pos->x) * delt_dist->x;
		}
		if (ray_dir->y < 0)
		{
			step->y = -1;
			side_dist->y = (ray_pos->y - (double)map_y) * delt_dist->y;
		}
		else
		{
			step->y = 1;
			side_dist->y = ((double)map_y + 1 - ray_pos->y) * delt_dist->y;
		}
		while (!hit)
		{
			if (side_dist->x < side_dist->y)
			{
				side_dist->x += delt_dist->x;
				map_x += step->x;
				side = 0;
			}
			else
			{
				side_dist->y += delt_dist->y;
				map_y += step->y;
				side = 1;
			}
			if (d->map[map_x][map_y] > 0)
				hit = 1;
		}
		if (side == 0) 
			ray_size = ((double)map_x - ray_pos->x + (1 - step->x) / 2)
				/ ray_dir->x;
		else
			ray_size = ((double)map_y - ray_pos->y + (1 - step->y) / 2)
				/ ray_dir->y;
	
		ft_putstr("fin dun tour de lalgo");
		draw_vline(d, x, (int)ray_size, d->map[map_x][map_y]);
		printf(" + dessin en x = %d avec un rayon de %f, et type de %d \n",
				x, ray_size, d->map[map_x][map_y]);
	}
}
