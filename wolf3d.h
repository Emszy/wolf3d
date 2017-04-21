#ifndef WOLF3D_H
# define WOLF3D_H


# include "libraries/libft/libft.h"
# include "libraries/minilibx_macos/mlx.h"
# include "key_map.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# define WIDTH 			250
# define HEIGHT 		250
# define mapWidth		24
# define mapHeight		24

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

# define sign(x) ((x>0)?1:((x<0)?-1:0))

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
}				t_ray;

typedef struct s_line
{

}				t_lines;

typedef struct	s_connection
{
	void			*mlx;
	void			*win;
	t_keys			key;
	t_pos			pos;
	t_ray			ray;
	t_lines			line;
}				t_connection;

void  	chorus(t_connection *obj);
void 	draw(t_connection *obj, int x1,int y1,int x2,int y2);
void 	ray_calc(t_connection *obj);
int   	tog_key(int key, int on_off);
int   	key_up_hook(int keycode, t_connection *obj);
int   	key_down_hook(int keycode, t_connection *obj);
void  	init_window(t_connection *obj);
void  	initializer(t_connection *obj);
void  	error_master5000(char *message);
int 	worldMap[mapWidth][mapHeight];


#endif