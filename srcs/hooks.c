/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebucheit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 21:56:25 by ebucheit          #+#    #+#             */
/*   Updated: 2017/04/25 21:56:25 by ebucheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		tog_key(int key, int on_off)
{
	key = on_off;
	return (key);
}

void	did_i_win(t_connection *obj)
{
	if (obj->pos.x > obj->pos.win_low && obj->pos.x < obj->pos.win_high && \
		obj->pos.y > obj->pos.win_low && obj->pos.y < obj->pos.win_high)
	{
		reset_map(obj);
		if (obj->map_chosen == 1)
			random_map_2(obj);
		if (obj->map_chosen == 2)
			error_master5000("YOU WIN!!");
		if (obj->map_chosen == 1)
			obj->map_chosen = 2;
	}
}

int		loop_hook(t_connection *obj)
{
	did_i_win(obj);
	move_check(obj);
	mlx_clear_window(obj->mlx, obj->win);
	ray_calc(obj);
	return (1);
}

int		key_up_hook(int keycode, t_connection *obj)
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

int		key_down_hook(int keycode, t_connection *obj)
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
	return (0);
}
