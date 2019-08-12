/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_exec_carr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 16:50:46 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/25 16:19:29 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_op_def.h"
#include "corewar.h"

static bool	static_arg_type(t_data *data, t_carriage *carr,
			const t_operation *op, unsigned int i)
{
	unsigned char	type;

	if (op->t_arg)
	{
		type = data->arena[corewar_8(carr->pos + OP_SIZE)];
		carr->args_types[i] = (unsigned char)(type >> (8 - ((i + 1) * 2)))
		& TYPE_SIZE;
		if (!(op->args[i][0] && carr->args_types[i] == REG)
		&& !(op->args[i][1] && carr->args_types[i] == DIR)
		&& !(op->args[i][2] && carr->args_types[i] == IND))
			return (false);
	}
	else
	{
		if (op->args[i][0])
			carr->args_types[i] = REG;
		else if (op->args[i][1])
			carr->args_types[i] = DIR;
		else
			carr->args_types[i] = IND;
	}
	return (true);
}

static bool	static_arg_size(t_data *data, t_carriage *carr,
			const t_operation *op, unsigned int i)
{
	bool	ret;

	ret = static_arg_type(data, carr, op, i);
	if (carr->args_types[i] == REG)
		carr->args_values[i] = REG_LINK_SIZE;
	else if (carr->args_types[i] == DIR)
		carr->args_values[i] = op->dir_size;
	else
		carr->args_values[i] = IND_SIZE;
	return (ret);
}

static bool	static_valid_arg(t_data *data, t_carriage *carr,
			const t_operation *op, unsigned int i)
{
	unsigned char	arg_size;
	bool			ret;

	ret = static_arg_size(data, carr, op, i);
	arg_size = (unsigned char)carr->args_values[i];
	corewar_read_arg(data, &(carr->args_values[i]), arg_size,
	carr->pos + carr->delta_pos);
	if (ret && carr->args_types[i] == REG
	&& ((int)carr->args_values[i] < 1
	|| (int)carr->args_values[i] > (int)N_REGS))
		ret = false;
	carr->delta_pos += arg_size;
	return (ret);
}

static bool	static_valid_op(t_data *data, t_carriage *carr,
			const t_operation *op)
{
	unsigned int	i;
	bool			ret;

	ret = false;
	if (data->arena[carr->pos] > 0 && data->arena[carr->pos] <= N_OPS)
	{
		ret = true;
		if (op->t_arg)
			carr->delta_pos += ARGS_TYPES_SIZE;
		i = 0;
		while (i < op->n_args)
		{
			if (!static_valid_arg(data, carr, op, i))
				ret = false;
			++i;
		}
	}
	return (ret);
}

void		corewar_exec_carr(t_data *data, t_carriage *carr, t_vis *vis)
{
	const t_operation	*op;

	if (!carr->timeout)
	{
		carr->op = data->arena[corewar_8(carr->pos)];
		if (carr->op > 0 && carr->op <= N_OPS)
		{
			op = &g_op_table[carr->op - 1];
			carr->timeout = op->timeout;
		}
		carr->delta_pos = OP_SIZE;
	}
	if (carr->timeout)
		--(carr->timeout);
	if (!carr->timeout)
	{
		op = &g_op_table[carr->op - 1];
		if (static_valid_op(data, carr, op))
			op->op(data, carr, vis);
		carr->pos = corewar_8(carr->pos + carr->delta_pos);
	}
}
