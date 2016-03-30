/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 18:33:07 by rdidier           #+#    #+#             */
/*   Updated: 2016/03/30 16:32:23 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FRACTOL_H
# define __FRACTOL_H

# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <time.h>
# include "../libft/libft.h"
# include <mlx.h>

//TEMP
# include <stdio.h>
//TEMP

# define SEPARATOR		' '
# define KEY_EVENT		2
# define KEY_MASK		(1L<<0)
# define FPS			100
# define WINDOW_H 		768
# define WINDOW_W	 	1024
# define ROTSPEED		0.05

typedef unsigned char	t_uchar;

typedef struct		s_color
{
	t_uchar			r;
	t_uchar			g;
	t_uchar			b;
}					t_color;

typedef struct		s_img
{
	void			*self;
	char			*buff;
	int				bpp;
	int				bpl;
	int				endian;
}					t_img;

typedef struct		s_point
{
	double			x;
	double			y;
}					t_point;

typedef struct		s_player
{
	t_point			*pos;
	t_point			*dir;
	t_point			*plane;
}					t_player;

typedef struct		s_ray
{
	char			touch;
	char			side;
	char			stepx;
	char			stepy;
	int				mapx;
	int				mapy;
	double			size;
	t_point			*pos;
	t_point			*dir;
	t_point			*sdist;
	t_point			*ddist;
}					t_ray;

typedef struct		s_wolfd
{
	char			code[4];
	t_ray			*ray;
	t_color			*sky;
	t_color			*ground;
	t_player		*player;
	int				size_map;
	//int				nbrw;
	int				**map;
	void			*ptr;
	void			*win;
	t_img			*img;
}					t_wolfd;

int					listener(int keycode, void *d);

void				algo(t_wolfd *d);

int					pix_on_img(t_img *img, int x, int y, t_color *clr);
void				draw_vline(t_wolfd *d, int x, int len, int type);
int					loop(t_wolfd *d);
int					launch_it(char *argv);
int					read_it(char *file_name, t_wolfd *d);
void				move(char *code, t_wolfd *d);
void				turn(char *code, t_wolfd *d, double olddx, double olddy);
t_point				*new_point(double x, double y);
t_color				*new_color(t_uchar r, t_uchar g, t_uchar b);
t_player			*new_player(t_point *pos, t_point *dir, t_point *plane);
t_ray				*new_ray();
void				cpy_point(t_point *a, t_point *b);
#endif
