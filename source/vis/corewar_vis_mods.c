/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_mods.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 14:40:21 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/10 19:05:02 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vis.h"
#include "SDL2/SDL_mixer.h"

void	corewar_vis_speed(t_vis *vis, bool state)
{
	if (vis->game_start || vis->game_over)
		return ;
	if (state)
	{
		if (vis->timeout > MIN_TYMEOUT_MS)
			vis->timeout -= D_TIMEOUT_MS;
	}
	else
	{
		if (vis->timeout < MAX_TIMEOUT_MS)
			vis->timeout += D_TIMEOUT_MS;
	}
}

void	corewar_vis_run(t_vis *vis)
{
	if (vis->game_over)
		return ;
	if (vis->btns.run.active)
	{
		vis->btns.run.active = false;
		vis->btns.status.active = false;
		Mix_PauseMusic();
	}
	else
	{
		vis->btns.run.active = true;
		vis->btns.status.active = true;
		vis->btns.detail.active = false;
		Mix_ResumeMusic();
	}
}

void	corewar_vis_values(t_vis *vis)
{
	if (vis->game_start || vis->game_over)
		return ;
	if (vis->btns.detail.active)
		vis->btns.detail.active = false;
	else
	{
		vis->btns.detail.active = true;
		vis->btns.run.active = false;
		vis->btns.status.active = false;
		Mix_PauseMusic();
	}
}

void	corewar_vis_quit(t_vis *vis)
{
	if (vis->btns.quit.active)
		vis->btns.quit.active = false;
	else
		vis->btns.quit.active = true;
}

void	corewar_vis_reverse(t_vis *vis)
{
	if (vis->game_start || vis->game_over)
		return ;
	if (vis->btns.reverse.active)
		vis->btns.reverse.active = false;
	else
		vis->btns.reverse.active = true;
}
