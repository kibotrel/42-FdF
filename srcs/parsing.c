/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 00:26:31 by kibotrel          #+#    #+#             */
/*   Updated: 2019/02/15 14:52:02 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "env.h"
#include "fdf.h"

static void	str_to_int_table(char **coords, t_env *env)
{
	t_pos		**table;
	int			y;
	int			x;

	if (!(table = (t_pos**)malloc(sizeof(t_pos*) * env->height)))
		print_error("ERR_MALLOC", 1);
	y = -1;
	while (++y < env->height)
		if (!(table[y] = (t_pos*)malloc(sizeof(t_pos) * (env->width))))
			print_error("ERR_MALLOC", 1);
	if (env->height - 1 > 0)
		expand_grid(table, env);
	x = -1;
	while (++x < env->width)
	{
		table[y - 1][x].x = x;
		table[y - 1][x].y = y - 1;
		table[y - 1][x].z = ft_atoi(coords[x]);
	}
	env->grid = table;
}

static void	get_values(int fd, t_env *env)
{
	char	*row;
	char	**coords;

	env->height = 0;
	while (ft_get_next_line(fd, &row))
	{
		env->height++;
		check_row(row);
		if (!(coords = ft_strsplit(row, ' ')))
			print_error(ERR_SPLIT, 6);
		if (env->height == 1)
			env->width = row_size(coords);
		else if (row_size(coords) != env->width)
			print_error(ERR_WIDTH, 5);
		str_to_int_table(coords, env);
		free(row);
		free_tab(coords);
	}
	if (!env->height)
		print_error(ERR_EMPTY_FILE, 9);
}

void		parse_file(char *file, t_env *env)
{
	int		fd;

	if (!is_validname(file))
		print_error(ERR_FILENAME, 4);
	if ((fd = open(file, O_RDONLY)) < 0)
		print_error(ERR_OPEN, 2);
	get_values(fd, env);
	if (close(fd))
		print_error(ERR_CLOSE, 3);
}
