/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 04:53:11 by kibotrel          #+#    #+#             */
/*   Updated: 2019/02/15 15:01:14 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

/*
**	Informations about mlx window and interface
*/

# define HEIGHT 1200
# define WIDTH 2000
# define TITLE "[Minilibx Project] Wireframe 42"

/*
**	Available projections and somes informations
*/

# define MIN_DEPTH 1.2
# define MAX_DEPTH 20
# define ISOMETRIC 0
# define PARALLEL 1
# define OFFSET 25

/*
**	Used keycodes to communicate with mlx
*/

# define PG_DOWN 121
# define PG_UP 116
# define RIGHT 124
# define MINUS 78
# define PLUS 69
# define DOWN 125
# define LEFT 123
# define NUM2 84
# define NUM3 85
# define NUM4 86
# define NUM6 88
# define NUM7 89
# define NUM8 91
# define ESC 53
# define UP 126
# define W 13
# define Z 6
# define X 7
# define C 8
# define S 1
# define A 0
# define D 2
# define H 4
# define I 34
# define P 35
# define R 15

/*
**	Preset colors :
**	first set : earth-maps
**	second set : planet-maps
**	third set : satelite-maps
*/

# define BLUE 0x6464FF
# define WHITE 0xFFFFFF
# define BROWN 0x5F2B17
# define GREEN 0x36B71C
# define GREENER 0x259000

# define RED 0xF03A15
# define REDER 0xAC270B
# define ORANGE 0xFF8000
# define BROWNER 0x440D09

# define GRAY_MIN 0x4F4F4F
# define GRAY_LOW 0x6A6A6A
# define GRAY_MID 0x868686
# define GRAY_HIGH 0xC3C3C3

/*
**	Error messages
*/

# define ERR_MALLOC "\033[31;1mError :\033[0m Can't allocate memory."
# define ERR_SPLIT "\033[31;1mError :\033[0m Can't retrieve all points."
# define ERR_WIDTH "\033[31;1mError :\033[0m Map width isn't the same all rows."
# define ERR_EMPTY_FILE "\033[31;1mError :\033[0m Empty file."
# define ERR_FILENAME "\033[31;1mError :\033[0m Wrong filename."
# define ERR_OPEN "\033[31;1mError :\033[0m Can't open file."
# define ERR_CLOSE "\033[31;1mError :\033[0m Can't close file."
# define ERR_EMPTY_ROW "\033[31;1mError :\033[0m Empty row within the file."
# define ERR_FORMAT "\033[31;1mError :\033[0m Incorrect row format."
#endif
