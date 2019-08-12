/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:12:57 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/17 18:19:11 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_mixer.h"

static void	static_free_data(t_data *data)
{
	corewar_kill_carrs(data, data->carr);
	free(data->carr);
}

static void	static_free_parse(t_parse *parse)
{
	unsigned int	i;

	i = 0;
	while (i < parse->n_champs)
	{
		ft_memdel((void**)&(parse->champs[i].code));
		++i;
	}
}

static void	static_free_vis(t_vis *vis)
{
	SDL_DestroyRenderer(vis->rend);
	SDL_DestroyWindow(vis->win);
	Mix_Quit();
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
}

bool		corewar_exit(t_parse *parse, t_data *data, t_vis *vis)
{
	if (parse)
		static_free_parse(parse);
	if (data)
		static_free_data(data);
	if (vis)
		static_free_vis(vis);
	return (true);
}
