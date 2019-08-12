/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_mouse_handle.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:58:45 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/09 19:50:36 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vis.h"

static void	static_mousebuttonup_left(t_vis *vis, Sint32 x, Sint32 y)
{
	corewar_vis_set_press(vis, NULL);
	if (corewar_vis_hitbox(vis, x, y, &vis->btns.detail.bg))
		corewar_vis_values(vis);
	else if (corewar_vis_hitbox(vis, x, y, &vis->btns.reverse.bg))
		corewar_vis_reverse(vis);
	else if (corewar_vis_hitbox(vis, x, y, &vis->btns.quit.bg))
		corewar_vis_quit(vis);
	else if (corewar_vis_hitbox(vis, x, y, &vis->btns.run.bg))
		corewar_vis_run(vis);
	else if (corewar_vis_hitbox(vis, x, y, &vis->btns.slow_down.bg))
		corewar_vis_speed(vis, false);
	else if (corewar_vis_hitbox(vis, x, y, &vis->btns.speed_up.bg))
		corewar_vis_speed(vis, true);
	else if (corewar_vis_hitbox(vis, x, y, &vis->btns.status.bg))
		corewar_vis_run(vis);
	else if (corewar_vis_hitbox(vis, x, y, &vis->btns.next.bg))
		corewar_vis_nxt(vis);
}

void		corewar_vis_mousebuttonup(t_vis *vis, SDL_Event *event)
{
	Sint32	x;
	Sint32	y;

	x = event->button.x;
	y = event->button.y;
	if (event->button.button == SDL_BUTTON_LEFT)
	{
		static_mousebuttonup_left(vis, x, y);
		vis->keydown.mbl = false;
	}
}

void		corewar_mousebuttondown_left(t_vis *vis, Sint32 x, Sint32 y)
{
	if (corewar_vis_hitbox(vis, x, y, &vis->btns.detail.bg))
		corewar_vis_set_press(vis, &vis->btns.detail);
	else if (corewar_vis_hitbox(vis, x, y, &vis->btns.reverse.bg))
		corewar_vis_set_press(vis, &vis->btns.reverse);
	else if (corewar_vis_hitbox(vis, x, y, &vis->btns.quit.bg))
		corewar_vis_set_press(vis, &vis->btns.quit);
	else if (corewar_vis_hitbox(vis, x, y, &vis->btns.run.bg))
		corewar_vis_set_press(vis, &vis->btns.run);
	else if (corewar_vis_hitbox(vis, x, y, &vis->btns.slow_down.bg))
		corewar_vis_set_press(vis, &vis->btns.slow_down);
	else if (corewar_vis_hitbox(vis, x, y, &vis->btns.speed_up.bg))
		corewar_vis_set_press(vis, &vis->btns.speed_up);
	else if (corewar_vis_hitbox(vis, x, y, &vis->btns.status.bg))
		corewar_vis_set_press(vis, &vis->btns.status);
	else if (corewar_vis_hitbox(vis, x, y, &vis->btns.next.bg))
		corewar_vis_set_press(vis, &vis->btns.next);
	else
		corewar_vis_set_press(vis, NULL);
}

void		corewar_vis_mousebuttondown(t_vis *vis, SDL_Event *event)
{
	Sint32	x;
	Sint32	y;

	x = event->button.x;
	y = event->button.y;
	if (event->button.button == SDL_BUTTON_LEFT)
	{
		corewar_mousebuttondown_left(vis, x, y);
		vis->keydown.mbl = true;
	}
}
