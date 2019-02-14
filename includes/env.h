/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 04:53:11 by kibotrel          #+#    #+#             */
/*   Updated: 2019/02/14 23:46:17 by kibotrel         ###   ########.fr       */
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

# define MIN_DEPTH 0.5
# define MAX_DEPTH 5
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
#endif
