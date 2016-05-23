/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgueguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 11:04:50 by hgueguen          #+#    #+#             */
/*   Updated: 2016/05/23 11:04:53 by hgueguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		get_color_global(int val)
{
	if (val == 0)
		return (COLOR_1);
	else if (val == 1)
		return (COLOR_2);
	else if (val == 2)
		return (COLOR_3);
	else if (val == 3)
		return (COLOR_4);
	else if (val == 4)
		return (COLOR_5);
	else if (val == 5)
		return (COLOR_6);
	else if (val == 6)
		return (COLOR_7);
	else if (val == 7)
		return (COLOR_8);
	else if (val == 8)
		return (COLOR_9);
	else if (val == 9)
		return (COLOR_10);
	else if (val == 10)
		return (COLOR_11);
	else
		return (COLOR_11);
}

static void		translate_colors_to_rgb(t_env *e)
{
	int			i;
	int			color;
	int			tmp;

	i = 0;
	while (i < DETAIL + 1)
	{
		color = get_color_global(i);
		tmp = color / (256 * 256);
		color = color % (256 * 256);
		e->color[i][0] = tmp;
		tmp = color / 256;
		color = color % 256;
		e->color[i][1] = tmp;
		tmp = color / 1;
		e->color[i][2] = tmp;
		i++;
	}
}

static int		color_mix(t_env *e, int relative, int i_color)
{
	int			pas[3];
	int			color;
	int			rgb[3];

	pas[0] = (e->color[i_color][0] - e->color[i_color + 1][0]) / e->inter_color;
	pas[1] = (e->color[i_color][1] - e->color[i_color + 1][1]) / e->inter_color;
	pas[2] = (e->color[i_color][2] - e->color[i_color + 1][2]) / e->inter_color;
	rgb[0] = e->color[i_color][0] - (pas[0] * relative);
	rgb[1] = e->color[i_color][1] - (pas[1] * relative);
	rgb[2] = e->color[i_color][2] - (pas[2] * relative);
	color = RGB(rgb[0], rgb[1], rgb[2]);
	return (color);
}

void			fill_color_val(t_env *e)
{
	int			i;
	int			j;
	int			k;

	translate_colors_to_rgb(e);
	k = 0;
	j = 0;
	while (j < DETAIL)
	{
		i = 0;
		while (i < e->iteration / DETAIL)
		{
			e->color_val[k] = color_mix(e, i, j);
			i++;
			k++;
		}
		j++;
	}
	e->color_val[k] = RGB(255, 255, 255);
}
