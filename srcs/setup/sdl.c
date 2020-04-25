/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demonwav <demonwav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 01:45:57 by demonwav          #+#    #+#             */
/*   Updated: 2020/04/25 07:01:26 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "clean.h"
#include "utils.h"

void	setup_sdl(t_env *env)
{
	int		config;
	t_pos	p;

	p.x = WIDTH;
	p.y = HEIGHT;
	config = SDL_WINDOWPOS_CENTERED;
	if (SDL_Init(SDL_INIT_VIDEO))
		clean(env, 10, ERR_SDL_INIT);
	if (!(env->sdl.win = SDL_CreateWindow("", config, config, p.x, p.y, 0)))
		clean(env, 11, ERR_SDL_WIN);
	if (!(env->sdl.screen = SDL_GetWindowSurface(env->sdl.win)))
		clean(env, 12, ERR_SDL_WINSURF);
	SDL_SetWindowTitle(env->sdl.win, TITLE);
	env->sdl.resolution = env->sdl.screen->h * env->sdl.screen->pitch;
}
