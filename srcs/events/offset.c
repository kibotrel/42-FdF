/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demonwav <demonwav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 03:27:29 by demonwav          #+#    #+#             */
/*   Updated: 2020/04/25 03:29:43 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "structs.h"

void	offset(t_env *env)
{
	if (env->input[SDL_SCANCODE_UP])
		env->cam.offset_y -= OFFSET;
	if (env->input[SDL_SCANCODE_LEFT])
		env->cam.offset_x -= OFFSET;
	if (env->input[SDL_SCANCODE_DOWN])
		env->cam.offset_y += OFFSET;
	if (env->input[SDL_SCANCODE_RIGHT])
		env->cam.offset_x += OFFSET;
}
