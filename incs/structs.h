/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demonwav <demonwav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 00:52:37 by demonwav          #+#    #+#             */
/*   Updated: 2020/04/25 04:47:09 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "SDL.h"
# include "SDL_ttf.h"

typedef struct	s_pos
{
	int			y;
	int			x;
	int			z;
	int			color;
}				t_pos;

typedef struct	s_cam
{
	int			hud;
	int			type;
	int			zoom;
	int			offset_y;
	int			offset_x;
	float		depth;
	double		alpha;
	double		beta;
	double		gamma;
}				t_cam;

typedef struct	s_sdl
{
	int			resolution;
	TTF_Font	*font;
	SDL_Event	event;
	SDL_Color	color;
	SDL_Window	*win;
	SDL_Surface	*screen;
}				t_sdl;

typedef struct	s_env
{
	int			delay;
	int			z_min;
	int			z_max;
	int			width;
	int			height;
	int			color_min;
	int			color_max;
	int			color_half;
	int			color_third;
	int			color_fourth;
	int			input[SDL_NUM_SCANCODES];
	t_cam		cam;
	t_sdl		sdl;
	t_pos		**grid;
	t_pos		gridmin;
}				t_env;

#endif
