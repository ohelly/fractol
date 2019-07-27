/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohelly <ohelly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 17:12:22 by ohelly            #+#    #+#             */
/*   Updated: 2019/06/15 19:32:41 by ohelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_press_2(int x, t_fr *fr)
{
	if (x == 27 && fr->app != 0 && fr->it_max != 50)
		fr->it_max -= 50;
	if (x == 24 && fr->app != 0 && fr->it_max != 400)
		fr->it_max += 50;
	if (x == 83 && fr->app != 0)
		fr->color = 2050;
	if (x == 84 && fr->app != 0)
		fr->color = 40;
	if (x == 85 && fr->app != 0)
		fr->color = 10000;
	if (x == 86 && fr->app != 0)
		fr->color = 330000;
	if (x == 87 && fr->app != 0)
		fr->color = 460000;
	if (x == 88 && fr->app != 0)
		fr->color = 590000;
	if (x == 51)
		ft_empty(fr);
	return (0);
}

int		key_press(int x, t_fr *fr)
{
	if (x == 123 && fr->app != 0)
		fr->movx += fabs(fr->remax - fr->remin) * 0.1;
	if (x == 124 && fr->app != 0)
		fr->movx -= fabs(fr->remax - fr->remin) * 0.1;
	if (x == 125 && fr->app != 0)
		fr->movy -= fabs(fr->immax - fr->immin) * 0.1;
	if (x == 126 && fr->app != 0)
		fr->movy += fabs(fr->immax - fr->immin) * 0.1;
	if (x == 53)
		return (cloose(fr));
	key_press_2(x, fr);
	if (x == 18 || x == 19 || x == 20 || x == 15)
	{
		if (x == 18 && fr->app != 1)
			fr->app = 1;
		if (x == 19 && fr->app != 2)
			fr->app = 2;
		if (x == 20 && fr->app != 3)
			fr->app = 3;
		ft_launch_fract(fr);
	}
	else
		fract_calc(fr);
	return (0);
}

int		mouse_move_julia(int x, int y, t_fr *fr)
{
	if (fr->app == 2 && !fr->block)
	{
		fr->cre = (double)x / (WIDTH / (fr->remax - fr->remin)) + fr->remin;
		fr->cim = (double)y / (HEIGHT / (fr->immax - fr->immin)) + fr->immin;
	}
	fract_calc(fr);
	return (0);
}

int		key_realease(int key, t_fr *fr)
{
	if (key == 257 && fr->block == 0)
		fr->block = 1;
	else if (key == 257 && fr->block == 1)
		fr->block = 0;
	return (0);
}

int		mouse_press(int button, int x, int y, t_fr *fr)
{
	double	mousere;
	double	mouseim;

	mousere = (double)x / (WIDTH / (fr->remax - fr->remin)) + fr->remin;
	mouseim = (double)y / (HEIGHT / (fr->immax - fr->immin)) + fr->immin;
	if (button == 1 || button == 4)
		applyzoom(fr, mousere, mouseim, 1.2);
	if (button == 2 || button == 5)
		applyzoom(fr, mousere, mouseim, 1 / 1.2);
	fract_calc(fr);
	return (0);
}
