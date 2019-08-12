/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_render_mdlb.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 18:06:20 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/17 15:43:56 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vis.h"
#include "libft.h"
#include "corewar_vis_color.h"
#include "corewar_vis_content.h"

static void	static_domination_bar(t_vis *vis, unsigned int player, SDL_Rect box)
{
	unsigned int	pct;
	unsigned int	i;

	SDL_SetRenderDrawColor(vis->rend, R(RGBA_SHADOW), G(RGBA_SHADOW),
	B(RGBA_SHADOW), PLAYER_BAR_OP);
	SDL_RenderFillRect(vis->rend, &box);
	pct = 0;
	i = 0;
	while (i < ARENA_SIZE)
	{
		if (vis->color[i] == g_color[player])
			++pct;
		++i;
	}
	box.x += SHADOW_SIZE;
	box.y += SHADOW_SIZE;
	box.h -= (SHADOW_SIZE * 2);
	box.w -= (SHADOW_SIZE * 2);
	SDL_SetRenderDrawColor(vis->rend, R(g_color[0]), G(g_color[0]),
	B(g_color[0]), PLAYER_BAR_OP);
	SDL_RenderFillRect(vis->rend, &box);
	box.w = (Sint32)(box.w * corewar_vis_pct(0, ARENA_SIZE, pct));
	SDL_SetRenderDrawColor(vis->rend, R(g_color[player]), G(g_color[player]),
	B(g_color[player]), PLAYER_BAR_OP);
	SDL_RenderFillRect(vis->rend, &box);
}

static void	static_render_name(SDL_Renderer *rend, t_data *data, unsigned int i)
{
	static Sint32	w = 0;

	if (!w)
		w = (Sint32)ft_strlen(MBAR_NAME_MSG);
	corewar_vis_render_btext(rend, MBAR_NAME_MSG, RGBA_TEXT2,
	(SDL_Rect){BAR_X, MBAR_NAME_Y(i), S_CHAR_W, M_CHAR_H});
	corewar_vis_render_btext(rend, data->players[i].name, g_color[i + 1],
	(SDL_Rect){BAR_X + (w * S_CHAR_W) + (PAD * 2), MBAR_NAME_Y(i), S_CHAR_W,
	M_CHAR_H});
}

static void	static_render_lcl(SDL_Renderer *rend, t_data *data, unsigned int i)
{
	static Sint32	w = 0;
	char			*value;

	if (!w)
		w = (Sint32)ft_strlen(MBAR_LCL_MSG);
	corewar_vis_render_btext(rend, MBAR_LCL_MSG, g_color[i + 1],
	(SDL_Rect){BAR_X, MBAR_LCL_Y(i), XS_CHAR_W, S_CHAR_H});
	if (data->players[i].last_live)
	{
		value = ft_uitoabase(DEC, data->players[i].last_live);
		corewar_vis_render_btext(rend, value, RGBA_TEXT2,
		(SDL_Rect){BAR_X + (w * XS_CHAR_W) + PAD, MBAR_LCL_Y(i), S_CHAR_W,
		S_CHAR_H});
		ft_strdel(&value);
	}
}

static void	static_render_cl(SDL_Renderer *rend, t_data *data, unsigned int i)
{
	static Sint32	w = 0;
	char			*value;

	if (!w)
		w = (Sint32)ft_strlen(MBAR_CL_MSG);
	corewar_vis_render_btext(rend, MBAR_CL_MSG, g_color[i + 1],
	(SDL_Rect){BAR_X, MBAR_CL_Y(i), XS_CHAR_W, S_CHAR_H});
	value = ft_uitoabase(DEC, data->players[i].n_lives);
	corewar_vis_render_btext(rend, value, RGBA_TEXT2,
	(SDL_Rect){BAR_X + (w * XS_CHAR_W) + PAD, MBAR_CL_Y(i), S_CHAR_W,
	S_CHAR_H});
	ft_strdel(&value);
}

void		corewar_vis_render_mdlb(t_data *data, t_vis *vis)
{
	unsigned int	i;
	static SDL_Rect	bg = {BAR_X, 0, BAR_W, P_SHADOW_H};
	Uint8			opacity;
	Uint8			opacity_fix;

	opacity = PLAYER_SHADOW_OP;
	opacity_fix = 0;
	i = 0;
	while (i < data->n_players)
	{
		if (i == 1)
			opacity_fix = PLAYER_SHADOW_OP;
		SDL_SetRenderDrawColor(vis->rend, R(RGBA_SHADOW), G(RGBA_SHADOW),
		B(RGBA_SHADOW), (Uint8)(opacity * (i + 1) + opacity_fix));
		bg.y = MID_BAR_Y(i, 0);
		SDL_RenderFillRect(vis->rend, &bg);
		static_render_name(vis->rend, data, i);
		static_render_lcl(vis->rend, data, i);
		static_render_cl(vis->rend, data, i);
		static_domination_bar(vis, i + 1,
		(SDL_Rect){BAR_X, MID_BAR_Y(i, 3), BAR_W, M_CHAR_H});
		++i;
	}
}
