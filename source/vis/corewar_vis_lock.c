/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_lock.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 20:15:24 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/12 15:59:06 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vis.h"
#include "corewar_vis_prop.h"
#include "corewar_vis_color.h"
#include "libft.h"

void			corewar_vis_gameover_lock(t_buttons *btns)
{
	btns->detail.active = false;
	btns->detail.hower = false;
	btns->detail.press = false;
	btns->reverse.active = false;
	btns->reverse.hower = false;
	btns->reverse.press = false;
	btns->next.active = false;
	btns->next.hower = false;
	btns->next.press = false;
	btns->run.active = false;
	btns->run.hower = false;
	btns->run.press = false;
	btns->speed_up.active = false;
	btns->speed_up.hower = false;
	btns->speed_up.press = false;
	btns->slow_down.active = false;
	btns->slow_down.hower = false;
	btns->slow_down.press = false;
	btns->status.active = true;
	btns->status.hower = false;
	btns->status.press = false;
}

static void		static_render_comment(t_data *data, t_vis *vis)
{
	static SDL_Rect	box;
	static Sint32	w = 0;

	if (!w)
	{
		w = (Sint32)ft_strlen(data->players[data->leader - 1].comment);
		box.x = (ARENA_W - (w * CHAR_W)) / 2;
		box.y = ((MAX_WIN_H - L_CHAR_H) / 2) + L_CHAR_H + (PAD * 10);
		box.w = CHAR_W;
		box.h = L_CHAR_H;
	}
	corewar_vis_render_btext(vis->rend, data->players[data->leader - 1].comment,
	vis->color[data->leader - 1], box);
}

void			corewar_vis_render_gameover(t_vis *vis, t_data *data)
{
	static Sint32	w = 0;
	static SDL_Rect	box;
	static char		*str = NULL;

	if (!w)
	{
		w = (Sint32)ft_strlen("Player ");
		w += ft_strlen(" won !!!");
		w += ft_strlen(data->players[data->leader - 1].name);
		ft_strninject(&str, "Player ", 0, -1);
		ft_strninject(&str, data->players[data->leader - 1].name, -1, -1);
		ft_strninject(&str, " won !!!", -1, -1);
		box.x = (ARENA_W - (w * L_CHAR_W)) / 2;
		box.y = (MAX_WIN_H - L_CHAR_H) / 2;
		box.w = L_CHAR_W;
		box.h = L_CHAR_H;
	}
	corewar_vis_render_btext(vis->rend, str, vis->color[data->leader - 1], box);
	static_render_comment(data, vis);
}

static SDL_Rect	static_box(unsigned int i)
{
	if (i == 1)
		return ((SDL_Rect){200, 200, 0, 0});
	if (i == 2)
		return ((SDL_Rect){ARENA_W - 200, 200, 0, 0});
	if (i == 3)
		return ((SDL_Rect){200, MAX_WIN_H - 200, 0, 0});
	else
		return ((SDL_Rect){ARENA_W - 200, MAX_WIN_H - 200, 0, 0});
}

void			corewar_vis_render_gamestart(t_vis *vis, t_data *data)
{
	SDL_Rect		box;
	unsigned int	i;
	Sint32			w_tmp;
	char			*str;

	i = 1;
	while (i <= data->n_players)
	{
		w_tmp = (Sint32)ft_strlen(data->players[i - 1].name);
		box = static_box(i);
		corewar_vis_render_btext(vis->rend, data->players[i - 1].name,
		g_color[i], (SDL_Rect){box.x - (w_tmp * L_CHAR_W / 2),
		box.y - L_CHAR_H - (PAD * 5), L_CHAR_W, L_CHAR_H});
		str = ft_itoabase(DEC, data->players[i - 1].code_size);
		ft_strninject(&str, "Weight of ", 0, -1);
		w_tmp = (Sint32)ft_strlen(str);
		corewar_vis_render_btext(vis->rend, str, g_color[i],
		(SDL_Rect){box.x - (w_tmp * CHAR_W / 2), box.y,
		CHAR_W, CHAR_H});
		ft_strdel(&str);
		++i;
	}
}
