/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_render_topb2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 21:03:14 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/10 15:11:53 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vis.h"
#include "corewar_vis_content.h"
#include "corewar_vis_color.h"
#include "libft.h"

static void	static_render_fc(SDL_Renderer *rend, int check)
{
	static Sint32	w = 0;
	char			*value;
	Sint32			tmp;

	if (!w)
		w = (Sint32)ft_strlen(TBAR_FC_MSG);
	corewar_vis_render_btext(rend, TBAR_FC_MSG, RGBA_TEXT2,
	(SDL_Rect){BAR_X, TBAR_FC_Y, S_CHAR_W, M_CHAR_H});
	value = ft_itoabase(DEC, check);
	tmp = (check < (int)MAX_CHECKS ? RGBA_TEXT3 : RGBA_TEXTS);
	corewar_vis_render_btext(rend, value, (unsigned int)tmp,
	(SDL_Rect){BAR_X + (w * S_CHAR_W) + PAD, TBAR_FC_Y, S_CHAR_W, M_CHAR_H});
	ft_strdel(&value);
	tmp = (Sint32)ft_nbrlen(check, 10);
	corewar_vis_render_btext(rend, TBAR_SEP, RGBA_TEXT2,
	(SDL_Rect){BAR_X + (w * S_CHAR_W) + (PAD * 2) + (S_CHAR_W * tmp), TBAR_FC_Y,
	S_CHAR_W, M_CHAR_H});
	value = ft_itoabase(DEC, MAX_CHECKS);
	corewar_vis_render_btext(rend, value, RGBA_TEXT3,
	(SDL_Rect){BAR_X + (w * S_CHAR_W) + (PAD * 3) + (S_CHAR_W * (tmp + 1)),
	TBAR_FC_Y, S_CHAR_W, M_CHAR_H});
	ft_strdel(&value);
}

void		corewar_vis_render_topb2(t_data *data, t_vis *vis)
{
	static_render_fc(vis->rend, data->check);
}
