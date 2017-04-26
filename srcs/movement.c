/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebucheit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 21:56:25 by ebucheit          #+#    #+#             */
/*   Updated: 2017/04/25 21:56:25 by ebucheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	move_forward(t_connection *obj, double speed)
{
	if (obj->map[(int)(obj->pos.x + obj->pos.dir_x * speed)]
		[(int)(obj->pos.y)] == 0)
		obj->pos.x += obj->pos.dir_x * speed;
	if (obj->map[(int)(obj->pos.x)]
		[(int)(obj->pos.y + obj->pos.dir_y * speed)] == 0)
		obj->pos.y += obj->pos.dir_y * speed;
}

void	move_backwards(t_connection *obj, double move_speed)
{
	if (!obj->map[(int)(obj->pos.x - obj->pos.dir_x * move_speed)]
		[(int)(obj->pos.y)])
		obj->pos.x -= obj->pos.dir_x * move_speed;
	if (!obj->map[(int)(obj->pos.x)]
		[(int)(obj->pos.y - obj->pos.dir_y * move_speed)])
		obj->pos.y -= obj->pos.dir_y * move_speed;
}

void	rotate_left(t_connection *obj, double rot)
{
	double old_x;
	double old_plane;

	old_x = obj->pos.dir_x;
	obj->pos.dir_x = obj->pos.dir_x * cos(rot) - obj->pos.dir_y *
					sin(rot);
	obj->pos.dir_y = old_x * sin(rot) + obj->pos.dir_y *
					cos(rot);
	old_plane = obj->pos.plane_x;
	obj->pos.plane_x = obj->pos.plane_x * cos(rot) - obj->pos.plane_y *
					sin(rot);
	obj->pos.plane_y = old_plane * sin(rot) + obj->pos.plane_y *
					cos(rot);
}

void	rotate_right(t_connection *obj, double rot)
{
	double old_x;
	double old_plane;

	old_x = obj->pos.dir_x;
	obj->pos.dir_x = obj->pos.dir_x * cos(-rot) - obj->pos.dir_y * sin(-rot);
	obj->pos.dir_y = old_x * sin(-rot) + obj->pos.dir_y * cos(-rot);
	old_plane = obj->pos.plane_x;
	obj->pos.plane_x = obj->pos.plane_x * cos(-rot) - obj->pos.plane_y *
						sin(-rot);
	obj->pos.plane_y = old_plane * sin(-rot) + obj->pos.plane_y * cos(-rot);
}

void	move_check(t_connection *obj)
{
	if (obj->key.w == 1)
		move_forward(obj, obj->pos.speed);
	if (obj->key.s == 1)
		move_backwards(obj, obj->pos.speed);
	if (obj->key.a == 1)
		rotate_left(obj, obj->pos.rot_speed);
	if (obj->key.d == 1)
		rotate_right(obj, obj->pos.rot_speed);
}
