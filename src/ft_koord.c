/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_koord.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 19:54:58 by kplums            #+#    #+#             */
/*   Updated: 2020/02/06 19:55:00 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		ft_delarr(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		ft_memdel((void **)&arr[i]);
		i++;
	}
	ft_memdel((void**)&arr);
}

void		ft_koord(char *str, t_fdf *fdf, int y)
{
	int		fd;
	int		x;
	char	*line;
	char	**arr;

	x = -1;
	if ((fd = open(str, O_RDWR)) < 1)
		ft_error(fdf, "open fd koord", 0);
	if (!(fdf->matrix = (int **)malloc(fdf->height * sizeof(int *))))
		ft_error(fdf, "malloc **matrix", fd);
	while (get_next_line(fd, &line) == 1)
	{
		x = -1;
		arr = ft_strsplit(line, ' ');
		if (!(fdf->matrix[y] = (int *)malloc(fdf->width * sizeof(int))))
			ft_error(fdf, "malloc matrix y", fd);
		while (++x < fdf->width)
			fdf->matrix[y][x] = ft_atoi(arr[x]);
		ft_delarr(arr);
		arr = NULL;
		ft_memdel((void **)&line);
		y++;
	}
	ft_memdel((void **)&line);
	close(fd);
}
