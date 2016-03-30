/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 18:36:21 by rdidier           #+#    #+#             */
/*   Updated: 2016/03/30 14:26:54 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int					pix_on_img(t_img *img, int x, int y, t_color *clr)
{
	int		pos;

	pos = x * img->bpp / 8 + y * img->bpl;
	img->buff[pos] = clr->b;
	img->buff[pos + 1] = clr->g;
	img->buff[pos + 2] = clr->r;
	return (0);
}

static t_color		*clr_by_type(int type, char side)
{
	t_color	*color;

	if (type == 1)
		color = new_color(255,0,0);
	else if (type == 2)
		color = new_color(0,255,0);
	else if (type == 3)
		color = new_color(0,0,255);
	else if (type == 4)
		color = new_color(255,0,255);
	else
		color = new_color(0,255,255);
	if (side)
	{
		color->r *= 0.5;
		color->g *= 0.5;
		color->b *= 0.5;
	}
	return (color);
}

void				draw_vline(t_wolfd *d, int x, int len, int type)
{
	int	i;
	int start;
	int end;

	start = - len / 2 + WINDOW_H / 2;
	end = len / 2 + WINDOW_H / 2;
	i = 0;
	if (start < 0)
		start = 0;
	if (end >= WINDOW_H)
		end = WINDOW_H -1;
	while (++i < start)
		pix_on_img(d->img, x, i, d->sky);
	i--;
	while (++i < end)
		pix_on_img(d->img, x, i, clr_by_type(type, d->ray->side));
	i--;
	while (++i < WINDOW_H)
		pix_on_img(d->img, x, i, d->ground);
}
