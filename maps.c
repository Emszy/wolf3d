#include "wolf3d.h"

void reset_map(t_connection *obj)
{
	int x;
	int y;

	y = -1;
	while(++y < mapHeight)
	{
		x = -1;
		while (++x < mapWidth)
		{
			obj->map[x][y] = 0;
		}
	}
}

void	win_building(t_connection *obj, int x, int y, int offset)
{
	int m;
	m = 0;

	while (m < 20)
	{
		if (y == mapHeight / 2 + offset && x == mapWidth / 2 + m + offset)
			obj->map[x][y] = 1;
	
		if (y == mapHeight / 2 + m + offset && x == mapWidth / 2 + offset)
			obj->map[x][y] = 1;
		if (y == mapHeight / 2 + m + offset && x == mapWidth / 2 + 7 + offset)
			obj->map[x][y] = 1;
		if (y == mapHeight / 2 + 7 + offset && x == mapWidth / 2 + m + offset)
			obj->map[x][y] = 1;
		m++;
	}
	if (x == mapWidth / 2  + 4 + offset && y == mapHeight / 2 + 4 + offset )
		obj->map[x][y] = 7;
}

void	random_map_1(t_connection *obj)
{
	int x;
	int y;
	obj->pos.x = 15;
  	obj->pos.y = 3;
  	obj->pos.win_low = 36;
  	obj->pos.win_high = 40;

  		rotate_left(obj, 3);
	y = -1;
	while(++y < mapHeight)
	{
		x = -1;
		while (++x < mapWidth)
		{
			obj->map[x][y] = 0;
			if (x == 5 || y == 5 || x == mapWidth - 5 || (y == mapHeight - 5))
				obj->map[x][y] = 1;
			if (x == 7 || y == 9 || x == mapWidth - 10 || (y == mapHeight - 14))
				obj->map[x][y] = 1;
			if (x == mapWidth / 2 + 5 || y == mapHeight / 2 + 5 || x == mapWidth - 10 || (y == mapHeight - 14))
				obj->map[x][y] = 1;
			win_building(obj, x, y, 8);
			if (x == mapWidth / 2 || y == mapHeight / 2)
				obj->map[x][y] = 0;
			if (x == 0 || y == 0 || x == mapWidth - 1 || (y == mapHeight - 2))
				obj->map[x][y] = 1;
			if (x == mapWidth / 2 + 7 && y == mapHeight / 2 + 6)
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
	}
}

void random_map_2(t_connection *obj)
{
	int x;
	int y;

	obj->pos.x = 47;
  	obj->pos.y = 47;
  	obj->pos.win_low = 28;
  	obj->pos.win_high = 31;
	rotate_left(obj, 1.6);
	y = -1;
	while(++y < mapHeight)
	{
		x = -1;
		while (++x < mapWidth)
		{
			if (x == mapWidth - 5 && y != 1 && y != 2)
				obj->map[x][y] = 1;
			if (y == 3 && x != 1 && x != 2 && x != 46 && x != 47 && x != 48)
				obj->map[x][y] = 1;
			if (x == 3 && y != 1 && y != 2 && y != 46 && y != 47 && y != 48)
				obj->map[x][y] = 1;
			if (y == 45 && x != 1 && x != 2 && x != 43 && x != 44 && x != 46 && x != 47 && x != 48)
				obj->map[x][y] = 1;
			win_building(obj, x, y, 0);
			if (x == 0 || y == 0 || x == mapWidth - 1 || (y == mapHeight - 2))
				obj->map[x][y] = 1;
			obj->map[32][42] = 0;
			obj->map[25][41] = 0;
			obj->map[38][32] = 0;
			obj->map[32][26] = 0;
		}
	}
}