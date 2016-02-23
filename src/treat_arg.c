#include "fractol.h"

int			treat_arg(t_env *env, int ac, char **av)
{	
	if (ac == 2 && ft_strcmp("mandelbrot", av[1]) == 0)
		return (load_mandelbrot(env));
	else if (ac == 2 && ft_strcmp("julia", av[1]) == 0)
		return (load_julia(env));
	else if (ac == 2 && ft_strcmp("burningship", av[1]) == 0)
		return (load_burninship(env));
	else if (ac == 2 && ft_strcmp("buddhabrot", av[1]) == 0)
		return (load_buddhabrot(env));
	ft_putendl("[fractol] usage : ./fractol [fractal name]");
	return (1);
}
