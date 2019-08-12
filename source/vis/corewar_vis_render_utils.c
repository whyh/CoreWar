/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_render_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 18:35:55 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/12 14:23:28 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vis.h"
#include "libft.h"
#include "SDL2/SDL_ttf.h"
#include "corewar_vis_prop.h"
#include "corewar_vis_color.h"

void		corewar_vis_render_btext(SDL_Renderer *rend, const char *msg,
			unsigned int color, SDL_Rect box)
{
	SDL_Surface		*surf;
	SDL_Texture		*txtr;
	static TTF_Font	*font = NULL;

	if (!font)
		font = TTF_OpenFont(FONT_BOLD, 60);
	box.w *= ft_strlen(msg);
	surf = TTF_RenderText_Blended(font, msg,
	(SDL_Color){R(color), G(color), B(color), A(color)});
	txtr = SDL_CreateTextureFromSurface(rend, surf);
	SDL_RenderCopy(rend, txtr, NULL, &box);
	SDL_DestroyTexture(txtr);
	SDL_FreeSurface(surf);
}

void		corewar_vis_render_rtext(SDL_Renderer *rend, const char *msg,
			unsigned int color, SDL_Rect box)
{
	SDL_Surface		*surf;
	SDL_Texture		*txtr;
	static TTF_Font	*font = NULL;

	if (!font)
		font = TTF_OpenFont(FONT_REG, 30);
	box.w *= ft_strlen(msg);
	surf = TTF_RenderText_Blended(font, msg,
	(SDL_Color){R(color), G(color), B(color), A(color)});
	txtr = SDL_CreateTextureFromSurface(rend, surf);
	SDL_RenderCopy(rend, txtr, NULL, &box);
	SDL_DestroyTexture(txtr);
	SDL_FreeSurface(surf);
}

void		static_color(t_button *btn, unsigned int *msg_color,
			unsigned int *bg_color)
{
	Sint8	mod;

	*msg_color = RGBA_TEXT;
	*bg_color = RGBA_BUTTON;
	if (btn->press)
		mod = PRESS;
	else if (btn->hower)
		mod = HOWER;
	else
		return ;
	*msg_color = A(*msg_color) << 24u
	| (Uint8)((unsigned int)(R(*msg_color) + mod) & 255u) << 16u
	| (Uint8)((unsigned int)(G(*msg_color) + mod) & 255u) << 8u
	| (Uint8)((unsigned int)(B(*msg_color) + mod) & 255u);
	*bg_color = A(*bg_color) << 24u
	| (Uint8)((unsigned int)(R(*bg_color) + mod) & 255u) << 16u
	| (Uint8)((unsigned int)(G(*bg_color) + mod) & 255u) << 8u
	| (Uint8)((unsigned int)(B(*bg_color) + mod) & 255u);
}

void		corewar_vis_render_button(t_vis *vis, t_button *btn)
{
	const char		*msg;
	SDL_Rect		box;
	unsigned int	msg_color;
	unsigned int	bg_color;

	static_color(btn, &msg_color, &bg_color);
	if (btn->bg_shown)
	{
		SDL_SetRenderDrawColor(vis->rend, R(bg_color), G(bg_color),
		B(bg_color), A(bg_color));
		SDL_RenderFillRect(vis->rend, &btn->bg);
	}
	if (vis->game_start && btn->init_msg)
		msg = btn->init_msg;
	else if (btn->active && btn->alt_msg)
		msg = btn->alt_msg;
	else
		msg = btn->msg;
	box.w = MESSAGE_W(btn->bg.h);
	box.h = MESSAGE_H(btn->bg.h);
	box.x = btn->bg.x + BUTTON_MSG_X(btn->bg.w, box.w * (Sint32)ft_strlen(msg));
	box.y = btn->bg.y + BUTTON_MSG_Y(btn->bg.h, box.h);
	corewar_vis_render_btext(vis->rend, msg, msg_color, box);
}

double		corewar_vis_pct(int min, int max, int eval)
{
	double	pos;
	double	pct;
	double	dist;

	dist = max - min;
	pos = eval - min;
	if (dist == 0)
		pct = 1.0;
	else
		pct = pos / dist;
	return (pct);
}
