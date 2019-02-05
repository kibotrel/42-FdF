/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 00:07:38 by kibotrel          #+#    #+#             */
/*   Updated: 2019/02/05 01:18:20 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

typedef struct	s_env
{
	int			x;
}				t_env;

/*
**	main.c
*/

void			print_error(char *desc, int error);

/*
**	parsing.c
*/

void			parse_file(char *file, t_env *env);

/*
**	utils.c
*/

int				is_validname(char *filename);

#endif
