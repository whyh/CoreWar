/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_handle_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 23:48:36 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/12 13:56:05 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vis_def.h"

bool	corewar_vis_hitbox(t_vis *vis, Sint32 x, Sint32 y, SDL_Rect *box)
{
	if (x > (box->x * vis->scale) && x < ((box->x + box->w) * vis->scale)
	&& y > (box->y * vis->scale) && y < ((box->y + box->h) * vis->scale))
		return (true);
	return (false);
}

void	corewar_vis_set_hower(t_vis *vis, t_button *btn)
{
	vis->btns.detail.hower = false;
	vis->btns.reverse.hower = false;
	vis->btns.quit.hower = false;
	vis->btns.run.hower = false;
	vis->btns.slow_down.hower = false;
	vis->btns.speed_up.hower = false;
	vis->btns.status.hower = false;
	vis->btns.next.hower = false;
	if (btn)
		btn->hower = true;
}

void	corewar_vis_set_press(t_vis *vis, t_button *btn)
{
	vis->btns.detail.press = false;
	vis->btns.reverse.press = false;
	vis->btns.quit.press = false;
	vis->btns.run.press = false;
	vis->btns.slow_down.press = false;
	vis->btns.speed_up.press = false;
	vis->btns.status.press = false;
	vis->btns.next.press = false;
	if ((vis->game_start && btn != &vis->btns.status
	&& btn != &vis->btns.run && btn != &vis->btns.quit)
	|| (vis->game_over && btn != &vis->btns.quit))
		return ;
	if (btn)
		btn->press = true;
}
