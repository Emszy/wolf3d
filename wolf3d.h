#ifndef WOLF3D_H
# define WOLF3D_H


# include "libraries/libft/libft.h"
# include "libraries/minilibx_macos/mlx.h"
# include "key_map.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# define WIDTH 			800
# define HEIGHT 		800
# define mapWidth		24
# define mapHeight		24


# define PURPLE			0x00ca2bf2
# define WHITE			0x00ffffff
# define SHADOW_WHITE	0x00dbdbdb
# define RED			0x00ff0000
# define SHADOW_RED		0x00ad0606
# define BLUE			0x002200ff
# define SHADOW_BLUE 	0x00180499
# define YELLOW			0x00fff600
# define SHADOW_YELLOW	0xccc402
# define GREEN			0x001ae000
# define SHADOW_GREEN	0x00129301


typedef struct s_position
{
	double x;
	double y;   
	double dir_x;
	double dir_y;   
	double plane_x;
	double plane_y; 
	double time;
	double oldTime;
	int texture;
	int color;
}				t_pos;

typedef struct s_ray
{
	  double camera_x;
      double pos_x;
      double pos_y;
      double dir_x;
      double dir_y;
      double side_dist_x;
      double side_dist_y;
      double delta_dist_x;
      double delta_dist_y;
      double perp_wall_dist;
      int map_x;
      int map_y;
      int step_x;
      int step_y;
}				t_ray;

typedef struct s_image
{
	void			*ptr;
	char			*pix;
	int				bpp;
	int				line_size;
	int				endian;
}				t_image;

typedef struct	s_connection
{
	void			*mlx;
	void			*win;
	t_image			img;
	t_keys			key;
	t_pos			pos;
	t_ray			ray;
}				t_connection;

void  	chorus(t_connection *obj);
void 	ray_calc(t_connection *obj);
int   	tog_key(int key, int on_off);
void  	init_window(t_connection *obj);
void  	initializer(t_connection *obj);
void  	error_master5000(char *message);
void 	move_forward(t_connection *obj, double move_speed);
void 	move_backwards(t_connection *obj, double move_speed);
void 	rotate_left(t_connection *obj, double rotation_speed);
void 	rotate_right(t_connection *obj, double rotation_speed);
void 	move_check(t_connection *obj);
int   	key_up_hook(int keycode, t_connection *obj);
int   	key_down_hook(int keycode, t_connection *obj);
void 	create_img(t_connection *obj);
void	draw_pixel_to_img(t_connection *obj, int x, int y, int color);
void 	choose_color(t_connection *obj, int side, int map_x, int map_y);
void 	draw(t_connection *obj, int line_height, int side, int x);
void 	put_line(t_connection *obj, int x1,int y1, int y2);


int 	worldMap[mapWidth][mapHeight];


#endif