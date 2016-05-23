/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgueguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 11:06:42 by hgueguen          #+#    #+#             */
/*   Updated: 2016/05/23 11:06:43 by hgueguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			direction_keys(int keycode, t_env *e, double diviseur)
{
	if (keycode == KEY_LEFT)
	{
		e->fractal_x[0] = e->fractal_x[0] - (0.2 / diviseur);
		e->fractal_x[1] = e->fractal_x[1] - (0.2 / diviseur);
	}
	else if (keycode == KEY_RIGHT)
	{
		e->fractal_x[0] = e->fractal_x[0] + (0.2 / diviseur);
		e->fractal_x[1] = e->fractal_x[1] + (0.2 / diviseur);
	}
	else if (keycode == KEY_DOWN)
	{
		e->fractal_y[0] = e->fractal_y[0] + (0.2 / diviseur);
		e->fractal_y[1] = e->fractal_y[1] + (0.2 / diviseur);
	}
	else if (keycode == KEY_UP)
	{
		e->fractal_y[0] = e->fractal_y[0] - (0.2 / diviseur);
		e->fractal_y[1] = e->fractal_y[1] - (0.2 / diviseur);
	}
}

void			zoom_keys(int keycode, t_env *e, double diviseur)
{
	int			y;
	int			x;

	x = e->mouse_pos[0] / e->win_x;
	y = e->mouse_pos[1] / e->win_y;
	if (keycode == KEY_Q)
	{
		e->fractal_y[0] = e->fractal_y[0] + (0.1 / diviseur) * 5;
		e->fractal_x[0] = e->fractal_x[0] + (0.1 / diviseur) * 5;
		e->zoom *= 1.2;
	}
	else if (keycode == KEY_W)
	{
		e->fractal_y[0] = e->fractal_y[0] - (0.1 / diviseur) * 5;
		e->fractal_x[0] = e->fractal_x[0] - (0.1 / diviseur) * 5;
		e->zoom /= 1.2;
	}
}

void			switch_key(t_env *e)
{
	if (e->fractal_id == 1)
		e->fractal_id = 2;
	else if (e->fractal_id == 2)
		e->fractal_id = 0;
	else if (e->fractal_id == 0)
		e->fractal_id = 1;
}

int				key_hook(int keycode, t_env *e)
{
	double		diviseur;

	diviseur = e->zoom / 100;
	if (keycode == 53)
		exit(0);
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT ||
		keycode == KEY_DOWN || keycode == KEY_UP)
		direction_keys(keycode, e, diviseur);
	else if (keycode == KEY_Q || keycode == KEY_W)
		zoom_keys(keycode, e, diviseur);
	else if (keycode == KEY_E)
	{
		e->fractal_y[0] = e->fractal_y[0] - 0.1;
		e->fractal_y[1] = e->fractal_y[1] - 0.1;
	}
	else if (keycode == KEY_C)
		switch_key(e);
	else if (keycode == KEY_P)
		e->motion_enabled ^= 1;
	expose_event(e);
	return (0);
}
