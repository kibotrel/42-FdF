/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demonwav <demonwav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 00:48:39 by demonwav          #+#    #+#             */
/*   Updated: 2020/04/25 06:09:29 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

/*
**	Informations about window and interface
*/

# define TITLE			"[Graphic Project] Wireframe 42"
# define WIDTH			1280
# define HEIGHT			720
# define FONT_SIZE		16

/*
**	Available projections and somes informations
*/

# define OFFSET			25
# define PARALLEL		1
# define ISOMETRIC		0
# define MAX_DEPTH		20
# define MIN_DEPTH		1.2

/*
**	Color palettes
*/

# define BLUE			0x6464FF
# define WHITE			0xFFFFFF
# define BROWN			0x5F2B17
# define GREEN			0x36B71C
# define GREENER		0x259000

# define RED			0xF03A15
# define REDER			0xAC270B
# define ORANGE			0xFF8000
# define BROWNER		0x440D09

# define GRAY_MIN		0x4F4F4F
# define GRAY_LOW		0x6A6A6A
# define GRAY_MID		0x868686
# define GRAY_HIGH		0xC3C3C3

/*
**	Error messages
*/

# define ERR_OPEN		"\033[31;1mError:\033[0m Can't open file."
# define ERR_CLOSE		"\033[31;1mError:\033[0m Can't close file."
# define ERR_SPLIT		"\033[31;1mError:\033[0m Can't retrieve all points."
# define ERR_WIDTH	"\033[31;1mError:\033[0m Map width isn't the same all rows."
# define ERR_FORMAT		"\033[31;1mError:\033[0m Incorrect row format."
# define ERR_MALLOC		"\033[31;1mError:\033[0m Can't allocate memory."
# define ERR_SDL_WIN	"\033[31;1mError:\033[0m Can't create SDL window."
# define ERR_FILENAME	"\033[31;1mError:\033[0m Wrong filename."
# define ERR_SDL_BLIT	"\033[31;1mError:\033[0m Can't blit text on the screen."
# define ERR_SDL_INIT	"\033[31;1mError:\033[0m Can't init SDL connexion."
# define ERR_TTF_FONT	"\033[31;1mError:\033[0m Can't load the given font."
# define ERR_TTF_INIT	"\033[31;1mError:\033[0m Can't init TTF connexion."
# define ERR_EMPTY_ROW	"\033[31;1mError:\033[0m Empty row within the file."
# define ERR_EMPTY_FILE	"\033[31;1mError:\033[0m Empty file."
# define ERR_SDL_UPDATE	"\033[31;1mError:\033[0m Can't update the given frame."
# define ERR_TTF_RENDER	"\033[31;1mError:\033[0m Can't write text on surface."
# define ERR_SDL_WINSURF "\033[31;1mError:\033[0m Can't get window surface."

#endif
