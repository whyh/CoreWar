/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_render_pc_msg.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 17:10:09 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/10 17:50:09 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vis.h"
#include "corewar_vis_color.h"
#include "corewar_vis_prop.h"
#include "corewar_op_def.h"
#include "libft.h"

void	corewar_vis_render_pc_id(SDL_Renderer *rend, t_carriage *carr,
		SDL_Rect box)
{
	static Sint32	w = 0;
	char			*value;

	if (!w)
		w = (Sint32)ft_strlen("Id");
	corewar_vis_render_btext(rend, "Id", RGBA_TEXT,
	(SDL_Rect){box.x, box.y, S_CHAR_W, S_CHAR_H});
	value = ft_uitoabase(DEC, carr->id);
	corewar_vis_render_btext(rend, value, RGBA_TEXT2,
	(SDL_Rect){box.x + (w * S_CHAR_W) + PAD, box.y, S_CHAR_W, S_CHAR_H});
	ft_strdel(&value);
}

void	corewar_vis_render_pc_carry(SDL_Renderer *rend, t_carriage *carr,
		SDL_Rect box)
{
	static Sint32	w = 0;
	char			*value;

	if (!w)
		w = (Sint32)ft_strlen("Carry");
	corewar_vis_render_btext(rend, "Carry", RGBA_TEXT,
	(SDL_Rect){box.x, box.y, S_CHAR_W, S_CHAR_H});
	value = ft_itoabase(DEC, carr->carry);
	corewar_vis_render_btext(rend, value, RGBA_TEXT2,
	(SDL_Rect){box.x + (w * S_CHAR_W) + PAD, box.y, S_CHAR_W, S_CHAR_H});
	ft_strdel(&value);
}

void	corewar_vis_render_pc_op(SDL_Renderer *rend, t_carriage *carr,
		SDL_Rect box)
{
	static Sint32	w = 0;

	if (!w)
		w = (Sint32)ft_strlen("Operation");
	corewar_vis_render_btext(rend, "Operation", RGBA_TEXT,
	(SDL_Rect){box.x, box.y, S_CHAR_W, S_CHAR_H});
	if (carr->op > 0 && carr->op <= N_OPS)
		corewar_vis_render_btext(rend, g_op_table[carr->op - 1].name,
		RGBA_TEXT2, (SDL_Rect){box.x + (w * S_CHAR_W) + PAD, box.y, S_CHAR_W,
		S_CHAR_H});
}

void	corewar_vis_render_pc_lastlive(SDL_Renderer *rend, t_carriage *carr,
		SDL_Rect box)
{
	static Sint32	w = 0;
	char			*value;

	if (!w)
		w = (Sint32)ft_strlen("Last live");
	corewar_vis_render_btext(rend, "Last live", RGBA_TEXT,
	(SDL_Rect){box.x, box.y, S_CHAR_W, S_CHAR_H});
	value = ft_uitoabase(DEC, carr->last_live);
	corewar_vis_render_btext(rend, value, RGBA_TEXT2,
	(SDL_Rect){box.x + (w * S_CHAR_W) + PAD, box.y, S_CHAR_W, S_CHAR_H});
	ft_strdel(&value);
}

void	corewar_vis_render_pc_timeout(SDL_Renderer *rend, t_carriage *carr,
		SDL_Rect box)
{
	static Sint32	w = 0;
	char			*value;

	if (!w)
		w = (Sint32)ft_strlen("Timeout");
	corewar_vis_render_btext(rend, "Timeout", RGBA_TEXT,
	(SDL_Rect){box.x, box.y, S_CHAR_W, S_CHAR_H});
	value = ft_uitoabase(DEC, carr->timeout);
	corewar_vis_render_btext(rend, value, RGBA_TEXT2,
	(SDL_Rect){box.x + (w * S_CHAR_W) + PAD, box.y, S_CHAR_W, S_CHAR_H});
	ft_strdel(&value);
}
