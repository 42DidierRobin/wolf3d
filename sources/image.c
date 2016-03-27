/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 18:36:21 by rdidier           #+#    #+#             */
/*   Updated: 2016/03/27 18:45:35 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int			pix_on_img(t_img *img, int x, int y, t_color *clr)
{
	int		pos;

	pos = x * img->bpp / 8 + y * img->bpl;
	img->buff[pos] = clr->b;
	img->buff[pos + 1] = clr->g;
	img->buff[pos + 2] = clr->r;
	return (0);
}
