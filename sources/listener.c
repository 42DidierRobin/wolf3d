/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listener.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 19:46:46 by rdidier           #+#    #+#             */
/*   Updated: 2016/03/30 13:44:11 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static char		test_move(t_player *p, int **m, int max, char sign)
{
	int	newx;
	int	newy;
	
	if (sign)
	{
		newx = p->pos->x + 0.5 * p->dir->x;
		newy = p->pos->y + 0.5 * p->dir->y;
	}
	else
	{
		newx = p->pos->x - 0.5 * p->dir->x;
		newy = p->pos->y - 0.5 * p->dir->y;
	}
	if (newx < max && newy < max && newx > 1 && newy > 1 
			&& !m[newx][newy])
		return (1);
	return (0);
}

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
	if (keycode == 126 && test_move(d->player, d->map, d->size_map, 1))
	{
		d->player->pos->x += 0.5 * d->player->dir->x;
		d->player->pos->y += 0.5 * d->player->dir->y;
	}
	else if (keycode == 125 && test_move(d->player, d->map, d->size_map, 0))
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
	algo(d);
	mlx_put_image_to_window(d->ptr, d->win, d->img->self, 0, 0);
	return (1);
}
