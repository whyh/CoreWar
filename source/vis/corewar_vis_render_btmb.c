/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_render_btmb.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:36:11 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/10 18:15:05 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vis.h"
#include "corewar_vis_color.h"
#include "corewar_vis_content.h"

static void	static_render_tips(SDL_Renderer *rend)
{
	corewar_vis_render_btext(rend, BBAR_TIP_MSG,
	RGBA_TEXT2, (SDL_Rect){BAR_X, BBAR_TIP_MSG_Y, XS_CHAR_W, S_CHAR_H});
	corewar_vis_render_btext(rend, BBAR_SPEEDUP_MSG, RGBA_TEXT2,
	(SDL_Rect){BTM_BAR_MSG_X, BBAR_SPEEDUP_MSG_Y, XS_CHAR_W, S_CHAR_H});
	corewar_vis_render_btext(rend, BBAR_SLOWDOWN_MSG, RGBA_TEXT2,
	(SDL_Rect){BTM_BAR_MSG_X, BBAR_SLOWDOWN_MSG_Y, XS_CHAR_W, S_CHAR_H});
	corewar_vis_render_btext(rend, BBAR_DETAILS_MSG, RGBA_TEXT2,
	(SDL_Rect){BTM_BAR_MSG_X, BBAR_DETAILS_MSG_Y, XS_CHAR_W, S_CHAR_H});
	corewar_vis_render_btext(rend, BBAR_REVERSE_MSG, RGBA_TEXT2,
	(SDL_Rect){BTM_BAR_MSG_X, BBAR_REVERSE_MSG_Y, XS_CHAR_W, S_CHAR_H});
	corewar_vis_render_btext(rend, BBAR_RUN_MSG, RGBA_TEXT2,
	(SDL_Rect){BTM_BAR_MSG_X, BBAR_RUN_MSG_Y, XS_CHAR_W, S_CHAR_H});
	corewar_vis_render_btext(rend, BBAR_QUIT_MSG, RGBA_TEXT2,
	(SDL_Rect){BTM_BAR_MSG_X, BBAR_QUIT_MSG_Y, XS_CHAR_W, S_CHAR_H});
}

static void	static_render_buttons(t_vis *vis)
{
	SDL_SetRenderDrawBlendMode(vis->rend, SDL_BLENDMODE_BLEND);
	corewar_vis_render_button(vis, &vis->btns.speed_up);
	corewar_vis_render_button(vis, &vis->btns.slow_down);
	corewar_vis_render_button(vis, &vis->btns.next);
	corewar_vis_render_button(vis, &vis->btns.run);
	corewar_vis_render_button(vis, &vis->btns.quit);
	corewar_vis_render_button(vis, &vis->btns.reverse);
	corewar_vis_render_button(vis, &vis->btns.detail);
}

static void	static_speed_bar(t_vis *vis, SDL_Rect box)
{
	SDL_SetRenderDrawColor(vis->rend, R(RGBA_SHADOW), G(RGBA_SHADOW),
	B(RGBA_SHADOW), A(RGBA_SHADOW));
	SDL_RenderFillRect(vis->rend, &box);
	box.x += SHADOW_SIZE;
	box.y += SHADOW_SIZE;
	box.h -= (SHADOW_SIZE * 2);
	box.w -= (SHADOW_SIZE * 2);
	SDL_SetRenderDrawColor(vis->rend, R(RGBA_BUTTON), G(RGBA_BUTTON),
	B(RGBA_BUTTON), A(RGBA_BUTTON));
	SDL_RenderFillRect(vis->rend, &box);
	box.w = (Sint32)(box.w
	* corewar_vis_pct(MAX_TIMEOUT_MS, MIN_TYMEOUT_MS, vis->timeout));
	SDL_SetRenderDrawColor(vis->rend, R(RGBA_TEXT2), G(RGBA_TEXT2),
	B(RGBA_TEXT2), A(RGBA_TEXT2));
	SDL_RenderFillRect(vis->rend, &box);
	corewar_vis_render_btext(vis->rend, BBAR_SP_MSG, RGBA_TEXT,
	(SDL_Rect){BTM_BAR_MSG_X, BBAR_SPEED_MSG_Y - PAD, S_CHAR_W, S_CHAR_H});
}

void		corewar_vis_render_btmb(t_vis *vis)
{
	static_render_buttons(vis);
	static_render_tips(vis->rend);
	static_speed_bar(vis, (SDL_Rect){BAR_X, BBAR_SPEED_B_Y, BAR_W, S_BUTTON_H});
}
