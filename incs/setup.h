/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demonwav <demonwav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 00:48:39 by demonwav          #+#    #+#             */
/*   Updated: 2020/04/22 07:57:48 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETUP_H
# define SETUP_H

# include "structs.h"

void	setup(t_env *env);

void	setup_sdl(t_env *env);

void	setup_ttf(t_env *env);

#endif
