/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demonwav <demonwav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 09:59:23 by demonwav          #+#    #+#             */
/*   Updated: 2020/04/25 04:33:54 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clean.h"
#include "events.h"

static void	read_inputs(t_env *env)
{
	if (env->input[SDL_SCANCODE_ESCAPE])
		clean(env, 0, "OK");
	if (env->input[SDL_SCANCODE_9] || env->input[SDL_SCANCODE_0])
		zoom(env);
	if (env->input[SDL_SCANCODE_I] || env->input[SDL_SCANCODE_P])
		projection(env);
	if (env->input[SDL_SCANCODE_R])
		reset_view(env);
	if (env->input[SDL_SCANCODE_LEFT] || env->input[SDL_SCANCODE_RIGHT]
		|| env->input[SDL_SCANCODE_UP] || env->input[SDL_SCANCODE_DOWN])
		offset(env);
	if (env->input[SDL_SCANCODE_PAGEUP] || env->input[SDL_SCANCODE_PAGEDOWN])
		scale_height(env);
	if (env->input[SDL_SCANCODE_1] || env->input[SDL_SCANCODE_2]
		|| env->input[SDL_SCANCODE_3])
		colorset(env);
	if (env->input[SDL_SCANCODE_Q] || env->input[SDL_SCANCODE_W]
		|| env->input[SDL_SCANCODE_A] || env->input[SDL_SCANCODE_D]
		|| env->input[SDL_SCANCODE_X] || env->input[SDL_SCANCODE_C])
		rotate(env);
	if (env->input[SDL_SCANCODE_H] && env->delay + 250 < (int)SDL_GetTicks())
	{
		env->cam.hud *= -1;
		env->delay = SDL_GetTicks();
	}
}

void		hooks(t_env *env)
{
	while (SDL_PollEvent(&env->sdl.event))
	{
		if (env->sdl.event.type == SDL_QUIT)
			clean(env, 0, "OK");
		if (env->sdl.event.window.event == SDL_WINDOWEVENT_CLOSE)
			clean(env, 0, "OK");
		if (env->sdl.event.type == SDL_KEYDOWN)
			env->input[env->sdl.event.key.keysym.scancode] = 1;
		if (env->sdl.event.type == SDL_KEYUP)
			env->input[env->sdl.event.key.keysym.scancode] = 0;
	}
	read_inputs(env);
}
