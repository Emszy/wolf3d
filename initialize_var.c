/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebucheit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 15:43:12 by ebucheit          #+#    #+#             */
/*   Updated: 2017/04/15 15:43:12 by ebucheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void init_ray_var(t_connection *obj)
{
   obj->ray.camera_x = 0;
   obj->ray.pos_x = 0;
   obj->ray.pos_y = 0;
   obj->ray.dir_x = 0;
   obj->ray.dir_y = 0;
   obj->ray.side_dist_x = 0;
   obj->ray.side_dist_y = 0;
   obj->ray.delta_dist_x = 0;
   obj->ray.delta_dist_y = 0;
   obj->ray.perp_wall_dist = 0;
}

void	init_pos_var(t_connection *obj)
{
  obj->pos.x = 20;
  obj->pos.y = 15;
  obj->pos.dir_x = -1;
  obj->pos.dir_y = 0;     
  obj->pos.plane_x = 0;
  obj->pos.plane_y = 0.66;
  obj->pos.time = 0;     
  obj->pos.oldTime = 0;
  obj->pos.color = 0;
  obj->pos.texture = 0;
}

void init_keys(t_connection *obj)
{
	obj->key.space = 0;
	obj->key.w = 0;
	obj->key.a = 0;
	obj->key.s = 0;
	obj->key.d = 0;
}

void  init_window(t_connection *obj)
{
  obj->mlx = mlx_init();
  obj->win = mlx_new_window(obj->mlx, WIDTH, HEIGHT, "WLOLF3D");
}
void  initializer(t_connection *obj)
{
	init_pos_var(obj);
	init_ray_var(obj);
	init_keys(obj);
  	init_window(obj);
}
