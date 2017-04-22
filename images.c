#include "wolf3d.h"

void create_img(t_connection *obj)
{
      obj->img.ptr = mlx_new_image(obj->mlx, WIDTH, HEIGHT);
      obj->img.pix = mlx_get_data_addr(obj->img.ptr,
      &obj->img.bpp,
      &obj->img.line_size,
      &obj->img.endian);
}

void	draw_pixel_to_img(t_connection *obj, int x, int y, int color)
{
	int i;
	
	if (x > 0 && x < WIDTH && y > 0 & y < HEIGHT)
	{
		i = (x * (obj->img.bpp / 8)) + (y * obj->img.line_size);
		obj->img.pix[i] = color;
		obj->img.pix[++i] = color >> 8;
		obj->img.pix[++i] = color >> 16;
	}
}

void choose_color(t_connection *obj, int side, int map_x, int map_y)
{
      if (worldMap[map_x][map_y] == 1)
        obj->pos.color = RED;
      else if (worldMap[map_x][map_y] == 2)
          obj->pos.color = GREEN;
      else if (worldMap[map_x][map_y] == 3)
          obj->pos.color = BLUE;
      else if (worldMap[map_x][map_y] == 4)
          obj->pos.color = WHITE;
      else
          obj->pos.color = YELLOW;
       if (side == 1 && obj->pos.color == RED) 
        obj->pos.color = SHADOW_RED;
       if (side == 1 && obj->pos.color == GREEN) 
        obj->pos.color = SHADOW_GREEN;
       if (side == 1 && obj->pos.color == BLUE) 
        obj->pos.color = SHADOW_BLUE;
       if (side == 1 && obj->pos.color == GREEN) 
        obj->pos.color = SHADOW_GREEN;
      if (side == 1 && obj->pos.color == WHITE) 
        obj->pos.color = SHADOW_WHITE;
       if (side == 1 && obj->pos.color == YELLOW) 
        obj->pos.color = SHADOW_YELLOW;
}

void draw(t_connection *obj, int line_height, int side, int x)
{
	int draw_start;
  	int draw_end;

	draw_start = -line_height / 2 + HEIGHT / 2;
	if(draw_start < 0)
  		draw_start = 0;
	draw_end = line_height / 2 + HEIGHT / 2;
	if(draw_end >= HEIGHT)
        draw_end = HEIGHT - 1;
      choose_color(obj, side, obj->ray.map_x, obj->ray.map_y);
      put_line(obj, x, draw_start, draw_end);
}

void put_line(t_connection *obj, int x1,int y1, int y2)
{
	int dx;
	int p;
	int i;

	i = -1;
	dx = y2 - y1;	
	p = -dx;
	while(++i < dx)
 	{
  		draw_pixel_to_img(obj, x1, y1, obj->pos.color);
 		while(p >= 0)
  			p = p - 2 * dx;
  		y1 += 1;
 	}
}
