/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebucheit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 21:56:25 by ebucheit          #+#    #+#             */
/*   Updated: 2017/04/25 21:56:25 by ebucheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void			reset_map(t_connection *obj)
{
	int x;
	int y;

	y = -1;
	while (++y < MAPHEIGHT)
	{
		x = -1;
		while (++x < MAPWIDTH)
		{
			obj->map[x][y] = 0;
		}
	}
}

void			win_building(t_connection *obj, int x, int y, int offset)
{
	int m;

	m = 0;
	while (m < 20)
	{
		if (y == MAPHEIGHT / 2 + offset && x == MAPWIDTH / 2 + m + offset)
			obj->map[x][y] = 1;
		if (y == MAPHEIGHT / 2 + m + offset && x == MAPWIDTH / 2 + offset)
			obj->map[x][y] = 1;
		if (y == MAPHEIGHT / 2 + m + offset && x == MAPWIDTH / 2 + 7 + offset)
			obj->map[x][y] = 1;
		if (y == MAPHEIGHT / 2 + 7 + offset && x == MAPWIDTH / 2 + m + offset)
			obj->map[x][y] = 1;
		m++;
	}
	if (x == MAPWIDTH / 2 + 4 + offset && y == MAPHEIGHT / 2 + 4 + offset)
		obj->map[x][y] = 7;
}

static void		add_doors_map_one(t_connection *obj, int x, int y)
{
	if (x == MAPWIDTH / 2 || y == MAPHEIGHT / 2)
		obj->map[x][y] = 0;
	if (x == 0 || y == 0 || x == MAPWIDTH - 1 || (y == MAPHEIGHT - 2))
		obj->map[x][y] = 1;
	if (x == MAPWIDTH / 2 + 7 && y == MAPHEIGHT / 2 + 6)
		obj->map[x][y] = 0;
	obj->map[33][42] = 0;
	obj->map[47][30] = 0;
	obj->map[32][30] = 0;
	obj->map[32][36] = 0;
	obj->map[40][40] = 0;
	obj->map[40][32] = 0;
	obj->map[45][33] = 0;
	obj->map[39][40] = 0;
}

void			random_map_1(t_connection *obj)
{
	int x;
	int y;

	obj->pos.x = 15;
	obj->pos.y = 3;
	obj->pos.win_low = 38;
	obj->pos.win_high = 41;
	rotate_left(obj, 3);
	y = -1;
	while (++y < MAPHEIGHT)
	{
		x = -1;
		while (++x < MAPWIDTH)
		{
			if (x == 5 || y == 5 || x == MAPWIDTH - 5 || (y == MAPHEIGHT - 5))
				obj->map[x][y] = 1;
			if (x == 7 || y == 9 || x == MAPWIDTH - 10 || (y == MAPHEIGHT - 14))
				obj->map[x][y] = 1;
			if (x == MAPWIDTH / 2 + 5 || y == MAPHEIGHT / 2 + 5 ||
				x == MAPWIDTH - 10 || (y == MAPHEIGHT - 14))
				obj->map[x][y] = 1;
			win_building(obj, x, y, 8);
			add_doors_map_one(obj, x, y);
		}
	}
}
