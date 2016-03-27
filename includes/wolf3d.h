/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 18:33:07 by rdidier           #+#    #+#             */
/*   Updated: 2016/03/27 21:39:49 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FRACTOL_H
# define __FRACTOL_H

# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include "../libft/libft.h"
# include <mlx.h>

//TEMP
# include <stdio.h>
//TEMP

# define WINDOW_H 		800
# define WINDOW_W	 	800

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

typedef struct		s_wolfd
{
	int				size_map;
	//int				nbrw;
	int				**map;
	void			*ptr;
	void			*win;
	t_img			*img;
}					t_wolfd;

int					launch_it(char *argv);
int					read_it(char *file_name, t_wolfd *d);
#endif
