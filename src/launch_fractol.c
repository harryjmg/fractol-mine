/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_fractol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgueguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 11:06:34 by hgueguen          #+#    #+#             */
/*   Updated: 2016/05/23 11:06:35 by hgueguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		launch_hook(t_env *e)
{
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_key_hook(e->win, key_hook, e);
	mlx_mouse_hook(e->win, mouse_hook, e);
	mlx_hook(e->win, MOTION_NOTIFY, POINTER_MOTION_MASK, motion_hook, e);
}

static void		init_win(t_env *e)
{
	e->fractal_x[0] = -1.5;
	e->fractal_x[1] = 1.5;
	e->fractal_y[0] = -1.2;
	e->fractal_y[1] = 1.2;
	e->zoom = INITIAL_ZOOM;
	e->win_x = (e->fractal_x[1] - e->fractal_x[0]) * e->zoom;
	e->win_y = (e->fractal_y[1] - e->fractal_y[0]) * e->zoom;
	e->win = mlx_new_window(e->mlx, e->win_x, e->win_y, WINDOW_NAME);
}

void			create_image(t_env *e)
{
	e->img = mlx_new_image(e->mlx, e->win_x, e->win_y);
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->sl), &(e->e));
}

void			load_mandelbrot(t_env *e)
{
	e->fractal_x[0] = -1.5;
	e->fractal_x[1] = 1.5;
	e->fractal_y[0] = -1.2;
	e->fractal_y[1] = 1.2;
	ft_bzero(e->modifier_z, 2);
	ft_bzero(e->modifier_c, 2);
	e->color_val = (int *)malloc(sizeof(int) * INITIAL_ITER + 1);
	e->inter_color = INITIAL_ITER / DETAIL;
	e->iteration = INITIAL_ITER;
	fill_color_val(e);
}

void			launch_fractol(t_env *e)
{
	e->mlx = mlx_init();
	if (e->mlx == NULL)
		exit(0);
	e->motion_enabled = 1;
	load_mandelbrot(e);
	init_win(e);
	launch_hook(e);
	mlx_expose_hook(e->win, expose_hook, e);
	create_image(e);
	mlx_loop(e->mlx);
}
