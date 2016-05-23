/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_mandel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgueguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 11:05:35 by hgueguen          #+#    #+#             */
/*   Updated: 2016/05/23 11:05:38 by hgueguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			fract_mandel(t_env *e, int x, int y)
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

int			fract_burningship(t_env *e, int x, int y)
{
	int		i;
	double	tmp;

	e->c[0] = 0.04 * (x / e->zoom) + 1.705;
	e->c[1] = 0.04 * (y / e->zoom) - 0.085;
	e->z[0] = 0 + e->modifier_z[0] * 0.10;
	e->z[1] = 0;
	i = 0;
	while ((e->z[0] * e->z[0] + e->z[1] * e->z[1]) < 4 && i < e->iteration)
	{
		tmp = e->z[0];
		e->z[0] = e->z[0] * e->z[0] - e->z[1] * e->z[1] - e->c[0];
		e->z[1] = 2 * fabs(e->z[1] * tmp) + e->c[1];
		i++;
	}
	return (i);
}
