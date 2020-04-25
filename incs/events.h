/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demonwav <demonwav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 02:59:52 by demonwav          #+#    #+#             */
/*   Updated: 2020/04/25 03:47:52 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "structs.h"

void	zoom(t_env *env);

void	offset(t_env *env);

void	rotate(t_env *env);

void	colorset(t_env *env);

void	projection(t_env *env);

void	reset_view(t_env *env);

void	scale_height(t_env *env);

#endif
