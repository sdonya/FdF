/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 18:32:27 by kplums            #+#    #+#             */
/*   Updated: 2020/02/02 18:32:29 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# include "../libft/includes/libft.h"
# include <OpenGL/OpenGL.h>
# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

# define W 0xffffff

typedef struct	s_fdf
{
	int			width;
	int			height;
	int			**matrix;
	int			zoom;
	int			color;
	float		x_step;
	float		y_step;
	int			shift_x;
	int			shift_y;
	int			shift_z;
	int			shift_color;
	int			flag;
	float		angle;
	void		*mlx_ptr;
	void		**win_ptr;
}				t_fdf;

int				ft_mod(int a);
int				ft_max(int a, int b);
void			ft_text(t_fdf *fdf);
void			ft_text2(t_fdf *fdf);
int				ft_validation(t_fdf *fdf, char *str, int flag);
void			ft_koord(char *str, t_fdf *fdf, int y);
void			ft_error(t_fdf *fdf, char *str, int fd);
void			ft_draw(t_fdf *fdf);
void			ft_delfdf(t_fdf *fdf);
int				deal_mouse(int mouse, int x, int y, t_fdf *fdf);
int				deal_key(int key, t_fdf *fdf);

#endif
