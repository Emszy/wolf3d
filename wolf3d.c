#include "wolf3d.h"

void  error_master5000(char *message)
{
  ft_putstr(message);
  ft_putstr("\n");
  exit(-1);
}

int goodbye(void)
{
  exit(0);
}

void  chorus(t_connection *obj)
{
    mlx_hook(obj->win, 2, 0, key_down_hook, obj);
    mlx_hook(obj->win, 3, 0, key_up_hook, obj);
    mlx_loop_hook(obj->mlx, loop_hook, obj);
    mlx_hook(obj->win, 17, 0, goodbye, obj);
    mlx_loop(obj->mlx);
}

int main(int ac, char **av)
{
	t_connection *obj;
	obj = malloc(sizeof(t_connection));
	initializer(obj);
	if (ac == 1)
	{
		random_map_2(obj);
		obj->map_chosen = 2;
	}
	else if (ac == 2 && ft_strcmp(av[1], "1") == 0)
	{
	 	random_map_1(obj);
	 	obj->map_chosen = 1;
	}
	else if (ac == 2 && ft_strcmp(av[1], "2") == 0)
	{
	 	random_map_2(obj);
	 	obj->map_chosen = 2;
	}
	else
		error_master5000("Usage:\n ./wolf3d\n ./wolf3d 1\n ./wolf3d 2");
	ray_calc(obj);
	chorus(obj);
	return (0);
}








