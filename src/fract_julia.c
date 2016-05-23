/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_julia.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgueguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 11:04:25 by hgueguen          #+#    #+#             */
/*   Updated: 2016/05/23 11:04:26 by hgueguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			fract_julia(t_env *e, int x, int y)
{
	int		i;
	double	tmp;

	e->z[0] = x / e->zoom + e->fractal_x[0] + e->modifier_c[0];
	e->z[1] = y / e->zoom + e->fractal_y[0] + e->modifier_c[1];
	e->c[0] = 0 + e->modifier_z[0];
	e->c[1] = 0 + e->modifier_z[1];
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
