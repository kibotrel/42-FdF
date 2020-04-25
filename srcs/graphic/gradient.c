/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demonwav <demonwav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 07:48:10 by demonwav          #+#    #+#             */
/*   Updated: 2020/04/25 06:02:21 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

static int		light(int start, int end, double percent)
{
	return ((int)((1 - percent) * start + percent * end));
}

static double	ratio(int a, int b, int x)
{
	return (b - a == 0 ? 1.0 : (double)(x - a) / (double)(b - a));
}

int				gradient(t_pos pos, t_pos start, t_pos end, t_line params)
{
	int		red;
	int		green;
	int		blue;
	double	percent;

	if (pos.color == end.color)
		return (pos.color);
	if (params.delta_x > params.delta_y)
		percent = ratio(start.x, end.x, pos.x);
	else
		percent = ratio(start.y, end.y, pos.y);
	red = light((start.color >> 16) & 0xFF, (end.color >> 16) & 0xFF, percent);
	green = light((start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF, percent);
	blue = light(start.color & 0xFF, end.color & 0xFF, percent);
	return ((red << 16) | (green << 8) | blue);
}

int				init_color(t_env *env, int z)
{
	double	percent;

	percent = ratio(env->z_min, env->z_max, z);
	if (percent < 0.005)
		return (env->color_min);
	else if (percent < 0.0525)
		return (env->color_fourth);
	else if (percent < 0.125)
		return (env->color_half);
	else if (percent < 0.275)
		return (env->color_third);
	else
		return (env->color_max);
}
