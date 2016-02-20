
#include "fractol.h"

int		key_hook(int keycode, t_env *e)
{
	double 		diviseur;

	diviseur = e->zoom / 100;

	if (keycode == 53)
		exit(0);
	else if (keycode == KEY_LEFT)
	{
		e->fractal_x[0] = e->fractal_x[0] - (0.1 / diviseur);
		e->fractal_x[1] = e->fractal_x[1] - (0.1 / diviseur);
	}
	else if (keycode == KEY_RIGHT)
	{
		e->fractal_x[0] = e->fractal_x[0] + (0.1 / diviseur);
		e->fractal_x[1] = e->fractal_x[1] + (0.1 / diviseur);
	}
	else if (keycode == KEY_DOWN)
	{
		e->fractal_y[0] = e->fractal_y[0] + (0.1 / diviseur);
		e->fractal_y[1] = e->fractal_y[1] + (0.1 / diviseur);
	}
	else if (keycode == KEY_UP)
	{
		e->fractal_y[0] = e->fractal_y[0] - (0.1 / diviseur);
		e->fractal_y[1] = e->fractal_y[1] - (0.1 / diviseur);
	}
	else if (keycode == KEY_Q)
	{
		e->fractal_y[0] = e->fractal_y[0] + (0.1 / diviseur) * 10;
		e->fractal_y[1] = e->fractal_y[1] + (0.1 / diviseur) * 10;
		e->fractal_x[0] = e->fractal_x[0] + (0.1 / diviseur) * 20;
		e->fractal_x[1] = e->fractal_x[1] + (0.1 / diviseur) * 20;
		e->zoom *= 2;
	}
	else if (keycode == KEY_W)
	{
		e->fractal_y[0] = e->fractal_y[0] - (0.1 / diviseur) * 10;
		e->fractal_y[1] = e->fractal_y[1] - (0.1 / diviseur) * 10;
		e->fractal_x[0] = e->fractal_x[0] - (0.1 / diviseur) * 20;
		e->fractal_x[1] = e->fractal_x[1] - (0.1 / diviseur) * 20;
		e->zoom /= 2;
	}
	else if (keycode == KEY_E)
	{
		e->fractal_y[0] = e->fractal_y[0] - 0.1;
		e->fractal_y[1] = e->fractal_y[1] - 0.1;
	}
	else if (keycode == KEY_C)
	{
		e->fractal_id ^= 1;
	}
	else if (keycode == KEY_D)
	{
		e->modifier_z[0] -= 0.01;
	}
	else
		printf("pressed : %d\n", keycode);
	expose_event(e);
	return (0);
}
