/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebucheit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 21:56:25 by ebucheit          #+#    #+#             */
/*   Updated: 2017/04/25 21:56:25 by ebucheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	create_img(t_connection *obj)
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

	i = 0;
	if (x > 0 && x < WIDTH && y > 0 & y < HEIGHT)
	{
		i = (x * (obj->img.bpp / 8)) + (y * obj->img.line_size);
		obj->img.pix[i] = color;
		obj->img.pix[++i] = color >> 8;
		obj->img.pix[++i] = color >> 16;
	}
}

void	choose_color(t_connection *obj, int side)
{
	if (side == 1)
	{
		if ((obj->ray.step_x == -1 && obj->ray.step_y == -1) ||
			(obj->ray.step_x == 1 && obj->ray.step_y == -1))
			obj->pos.color = SHADOW_RED;
		if ((obj->ray.step_x == -1 && obj->ray.step_y == 1) ||
			(obj->ray.step_x == 1 && obj->ray.step_y == 1))
			obj->pos.color = SHADOW_GREEN;
	}
	else
	{
		if ((obj->ray.step_x == -1 && obj->ray.step_y == -1) ||
			(obj->ray.step_x == -1 && obj->ray.step_y == 1))
			obj->pos.color = SHADOW_BLUE;
		else
			obj->pos.color = PURPLE;
	}
}

void	draw(t_connection *obj, int line_height, int side, int x)
{
	int line_start;
	int line_end;

	line_start = -line_height / 2 + HEIGHT / 2;
	if (line_start < 0)
		line_start = 0;
	line_end = line_height / 2 + HEIGHT / 2;
	if (line_end >= HEIGHT)
		line_end = HEIGHT - 1;
	choose_color(obj, side);
	put_line(obj, x, line_start, line_end);
	obj->pos.color = BROWN;
	put_line(obj, x, line_end, HEIGHT);
	obj->pos.color = BLUE;
	put_line(obj, x, 0, line_start);
}

void	put_line(t_connection *obj, int x1, int y1, int y2)
{
	int dx;
	int p;
	int i;

	i = -1;
	dx = y2 - y1;
	p = -dx;
	while (++i < dx)
	{
		draw_pixel_to_img(obj, x1, y1, obj->pos.color);
		while (p >= 0)
			p = p - 2 * dx;
		y1 += 1;
	}
}
