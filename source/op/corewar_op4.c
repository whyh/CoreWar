/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_op4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 23:34:03 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/18 23:30:18 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_op_def.h"
#include "libft.h"

static void	static_op_new_carriage(t_data *data, t_carriage *carr_src, int pos)
{
	t_carriage		*carr_new;
	unsigned int	i;

	data->n_carrs++;
	data->n_a_carrs++;
	carr_new = ft_memalloc(sizeof(t_carriage));
	carr_new->id = data->n_a_carrs;
	carr_new->carry = carr_src->carry;
	carr_new->op = 0;
	carr_new->last_live = carr_src->last_live;
	carr_new->pos = corewar_8(pos);
	carr_new->delta_pos = 0;
	carr_new->shown = false;
	i = 0;
	while (i < N_REGS + 1)
	{
		carr_new->regs[i] = carr_src->regs[i];
		++i;
	}
	carr_new->next = data->carr;
	data->carr = carr_new;
}

void		corewar_op_lfork(t_data *data, t_carriage *carr, t_vis *vis)
{
	int	pos;

	(void)vis;
	pos = carr->pos + (int)carr->args_values[0];
	static_op_new_carriage(data, carr, pos);
}

void		corewar_op_fork(t_data *data, t_carriage *carr, t_vis *vis)
{
	int	pos;

	(void)vis;
	pos = carr->pos + (((int)(carr->args_values[0])) % IDX_MOD);
	static_op_new_carriage(data, carr, pos);
}

void		corewar_op_ld(t_data *data, t_carriage *carr, t_vis *vis)
{
	unsigned int	value;
	int				pos;

	(void)vis;
	if (carr->args_types[0] == DIR)
		value = carr->args_values[0];
	else
	{
		pos = carr->pos + (((int)carr->args_values[0]) % IDX_MOD);
		corewar_read_arg(data, &value, REG_SIZE, pos);
	}
	carr->regs[carr->args_values[1]] = value;
	if (value == 0)
		carr->carry = true;
	else
		carr->carry = false;
}

void		corewar_op_lld(t_data *data, t_carriage *carr, t_vis *vis)
{
	unsigned int	value;
	int				pos;

	(void)vis;
	if (carr->args_types[0] == DIR)
		value = carr->args_values[0];
	else
	{
		pos = carr->pos + (int)carr->args_values[0];
		corewar_read_arg(data, &value, REG_SIZE, pos);
	}
	carr->regs[carr->args_values[1]] = value;
	if (value == 0)
		carr->carry = true;
	else
		carr->carry = false;
}
