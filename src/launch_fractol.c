
#include "fractol.h"

static void		launch_hook(t_env *e)
{
	mlx_expose_hook(e->win, expose_hook, e);
	//mlx_hook(e.win, MotionNotify, PointerMotionMask, motion_hook, &e);
	mlx_key_hook(e->win, key_hook, e);
	mlx_hook(e->win, MotionNotify, PointerMotionMask, motion_hook, e);
	//mlx_loop_hook(e->mlx, loop_hook, e);
}

static void		init_win(t_env *e)
{
	e->fractal_x[0] = -1;
	e->fractal_x[1] = 1;
	e->fractal_y[0] = -1.2;
	e->fractal_y[1] = 1.2;

	e->zoom = INITIAL_ZOOM;
	e->win_x = (e->fractal_x[1] - e->fractal_x[0]) * e->zoom;
	e->win_y = (e->fractal_y[1] - e->fractal_y[0]) * e->zoom;
	e->win = mlx_new_window(e->mlx, e->win_x, e->win_y, WINDOW_NAME);
}

static void		translate_colors_to_rgb(t_env *e)
{
	int 	 	i;
	int 		color;
	int 		tmp;

	i = 0;
	while (i < DETAIL+ 1)
	{
		if (i == 0)
			color = COLOR_1;
		else if (i == 1)
			color = COLOR_2;
		else if (i == 2)
			color = COLOR_3;
		else if (i == 3)
			color = COLOR_4;
		else if (i == 4)
			color = COLOR_5;
		else if (i == 5)
			color = COLOR_6;
		else if (i == 6)
			color = COLOR_7;
		else if (i == 7)
			color = COLOR_8;
		else if (i == 8)
			color = COLOR_9;
		else if (i == 9)
			color = COLOR_10;
		else if (i == 10)
			color = COLOR_11;
		else
			printf("fucked up\n");
		tmp = color / (256 * 256);
		color = color % (256 * 256);
		e->color[i][0] = tmp;
		tmp = color / 256;
		color = color % 256;
		e->color[i][1] = tmp;
		tmp = color / 1;
		e->color[i][2] = tmp;
		i++;
	}
}

static int 		color_mix(t_env *e, int relative, int i_color)
{
	// relative va de 	0 a 19		position entre les deux couleurs
	// i_color va de 	0 a 4 		quelles sont ces deux couleurs
	int 		pas[3];
	int 		color;
	int 		rgb[3];

	//if (i_color > 8)
	//	printf("TELL ME %d\n",i_color);
	pas[0] = (e->color[i_color][0] - e->color[i_color + 1][0]) / e->inter_color;
	pas[1] = (e->color[i_color][1] - e->color[i_color + 1][1]) / e->inter_color;
	pas[2] = (e->color[i_color][2] - e->color[i_color + 1][2]) / e->inter_color;

	rgb[0] = e->color[i_color][0] - (pas[0] * relative);
	rgb[1] = e->color[i_color][1] - (pas[1] * relative);
	rgb[2] = e->color[i_color][2] - (pas[2] * relative);

	color = RGB(rgb[0], rgb[1], rgb[2]);

	return (color);
}

static void		fill_color_val(t_env *e)
{
	int 		i;
	int 		j;
	int 		k;

	translate_colors_to_rgb(e);
	k = 0;
	j = 0;
	while (j < DETAIL)
	{
		i = 0;
		while (i < e->iteration / DETAIL)
		{
			e->color_val[k] = color_mix(e, i, j);
			i++;
			k++;
		}
		j++;
	}
	e->color_val[k] = RGB(255, 255, 255);
	//printf("k = %d\n", k);
}

static void		load_mandelbrot(t_env *e)
{
	e->fractal_id = 0;
	e->fractal_x[0] = -1;
	e->fractal_x[1] = 1;
	e->fractal_y[0] = -1.2;
	e->fractal_y[1] = 1.2;

	ft_bzero(e->modifier_z, 2);
	ft_bzero(e->modifier_c, 2);

	e->color_val = (int *)malloc(sizeof(int) * INITIAL_ITER + 1);
	e->inter_color = INITIAL_ITER / DETAIL;
	e->iteration = INITIAL_ITER;
	fill_color_val(e);
}

void		create_image(t_env *e)
{
	e->img = mlx_new_image(e->mlx, e->win_x, e->win_y);
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->sl), &(e->e));
}

void			launch_fractol(t_env *e)
{
	e->mlx = mlx_init();
	if (e->mlx == NULL)
		exit(0);
	load_mandelbrot(e);
	init_win(e);

	launch_hook(e);
	mlx_expose_hook(e->win, expose_hook, e);
	create_image(e);
	mlx_loop(e->mlx);
}
