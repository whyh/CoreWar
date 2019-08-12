/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 14:22:05 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/17 20:59:18 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H

# define COREWAR_H

# include "corewar_def.h"
# include "corewar_parse_def.h"

bool	corewar_parse(t_parse *parse, unsigned int argc, const char **argv);

void	corewar_vm(t_data *data, t_parse *parse, t_vis *vis);
void	corewar_init(t_data *data, t_parse *parse, t_vis *vis);
void	corewar_exec_carr(t_data *data, t_carriage *carr, t_vis *vis);

void	corewar_read_arg(t_data *data, unsigned int *value, unsigned char size,
		int pos);
int		corewar_8(int pos);
void	corewar_kill_carrs(t_data *data, t_carriage *carr_tmp);
void	corewar_dump(const unsigned char *arena, t_vis *vis);

bool	corewar_exit(t_parse *parse, t_data *data, t_vis *vis);

bool	corewar_vis_init(t_vis *vis);
void	corewar_vis(t_data *data, t_vis *vis);

#endif
