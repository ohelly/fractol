/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohelly <ohelly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:12:50 by ohelly            #+#    #+#             */
/*   Updated: 2019/06/15 19:24:23 by ohelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fract_calc(t_fr *fr)
{
	if (fr->app == 1)
		mandelbrot_thread(fr);
	if (fr->app == 2)
		julia_thread(fr);
	if (fr->app == 3)
		burningship_thread(fr);
}

void	ft_launch_fract(t_fr *fr)
{
	if (fr->app == 1)
		init_mandelbrot(fr);
	if (fr->app == 2)
		init_julia(fr);
	if (fr->app == 3)
		init_burningship(fr);
	if (fr->app == 0)
		ft_empty(fr);
	fract_calc(fr);
}

int		ft_init_struct(t_fr *fr)
{
	if (!(fr->mlx = mlx_init()))
		return (0);
	if (!(fr->win = mlx_new_window(fr->mlx, WIDTH, HEIGHT, "fractol")))
		return (0);
	if (!(fr->pic = mlx_new_image(fr->mlx, WIDTH, HEIGHT)))
		return (0);
	if (!(fr->img = mlx_get_data_addr(fr->pic, &fr->bits, &fr->sl, &fr->en)))
		return (0);
	ft_launch_fract(fr);
	return (1);
}

int		ft_init_fractol(t_fr *fr, char *av)
{
	if ((ft_strcmp(av, "Mandelbrot")) == 0)
		fr->app = 1;
	else if ((ft_strcmp(av, "Julia")) == 0)
		fr->app = 2;
	else if ((ft_strcmp(av, "Burningship")) == 0)
		fr->app = 3;
	return (1);
}

int		main(int ac, char **av)
{
	t_fr	*fr;

	if (!(fr = (t_fr*)ft_memalloc(sizeof(t_fr))))
		return (0);
	if (ac == 2)
		if (!(ft_init_fractol(fr, av[1])))
			return (ft_clear(fr));
	if (!(ft_init_struct(fr)))
		return (ft_clear(fr));
	mlx_hook(fr->win, 4, 0, mouse_press, (void*)fr);
	mlx_hook(fr->win, 3, 0, key_realease, (void*)fr);
	mlx_hook(fr->win, 2, 0, key_press, (void*)fr);
	mlx_hook(fr->win, 6, 0, mouse_move_julia, (void*)fr);
	mlx_hook(fr->win, 17, 0, cloose, (void*)fr);
	mlx_loop(fr->mlx);
	return (ft_clear(fr));
}
