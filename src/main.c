/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdonya <sdonya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 22:26:06 by sdonya            #+#    #+#             */
/*   Updated: 2020/02/02 17:32:33 by sdonya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		ft_text2(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 10, W, \
	"Team sdonya and kplums");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 45, W, "KEYBOARD");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 65, W, \
	"Button movement - up, down, right, left");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 84, W, \
	"Color           - +, -");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 100, W,\
	"Zoom            - W, S");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 117, W, \
	"Angle           - A, D");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 135, W, \
	"Angle = const   - 0");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 153, W, \
	"Change of angle - 1, 2");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 170, W,\
	"Exit            - ESC");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 200, W, "MOUSE");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 220, W, \
	"Change height   - wheel UP and DOWN");
}

void		ft_text(t_fdf *fdf)
{
	ft_text2(fdf);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 580, 45, W, "COLOR");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 500, 65, 0xffff00, "Yellow");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 500, 85, 0xff6699, "Pink");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 500, 105, 0xff00ff, "Fuchsia");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 500, 125, 0x0000ff, "Blue");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 650, 65, 0x00ff00, "Green");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 650, 85, 0xfffa500, "Orange");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 650, 105, 0x800080, "Purple");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 650, 125, 0xff0000, "Red");
}

void		ft_startfdf(t_fdf *fdf)
{
	fdf->height = 0;
	fdf->zoom = 15;
	fdf->color = 0x0ff000;
	fdf->shift_x = 550;
	fdf->shift_y = 550;
	fdf->angle = 0.8;
	fdf->shift_color = 0;
	fdf->flag = 0;
	fdf->shift_z = 1;
	fdf->matrix = NULL;
}

int			main(int ac, char **av)
{
	t_fdf	*fdf;

	fdf = NULL;
	if (ac != 2)
		ft_error(fdf, "ac", 0);
	if (!(fdf = (t_fdf*)malloc(sizeof(t_fdf))))
		ft_error(fdf, "malloc fdf", 0);
	ft_startfdf(fdf);
	if (ft_validation(fdf, av[1], 0) == 0)
		ft_error(fdf, "validation", 0);
	ft_koord(av[1], fdf, 0);
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, 1500, 1500, "FDF");
	ft_draw(fdf);
	mlx_hook(fdf->win_ptr, 2, fdf->width, deal_key, fdf);
	mlx_hook(fdf->win_ptr, 4, fdf->width, deal_mouse, fdf);
	ft_text(fdf);
	mlx_loop(fdf->mlx_ptr);
	return (0);
}
