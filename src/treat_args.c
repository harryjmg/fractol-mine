/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgueguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 12:06:34 by hgueguen          #+#    #+#             */
/*   Updated: 2016/05/23 12:06:34 by hgueguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	arg_load_julia(t_env *e)
{
	e->fractal_id = 1;
	return (0);
}

static int	arg_load_burninship(t_env *e)
{
	e->fractal_id = 2;
	return (0);
}

static int	arg_load_mandelbrot(t_env *e)
{
	e->fractal_id = 0;
	return (0);
}

int			treat_args(t_env *env, int ac, char **av)
{
	if (ac == 2 && ft_strcmp("mandelbrot", av[1]) == 0)
		return (arg_load_mandelbrot(env));
	else if (ac == 2 && ft_strcmp("julia", av[1]) == 0)
		return (arg_load_julia(env));
	else if (ac == 2 && ft_strcmp("burningship", av[1]) == 0)
		return (arg_load_burninship(env));
	ft_putendl("[fractol] usage : ./fractol [fractal name]");
	return (1);
}
