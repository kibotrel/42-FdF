/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 00:26:31 by kibotrel          #+#    #+#             */
/*   Updated: 2019/02/05 03:41:36 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "fdf.h"

static void	check_row(char *row)
{
	int		i;

	i = 0;
	if (!*row)
		print_error("Error : Empty row within the file.", 7);
	while (row[i])
	{
		if (row[i] == '-' && ft_isdigit(row[i + 1]))
			i++;
		else if (ft_isdigit(row[i]) || row[i] == ' ')
			i++;
		else
			print_error("Error : Incorrect row format.", 8);
	}
}

static void	expand_grid(int **table, t_env *env)
{
	int		y;
	int		x;

	y = -1;
	while (++y < env->height - 1)
	{
		x = -1;
		while (++x < env->width)
			table[y][x] = env->grid[y][x];
		free(env->grid[y]);
	}
	free(env->grid);
}

static void	str_to_int_table(char **coords, t_env *env)
{
	int		**table;
	int		y;
	int		x;

	if (!(table = (int**)malloc(sizeof(int*) * env->height)))
		print_error("Error : Can't allocate memory.", 1);
	y = -1;
	while (++y < env->height)
		if(!(table[y] = (int*)malloc(sizeof(int) * (env->width))))
			print_error("Error : Can't allocate memory.", 1);
	if (env->height - 1 > 0)
		expand_grid(table, env);
	x = -1;
	while (++x < env->width)
		table[y - 1][x] = ft_atoi(coords[x]);
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
			print_error("Error : Can't retrieve all points.", 6);
		if (env->height == 1)
			env->width = row_size(coords);
		else if (row_size(coords) != env->width)
			print_error("Error : Map width isn't the same on each row.", 5);
		str_to_int_table(coords, env);
		free(row);
		free(coords);
	}
}

void		parse_file(char *file, t_env *env)
{
	int		fd;
	int		y;
	int		x;

	if (!is_validname(file))
		print_error("Error : Wrong filename (expected *.fdf).", 4);
	if ((fd = open(file, O_RDONLY)) < 0)
		print_error("Error : Can't open file.", 2);
	get_values(fd, env);
	if (close(fd))
		print_error("Error : Can't close file.", 3);
	y = -1;
	while (++y < env->height)
	{
		x = -1;
		while (++x < env->width)
			printf("%d ", env->grid[y][x]);
		printf("\n");
	}
}
