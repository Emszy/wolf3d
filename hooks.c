#include "wolf3d.h"

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
