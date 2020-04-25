/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_view.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demonwav <demonwav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 03:20:06 by demonwav          #+#    #+#             */
/*   Updated: 2020/04/25 03:23:11 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "env.h"
#include "structs.h"

void	reset_view(t_env *env)
{
	env->cam.zoom = fmin(WIDTH / env->width / 2, HEIGHT / env->height / 2);
	env->cam.offset_x = 0;
	env->cam.offset_y = 0;
	env->cam.depth = 20.0;
	env->cam.alpha = 0.0;
	env->cam.beta = 0.0;
	env->cam.gamma = 0.0;
}
