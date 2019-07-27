/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohelly <ohelly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:43:06 by ohelly            #+#    #+#             */
/*   Updated: 2019/06/15 19:31:09 by ohelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include "const.h"
# include <ctype.h>
# include "libft.h"
# include <math.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <unistd.h>

typedef struct		s_fr
{
	void			*mlx;
	void			*win;
	void			*pic;
	void			*img;
	int				it_max;
	int				app;
	int				bits;
	int				en;
	int				sl;
	int				color;
	int				y;
	int				x;
	int				block;
	double			ymax;
	double			remin;
	double			remax;
	double			immin;
	double			immax;
	double			movx;
	double			movy;
	double			cre;
	double			cim;
}					t_fr;

void				init_mandelbrot(t_fr *fr);
void				init_julia(t_fr *fr);
void				init_burningship(t_fr *fr);
void				fract_calc(t_fr *fr);
void				put_color(t_fr *t, int i, int color);
void				applyzoom(t_fr *fr, double mousere, double mouseim,
					double zoomfactor);
void				ft_empty(t_fr *fr);
void				ft_launch_fract(t_fr *fr);
int					key_realease(int key, t_fr *fr);
int					mouse_move_julia(int x, int y, t_fr *fr);
int					cloose(t_fr *fr);
int					mandelbrot_thread(t_fr *fr);
int					key_press(int x, t_fr *fr);
int					mouse_press(int button, int x, int y, t_fr *fr);
int					ft_clear(t_fr *fr);
int					julia_thread(t_fr *fr);
int					burningship_thread(t_fr *fr);
double				interpolate(double start, double end, double interpolation);

#endif
