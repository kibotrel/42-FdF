/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demonwav <demonwav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 01:03:26 by demonwav          #+#    #+#             */
/*   Updated: 2020/04/22 01:28:04 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "env.h"
#include "libft.h"
#include "utils.h"

int		row_size(char **coords)
{
	int		y;

	y = 0;
	while (coords[y])
		y++;
	return (y);
}

int		is_validname(char *filename)
{
	int		i;
	int		j;
	char	*reference;

	reference = ".fdf";
	i = ft_strlen(filename) - 1;
	j = 3;
	while (j >= 0)
		if (filename[i--] != reference[j--])
			return (0);
	return (i >= 0 ? 1 : 0);
}

void	free_tab(char **coords)
{
	int	y;

	y = 0;
	while (coords[y])
		free(coords[y++]);
	free(coords);
}

void	check_row(char *row)
{
	int		i;

	i = 0;
	if (!*row)
		print_error(ERR_EMPTY_ROW, 7);
	while (row[i])
	{
		if (row[i] == '-' && ft_isdigit(row[i + 1]))
			i++;
		else if (ft_isdigit(row[i]) || row[i] == ' ')
			i++;
		else
			print_error(ERR_FORMAT, 8);
	}
}

void	expand_grid(t_pos **table, t_env *env)
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
