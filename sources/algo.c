/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_temp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 15:52:30 by rdidier           #+#    #+#             */
/*   Updated: 2016/04/01 15:53:44 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void		dda(t_wolfd *d, t_ray *r)
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

static void		give_steps(t_ray *r)
{
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
}

void			algo(t_wolfd *d)
{
	int			x;
	double		xi;
	t_ray		*r;

	r = d->ray;
	x = -1;
	printf("direction player : (%f, %f)\n", d->player->dir->x, d->player->dir->y);
	while (++x < WINDOW_W)
	{
		xi = 2 * (double)x / (double)WINDOW_W - 1;
		cpy_point(r->pos, d->player->pos);
		r->dir->x = d->player->dir->x + d->player->plane->x * xi;
		r->dir->y = d->player->dir->y + d->player->plane->y * xi;
		r->ddist->x = sqrt(1 + (pow(r->dir->y, 2) / pow(r->dir->x, 2)));
		r->ddist->y = sqrt(1 + (pow(r->dir->x, 2) / pow(r->dir->y, 2)));
		r->mapx = (int)r->pos->x;
		r->mapy = (int)r->pos->y;
		give_steps(r);
		r->touch = 0;
		while (!(r->touch))
			dda(d, r);
		if (!r->side) 
			r->size = (r->mapx - r->pos->x + (1 - r->stepx) / 2) / r->dir->x;
		else
			r->size = (r->mapy - r->pos->y + (1 - r->stepy) / 2) / r->dir->y;
		draw_vline(d, x, (int)((WINDOW_H / r->size)));
	}
}
