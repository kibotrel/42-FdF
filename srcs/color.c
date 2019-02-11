/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 18:05:41 by kibotrel          #+#    #+#             */
/*   Updated: 2019/02/11 19:25:16 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "env.h"

static double	ratio(int start, int end, int current)
{
	double	pos;
	double	distance;

	pos = current - start;
	distance = end - start;
	return (distance == 0 ? 1.0 : pos / distance);
}

static int		light(int start, int end, double percent)
{
	return ((int)((1 - percent) * start + percent * end));
}

int		init_color(t_env* env, t_pos p)
{
	double	percent;

	percent = ratio(env->z_min, env->z_max, p.z);
	if (percent < 0.2)
		return (WHITE);
	else if (percent < 0.4)
		return (GREEN);
	else if (percent < 0.6)
		return (YELLOW);
	else if (percent < 0.8)
		return (ORANGE);
	else
		return (RED);
}

int				color(t_pos pos, t_pos start, t_pos end, t_line params)
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
