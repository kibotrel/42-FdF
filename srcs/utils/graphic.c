/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demonwav <demonwav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 07:41:23 by demonwav          #+#    #+#             */
/*   Updated: 2020/04/25 05:52:52 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "clean.h"

void	draw_pixel(SDL_Surface *win, t_pos p, unsigned int color)
{
	int	*px;

	if ((p.x >= 0 && p.x < WIDTH) && (p.y >= 0 && p.y < HEIGHT))
	{
		px = win->pixels + p.y * win->pitch + p.x * win->format->BytesPerPixel;
		*px = color;
	}
}

void	text(t_env *env, char *str, t_pos pos, int mode)
{
	int			e;
	t_pos		p;
	SDL_Rect	where;
	SDL_Surface	*tmp;

	e = 0;
	if (!str)
		return ;
	TTF_SizeText(env->sdl.font, str, &p.x, &p.y);
	where.x = env->gridmin.x * pos.x;
	where.y = env->gridmin.y * pos.y;
	if (mode == 1)
	{
		where.x += (((where.x + env->gridmin.x) - (where.x + p.x)) / 2);
		where.y += (((where.y + env->gridmin.y) - (where.y + p.y)) / 2);
	}
	if (!(tmp = TTF_RenderText_Blended(env->sdl.font, str, env->sdl.color)))
		e = 16;
	if (!e && SDL_BlitSurface(tmp, 0, env->sdl.screen, &where))
		e = 17;
	if (tmp)
		SDL_FreeSurface(tmp);
	if (e)
		e == 16 ? clean(env, e, ERR_TTF_RENDER) : clean(env, e, ERR_SDL_BLIT);
}
