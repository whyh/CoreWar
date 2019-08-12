/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_render_topb.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 18:13:07 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/10 18:42:54 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vis.h"
#include "libft.h"
#include "corewar_vis_content.h"
#include "corewar_vis_color.h"

static void	static_render_cycle(SDL_Renderer *rend, int cycle)
{
	static Sint32	w = 0;
	char			*value;

	if (!w)
		w = (Sint32)ft_strlen(TBAR_CYCLE_MSG);
	corewar_vis_render_btext(rend, TBAR_CYCLE_MSG, RGBA_TEXT2,
	(SDL_Rect){BAR_X, TBAR_CYCLE_Y, S_CHAR_W, M_CHAR_H});
	value = ft_itoabase(DEC, cycle);
	corewar_vis_render_btext(rend, value, RGBA_TEXT3,
	(SDL_Rect){BAR_X + (w * S_CHAR_W) + PAD, TBAR_CYCLE_Y, S_CHAR_W, M_CHAR_H});
	ft_strdel(&value);
}

static void	static_render_nci(SDL_Renderer *rend, int cycle, int ctc)
{
	static Sint32	w = 0;
	char			*value;
	Sint32			tmp;

	if (!w)
		w = (Sint32)ft_strlen(TBAR_NCI_MSG);
	tmp = (ctc == 0) ? 0 : ctc - (cycle % ctc);
	corewar_vis_render_btext(rend, TBAR_NCI_MSG, RGBA_TEXT2,
	(SDL_Rect){BAR_X, TBAR_NCI_Y, S_CHAR_W, M_CHAR_H});
	value = ft_itoabase(DEC, tmp);
	corewar_vis_render_btext(rend, value, RGBA_TEXT3,
	(SDL_Rect){BAR_X + (w * S_CHAR_W) + PAD, TBAR_NCI_Y, S_CHAR_W, M_CHAR_H});
	ft_strdel(&value);
	tmp = (Sint32)ft_nbrlen(tmp, 10);
	corewar_vis_render_btext(rend, TBAR_SEP, RGBA_TEXT2,
	(SDL_Rect){BAR_X + (w * S_CHAR_W) + (PAD * 2) + (S_CHAR_W * tmp),
	TBAR_NCI_Y, S_CHAR_W, M_CHAR_H});
	value = ft_itoabase(DEC, ctc);
	corewar_vis_render_btext(rend, value, RGBA_TEXT3,
	(SDL_Rect){BAR_X + (w * S_CHAR_W) + (PAD * 3) + (S_CHAR_W * (tmp + 1)),
	TBAR_NCI_Y, S_CHAR_W, M_CHAR_H});
	ft_strdel(&value);
}

static void	static_render_lc(SDL_Renderer *rend, int n_live)
{
	static Sint32	w = 0;
	char			*value;
	Sint32			tmp;

	if (!w)
		w = (Sint32)ft_strlen(TBAR_LC_MSG);
	corewar_vis_render_btext(rend, TBAR_LC_MSG, RGBA_TEXT2,
	(SDL_Rect){BAR_X, TBAR_LC_Y, S_CHAR_W, M_CHAR_H});
	value = ft_itoabase(DEC, n_live);
	tmp = (n_live < (int)MIN_LIVE ? RGBA_TEXT3 : RGBA_TEXTS);
	corewar_vis_render_btext(rend, value, (unsigned int)tmp,
	(SDL_Rect){BAR_X + (w * S_CHAR_W) + PAD, TBAR_LC_Y, S_CHAR_W, M_CHAR_H});
	ft_strdel(&value);
	tmp = (Sint32)ft_nbrlen(n_live, 10);
	corewar_vis_render_btext(rend, TBAR_SEP, RGBA_TEXT2,
	(SDL_Rect){BAR_X + (w * S_CHAR_W) + (PAD * 2) + (S_CHAR_W * tmp),
	TBAR_LC_Y, S_CHAR_W, M_CHAR_H});
	value = ft_itoabase(DEC, MIN_LIVE);
	corewar_vis_render_btext(rend, value, RGBA_TEXT3,
	(SDL_Rect){BAR_X + (w * S_CHAR_W) + (PAD * 3) + (S_CHAR_W * (tmp + 1)),
	TBAR_LC_Y, S_CHAR_W, M_CHAR_H});
	ft_strdel(&value);
}

static void	static_render_pcs(SDL_Renderer *rend, int n_carrs)
{
	static Sint32	w = 0;
	char			*value;

	if (!w)
		w = (Sint32)ft_strlen(TBAR_PCS_MSG);
	corewar_vis_render_btext(rend, TBAR_PCS_MSG, RGBA_TEXT2,
	(SDL_Rect){BAR_X, TBAR_PCS_Y, S_CHAR_W, M_CHAR_H});
	value = ft_itoabase(DEC, n_carrs);
	corewar_vis_render_btext(rend, value, RGBA_TEXT3,
	(SDL_Rect){BAR_X + (w * S_CHAR_W) + PAD, TBAR_PCS_Y, S_CHAR_W, M_CHAR_H});
	ft_strdel(&value);
}

void		corewar_vis_render_topb(t_data *data, t_vis *vis)
{
	corewar_vis_render_button(vis, &vis->btns.status);
	static_render_cycle(vis->rend, data->cycle);
	static_render_nci(vis->rend, data->cycle, data->ctc);
	static_render_lc(vis->rend, data->n_live);
	static_render_pcs(vis->rend, data->n_carrs);
	corewar_vis_render_topb2(data, vis);
}
