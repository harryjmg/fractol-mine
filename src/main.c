#include "fractol.h"

int			main()
{
	t_env	*env;

	env = (t_env *)malloc(sizeof(t_env));
	//if (treat_args(env, ac, av))
	//	return (1);
	launch_fractol(env);
	return (0);
}
