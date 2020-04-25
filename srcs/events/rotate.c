/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demonwav <demonwav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 03:45:37 by demonwav          #+#    #+#             */
/*   Updated: 2020/04/25 03:51:35 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

void	rotate(t_env *env)
{
	if (env->input[SDL_SCANCODE_X])
		env->cam.alpha += 0.05;
	if (env->input[SDL_SCANCODE_W])
		env->cam.alpha -= 0.05;
	if (env->input[SDL_SCANCODE_A])
		env->cam.beta -= 0.05;
	if (env->input[SDL_SCANCODE_D])
		env->cam.beta += 0.05;
	if (env->input[SDL_SCANCODE_Q])
		env->cam.gamma -= 0.05;
	if (env->input[SDL_SCANCODE_C])
		env->cam.gamma += 0.05;
}
