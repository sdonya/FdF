/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 19:47:17 by kplums            #+#    #+#             */
/*   Updated: 2020/02/06 19:47:19 by kplums           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			checkline(char *line)
{
	int		i;

	i = 0;
	if (!line)
		ft_error(NULL, "no line", 2);
	while (line[i] != '\0')
	{
		if (line[i] != ' ' && ft_isdigit(line[i]) == 0 && line[i] != '-')
		{
			return (0);
		}
		if (line[i] == '-')
		{
			if (!(line[i + 1]) && ft_isdigit(line[i + 1]) == 0)
				return (0);
			if (i != 0 && ft_isdigit(line[i - 1]) == 1)
				return (0);
		}
		i++;
	}
	return (1);
}

int			ft_validation(t_fdf *fdf, char *str, int flag)
{
	int		fd;
	int		gnl;
	char	*line;

	line = NULL;
	if ((fd = open(str, O_RDWR)) < 1)
		ft_error(fdf, "open fd validation", 0);
	while ((gnl = get_next_line(fd, &line)) == 1)
	{
		if (checkline(line) == 0)
			ft_error(fdf, "check", fd);
		fdf->height++;
		if (flag == 0)
		{
			fdf->width = ft_countarrtochar(line, ' ');
			flag = fdf->width;
		}
		if (ft_countarrtochar(line, ' ') != flag)
			ft_error(fdf, "validation: wrong len", fd);
		ft_memdel((void **)&line);
	}
	ft_memdel((void **)&line);
	close(fd);
	return (gnl == -1 ? 0 : 1);
}
