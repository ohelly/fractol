/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohelly <ohelly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 17:07:37 by ohelly            #+#    #+#             */
/*   Updated: 2019/06/12 17:14:31 by ohelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_color(t_fr *t, int i, int color)
{
	color = mlx_get_color_value(t->mlx, color);
	if (i == t->it_max)
		ft_memcpy((void*)t->img + t->y * 4 * WIDTH +
		t->x * 4, &color, sizeof(int));
	else
		ft_memcpy((void*)t->img + t->y * 4 * WIDTH +
		t->x * 4, &color, sizeof(int));
}

double	interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

void	applyzoom(t_fr *fr, double mousere, double mouseim, double zoomfactor)
{
	double interpolation;

	interpolation = 1.0 / zoomfactor;
	fr->remin = interpolate(mousere, fr->remin, interpolation);
	fr->immin = interpolate(mouseim, fr->immin, interpolation);
	fr->remax = interpolate(mousere, fr->remax, interpolation);
	fr->immax = interpolate(mouseim, fr->immax, interpolation);
}
