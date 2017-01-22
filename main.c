/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 20:18:36 by icheres           #+#    #+#             */
/*   Updated: 2017/01/22 22:08:41 by icheres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		init_julia_config(t_conf *config)
{
	config->zoom = 1;
	config->move_x = 0;
	config->move_y = 0;
	config->max_iter = 650;
	config->name = (char *)malloc(sizeof(char) * 6);
	config->name = "Julia";
}

int			valid(int argc, char *av[])
{
	if (argc != 2)
		return (0);
	if (ft_strcmp(av[1], "Julia") != 0 && ft_strcmp(av[1], "Mandelbrot") != 0)
		return (0);
	return (1);
}

int			main(int argc, char *av[])
{
	t_tot		*tot;

	tot = (t_tot*)malloc(sizeof(t_tot));
	if (!valid(argc, av))
		return (0);
	init_mlx(&tot->mlx);
	tot->data = init_img_mlx(tot->data, &tot->mlx);
	if (ft_strcmp(av[1], "Julia") == 0)
	{
		init_julia_config(&tot->conf);
		ft_julia(&tot->mlx, &tot->conf, &tot->data);
	}
	mlx_key_hook(tot->mlx.win, key_hook, tot);
	mlx_mouse_hook(tot->mlx.win, mouse_hook, tot);
	mlx_loop(tot->mlx.mlx);
	return (0);
}
