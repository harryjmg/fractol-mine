/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgueguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 12:49:36 by hgueguen          #+#    #+#             */
/*   Updated: 2016/05/23 12:49:40 by hgueguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				mouse_hook(int button, int x, int y, t_env *e)
{
	double		diviseur;

	x = x / e->win_x;
	y = y / e->win_y;
	diviseur = e->zoom / 100;
	if (button == 4)
	{
		e->fractal_y[0] = e->fractal_y[0] + (0.1 / diviseur) * 5;
		e->fractal_x[0] = e->fractal_x[0] + (0.1 / diviseur) * 5;
		e->zoom *= 1.2;
	}
	else if (button == 3)
	{
		e->fractal_y[0] = e->fractal_y[0] - (0.1 / diviseur) * 5;
		e->fractal_x[0] = e->fractal_x[0] - (0.1 / diviseur) * 5;
		e->zoom /= 1.2;
	}
	expose_event(e);
	return (0);
}
