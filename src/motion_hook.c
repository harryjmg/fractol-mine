
#include "fractol.h"

int 		motion_hook(int x, int y, t_env *e)
{
	int ref_x = e->win_x / 2;
	int ref_y = e->win_y / 2;

	if ((x >= 0 && x <= e->win_x) && (y >= 0 && y <= e->win_y))
	{
		e->modifier_z[0] = 0 + 0.01 * (ref_x - x);
		e->modifier_z[1] = 0 + 0.01 * (ref_y - y);
		//printf("mouse (%d,%d)\n", x, y);
	}
	//printf("mouse (%d,%d)\n", (ref_x - x), (ref_y - y));
	expose_event(e);

	return (0);
}