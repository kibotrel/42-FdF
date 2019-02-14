/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 00:54:37 by kibotrel          #+#    #+#             */
/*   Updated: 2019/02/07 08:27:35 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fdf.h"

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

int		row_size(char **coords)
{
	int		y;

	y = 0;
	while (coords[y])
		y++;
	return (y);
}

void	check_row(char *row)
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

int		absolute_value(int nb)
{
	return (nb < 0 ? -nb : nb);
}
