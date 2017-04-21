#include "wolf3d.h"

int worldMap[mapWidth][mapHeight] =
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

// testmap


int   tog_key(int key, int on_off)
{
  key = on_off;
  return (key);

}

int   key_up_hook(int keycode, t_connection *obj)
{
  if (keycode == KEY_SPACE)
    obj->key.space = tog_key(obj->key.space, 0);
  if (keycode == KEY_W)
    obj->key.w = tog_key(obj->key.w, 0);
  if (keycode == KEY_A)
    obj->key.a = tog_key(obj->key.a, 0);
  if (keycode == KEY_S)
    obj->key.s = tog_key(obj->key.s, 0);
   if (keycode == KEY_D)
    obj->key.d = tog_key(obj->key.d, 0);
  return (0);
}


void move_forward(t_connection *obj, double move_speed)
{
  if(worldMap[(int)(obj->pos.x + obj->pos.dir_x * move_speed)][(int)(obj->pos.y)] == 0)
        obj->pos.x += obj->pos.dir_x * move_speed;
  if(worldMap[(int)(obj->pos.x)][(int)(obj->pos.y + obj->pos.dir_y * move_speed)] == 0)
        obj->pos.y += obj->pos.dir_y * move_speed;
}

void move_backwards(t_connection *obj, double move_speed)
{
  if(!worldMap[(int)(obj->pos.x - obj->pos.dir_x * move_speed)][(int)(obj->pos.y)])
    obj->pos.x -= obj->pos.dir_x * move_speed;
  if(!worldMap[(int)(obj->pos.x)][(int)(obj->pos.y - obj->pos.dir_y * move_speed)])
    obj->pos.y -= obj->pos.dir_y * move_speed;
}

void rotate_left(t_connection *obj, double rotation_speed)
{
  double oldDirX;
  double oldPlaneX;

      oldDirX = obj->pos.dir_x;
      obj->pos.dir_x = obj->pos.dir_x * cos(rotation_speed) - obj->pos.dir_y * sin(rotation_speed);
      obj->pos.dir_y = oldDirX * sin(rotation_speed) + obj->pos.dir_y * cos(rotation_speed);
      oldPlaneX = obj->pos.plane_x;
      obj->pos.plane_x = obj->pos.plane_x * cos(rotation_speed) - obj->pos.plane_y * sin(rotation_speed);
      obj->pos.plane_y = oldPlaneX * sin(rotation_speed) + obj->pos.plane_y * cos(rotation_speed);

}

void rotate_right(t_connection *obj, double rotation_speed)
{
    double oldDirX;
    double oldPlaneX;

      oldDirX = obj->pos.dir_x;
      obj->pos.dir_x = obj->pos.dir_x * cos(-rotation_speed) - obj->pos.dir_y * sin(-rotation_speed);
      obj->pos.dir_y = oldDirX * sin(-rotation_speed) + obj->pos.dir_y * cos(-rotation_speed);
      oldPlaneX = obj->pos.plane_x;
      obj->pos.plane_x = obj->pos.plane_x * cos(-rotation_speed) - obj->pos.plane_y * sin(-rotation_speed);
      obj->pos.plane_y = oldPlaneX * sin(-rotation_speed) + obj->pos.plane_y * cos(-rotation_speed);
}

void move_check(t_connection *obj)
{
  double move_speed;
  double rotation_speed;
  
  rotation_speed = 0.1;
  move_speed = 0.2;
  if (obj->key.w == 1)
        move_forward(obj, move_speed);
  if (obj->key.s == 1)
        move_backwards(obj, move_speed);
  if (obj->key.a == 1)
        rotate_left(obj, rotation_speed);
  if (obj->key.d == 1)
    rotate_right(obj, rotation_speed);
}



int   key_down_hook(int keycode, t_connection *obj)
{
  if (keycode == KEY_SPACE)
    obj->key.space = tog_key(obj->key.space, 1);
  if (keycode == KEY_W)
    obj->key.w = tog_key(obj->key.w, 1);
  if (keycode == KEY_A)
    obj->key.a = tog_key(obj->key.a, 1);
  if (keycode == KEY_S)
    obj->key.s = tog_key(obj->key.s, 1);
  if (keycode == KEY_D)
    obj->key.d = tog_key(obj->key.d, 1);
  if (keycode == 53)
  {
    free(obj);
    error_master5000("GOODBYE WORLD!");
  }
  move_check(obj);
  mlx_clear_window(obj->mlx, obj->win);
  ray_calc(obj);
  return (0);
}


void  chorus(t_connection *obj)
{
    
    mlx_hook(obj->win, 2, 0, key_down_hook, obj);
    mlx_hook(obj->win, 3, 0, key_up_hook, obj);
    mlx_loop(obj->mlx);
}

void draw(t_connection *obj, int x1,int y1,int x2,int y2)
{
int x,y,dx,dy,swap,temp,s1,s2,p,i;

x=x1;
y=y1;
dx=abs(x2-x1);
dy=abs(y2-y1);
s1=sign(x2-x1);
s2=sign(y2-y1);
swap=0;
  mlx_pixel_put(obj->mlx, obj->win, x, y, obj->pos.color);
if(dy>dx)
 {
 temp=dx;
 dx=dy;
 dy=temp;
 swap=1;
 }
p=2*dy-dx;
for(i=0;i<dx;i++)
 {
  mlx_pixel_put(obj->mlx, obj->win, x, y, obj->pos.color);
 while(p>=0)
  {
  p=p-2*dx;
  if(swap)
   x+=s1;
  else
   y+=s2;
  }
 p=p+2*dy;
 if(swap)
  y+=s2;
 else
  x+=s1;
 }
  mlx_pixel_put(obj->mlx, obj->win, x, y, obj->pos.color);
}

void ray_calc(t_connection *obj)
{
  int x;
  x = -1;
    while(++x < WIDTH)
    {
      int map_x;
      int map_y;
      int step_x;
      int step_y;
      int side;
      int line_height;
      int draw_start;
      int draw_end;
      int hit;
      hit = 0; 
      //calculate ray position and direction
      obj->ray.camera_x = 2 * x / (double)WIDTH - 1; //x-coordinate in camera space
      obj->ray.pos_x = obj->pos.x;
      obj->ray.pos_y = obj->pos.y;
      obj->ray.dir_x = obj->pos.dir_x + obj->pos.plane_x * obj->ray.camera_x;
      obj->ray.dir_y = obj->pos.dir_y + obj->pos.plane_y * obj->ray.camera_x;
      //which box of the map we're in
      map_x = (int)obj->ray.pos_x;
      map_y = (int)obj->ray.pos_y;

      obj->ray.delta_dist_x = sqrt(1 + (obj->ray.dir_y * obj->ray.dir_y) / (obj->ray.dir_x * obj->ray.dir_x));
      obj->ray.delta_dist_y = sqrt(1 + (obj->ray.dir_x * obj->ray.dir_x) / (obj->ray.dir_y * obj->ray.dir_y));


      //calculate step and initial sideDist
      if (obj->ray.dir_x < 0)
      {
        step_x = -1;
        obj->ray.side_dist_x = (obj->ray.pos_x - map_x) * obj->ray.delta_dist_x;
      }
      else
      {
        step_x = 1;
        obj->ray.side_dist_x = (map_x + 1.0 - obj->ray.pos_x) * obj->ray.delta_dist_x;
      }
      if (obj->ray.dir_y < 0)
      {
        step_y = -1;
        obj->ray.side_dist_y = (obj->ray.pos_y - map_y) * obj->ray.delta_dist_y;
      }
      else
      {
        step_y = 1;
        obj->ray.side_dist_y = (map_y + 1.0 - obj->ray.pos_y) * obj->ray.delta_dist_y;
      }
      //perform DDA
      while (hit == 0)
      {
        //jump to next map square, OR in x-direction, OR in y-direction
        if (obj->ray.side_dist_x < obj->ray.side_dist_y)
        {
          obj->ray.side_dist_x += obj->ray.delta_dist_x;
          map_x += step_x;
          side = 0;
        }
        else
        {
          obj->ray.side_dist_y += obj->ray.delta_dist_y;
          map_y += step_y;
          side = 1;
        }
        //Check if ray has hit a wall
        if (worldMap[map_x][map_y] > 0)
          hit = 1;
      }
      //Calculate distance projected on camera direction (oblique distance will give fisheye effect!)
      if (side == 0) 
        obj->ray.perp_wall_dist = (map_x - obj->ray.pos_x + (1 - step_x) / 2) / obj->ray.dir_x;
      else
        obj->ray.perp_wall_dist = (map_y - obj->ray.pos_y + (1 - step_y) / 2) / obj->ray.dir_y;
     //Calculate height of line to draw on screen
      line_height = (int)(HEIGHT / obj->ray.perp_wall_dist);

      //calculate lowest and highest pixel to fill in current stripe
      draw_start = -line_height / 2 + HEIGHT / 2;
      if(draw_start < 0)
        draw_start = 0;
      draw_end = line_height / 2 + HEIGHT / 2;
      if(draw_end >= HEIGHT)
        draw_end = HEIGHT - 1;

      //choose wall obj->pos.color
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
      draw(obj, x, draw_start, x, draw_end);
    }
}
          
          
      
int main(void)
{

  t_connection *obj;
  obj = malloc(sizeof(t_connection));

  initializer(obj);
  ray_calc(obj);
  chorus(obj);
  return (0);
}








