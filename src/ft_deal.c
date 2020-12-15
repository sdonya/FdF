/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdonya <sdonya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 17:22:16 by sdonya            #+#    #+#             */
/*   Updated: 2020/02/20 17:22:17 by sdonya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_mouse(int x, int y, t_fdf *fdf)
{
	if (x > 500 && x < 560 && y > 65 && y < 87)
		fdf->color = 0x0000ff;
	if (x > 500 && x < 545 && y > 93 && y < 110)
		fdf->color = 0x000ff0;
	if (x > 500 && x < 570 && y > 115 && y < 125)
		fdf->color = 0x00ff00;
	if (x > 500 && x < 545 && y > 130 && y < 147)
		fdf->color = 0x0ff000;
	if (x > 650 && x < 705 && y > 70 && y < 85)
		fdf->color = 0x0f000f;
	if (x > 650 && x < 715 && y > 90 && y < 105)
		fdf->color = 0xf00f0ff;
	if (x > 650 && x < 715 && y > 110 && y < 125)
		fdf->color = 0x0fff0f;
	if (x > 650 && x < 685 && y > 130 && y < 150)
		fdf->color = 0x00ffff;
}

int		deal_mouse(int mouse, int x, int y, t_fdf *fdf)
{
	int	x1;
	int	y1;

	x1 = 0;
	y1 = 0;
	if (x1 < x && y1 < y)
		ft_mouse(x, y, fdf);
	if (mouse == 5)
		fdf->shift_z += 1;
	if (mouse == 4)
		fdf->shift_z -= 1;
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	ft_draw(fdf);
	ft_text(fdf);
	return (0);
}

void	ft_key(int key, t_fdf *fdf)
{
	if (key == 126)
		fdf->shift_y -= 10;
	if (key == 125)
		fdf->shift_y += 10;
	if (key == 123)
		fdf->shift_x -= 10;
	if (key == 124)
		fdf->shift_x += 10;
	if (key == 13)
		fdf->zoom += 2;
	if (key == 1)
		fdf->zoom -= 2;
	if (key == 0)
		fdf->angle += 0.02;
	if (key == 2)
		fdf->angle -= 0.02;
}

int		deal_key(int key, t_fdf *fdf)
{
	ft_key(key, fdf);
	if (key == 69)
		fdf->shift_color += 1;
	if (key == 78)
		fdf->shift_color -= 1;
	if (key == 18)
		fdf->flag = 1;
	if (key == 19)
		fdf->flag = 2;
	if (key == 82)
		fdf->angle = 0.8;
	if (key == 53)
	{
		ft_delfdf(fdf);
		exit(0);
	}
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	ft_draw(fdf);
	ft_text(fdf);
	return (0);
}
