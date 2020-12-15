/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdonya <sdonya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 17:58:56 by sdonya            #+#    #+#             */
/*   Updated: 2020/02/20 17:58:58 by sdonya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		ft_pixel_put(float x, float y, int z, t_fdf *fdf)
{
	mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x, y,\
	W - (fdf->color + fdf->shift_color) * z);
}

void		ft_step(float x, float y, t_fdf *fdf)
{
	int		max;

	fdf->x_step = x;
	fdf->y_step = y;
	max = ft_max(ft_mod(fdf->x_step), ft_mod(fdf->y_step));
	fdf->x_step /= max;
	fdf->y_step /= max;
}

void		ft_param(float *x, float *y, int z, t_fdf *fdf)
{
	*x -= fdf->width / 2.0;
	*y -= fdf->height / 2.0;
	*x *= fdf->zoom;
	*y *= fdf->zoom;
	if (fdf->flag == 1)
	{
		*x = *x * cos(fdf->angle) + z * fdf->shift_z * sin(fdf->angle);
		z = -1 * *x * sin(fdf->angle) + z * cos(fdf->angle);
	}
	else
	{
		*x = *x * cos(fdf->angle) - *y * sin(fdf->angle);
		*y = *x * sin(fdf->angle) + *y * cos(fdf->angle) - z * fdf->shift_z;
	}
	*x += fdf->shift_x;
	*y += fdf->shift_y;
}

void		ft_line(float x1, float y1, int flag, t_fdf *fdf)
{
	float	x2;
	float	y2;
	int		z1;
	int		z2;

	x2 = x1;
	y2 = y1;
	if (flag == 1)
		x2 = x1 + 1;
	else
		y2 = y1 + 1;
	z1 = fdf->matrix[(int)y1][(int)x1];
	z2 = fdf->matrix[(int)y2][(int)x2];
	ft_param(&x1, &y1, z1, fdf);
	ft_param(&x2, &y2, z2, fdf);
	ft_step(x2 - x1, y2 - y1, fdf);
	while ((int)(x1 - x2) || (int)(y1 - y2))
	{
		z1 ? ft_pixel_put(x1, y1, z1, fdf) : ft_pixel_put(x1, y1, z2, fdf);
		if (z1 == 0 && z2 == 0)
			mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x1, y1, W);
		x1 += fdf->x_step;
		y1 += fdf->y_step;
	}
}

void		ft_draw(t_fdf *fdf)
{
	int		x;
	int		y;

	y = 0;
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			if (x < fdf->width - 1)
				ft_line(x, y, 1, fdf);
			if (y < fdf->height - 1)
				ft_line(x, y, 2, fdf);
			x++;
		}
		y++;
	}
}
