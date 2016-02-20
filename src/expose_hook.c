
#include "fractol.h"

void		data_set_color(char *pixel, char red, char green, char blue)
{
	*(pixel) = blue;
	*(pixel + 1) = green;
	*(pixel + 2) = red;
	*(pixel + 3) = 0;

	// *(e->data + (e->sl + x * 4)) = 255;
	// *(e->data + (y * e->sl + x * 4) + 1) = 255;
	// *(e->data + (y * e->sl + x * 4) + 2) = 255;
	// *(e->data + (y * e->sl + x * 4) + 3) = 255;
	//mlx_pixel_put(e->mlx, e->win, x, y, color);
}

char			*color_maker(t_env *e, int pixel_value)
{
	double		r;
	double		g;
	double		b;
	char		*rgb;
	int			color;
	int			tmp;

	rgb = (char *)malloc(sizeof(char) * 3);
	color = e->color_val[pixel_value];
	tmp = color / (256 * 256);
	color = color % (256 * 256);
	r = tmp;
	tmp = color / 256;
	color = color % 256;
	g = tmp;
	tmp = color / 1;
	b = tmp;
	rgb[0] = r;
	rgb[1] = g;
	rgb[2] = b;
	return (rgb);
}

int			pixel_get_value(t_env *e, int x, int y)
{
	// Utilisation de pointeurs sur fonction possible pour toute les fractales
	if (e->fractal_id == 0)
		return (fract_mandel(e, x, y));
	else if (e->fractal_id == 1)
		return (fract_julia(e, x, y));
	exit(1);
}

void		expose_event(t_env *e)
{
	int		x;
	int		y;
	int		pixel_value;
	char	*color;

	x = 0;
	while (x < e->win_x)
	{
		y = 0;
		while (y < e->win_y)
		{
			//printf("%d,%d ", x, y);
			pixel_value = pixel_get_value(e, x, y);
			color = color_maker(e, pixel_value);
			data_set_color((e->data + (e->sl * y + x * 4)), color[0], color[1], color[2]);
			y++;
		}
		x++;
	}
	//mlx_do_sync(e->mlx);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

int			expose_hook(t_env *e)
{
	expose_event(e);
	return (0);
}

// char			*color_maker(t_env *e, int pixel_value)
// {
// 	double		r;
// 	double		g;
// 	double		b;
// 	char		*rgb;
// 	int			color;
// 	int			tmp;

// 	rgb = (char *)malloc(sizeof(char) * 3);
// 	if (pixel_value == e->iteration)
// 	{
// 		rgb[0] = 0;
// 		rgb[1] = 0;
// 		rgb[2] = 0;
// 		return (rgb);
// 	}
// 	color = 0xFFFFFF;
// 	tmp = color / (256 * 256);
// 	color = color % (256 * 256);
// 	r = tmp;
// 	tmp = color / 256;
// 	color = color % 256;
// 	g = tmp;
// 	tmp = color / 1;
// 	b = tmp;
// 	rgb[0] = (r /e->iteration) * pixel_value;
// 	rgb[1] = (g /e->iteration) * pixel_value;
// 	rgb[2] = (b /e->iteration) * pixel_value;
// 	return (rgb);
// }