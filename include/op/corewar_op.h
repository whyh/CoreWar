/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_op.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:55:00 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/18 23:30:19 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_OP_H

# define COREWAR_OP_H

# include "corewar_def.h"

void	corewar_write_arg(t_data *data, unsigned int value, int pos);

void	corewar_op_live(t_data *data, t_carriage *carr, t_vis *vis);
void	corewar_op_ld(t_data *data, t_carriage *carr, t_vis *vis);
void	corewar_op_st(t_data *data, t_carriage *carr, t_vis *vis);
void	corewar_op_add(t_data *data, t_carriage *carr, t_vis *vis);
void	corewar_op_sub(t_data *data, t_carriage *carr, t_vis *vis);
void	corewar_op_and(t_data *data, t_carriage *carr, t_vis *vis);
void	corewar_op_or(t_data *data, t_carriage *carr, t_vis *vis);
void	corewar_op_xor(t_data *data, t_carriage *carr, t_vis *vis);
void	corewar_op_zjmp(t_data *data, t_carriage *carr, t_vis *vis);
void	corewar_op_ldi(t_data *data, t_carriage *carr, t_vis *vis);
void	corewar_op_sti(t_data *data, t_carriage *carr, t_vis *vis);
void	corewar_op_fork(t_data *data, t_carriage *carr, t_vis *vis);
void	corewar_op_lld(t_data *data, t_carriage *carr, t_vis *vis);
void	corewar_op_lldi(t_data *data, t_carriage *carr, t_vis *vis);
void	corewar_op_lfork(t_data *data, t_carriage *carr, t_vis *vis);
void	corewar_op_aff(t_data *data, t_carriage *carr, t_vis *vis);

#endif
