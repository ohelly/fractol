/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohelly <ohelly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 17:11:15 by ohelly            #+#    #+#             */
/*   Updated: 2019/06/12 17:11:16 by ohelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		cloose(t_fr *fr)
{
	mlx_clear_window(fr->mlx, fr->win);
	mlx_destroy_image(fr->mlx, fr->pic);
	mlx_destroy_window(fr->mlx, fr->win);
	ft_clear(fr);
	exit(0);
	return (0);
}

int		ft_clear(t_fr *fr)
{
	if (!fr)
		return (0);
	free(fr);
	return (0);
}
