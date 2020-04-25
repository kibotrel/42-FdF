/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demonwav <demonwav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 06:06:58 by demonwav          #+#    #+#             */
/*   Updated: 2020/04/25 03:57:36 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "graphic.h"

void	print_map(t_env *env)
{
	int	y;
	int	x;

	y = -1;
	while (++y < env->height)
	{
		x = -1;
		while (++x < env->width)
		{
			if (x < env->width - 1)
				draw_line(transform(env->grid[y][x], env),
				transform(env->grid[y][x + 1], env), env);
			if (y < env->height - 1)
				draw_line(transform(env->grid[y][x], env),
				transform(env->grid[y + 1][x], env), env);
		}
	}
}
