/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 17:27:17 by icheres           #+#    #+#             */
/*   Updated: 2017/01/22 21:55:55 by icheres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"
#include <stdio.h>

t_data		init_img_mlx(t_data i, t_mlx *mlx)
{
	i.img = mlx_new_image(mlx->mlx, WIDTHIMG, HEIGHTIMG);
	i.data = mlx_get_data_addr(i.img, &i.bpp, &i.size_line, &i.endian);
	return i;
}

void		init_mlx(t_mlx *c)
{
	if ((c->mlx = mlx_init()) == NULL)
		err_exit("error in setting the window");
	if ((c->win = mlx_new_window(c->mlx, WIDTH, HEIGHT, "fractol")) == NULL)
		err_exit("error in setting the window");
}

void	put_pixel(t_data *i, int x, int y, int col)
{
	int		offset;

	offset = (int)x * 4;
	offset += (int)y * i->size_line;
	*(int *)(i->data + offset) = col;
	//printf("%d off %d sln\n", offset, i->size_line);
}

t_point	point(int x, int y)
{
	t_point point;

	point.x = x;
	point.y = y;
	return (point);
}
