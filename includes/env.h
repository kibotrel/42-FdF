/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 04:53:11 by kibotrel          #+#    #+#             */
/*   Updated: 2019/02/08 04:18:45 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

/*
**	Informations about mlx window
*/

# define HEIGHT 1200
# define WIDTH 1600
# define TITLE "Work in progress."

/*
**	Available projections
*/

# define MIN_DEPTH 1
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
# define ESC 53
# define UP 126
# define W 13
# define S 1
# define A 0
# define D 2
# define I 34
# define P 35
#endif
