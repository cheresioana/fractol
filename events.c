/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 16:27:37 by icheres           #+#    #+#             */
/*   Updated: 2017/01/22 22:07:14 by icheres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	continue_drawing(t_tot *tot)
{
	mlx_destroy_image(tot->mlx.mlx, tot->data.img);
	tot->data = init_img_mlx(tot->data, &tot->mlx);
	ft_julia(&tot->mlx, &tot->conf, &tot->data);
}

int		key_hook(int keycode, t_tot *tot)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 125)
		tot->conf.move_y += 0.01;
	else if (keycode == 126)
		tot->conf.move_y -= 0.01;
	else if (keycode == 124)
		tot->conf.move_x += 0.01;
	else if (keycode == 123)
		tot->conf.move_x -= 0.01;
	continue_drawing(tot);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_tot *tot)
{
	tot->conf.move_x += (WIDTHIMG / 2 - x) * -0.00035;
	tot->conf.move_y += (HEIGHTIMG / 2 - y) * -0.00035;
	if (button == 4)
		tot->conf.zoom *= 1.2;
	else if (button == 5)
		tot->conf.zoom /= 1.2;
	continue_drawing(tot);
	return (0);
}
