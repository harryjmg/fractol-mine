
#include "fractol.h"

int		loop_hook(t_env *e)
{
	expose_event(e);
	return (0);
}
