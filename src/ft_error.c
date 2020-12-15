/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:24:07 by kplums            #+#    #+#             */
/*   Updated: 2020/02/11 16:24:10 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_error(t_fdf *fdf, char *str, int fd)
{
	if (!str)
		ft_putstr_fd("Error Error\n", 2);
	else if (ft_strcmp(str, "ac") == 0)
		ft_putstr_fd("usage: ./fdf input_file\n", 2);
	else
	{
		ft_putstr_fd("Error ", 2);
		ft_putstr_fd(str, 2);
		ft_putchar_fd('\n', 2);
	}
	if (fdf != NULL)
		ft_delfdf(fdf);
	if (fd != 0)
		close(fd);
	exit(1);
}
