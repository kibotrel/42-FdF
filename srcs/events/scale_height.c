/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_height.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demonwav <demonwav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 03:35:14 by demonwav          #+#    #+#             */
/*   Updated: 2020/04/25 03:38:05 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "structs.h"

void	scale_height(t_env *env)
{
	if (env->input[SDL_SCANCODE_PAGEUP] && env->cam.depth > MIN_DEPTH)
		env->cam.depth -= 0.4;
	if (env->input[SDL_SCANCODE_PAGEDOWN] && env->cam.depth < MAX_DEPTH)
		env->cam.depth += 0.4;
}
