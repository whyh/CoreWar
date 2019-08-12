/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_op2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 23:29:55 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/25 16:20:11 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"
#include "corewar_op_def.h"

void	corewar_op_add(t_data *data, t_carriage *carr, t_vis *vis)
{
	unsigned int	value;

	(void)vis;
	(void)data;
	value = carr->regs[carr->args_values[0]] + carr->regs[carr->args_values[1]];
	carr->regs[carr->args_values[2]] = value;
	if (value == 0)
		carr->carry = true;
	else
		carr->carry = false;
}

void	corewar_op_ldi(t_data *data, t_carriage *carr, t_vis *vis)
{
	unsigned int	arg;
	unsigned int	arg1;
	unsigned int	value;
	int				pos;

	(void)vis;
	if (carr->args_types[0] == REG)
		arg = carr->regs[carr->args_values[0]];
	else if (carr->args_types[0] == DIR)
		arg = carr->args_values[0];
	else
	{
		pos = carr->pos + (((int)(carr->args_values[0])) % IDX_MOD);
		corewar_read_arg(data, &arg, REG_SIZE, pos);
	}
	if (carr->args_types[1] == REG)
		arg1 = carr->regs[carr->args_values[1]];
	else
		arg1 = carr->args_values[1];
	pos = carr->pos + (((int)(arg + arg1)) % IDX_MOD);
	corewar_read_arg(data, &value, REG_SIZE, pos);
	carr->regs[carr->args_values[2]] = value;
}

void	corewar_op_aff(t_data *data, t_carriage *carr, t_vis *vis)
{
	unsigned int	value;

	(void)vis;
	(void)data;
	value = carr->regs[carr->args_values[0]];
	ft_printf("%c", value % 256);
}

void	corewar_op_sub(t_data *data, t_carriage *carr, t_vis *vis)
{
	unsigned int	value;

	(void)vis;
	(void)data;
	value = carr->regs[carr->args_values[0]] - carr->regs[carr->args_values[1]];
	carr->regs[carr->args_values[2]] = value;
	if (value == 0)
		carr->carry = true;
	else
		carr->carry = false;
}

void	corewar_op_zjmp(t_data *data, t_carriage *carr, t_vis *vis)
{
	int	pos;

	(void)vis;
	(void)data;
	if (carr->carry)
	{
		pos = ((int)(carr->args_values[0])) % IDX_MOD;
		carr->pos = corewar_8(carr->pos + pos);
		carr->delta_pos = 0;
	}
}
