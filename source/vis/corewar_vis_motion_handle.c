/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_motion_handle.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 21:21:54 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/17 15:38:06 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vis.h"
#include "corewar_vis_prop.h"

void	corewar_vis_resize(t_vis *vis, SDL_Event *event)
{
	int w;
	int h;

	if (event->window.event == SDL_WINDOWEVENT_RESIZED)
	{
		w = (event->window.data1 > MAX_WIN_W) ? MAX_WIN_W : event->window.data1;
		h = (event->window.data2 > MAX_WIN_H) ? MAX_WIN_H : event->window.data2;
		if ((float)w / MAX_WIN_W < (float)h / MAX_WIN_H)
			vis->scale = (float)w / MAX_WIN_W;
		else
			vis->scale = (float)h / MAX_WIN_H;
		SDL_RenderSetScale(vis->rend, vis->scale, vis->scale);
		SDL_SetWindowSize(vis->win, (int)(vis->scale * MAX_WIN_W),
		(int)(vis->scale * MAX_WIN_H));
	}
}

void	corewar_vis_pc_shown(t_vis *vis, t_carriage *carr_tmp)
{
	if (vis->game_start || vis->game_over)
		return ;
	while (carr_tmp)
	{
		if (vis->m_x > (carr_tmp->hitbox.x * vis->scale)
		&& vis->m_x < ((carr_tmp->hitbox.x + carr_tmp->hitbox.w) * vis->scale)
		&& vis->m_y > (carr_tmp->hitbox.y * vis->scale)
		&& vis->m_y < ((carr_tmp->hitbox.y + carr_tmp->hitbox.h) * vis->scale))
			carr_tmp->shown = true;
		else
			carr_tmp->shown = false;
		carr_tmp = carr_tmp->next;
	}
}

void	corewar_vis_mousemotion(t_vis *vis, SDL_Event *event)
{
	vis->m_x = event->motion.x;
	vis->m_y = event->motion.y;
	if (vis->keydown.mbl)
		corewar_mousebuttondown_left(vis, event->motion.x, event->motion.y);
	if (corewar_vis_hitbox(vis, vis->m_x, vis->m_y, &vis->btns.detail.bg))
		corewar_vis_set_hower(vis, &vis->btns.detail);
	else if (corewar_vis_hitbox(vis, vis->m_x, vis->m_y, &vis->btns.reverse.bg))
		corewar_vis_set_hower(vis, &vis->btns.reverse);
	else if (corewar_vis_hitbox(vis, vis->m_x, vis->m_y, &vis->btns.quit.bg))
		corewar_vis_set_hower(vis, &vis->btns.quit);
	else if (corewar_vis_hitbox(vis, vis->m_x, vis->m_y, &vis->btns.run.bg))
		corewar_vis_set_hower(vis, &vis->btns.run);
	else if (corewar_vis_hitbox(vis, vis->m_x, vis->m_y,
	&vis->btns.slow_down.bg))
		corewar_vis_set_hower(vis, &vis->btns.slow_down);
	else if (corewar_vis_hitbox(vis, vis->m_x, vis->m_y,
	&vis->btns.speed_up.bg))
		corewar_vis_set_hower(vis, &vis->btns.speed_up);
	else if (corewar_vis_hitbox(vis, vis->m_x, vis->m_y, &vis->btns.status.bg))
		corewar_vis_set_hower(vis, &vis->btns.status);
	else if (corewar_vis_hitbox(vis, vis->m_x, vis->m_y, &vis->btns.next.bg))
		corewar_vis_set_hower(vis, &vis->btns.next);
	else
		corewar_vis_set_hower(vis, NULL);
}
