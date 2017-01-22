/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 16:31:33 by icheres           #+#    #+#             */
/*   Updated: 2017/01/22 22:51:25 by icheres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

extern t_col_name g_mlx_col_name[];

long	get_color(int red, int green, int blue)
{
	long rgb;

	rgb = red;
	rgb = (rgb << 8) + green;
	rgb = (rgb << 8) + blue;
	return (rgb);
}

void	init_struct(t_complexstruct *struc)
{
	struc->point.im = 0.27015;
	struc->point.re = -0.7;
}

int		get_iter(t_conf *config, t_complexstruct *struc)
{
	int			iter;

	iter = 0;
	while (iter <= config->max_iter)
	{
		struc->old.re = struc->nou.re;
		struc->old.im = struc->nou.im;
		struc->nou.re = struc->old.re * struc->old.re - struc->old.im *
			struc->old.im + struc->point.re;
		struc->nou.im = 2 * struc->old.re * struc->old.im + struc->point.im;
		if ((struc->nou.re * struc->nou.re + struc->nou.im * struc->nou.im)
				> 4)
			break ;
		iter += 3;
	}
	return (iter);
}

void	ft_julia(t_mlx *mlx, t_conf *config, t_data *img)
{
	t_point			z;
	t_complexstruct	struc;
	t_var			v;

	init_struct(&struc);
	v.i = 0;
	while (v.i < HEIGHTIMG)
	{
		v.j = 0;
		while (v.j < WIDTHIMG)
		{
			struc.nou.re = 1.5 * (v.j - WIDTHIMG / 2) / (0.5 * config->zoom
					* WIDTHIMG) + config->move_x;
			struc.nou.im = (v.i - HEIGHTIMG / 2) / (0.5 * config->zoom *
					HEIGHTIMG) + config->move_y;
			v.iter = get_iter(config, &struc);
			put_pixel(img, v.j, v.i, g_mlx_col_name[v.iter % 500].color);
			v.j++;
		}
		v.i++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, img->img, 0, 0);
}
