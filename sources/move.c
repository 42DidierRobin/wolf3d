/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listener.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 19:46:46 by rdidier           #+#    #+#             */
/*   Updated: 2016/04/01 15:53:35 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static char		test_move(t_player *p, int **m, int max, char sign)
{
	int	newx;
	int	newy;
	
	if (sign)
	{
		newx = p->pos->x + MOVESPEED * p->dir->x;
		newy = p->pos->y + MOVESPEED * p->dir->y;
	}
	else
	{
		newx = p->pos->x - MOVESPEED * p->dir->x;
		newy = p->pos->y - MOVESPEED * p->dir->y;
	}
	if (newx < max && newy < max && newx > 0 && newy > 0 
			&& !m[newx][newy])
		return (1);
	return (0);
}

void		turn(char *code, t_wolfd *d,
						double old_dirx, double old_planex)
{
	if (code[0])
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
	else if (code[1])
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

void		move(char *code, t_wolfd *d)
{
	if (code[2] && test_move(d->player, d->map, d->size_map, 1))
	{
		d->player->pos->x += MOVESPEED * d->player->dir->x;
		d->player->pos->y += MOVESPEED * d->player->dir->y;
	}
	else if (code[3] && test_move(d->player, d->map, d->size_map, 0))
	{
		d->player->pos->x -= MOVESPEED * d->player->dir->x;
		d->player->pos->y -= MOVESPEED * d->player->dir->y;
	}
}
