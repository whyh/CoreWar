/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_handle_wheel.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 20:22:54 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/08 20:23:49 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vis.h"

void	corewar_vis_mousewheel(t_vis *vis, SDL_Event *event)
{
	if (vis->keydown.lalt && event->wheel.y > 0)
		corewar_vis_speed(vis, true);
	else if (vis->keydown.lalt && event->wheel.y < 0)
		corewar_vis_speed(vis, false);
}
