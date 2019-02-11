/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 04:53:11 by kibotrel          #+#    #+#             */
/*   Updated: 2019/02/11 20:58:01 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

/*
**	Informations about mlx window
*/

# define HEIGHT 1200
# define WIDTH 2000
# define TITLE "Wireframe created by kibotrel."

/*
**	Available projections
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
# define PAD_1 83
# define PAD_2 84
# define PAD_3 85
# define RIGHT 124
# define MINUS 78
# define PLUS 69
# define DOWN 125
# define LEFT 123
# define ESC 53
# define UP 126
# define W 13
# define S 1
# define A 0
# define D 2
# define I 34
# define P 35

/*
**	Preset colors
*/

# define YELLOW 0xFFFF00
# define WHITE 0xFFFFFF
# define GREEN 0x00FF00
# define ORANGE 0x0020FF
# define RED 0xBA1200

#endif
