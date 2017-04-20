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


void  init_window(t_connection *obj)
{
  obj->mlx = mlx_init();
  obj->win = mlx_new_window(obj->mlx, WIDTH, HEIGHT, "WLOLF3D");
}
void  initializer(t_connection *obj)
{
  init_window(obj);
}

void  error_master5000(char *message)
{
  ft_putstr(message);
  ft_putstr("\n");
  exit(-1);
}



