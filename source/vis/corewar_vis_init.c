/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 16:38:19 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/17 19:23:35 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar_config.h"
#include "corewar_vis_def.h"
#include "corewar_vis_content.h"
#include "corewar_vis_color.h"
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"

static void	static_init_buttons(t_buttons *btns)
{
	btns->status = (t_button){false, false, false,
	TBAR_BSTATUS_MSG, TBAR_BSTATUS_A_MSG, TBAR_BSTATUS_I_MSG,
	false, (SDL_Rect){BAR_X, TBAR_STATUS_Y, BUTTON_W, BUTTON_H}};
	btns->slow_down = (t_button){false, false, false,
	BBAR_BSLOWDOWN_MSG, BBAR_BSLOWDOWN_A_MSG, BBAR_BSLOWDOWN_I_MSG,
	true, (SDL_Rect){BAR_X, BBAR_SLOWDOWN_B_Y, S_BUTTON_W, S_BUTTON_H}};
	btns->run = (t_button){false, false, false,
	BBAR_BRUN_MSG, BBAR_BRUN_A_MSG, BBAR_BRUN_I_MSG,
	true, (SDL_Rect){BAR_X, BBAR_RUN_B_Y, S_BUTTON_W, S_BUTTON_H}};
	btns->quit = (t_button){false, false, false,
	BBAR_BQUIT_MSG, BBAR_BQUIT_A_MSG, BBAR_BQUIT_I_MSG,
	true, (SDL_Rect){BAR_X, BBAR_QUIT_B_Y, S_BUTTON_W, S_BUTTON_H}};
	btns->reverse = (t_button){false, false, false,
	BBAR_BREVERSE_MSG, BBAR_BREVERSE_A_MSG, BBAR_BREVERSE_I_MSG,
	true, (SDL_Rect){BAR_X, BBAR_REVERSE_B_Y, S_BUTTON_W, S_BUTTON_H}};
	btns->detail = (t_button){false, false, false,
	BBAR_BDETAILS_MSG, BBAR_BDETAILS_A_MSG, BBAR_BDETAILS_I_MSG,
	true, (SDL_Rect){BAR_X, BBAR_DETAILS_B_Y, S_BUTTON_W, S_BUTTON_H}};
	btns->speed_up = (t_button){false, false, false,
	BBAR_BSPEEDUP_MSG, BTBAR_BSPEEDUP_A_MSG, BTBAR_BSPEEDUP_I_MSG,
	true, (SDL_Rect){BAR_X, BBAR_SPEEDUP_B_Y, S_BUTTON_W, S_BUTTON_H}};
	btns->next = (t_button){false, false, false,
	BBAR_BNEXT_MSG, BBAR_BNEXT_A_MSG, BBAR_BNEXT_I_MSG,
	true, (SDL_Rect){BAR_X, BBAR_NEXT_B_Y, BUTTON_W, S_BUTTON_H}};
}

static void	static_init_values(t_vis *vis)
{
	unsigned short	i;

	i = 0;
	while (i < ARENA_SIZE)
	{
		vis->color[i] = RGBA_PLAYER0;
		++i;
	}
	vis->timeout = TIMEOUT_MS;
	vis->keydown.esk = false;
	vis->keydown.space = false;
	vis->keydown.f = false;
	vis->keydown.lalt = false;
	vis->keydown.mbl = false;
	vis->game_start = true;
	vis->game_over = false;
	vis->m_x = 0;
	vis->m_y = 0;
	static_init_buttons(&vis->btns);
}

static bool	static_scale(t_vis *vis)
{
	SDL_Rect	display;

	SDL_GetDisplayUsableBounds(0, &display);
	SDL_GetDisplayBounds(0, &display);
	display.h -= STANDARD_BORDER_H;
	display.w = (display.w > MAX_WIN_W) ? MAX_WIN_W : display.w;
	display.h = (display.h > MAX_WIN_H) ? MAX_WIN_H : display.h;
	if ((double)(MAX_WIN_W - display.w) / MAX_WIN_W
	> (double)(MAX_WIN_H - display.h) / MAX_WIN_H)
		vis->scale = (float)display.w / MAX_WIN_W;
	else
		vis->scale = (float)display.h / MAX_WIN_H;
	return (true);
}

static bool	static_init_libs(void)
{
	if (SDL_Init(SDL_INIT_EVERYTHING))
	{
		ft_printf("[redError:~] Initialisation failed [yellowSDL2~]\n");
		return (false);
	}
	if (TTF_Init())
	{
		ft_printf("[redError:~] Initialisation failed [yellowSDL2_ttf~]\n");
		return (false);
	}
	if (!IMG_Init(IMG_INIT_PNG))
	{
		ft_printf("[redError:~] Initialisation failed [yellowSDL2_image~]\n");
		return (false);
	}
	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096)
	|| Mix_Init(MIX_INIT_MP3))
	{
		ft_printf("[redError:~] Initialisation failed [yellowSDL2_mix~]\n");
		return (false);
	}
	return (true);
}

bool		corewar_vis_init(t_vis *vis)
{
	if (!static_init_libs())
		return (false);
	static_scale(vis);
	if (!(vis->win = SDL_CreateWindow(WIN_NAME, 0, 0,
	(int)(vis->scale * MAX_WIN_W), (int)(vis->scale * MAX_WIN_H),
	SDL_WINDOW_RESIZABLE)))
		return (false);
	if (!(vis->rend =
	SDL_CreateRenderer(vis->win, -1, SDL_RENDERER_ACCELERATED)))
		return (false);
	SDL_SetWindowPosition(vis->win, SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED);
	SDL_SetWindowMaximumSize(vis->win, MAX_WIN_W, MAX_WIN_H);
	SDL_SetWindowMinimumSize(vis->win, MAX_WIN_W / 4, MAX_WIN_H / 4);
	SDL_RenderSetScale(vis->rend, vis->scale, vis->scale);
	static_init_values(vis);
	return (true);
}
