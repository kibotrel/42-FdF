/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demonwav <demonwav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 10:04:42 by demonwav          #+#    #+#             */
/*   Updated: 2020/04/22 19:15:56 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEAN_H
# define CLEAN_H

# include "structs.h"

void	clean(t_env *env, int error, char *description);

void	clean_ttf(t_env *env);

void	clean_sdl(t_env *env);

#endif
