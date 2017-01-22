/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 15:31:51 by icheres           #+#    #+#             */
/*   Updated: 2017/01/22 21:52:36 by icheres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include "includes/libft/libft.h"
# include "aux/mlx_res/mymlx.h"
# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>

typedef struct		s_comp
{
	double		im;
	double		re;
}					t_comp;

typedef struct s_col_name
{
	char *name;
	int color;
}               t_col_name;

typedef struct		s_var
{
	int			x;
	int			iter;
	int			y;
	int			z;
	int			i;
	int			j;
}					t_var;

typedef struct		s_complexstruct
{
	t_comp		point;
	t_comp		nou;
	t_comp		old;
}					t_complexstruct;

typedef struct		s_conf
{
	t_comp		c;
	t_comp		oldCoord;
	t_comp		newCoord;
	double		zoom;
	double		move_x;
	double		move_y;
	char		*name;
	int			max_iter;	
}					t_conf;

typedef struct		s_tot
{
	t_conf		conf;
	t_mlx		mlx;
	t_data		data;
}					t_tot;

void			ft_julia(t_mlx *mlx, t_conf *conf, t_data *data);
void			ft_mandelbrot(t_mlx mlx);
void			err(char *s);
int				key_hook(int keycode, t_tot *tot);
int				mouse_hook(int button, int x, int y, t_tot *tot);

#endif
