/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_render_pc.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 14:29:14 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/17 18:11:32 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vis.h"
#include "libft.h"
#include "corewar_vis_prop.h"
#include "corewar_vis_color.h"

static void	static_render_rg_value(SDL_Renderer *rend, t_carriage *carr,
			unsigned int i, SDL_Rect *box)
{
	static Sint32	w = 0;
	char			*value;
	Sint32			w_tmp;

	if (!w)
		w = (Sint32)ft_strlen("rg");
	corewar_vis_render_btext(rend, "rg", RGBA_TEXT,
	(SDL_Rect){box->x, box->y, XS_CHAR_W, S_CHAR_H});
	value = ft_itoabase(DEC, i);
	corewar_vis_render_btext(rend, value, RGBA_TEXT,
	(SDL_Rect){box->x + (w * XS_CHAR_W), box->y, XS_CHAR_W, S_CHAR_H});
	ft_strdel(&value);
	w_tmp = w + (Sint32)ft_nbrlen(i, 10);
	if (i <= 9)
		++w_tmp;
	value = ft_itoabase(DEC, (int)carr->regs[i]);
	corewar_vis_render_btext(rend, value, RGBA_TEXT2,
	(SDL_Rect){box->x + (w_tmp * XS_CHAR_W) + PAD, box->y, S_CHAR_W, S_CHAR_H});
	ft_strdel(&value);
}

static void	static_render_pc_regs(SDL_Renderer *rend, t_carriage *carr,
			SDL_Rect box)
{
	static Sint32	w;
	unsigned int	i;

	if (!w)
		w = (Sint32)ft_strlen("Registers:");
	corewar_vis_render_btext(rend, "Registers:", RGBA_TEXT,
	(SDL_Rect){box.x, box.y, S_CHAR_W, S_CHAR_H});
	box.x += PAD;
	box.y += S_CHAR_H;
	i = 1;
	while (i <= N_REGS)
	{
		static_render_rg_value(rend, carr, i, &box);
		box.y += S_CHAR_H;
		++i;
	}
}

static void	static_render_msg(SDL_Renderer *rend, t_carriage *carr,
			SDL_Rect box)
{
	SDL_SetRenderDrawColor(rend, R(RGBA_BUTTON), G(RGBA_BUTTON), B(RGBA_BUTTON),
	PROCESS_INF_OP);
	SDL_RenderFillRect(rend, &box);
	box.x += SHADOW_SIZE;
	box.y += SHADOW_SIZE;
	box.w -= (SHADOW_SIZE * 2);
	box.h -= (SHADOW_SIZE * 2);
	SDL_SetRenderDrawColor(rend, R(RGBA_BG), G(RGBA_BG), B(RGBA_BG),
	PROCESS_INF_OP);
	SDL_RenderFillRect(rend, &box);
	corewar_vis_render_pc_id(rend, carr,
	(SDL_Rect){box.x + PAD, box.y + PAD, 0, 0});
	corewar_vis_render_pc_lastlive(rend, carr,
	(SDL_Rect){box.x + PAD, box.y + PROCESS_H + PAD, 0, 0});
	corewar_vis_render_pc_carry(rend, carr,
	(SDL_Rect){box.x + PAD, box.y + (PROCESS_H * 2) + PAD, 0, 0});
	corewar_vis_render_pc_op(rend, carr,
	(SDL_Rect){box.x + PAD, box.y + (PROCESS_H * 3) + PAD, 0, 0});
	corewar_vis_render_pc_timeout(rend, carr,
	(SDL_Rect){box.x + PAD, box.y + (PROCESS_H * 4) + PAD, 0, 0});
	static_render_pc_regs(rend, carr,
	(SDL_Rect){box.x + PAD, box.y + (PROCESS_H * 5) + PAD, 0, 0});
}

static void	static_handle_msg(SDL_Renderer *rend, t_carriage *carr)
{
	static SDL_Rect	box = {0, 0, CAR_INF_W, CAR_INF_H};

	while (carr)
	{
		if (carr->shown)
			break ;
		carr = carr->next;
	}
	if (carr)
	{
		if (carr->hitbox.x > (ARENA_W / 2))
			box.x = carr->hitbox.x - box.w;
		else
			box.x = carr->hitbox.x + carr->hitbox.w;
		if (carr->hitbox.y > (MAX_WIN_H / 2))
			box.y = carr->hitbox.y + carr->hitbox.h - box.h;
		else
			box.y = carr->hitbox.y;
		static_render_msg(rend, carr, box);
	}
}

void		corewar_vis_render_pc(t_data *data, t_vis *vis)
{
	t_carriage		*carr_tmp;
	unsigned int	color;

	carr_tmp = data->carr;
	while (carr_tmp)
	{
		if (vis->btns.reverse.active && -carr_tmp->regs[1] >= MIN_PLAYERS
		&& -carr_tmp->regs[1] <= MAX_PLAYERS)
			color = g_color[-carr_tmp->regs[1]];
		else
			color = RGBA_CARR;
		carr_tmp->hitbox.w = BYTE_SIZE + BYTE_SHADOW * 2;
		carr_tmp->hitbox.h = BYTE_SIZE + BYTE_SHADOW * 2;
		carr_tmp->hitbox.x = ((carr_tmp->pos % N_COLUMNS) * (BYTE_SIZE + PAD))
		+ PAD - BYTE_SHADOW;
		carr_tmp->hitbox.y = ((carr_tmp->pos / N_COLUMNS) * (BYTE_SIZE + PAD))
		+ PAD - BYTE_SHADOW;
		SDL_SetRenderDrawColor(vis->rend, R(color), G(color), B(color),
		CARR_OP);
		SDL_RenderFillRect(vis->rend, &carr_tmp->hitbox);
		carr_tmp = carr_tmp->next;
	}
	if (!vis->btns.run.active)
		static_handle_msg(vis->rend, data->carr);
}
