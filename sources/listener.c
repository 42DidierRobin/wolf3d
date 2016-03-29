/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listener.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 19:46:46 by rdidier           #+#    #+#             */
/*   Updated: 2016/03/29 20:55:50 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void		turn(int keycode, t_wolfd *d,
						double old_dirx, double old_planex)
{
	if (keycode == 124)
	{
		d->player->dir->x = old_dirx * cos(-ROTSPEED)
							- d->player->dir->y * sin(-ROTSPEED);
		d->player->dir->y = old_dirx * sin(-ROTSPEED)
							+ d->player->dir->y * cos(-ROTSPEED);
		d->player->plane->x = old_planex * cos(-ROTSPEED)
							- d->player->plane->y * sin(-ROTSPEED);
		d->player->plane->y = old_planex * sin(-ROTSPEED)
							+ d->player->plane->y * cos(-ROTSPEED);
	}
	else if (keycode == 123)
	{
		d->player->dir->x = old_dirx * cos(ROTSPEED)
							- d->player->dir->y * sin(ROTSPEED);
		d->player->dir->y = old_dirx * sin(ROTSPEED)
							+ d->player->dir->y * cos(ROTSPEED);
		d->player->plane->x = old_planex * cos(ROTSPEED)
							- d->player->plane->y * sin(ROTSPEED);
		d->player->plane->y = old_planex * sin(ROTSPEED)
							+ d->player->plane->y * cos(ROTSPEED);
	}
}

static void		move(int keycode, t_wolfd *d)
{
	//pas de securite pour linstant
	if (keycode == 126)
	{
		d->player->pos->x += d->player->dir->x;
		d->player->pos->y += d->player->dir->y;
	}
	else if (keycode == 125)
	{
		d->player->pos->x -= d->player->dir->x;
		d->player->pos->y -= d->player->dir->y;
	}
}

int			listener(int keycode, void *data)
{
	t_wolfd	*d;

	d = (t_wolfd*)data;
	if (keycode == 53)
	{
		mlx_destroy_window(d->ptr, d->win);
		mlx_destroy_image(d->ptr, d->img->self);
		exit(0);
	}
	move(keycode, d);
	turn(keycode, d, d->player->dir->x, d->player->plane->x);
	mlx_clear_window(d->ptr, d->win);
	super_main(d);
	mlx_put_image_to_window(d->ptr, d->win, d->img->self, 0, 0);
	return (1);
}
