/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 20:29:49 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/17 17:53:48 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vis.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
#include "corewar_vis_prop.h"
#include "corewar_vis_color.h"

static void	static_handle_events(t_data *data, t_vis *vis)
{
	SDL_Event	event;

	if (!SDL_WaitEventTimeout(&event, 0))
		;
	else if (event.type == SDL_QUIT)
		vis->btns.quit.active = true;
	else if (event.type == SDL_KEYDOWN)
		corewar_vis_keydown(vis, &event);
	else if (event.type == SDL_KEYUP)
		corewar_vis_keyup(vis, &event);
	else if (event.type == SDL_MOUSEWHEEL)
		corewar_vis_mousewheel(vis, &event);
	else if (event.type == SDL_MOUSEMOTION)
		corewar_vis_mousemotion(vis, &event);
	else if (event.type == SDL_MOUSEBUTTONDOWN)
		corewar_vis_mousebuttondown(vis, &event);
	else if (event.type == SDL_MOUSEBUTTONUP)
		corewar_vis_mousebuttonup(vis, &event);
	else if (event.type == SDL_WINDOWEVENT)
		corewar_vis_resize(vis, &event);
	corewar_vis_pc_shown(vis, data->carr);
}

static void	static_cover_arena(t_vis *vis, t_data *data)
{
	static SDL_Rect		box = {0, 0, ARENA_W + PAD, MAX_WIN_H};
	static SDL_Texture	*bg_start = NULL;
	static SDL_Texture	*bg_end = NULL;

	if (vis->game_start)
	{
		if (!bg_start)
			bg_start = IMG_LoadTexture(vis->rend, IMG_GAMESTART);
		SDL_RenderCopy(vis->rend, bg_start, NULL, &box);
		corewar_vis_render_gamestart(vis, data);
	}
	else if (vis->game_over)
	{
		if (!bg_end)
			bg_end = IMG_LoadTexture(vis->rend, IMG_GAMEOVER);
		SDL_RenderCopy(vis->rend, bg_end, NULL, &box);
		corewar_vis_render_gameover(vis, data);
	}
}

static void	static_render_bg(t_vis *vis)
{
	static SDL_Rect		box = {ARENA_W, 0, MAX_WIN_W - ARENA_W, MAX_WIN_H};
	static SDL_Texture	*bg = NULL;

	if (!bg)
		bg = IMG_LoadTexture(vis->rend, IMG_BG);
	SDL_SetRenderDrawColor(vis->rend, R(RGBA_BG), G(RGBA_BG), B(RGBA_BG),
	A(RGBA_BG));
	SDL_RenderClear(vis->rend);
	SDL_SetRenderDrawBlendMode(vis->rend, SDL_BLENDMODE_BLEND);
	SDL_RenderCopy(vis->rend, bg, NULL, &box);
}

static void	static_render(t_data *data, t_vis *vis)
{
	Uint32	timeout;
	Uint32	time;

	timeout = SDL_GetTicks() + vis->timeout;
	time = 0;
	while (timeout > time)
	{
		static_render_bg(vis);
		corewar_vis_render_arena(data, vis);
		corewar_vis_render_pc(data, vis);
		corewar_vis_render_topb(data, vis);
		corewar_vis_render_mdlb(data, vis);
		corewar_vis_render_btmb(vis);
		if (vis->game_start || vis->game_over)
			static_cover_arena(vis, data);
		SDL_RenderPresent(vis->rend);
		static_handle_events(data, vis);
		time = SDL_GetTicks();
	}
}

void		corewar_vis(t_data *data, t_vis *vis)
{
	static Mix_Music	*music = NULL;

	vis->btns.next.active = false;
	if (vis->game_start)
	{
		if (!music)
			music = Mix_LoadMUS(MUSIC_BG);
		if (data->cycle != 0)
		{
			vis->game_start = false;
			Mix_PlayMusic(music, -1);
		}
	}
	else if (vis->game_over)
		corewar_vis_gameover_lock(&vis->btns);
	if (vis->btns.run.active && !vis->btns.quit.active)
		static_render(data, vis);
	else
	{
		while (!vis->btns.run.active && !vis->btns.quit.active
		&& !vis->btns.next.active)
			static_render(data, vis);
	}
}
