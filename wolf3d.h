#ifndef WOLF3D_H
# define WOLF3D_H


# include "libraries/libft/libft.h"
# include "libraries/minilibx_macos/mlx.h"
# include "key_map.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# define WIDTH 			512
# define HEIGHT 		384
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

typedef struct	s_connection
{
	void			*mlx;
	void			*win;
}				t_connection;

void  init_window(t_connection *obj);
void  initializer(t_connection *obj);
void  error_master5000(char *message);


#endif