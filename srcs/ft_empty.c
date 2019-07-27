/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_empty.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohelly <ohelly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 16:10:49 by ohelly            #+#    #+#             */
/*   Updated: 2019/06/15 19:38:58 by ohelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_empty_manual(t_fr *fr)
{
	mlx_string_put(fr->mlx, fr->win, (WIDTH / 2) - 57, 210, 0xFFFFFF,
	"Manual for research");
	mlx_string_put(fr->mlx, fr->win, 50, 240, 0xFFFFFF,
	"Press button [1], [2] or [3] to switch fractol");
	mlx_string_put(fr->mlx, fr->win, 50, 270, 0xFFFFFF,
	"Wheel or left/right button mouse for zoom");
	mlx_string_put(fr->mlx, fr->win, 50, 300, 0xFFFFFF,
	"[1], [2], [3], [4], [5], [6] (Numpad) for change color");
	mlx_string_put(fr->mlx, fr->win, 50, 330, 0xFFFFFF,
	"Use arrows for moving");
	mlx_string_put(fr->mlx, fr->win, 50, 360, 0xFFFFFF,
	"Press [Backspace] for open manual");
	mlx_string_put(fr->mlx, fr->win, 50, 390, 0xFFFFFF, "Press [R] for reset");
	mlx_string_put(fr->mlx, fr->win, 50, 420, 0xFFFFFF,
	"Press [shift] (left) for block Julia");
	mlx_string_put(fr->mlx, fr->win, 50, 450, 0xFFFFFF,
	"Press [-] or [+] for change max.iter");
	mlx_string_put(fr->mlx, fr->win, 50, 480, 0xFFFFFF,
	"Press [ESC] for Exit");
	mlx_string_put(fr->mlx, fr->win, (WIDTH / 2) - 93, 510, 0xFFFFFF,
	"Enjoy! Fractol waiting for you!");
}

void	ft_empty(t_fr *fr)
{
	fr->app = 0;
	mlx_clear_window(fr->mlx, fr->win);
	mlx_string_put(fr->mlx, fr->win, (WIDTH / 2) - 54, 30, 0xFFFFFF,
	"Welcom to Fractol!");
	mlx_string_put(fr->mlx, fr->win, (WIDTH / 2) - 60, 60, 0xFFFFFF,
	"Choose your fighter!");
	mlx_string_put(fr->mlx, fr->win, 50, 90, 0xFFFFFF,
	"Press [1] for Mandelbrot");
	mlx_string_put(fr->mlx, fr->win, 50, 120, 0xFFFFFF, "Press [2] for Julia");
	mlx_string_put(fr->mlx, fr->win, 50, 150, 0xFFFFFF,
	"Press [3] for Burningship");
	mlx_string_put(fr->mlx, fr->win, 50, 180, 0xFFFFFF, "Press [ESC] for Exit");
	ft_empty_manual(fr);
}
