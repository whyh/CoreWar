/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:21:51 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/17 18:23:11 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"
#include "corewar_vis_color.h"

static void	static_init_carr(t_data *data, unsigned int pos, unsigned int id)
{
	t_carriage		*carr_tmp;
	unsigned char	i;

	carr_tmp = ft_memalloc(sizeof(t_carriage));
	carr_tmp->id = id;
	carr_tmp->carry = false;
	carr_tmp->op = 0;
	carr_tmp->last_live = 0;
	carr_tmp->timeout = 0;
	carr_tmp->pos = pos;
	carr_tmp->delta_pos = 0;
	carr_tmp->shown = false;
	i = 0;
	while (i < N_REGS + 1)
	{
		carr_tmp->regs[i] = 0;
		++i;
	}
	carr_tmp->regs[1] = (unsigned int)(-id);
	if (data->carr)
		carr_tmp->next = data->carr;
	else
		carr_tmp->next = NULL;
	data->carr = carr_tmp;
}

static void	static_allocate_code(t_data *data, t_parse *parse, t_vis *vis,
			unsigned int i)
{
	unsigned int	byte;

	byte = 0;
	while (byte < parse->champs[i].code_size)
	{
		data->arena[data->players[i].pos + byte] =
				parse->champs[i].code[byte];
		if (vis)
			vis->color[data->players[i].pos + byte] = g_color[i + 1];
		++byte;
	}
}

static void	static_init_players(t_data *data, t_parse *parse, t_vis *vis)
{
	unsigned int	i;

	i = 0;
	while (i < parse->n_champs)
	{
		data->players[i].pos = (ARENA_SIZE / parse->n_champs) * i;
		data->players[i].name = parse->champs[i].name;
		data->players[i].comment = parse->champs[i].comment;
		data->players[i].code_size = parse->champs[i].code_size;
		data->players[i].last_live = 0;
		data->players[i].n_lives = 0;
		static_allocate_code(data, parse, vis, i);
		static_init_carr(data, data->players[i].pos, parse->champs[i].id);
		++i;
	}
}

void		corewar_init(t_data *data, t_parse *parse, t_vis *vis)
{
	data->dump = parse->dump;
	data->cycle = 0;
	data->leader = parse->n_champs;
	data->check = 0;
	data->ctc = CYCLES_TO_CHECK;
	data->n_live = 0;
	data->n_carrs = parse->n_champs;
	data->n_a_carrs = data->n_carrs;
	data->n_players = parse->n_champs;
	data->carr = NULL;
	ft_memset(data->arena, 0, ARENA_SIZE);
	static_init_players(data, parse, vis);
}
