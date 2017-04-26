#include "wolf3d.h"

void calc_ray_position(t_connection *obj, int x)
{
	obj->ray.camera = 2 * x / (double)WIDTH - 1;
	obj->ray.x = obj->pos.x;
	obj->ray.y = obj->pos.y;
	obj->ray.dir_x = obj->pos.dir_x + obj->pos.plane_x * obj->ray.camera;
	obj->ray.dir_y = obj->pos.dir_y + obj->pos.plane_y * obj->ray.camera;
	obj->ray.map_x = obj->ray.x;
	obj->ray.map_y = obj->ray.y;
	obj->ray.delta_dist_x = sqrt(1 + pow(obj->ray.dir_y, 2) / pow(obj->ray.dir_x, 2));
	obj->ray.delta_dist_y = sqrt(1 + pow(obj->ray.dir_x, 2) / pow(obj->ray.dir_y, 2));
}

void calc_side_length(t_connection *obj)
{
	if (obj->ray.dir_x < 0)
	{
		obj->ray.step_x = -1;
		obj->ray.side_dist_x = (obj->ray.x - obj->ray.map_x) * obj->ray.delta_dist_x;
	}
	else
	{
		obj->ray.step_x = 1;
		obj->ray.side_dist_x = ( obj->ray.map_x + 1.0 - obj->ray.x) * obj->ray.delta_dist_x;
	}
	if (obj->ray.dir_y < 0)
	{
		obj->ray.step_y = -1;
		obj->ray.side_dist_y = (obj->ray.y - obj->ray.map_y) * obj->ray.delta_dist_y;
	}
	else
	{
		obj->ray.step_y = 1;
		obj->ray.side_dist_y = ( obj->ray.map_y + 1.0 - obj->ray.y) * obj->ray.delta_dist_y;
	}
}

int calc_line_distance(t_connection *obj)
{
	int side;
	int hit;

	hit = 0; 
	while (hit == 0)
	{
	 	if (obj->ray.side_dist_x < obj->ray.side_dist_y)
	 	{
			obj->ray.side_dist_x += obj->ray.delta_dist_x;
			obj->ray.map_x += obj->ray.step_x;
	   		side = 0;
		}
		else
		{
			obj->ray.side_dist_y += obj->ray.delta_dist_y;
				obj->ray.map_y +=  obj->ray.step_y;
			side = 1;
		}
		if (obj->map[obj->ray.map_x][obj->ray.map_y] > 0)
			hit = 1;
	}
	return (side);
}

int projection_dis(t_connection *obj, int side)
{
	if (side == 0) 
		obj->ray.perp_wall_dist = (obj->ray.map_x - obj->ray.x + \
			(1 -  obj->ray.step_x) / 2) / obj->ray.dir_x;
	else
		obj->ray.perp_wall_dist = (obj->ray.map_y - obj->ray.y + \
			(1 -  obj->ray.step_y) / 2) / obj->ray.dir_y;
	return((HEIGHT / obj->ray.perp_wall_dist));
}

void ray_calc(t_connection *obj)
{
	int x;
	int side;
	int line_height;

	x = -1;
	side = 0;
	create_img(obj);
	while(++x < WIDTH)
	{
		calc_ray_position(obj, x);
		calc_side_length(obj);
		side = calc_line_distance(obj);
		line_height = projection_dis(obj, side);
		draw(obj, line_height, side, x);
	}
	mlx_put_image_to_window(obj->mlx, obj->win, obj->img.ptr,
			0, 0);
	mlx_destroy_image(obj->mlx, obj->img.ptr);
}