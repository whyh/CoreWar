/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_op_def.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 22:32:15 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/18 19:59:06 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_OP_DEF_H

# define COREWAR_OP_DEF_H

# include "corewar_op.h"

typedef struct				s_operation
{
	const unsigned int		n_args;
	const bool				args[3][3];
	const unsigned int		timeout;
	const bool				t_arg;
	const unsigned char		dir_size;
	const char				*name;
	const t_function		op;
}							t_operation;

static const t_operation	g_op_table[N_OPS] =
{
	{1, {{false, true, false}, {false, false, false}, {false, false, false}},
		10, 0, DIR_SIZE, "live", &corewar_op_live},
	{2, {{false, true, true}, {true, false, false}, {false, false, false}},
		5, 1, DIR_SIZE, "ld", &corewar_op_ld},
	{2, {{true, false, false}, {true, false, true}, {false, false, false}},
		5, 1, DIR_SIZE, "st", &corewar_op_st},
	{3, {{true, false, false}, {true, false, false}, {true, false, false}},
		10, 1, DIR_SIZE, "add", &corewar_op_add},
	{3, {{true, false, false}, {true, false, false}, {true, false, false}},
		10, 1, DIR_SIZE, "sub", &corewar_op_sub},
	{3, {{true, true, true}, {true, true, true}, {true, false, false}},
		6, 1, DIR_SIZE, "and", &corewar_op_and},
	{3, {{true, true, true}, {true, true, true}, {true, false, false}},
		6, 1, DIR_SIZE, "or", &corewar_op_or},
	{3, {{true, true, true}, {true, true, true}, {true, false, false}},
		6, 1, IND_SIZE, "xor", &corewar_op_xor},
	{1, {{false, true, false}, {false, false, false}, {false, false, false}},
		20, 0, IND_SIZE, "zjmp", &corewar_op_zjmp},
	{3, {{true, true, true}, {true, true, false}, {true, false, false}},
		25, 1, IND_SIZE, "ldi", &corewar_op_ldi},
	{3, {{true, false, false}, {true, true, true}, {true, true, false}},
		25, 1, IND_SIZE, "sti", &corewar_op_sti},
	{1, {{false, true, false}, {false, false, false}, {false, false, false}},
		800, 0, IND_SIZE, "fork", &corewar_op_fork},
	{2, {{false, true, true}, {true, false, false}, {false, false, false}},
		10, 1, DIR_SIZE, "lld", &corewar_op_lld},
	{3, {{true, true, true}, {true, true, false}, {true, false, false}},
		50, 1, IND_SIZE, "lldi", &corewar_op_lldi},
	{1, {{false, true, false}, {false, false, false}, {false, false, false}},
		1000, 0, IND_SIZE, "lfork", &corewar_op_lfork},
	{1, {{true, false, false}, {false, false, false}, {false, false, false}},
		2, 1, DIR_SIZE, "aff", &corewar_op_aff}
};

#endif
