#include "fractol.h"

int 		fract_mandel(t_env *e, int x, int y)
{
	int		i;
	double	tmp;

	e->c[0] = x / e->zoom + e->fractal_x[0] + e->modifier_c[0];
	e->c[1] = y / e->zoom + e->fractal_y[0] + e->modifier_c[1];
	e->z[0] = 0 + e->modifier_z[0];
	e->z[1] = 0 + e->modifier_z[1];

	i = 0;
	while (e->z[0] * e->z[0] + e->z[1] * e->z[1] < 4 && i < e->iteration)
	{
		tmp = e->z[0];
		e->z[0] = e->z[0] * e->z[0] - e->z[1] * e->z[1] + e->c[0];
		e->z[1] = 2 * e->z[1] * tmp + e->c[1];
		i++;
	}
	return (i);
}

int 		fract_burningship(t_env *e, int x, int y)
{
	int 	i;
	double tmp;

	e->c[0] = 0.04 * (x / e->zoom) + 1.705;// + e->modifier_c[0];
	e->c[1] = 0.04 * (y / e->zoom) - 0.01;// + e->modifier_c[1];
	e->z[0] = 0 + e->modifier_z[0] * 0.10;
	e->z[1] = 0;// + e->modifier_z[1];

	i = 0;
	while (e->z[0] * e->z[0] + e->z[1] * e->z[1] < 10 && i < e->iteration)
	{
		tmp = e->z[0];
		e->z[0] = e->z[0] * e->z[0] - e->z[1] * e->z[1] - e->c[0];
		e->z[1] = 2 * fabs(e->z[1] * tmp) - e->c[1];
		i++;
	}
	return (i);
}

int			fract_urningship(t_env *e, int x, int y)
{
	double		pox, poy;
	double		cx, cy;
	double		px, py;
	int			k;

	// px = z[0] , py = z[1]


			pox = 0;
			poy = 0;
			cx = 1.755 + 2 * 0.04 * (x / INITIAL_ZOOM - 0.5);
			cy = 0.03 + 2 * 0.04 * (y / INITIAL_ZOOM - 0.5);
			for (k = 0; k < e->iteration ;k++) {
				px = pox * pox - poy * poy - cx;
				py = 2 * fabs(pox * poy) - cy;
				pox = 0;
				poy = 0;
				if (px * px + py * py > 4)
					break ;
			}
			//if (k == iteratemax)
			//	image[j*N+i] = 0;
			//else
	
	return (k);
}