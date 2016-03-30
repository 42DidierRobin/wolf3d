/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_temp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 15:52:30 by rdidier           #+#    #+#             */
/*   Updated: 2016/03/30 10:36:19 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		super_main(t_wolfd *d)
{
	int			x;
	double		cam_x;
	t_ray		*r;

	r = new_ray();
	x = -1;
	while (++x < WINDOW_W)
	{
		cam_x = 2 * (double)x / (double)WINDOW_W - 1;
		cpy_point(r->pos, d->player->pos);
		cpy_point(r->dir, d->player->dir);
		r->ddist->x = sqrt(1 + (r->dir->y * r->dir->y) / (r->dir->x * r->dir->x));
		r->ddist->y = sqrt(1 + (r->dir->x * r->dir->x) / (r->dir->y * r->dir->y));
		r->mapx = (int)r->pos->x;
		r->mapy = (int)r->pos->y;
		if (r->dir->x < 0)
		{
			r->stepx = -1;
			r->sdist->x = (r->pos->x - (double)r->mapx) * r->ddist->x;
		}
		else
		{
			r->stepx = 1;
			r->sdist->x = ((double)r->mapx + 1 - r->pos->x) * r->ddist->x;
		}
		if (r->dir->y < 0)
		{
			r->stepy = -1;
			r->sdist->y = (r->pos->y - (double)r->mapy) * r->ddist->y;
		}
		else
		{
			r->stepy = 1;
			r->sdist->y = ((double)r->mapy + 1 - r->pos->y) * r->ddist->y;
		}
		r->touch = 0;
		while (!r->touch)
		{
			if (r->sdist->x < r->sdist->y)
			{
				r->sdist->x += r->ddist->x;
				r->mapx += (int)r->stepx;
				r->side = 0;
			}
			else
			{
				r->sdist->y += r->ddist->y;
				r->mapy += (int)r->stepy;
				r->side = 1;
			}
			if (d->map[r->mapx][r->mapy] > 0)
				r->touch = 1;
		}
		if (r->side == 0) 
			r->size = ((double)r->mapx - r->pos->x + (1 - (double)r->stepx) / 2)
				/ r->dir->x;
		else
			r->size = ((double)r->mapy - r->pos->y + (1 - (double)r->stepy) / 2)
				/ r->dir->y;
		draw_vline(d, x, (int)((double)WINDOW_H / r->size),
				d->map[r->mapx][r->mapy]);
	}
}
