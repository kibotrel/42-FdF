/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demonwav <demonwav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 07:31:19 by demonwav          #+#    #+#             */
/*   Updated: 2020/04/22 08:18:06 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "utils.h"
#include "graphic.h"

static void	line_parameters(t_line *params, t_pos a, t_pos b)
{
	params->sign_y = (a.y < b.y ? 1 : -1);
	params->sign_x = (a.x < b.x ? 1 : -1);
	params->delta_y = fabs(b.y - a.y);
	params->delta_x = fabs(b.x - a.x);
	params->offset = params->delta_x - params->delta_y;
	params->error = 0;
}

void		draw_line(t_pos a, t_pos b, t_env *env)
{
	t_pos	p;
	t_line	params;

	line_parameters(&params, a, b);
	p = a;
	while (p.y != b.y || p.x != b.x)
	{
		draw_pixel(env->sdl.screen, p, gradient(p, a, b, params));
		if ((params.error = params.offset * 2) > -params.delta_y)
		{
			params.offset -= params.delta_y;
			p.x += params.sign_x;
		}
		if (params.error < params.delta_x)
		{
			params.offset += params.delta_x;
			p.y += params.sign_y;
		}
	}
	draw_pixel(env->sdl.screen, p, gradient(p, a, b, params));
}
