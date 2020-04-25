/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demonwav <demonwav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 01:00:01 by demonwav          #+#    #+#             */
/*   Updated: 2020/04/25 06:49:03 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "env.h"
#include "clean.h"
#include "libft.h"
#include "utils.h"

static void	str_to_int_table(char **coords, t_env *env)
{
	int			error;
	t_pos		p;
	t_pos		**table;

	error = 0;
	if (!(table = (t_pos**)malloc(sizeof(t_pos*) * env->height)))
		error = 1;
	p.y = -1;
	while (++p.y < env->height && !error)
		if (!(table[p.y] = (t_pos*)malloc(sizeof(t_pos) * (env->width))))
			error = 1;
	error ? free(coords) : 0;
	error ? clean(env, 1, ERR_MALLOC) : 0;
	if (env->height - 1 > 0)
		expand_grid(table, env);
	p.x = -1;
	while (++p.x < env->width)
	{
		table[p.y - 1][p.x].x = p.x;
		table[p.y - 1][p.x].y = p.y - 1;
		table[p.y - 1][p.x].z = ft_atoi(coords[p.x]);
	}
	env->grid = table;
}

static void	get_values(int fd, t_env *env)
{
	char	*row;
	char	**coords;

	env->height = 0;
	while (ft_get_next_line(fd, &row) && ++env->height)
	{
		check_row(row);
		if (!(coords = ft_strsplit(row, ' ')))
			clean(env, 6, ERR_SPLIT);
		if (env->height == 1)
			env->width = row_size(coords);
		else if (row_size(coords) != env->width)
		{
			free(row);
			free_tab(coords);
			clean(env, 5, ERR_WIDTH);
		}
		str_to_int_table(coords, env);
		free(row);
		free_tab(coords);
	}
	if (!env->height)
		clean(env, 9, ERR_EMPTY_FILE);
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
		clean(env, 3, ERR_CLOSE);
}
