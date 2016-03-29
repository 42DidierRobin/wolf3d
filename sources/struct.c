/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 15:48:01 by rdidier           #+#    #+#             */
/*   Updated: 2016/03/29 15:51:57 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_point				*new_point(double x, double y)
{
	t_point	*ret;

	ret = (t_point*)malloc(sizeof(t_point));
	ret->x = x;
	ret->y = y;
	return (ret);
}

t_player			*new_player(t_point *pos, t_point *dir, t_point *plane)
{
	t_player	*ret;

	ret = (t_player*)malloc(sizeof(t_player));
	ret->pos = pos;
	ret->dir = dir;
	ret->plane = plane;
	return (ret);
}
