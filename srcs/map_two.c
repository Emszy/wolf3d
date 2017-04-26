/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_two.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebucheit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 22:39:42 by ebucheit          #+#    #+#             */
/*   Updated: 2017/04/25 22:39:42 by ebucheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void		add_doors_map_two(t_connection *obj, int x, int y)
{
	win_building(obj, x, y, 0);
	if (x == 0 || y == 0 || x == MAPWIDTH - 1 || (y == MAPHEIGHT - 2))
		obj->map[x][y] = 1;
	obj->map[32][42] = 0;
	obj->map[25][41] = 0;
	obj->map[38][32] = 0;
	obj->map[32][26] = 0;
}

static void		add_walls_map_two(t_connection *obj, int x, int y)
{
	if (x == MAPWIDTH - 5 && y != 1 && y != 2)
		obj->map[x][y] = 1;
	if (y == 3 && x != 1 && x != 2 && x != 46 && x != 47 && x != 48)
		obj->map[x][y] = 1;
	if (x == 3 && y != 1 && y != 2 && y != 46 && y != 47 && y != 48)
		obj->map[x][y] = 1;
	if (y == 45 && x != 1 && x != 2 && x != 43 && x != 44
		&& x != 46 && x != 47 && x != 48)
		obj->map[x][y] = 1;
}

void			random_map_2(t_connection *obj)
{
	int x;
	int y;

	obj->pos.x = 47;
	obj->pos.y = 47;
	obj->pos.win_low = 28;
	obj->pos.win_high = 31;
	rotate_left(obj, 1.6);
	y = -1;
	while (++y < MAPHEIGHT)
	{
		x = -1;
		while (++x < MAPWIDTH)
		{
			add_walls_map_two(obj, x, y);
			add_doors_map_two(obj, x, y);
		}
	}
}
