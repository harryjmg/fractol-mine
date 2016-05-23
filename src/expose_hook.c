/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgueguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 11:05:26 by hgueguen          #+#    #+#             */
/*   Updated: 2016/05/23 11:05:26 by hgueguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			data_set_color(char *pixel, char red, char green, char blue)
{
	*(pixel) = blue;
	*(pixel + 1) = green;
	*(pixel + 2) = red;
	*(pixel + 3) = 0;
}

char			*color_maker(t_env *e, int pixel_value)
{
	double		rgb[3];
	char		*rgb_to_return;
	int			color;
	int			tmp;

	rgb_to_return = (char *)malloc(sizeof(char) * 3);
	color = e->color_val[pixel_value];
	tmp = color / (256 * 256);
	color = color % (256 * 256);
	rgb[0] = tmp;
	tmp = color / 256;
	color = color % 256;
	rgb[1] = tmp;
	tmp = color / 1;
	rgb[2] = tmp;
	rgb_to_return[0] = rgb[0];
	rgb_to_return[1] = rgb[1];
	rgb_to_return[2] = rgb[2];
	return (rgb_to_return);
}

int				pixel_get_value(t_env *e, int x, int y)
{
	if (e->fractal_id == 0)
		return (fract_mandel(e, x, y));
	else if (e->fractal_id == 1)
		return (fract_julia(e, x, y));
	else if (e->fractal_id == 2)
		return (fract_burningship(e, x, y));
	exit(1);
}

void			expose_event(t_env *e)
{
	int			x;
	int			y;
	int			pixel_value;
	char		*color;

	x = 0;
	while (x < e->win_x)
	{
		y = 0;
		while (y < e->win_y)
		{
			pixel_value = pixel_get_value(e, x, y);
			color = color_maker(e, pixel_value);
			free(color);
			data_set_color((e->data + (e->sl * y + x * 4)),
				color[0], color[1], color[2]);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

int				expose_hook(t_env *e)
{
	expose_event(e);
	return (0);
}
