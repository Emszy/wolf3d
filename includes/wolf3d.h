/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebucheit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 21:56:25 by ebucheit          #+#    #+#             */
/*   Updated: 2017/04/25 21:56:25 by ebucheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../libraries/libft/libft.h"
# include "../libraries/minilibx_macos/mlx.h"
# include "key_map.h"
# include <math.h>
# define WIDTH 			640
# define HEIGHT 		480
# define MAPWIDTH		50
# define MAPHEIGHT		50
# define PURPLE			0x00ca2bf2
# define WHITE			0x00ffffff
# define SHADOW_WHITE	0x00dbdbdb
# define RED			0x00ff0000
# define SHADOW_RED		0x00ad0606
# define BLUE			0x002200ff
# define SHADOW_BLUE 	0x00180499
# define YELLOW			0x00fff600
# define GREEN			0x001ae000
# define SHADOW_GREEN	0x00129301
# define BROWN			0x00380105

typedef struct	s_position
{
	double		x;
	double		y;
	double		speed;
	double		rot_speed;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	int			win_low;
	int			win_high;
	int			color;
}				t_pos;

typedef struct	s_ray
{
	double		camera;
	double		x;
	double		y;
	double		dir_x;
	double		dir_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_x;
	double		delta_y;
	double		perp_wall_dist;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
}				t_ray;

typedef struct	s_imag
{
	void		*ptr;
	char		*pix;
	int			bpp;
	int			line_size;
	int			endian;
}				t_imag;

typedef struct	s_connection
{
	void		*mlx;
	void		*win;
	int			map[MAPWIDTH][MAPHEIGHT];
	int			map_chosen;
	t_imag		img;
	t_keys		key;
	t_pos		pos;
	t_ray		ray;
}				t_connection;

void			chorus(t_connection *obj);
void			win_building(t_connection *obj, int x, int y, int offset);
void			reset_map(t_connection *obj);
void			random_map_1(t_connection *obj);
void			random_map_2(t_connection *obj);
int				tog_key(int key, int on_off);
int				loop_hook(t_connection *obj);
void			init_window(t_connection *obj);
void			initializer(t_connection *obj);
void			error_master5000(char *message);
void			calc_ray_position(t_connection *obj, int x);
void			calc_side_length(t_connection *obj);
int				wcalc_line_distance(t_connection *obj);
int				projection_dis(t_connection *obj, int side);
void			ray_calc(t_connection *obj);
void			move_forward(t_connection *obj, double move_speed);
void			move_backwards(t_connection *obj, double move_speed);
void			rotate_left(t_connection *obj, double rotation_speed);
void			rotate_right(t_connection *obj, double rotation_speed);
void			move_check(t_connection *obj);
int				key_up_hook(int keycode, t_connection *obj);
int				key_down_hook(int keycode, t_connection *obj);
void			create_img(t_connection *obj);
void			draw_pixel_to_img(t_connection *obj, int x, int y, int color);
void			choose_color(t_connection *obj, int side);
void			draw(t_connection *obj, int line_height, int side, int x);
void			put_line(t_connection *obj, int x1, int y1, int y2);

#endif
