#include "fractol.h"

int			main(void)
{
	t_env	*env;

	env = (t_env *)malloc(sizeof(t_env));
	launch_fractol(env);
	return (0);
}