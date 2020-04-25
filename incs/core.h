/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demonwav <demonwav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 00:48:39 by demonwav          #+#    #+#             */
/*   Updated: 2020/04/25 04:10:44 by demonwaves       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# include "structs.h"

void	usage(void);

void	hooks(t_env *env);

void	print_hud(t_env *env);

void	print_map(t_env *env);

void	parse_file(char *file, t_env *env);

#endif
