/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 16:33:08 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/17 20:15:11 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "corewar.h"

static bool	static_loop(t_data *data, t_vis *vis)
{
	unsigned int	i;
	t_carriage		*carr_tmp;

	i = 0;
	while (i < data->ctc || (data->ctc == 0 && i == 0))
	{
		if (vis)
			corewar_vis(data, vis);
		carr_tmp = data->carr;
		if ((data->dump && data->cycle == data->dump && !vis)
		|| (vis && vis->btns.quit.active))
			return (false);
		while (carr_tmp != NULL)
		{
			corewar_exec_carr(data, carr_tmp, vis);
			carr_tmp = carr_tmp->next;
		}
		++i;
		data->cycle++;
	}
	return (true);
}

static void	static_check(t_data *data)
{
	unsigned int	i;

	corewar_kill_carrs(data, data->carr);
	if (data->n_live >= MIN_LIVE || data->check == MAX_CHECKS)
	{
		if (data->ctc > CYCLE_DELTA)
			data->ctc -= CYCLE_DELTA;
		else
			data->ctc = 0;
		data->check = 0;
	}
	else
		data->check++;
	data->n_live = 0;
	i = 0;
	while (i < data->n_players)
	{
		data->players[i].last_live = 0;
		data->players[i].n_lives = 0;
		++i;
	}
}

static bool	static_check_loop(t_data *data, t_vis *vis)
{
	while (!data->cycle || data->carr->next != NULL)
	{
		if (!static_loop(data, vis))
		{
			corewar_dump(data->arena, vis);
			return (false);
		}
		static_check(data);
	}
	return (true);
}

void		corewar_vm(t_data *data, t_parse *parse, t_vis *vis)
{
	corewar_init(data, parse, vis);
	if (static_check_loop(data, vis))
	{
		if (vis)
		{
			vis->game_over = true;
			corewar_vis(data, vis);
		}
		else
		{
			ft_printf("Player %d (%s) won\n", data->leader,
			data->players[data->leader - 1].name);
		}
	}
}
