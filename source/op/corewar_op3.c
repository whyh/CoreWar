/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_op3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 23:31:22 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/18 16:37:52 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	static_op_arg(t_data *data, t_carriage *carr, unsigned int n,
			unsigned int *arg)
{
	int	pos;

	if (carr->args_types[n] == REG)
		*arg = carr->regs[carr->args_values[n]];
	else if (carr->args_types[n] == DIR)
		*arg = carr->args_values[n];
	else
	{
		pos = carr->pos + (((int)(carr->args_values[n])) % IDX_MOD);
		corewar_read_arg(data, arg, REG_SIZE, pos);
	}
}

void		corewar_op_xor(t_data *data, t_carriage *carr, t_vis *vis)
{
	unsigned int	arg;
	unsigned int	arg1;
	unsigned int	value;

	(void)vis;
	static_op_arg(data, carr, 0, &arg);
	static_op_arg(data, carr, 1, &arg1);
	value = arg ^ arg1;
	carr->regs[carr->args_values[2]] = value;
	if (value == 0)
		carr->carry = true;
	else
		carr->carry = false;
}

void		corewar_op_and(t_data *data, t_carriage *carr, t_vis *vis)
{
	unsigned int	arg;
	unsigned int	arg1;
	unsigned int	value;

	(void)vis;
	static_op_arg(data, carr, 0, &arg);
	static_op_arg(data, carr, 1, &arg1);
	value = arg & arg1;
	carr->regs[carr->args_values[2]] = value;
	if (value == 0)
		carr->carry = true;
	else
		carr->carry = false;
}

void		corewar_op_or(t_data *data, t_carriage *carr, t_vis *vis)
{
	unsigned int	arg;
	unsigned int	arg1;
	unsigned int	value;

	(void)vis;
	static_op_arg(data, carr, 0, &arg);
	static_op_arg(data, carr, 1, &arg1);
	value = arg | arg1;
	carr->regs[carr->args_values[2]] = value;
	if (value == 0)
		carr->carry = true;
	else
		carr->carry = false;
}
