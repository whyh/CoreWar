/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:17:41 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/25 16:20:35 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_op_def.h"
#include "corewar_vis_color.h"
#include "libft.h"

static void	static_op_vis(t_carriage *carr, t_vis *vis, int pos, int n_players)
{
	unsigned int	color;
	unsigned int	i;

	if ((int)(carr->regs[1] * -1) <= n_players
	&& (int)(carr->regs[1] * -1) >= (int)MIN_PLAYERS)
		color = g_color[(-carr->regs[1])];
	else
		color = g_color[0];
	i = 0;
	while (i < REG_SIZE)
	{
		vis->color[corewar_8(pos + i)] = color;
		++i;
	}
}

void		corewar_op_st(t_data *data, t_carriage *carr, t_vis *vis)
{
	int	pos;

	if (carr->args_types[1] == REG)
		carr->regs[carr->args_values[1]] = carr->regs[carr->args_values[0]];
	else
	{
		pos = carr->pos + (((int)carr->args_values[1]) % IDX_MOD);
		corewar_write_arg(data, carr->regs[carr->args_values[0]], pos);
		if (vis)
			static_op_vis(carr, vis, pos, data->n_players);
	}
}

void		corewar_op_live(t_data *data, t_carriage *carr, t_vis *vis)
{
	unsigned int	arg;

	carr->last_live = data->cycle;
	++(data->n_live);
	arg = carr->args_values[0];
	if ((((int)arg) * -1) >= (int)MIN_PLAYERS
	&& (((int)arg) * -1) <= (int)data->n_players)
	{
		data->players[(((int)arg) * -1) - 1].n_lives++;
		data->players[(((int)arg) * -1) - 1].last_live = data->cycle;
		if (!vis)
			ft_printf("A process shows that player %u (%s) is alive\n",
			((int)arg) * -1, data->players[(((int)arg) * -1) - 1].name);
		data->leader = (unsigned int)(((int)arg) * -1);
	}
}

void		corewar_op_sti(t_data *data, t_carriage *carr, t_vis *vis)
{
	unsigned int	arg1;
	unsigned int	arg2;
	unsigned int	value;
	int				pos;

	value = carr->regs[carr->args_values[0]];
	if (carr->args_types[1] == REG)
		arg1 = carr->regs[carr->args_values[1]];
	else if (carr->args_types[1] == DIR)
		arg1 = carr->args_values[1];
	else
	{
		pos = carr->pos + (((int)(carr->args_values[1])) % IDX_MOD);
		corewar_read_arg(data, &arg1, REG_SIZE, pos);
	}
	if (carr->args_types[2] == REG)
		arg2 = carr->regs[carr->args_values[2]];
	else
		arg2 = carr->args_values[2];
	pos = carr->pos + (((int)(arg1 + arg2)) % IDX_MOD);
	corewar_write_arg(data, value, pos);
	if (vis)
		static_op_vis(carr, vis, pos, data->n_players);
}

void		corewar_op_lldi(t_data *data, t_carriage *carr, t_vis *vis)
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
	pos = carr->pos + (int)(arg + arg1);
	corewar_read_arg(data, &value, REG_SIZE, pos);
	carr->regs[carr->args_values[2]] = value;
}
