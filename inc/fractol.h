#ifndef FRACTOL_H_
# define FRACTOL_H_

# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <string.h>
# include "math.h"

# include "libft.h"

# define KEY_ESCAPE 	53
# define KEY_LEFT		123
# define KEY_RIGHT 		124
# define KEY_DOWN 		125
# define KEY_UP 		126
# define KEY_Q 			12
# define KEY_W 			13
# define KEY_E 			14
# define KEY_R			15
# define KEY_C			8
# define KEY_Z			6
# define KEY_D			2
# define KEY_A			0
# define RGB(r, g, b)	(256 * 256 * (int)(r) + 256 * (int)(g) + (int)(b))
# define COLOR_1		0x000000
# define COLOR_2		0x401A00
# define COLOR_3		0x803300
# define COLOR_4		0xBF4D00
# define COLOR_5		0xFF6600
# define COLOR_6		0xFF8C00
# define COLOR_7		0xFFB300
# define COLOR_8		0xFFD900
# define COLOR_9		0xFFFF00
# define COLOR_10		0xFFFF55
# define COLOR_11		0xFFFFFF
# define INITIAL_ITER	100
# define INITIAL_ZOOM 	200
# define DETAIL			10

#define PointerMotionMask (1L<<6)
#define MotionNotify 6

# define WINDOW_NAME "Project Fractol"

typedef struct 			s_img
{
	void				*img_ptr;
	void				*data;
	int					bpp;
	int					sl;
	int					e;
}						t_img;

typedef struct			s_env
{
	int 				max;
	void				*mlx;
	void				*win;

	double				zoom;
	double				fractal_x[2];
	double				fractal_y[2];

	double				z[2];
	double				c[2];

	int 				win_x;
	int 				win_y;

	int					iteration;

	int 				fractal_id;

	void				*img;
	char				*data;
	int					bpp;
	int					sl;
	int					e;

	int 				color_level[5][2];
	int 				color[11][3];
	int 				inter_color;

	int 				*color_val;

	double				modifier_c[2];
	double 				modifier_z[2];

}						t_env;

void					launch_fractol(t_env *e);
void					expose_event(t_env *e);
int						expose_hook(t_env *e);
int 					key_hook(int keycode, t_env *e);

int						ft_color(int i, int imax);

int 					motion_hook(int x, int y, t_env *e);

int 					fract_mandel(t_env *e, int x, int y);
int 					fract_julia(t_env *e, int x, int y);
int 					fract_burningship(t_env *e, int x, int y);


#endif