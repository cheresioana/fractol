/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mymlx.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 17:32:49 by icheres           #+#    #+#             */
/*   Updated: 2017/01/22 16:12:40 by icheres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MYMLX_H
# define FT_MYMLX_H

# define WIDTH 800
# define HEIGHT 800
# define WIDTHIMG 800
# define HEIGHTIMG 800

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

typedef	struct		s_mlx
{
	void		*win;
	void		*mlx;
	int			width;
	int			height;
	int			i;
	int			j;

}					t_mlx;

typedef struct		s_data
{

	int			size_line;
	int			endian;
	char		*data;
	int			bpp;
	void		*img;
}					t_data;

typedef struct		s_point
{
	int			x;
	int			y;
}					t_point;

t_data		init_img_mlx(t_data img, t_mlx *mlx);
void		init_mlx(t_mlx *c);
void		put_pixel(t_data *i, int x, int y, int color);
t_point		point(int x, int y);
void		err_exit(char *s);

#endif
