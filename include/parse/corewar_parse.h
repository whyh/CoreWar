/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_parse.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:36:52 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/02 22:22:17 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_PARSE_H

# define COREWAR_PARSE_H

# include "corewar_parse_def.h"

bool	corewar_parse_options(t_parse *parse, const char **argv,
		unsigned int *i);
bool	corewar_parse_champion(t_parse *parse, const char *file);

#endif
