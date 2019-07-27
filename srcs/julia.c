/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohelly <ohelly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 17:12:08 by ohelly            #+#    #+#             */
/*   Updated: 2019/06/12 17:12:09 by ohelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_julia(t_fr *fr)
{
	fr->it_max = 300;
	fr->color = 2050;
	fr->remax = 4;
	fr->remin = -4;
	fr->immax = 2;
	fr->immin = -2;
	fr->movx = -0.5;
	fr->movy = 0;
	fr->cre = -0.7;
	fr->cim = 0.27015;
}

void	ft_iter_julia(t_fr *t, double pr, double pi)
{
	int		i;
	double	temp;

	i = 0;
	temp = 0;
	while (i < t->it_max && pr * pr + pi * pi <= 4)
	{
		temp = pr;
		pr = temp * temp - pi * pi + t->cre;
		pi = 2 * temp * pi + t->cim;
		i++;
	}
	if (i == t->it_max)
		put_color(t, i, 0x000000);
	else
		put_color(t, i, t->color * i);
}

void	*julia_draw(void *thr)
{
	t_fr		*t;
	double		pr;
	double		pi;

	t = (t_fr*)thr;
	while (t->y < t->ymax)
	{
		t->x = 0;
		while (t->x < WIDTH)
		{
			pr = (double)t->x / (WIDTH / (t->remax - t->remin)) +
			t->remin + t->movx;
			pi = (double)t->y / (HEIGHT / (t->immax - t->immin)) +
			t->immin + t->movy;
			ft_iter_julia(t, pr, pi);
			t->x++;
		}
		t->y++;
	}
	pthread_exit(0);
}

int		julia_thread(t_fr *fr)
{
	pthread_t		p[NUM_THREADS];
	t_fr			t[NUM_THREADS];
	int				i;

	i = -1;
	while (++i < NUM_THREADS)
	{
		fr->y = i * HEIGHT / NUM_THREADS;
		fr->x = 0;
		fr->ymax = (i + 1) * HEIGHT / NUM_THREADS;
		ft_memcpy((void*)&t[i], (void*)fr, sizeof(t_fr));
		pthread_create(&p[i], NULL, julia_draw, (void*)&t[i]);
	}
	while (i--)
		pthread_join(p[i], NULL);
	mlx_put_image_to_window(fr->mlx, fr->win, fr->pic, 0, 0);
	return (0);
}
