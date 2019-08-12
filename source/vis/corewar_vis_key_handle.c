/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_key_handle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 20:03:57 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/06 14:56:43 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vis.h"

void		corewar_vis_keydown(t_vis *vis, SDL_Event *event)
{
	if (event->key.keysym.sym == SDLK_ESCAPE)
		vis->keydown.esk = true;
	else if (event->key.keysym.sym == SDLK_SPACE)
		vis->keydown.space = true;
	else if (event->key.keysym.sym == SDLK_LALT)
		vis->keydown.lalt = true;
	else if (event->key.keysym.sym == SDLK_f)
		vis->keydown.f = true;
}

static void	static_keyup2(t_vis *vis, SDL_Event *event)
{
	if (event->key.keysym.sym == SDLK_LALT)
		vis->keydown.lalt = false;
	else if (event->key.keysym.sym == SDLK_f)
	{
		vis->keydown.f = false;
		if (vis->keydown.lalt)
			corewar_vis_values(vis);
	}
}

void		corewar_vis_keyup(t_vis *vis, SDL_Event *event)
{
	if (event->key.keysym.sym == SDLK_ESCAPE)
	{
		vis->keydown.esk = false;
		corewar_vis_quit(vis);
	}
	else if (event->key.keysym.sym == SDLK_SPACE)
	{
		vis->keydown.space = false;
		if (vis->keydown.lalt)
			corewar_vis_reverse(vis);
		else
			corewar_vis_run(vis);
	}
	else
		static_keyup2(vis, event);
}
