/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 20:30:17 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/12 13:48:26 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_VIS_H

# define COREWAR_VIS_H

# include "corewar_vis_def.h"
# include "corewar_def.h"

void	corewar_vis_render_arena(t_data *data, t_vis *vis);
void	corewar_vis_render_pc(t_data *data, t_vis *vis);
void	corewar_vis_render_topb(t_data *data, t_vis *vis);
void	corewar_vis_render_topb2(t_data *data, t_vis *vis);
void	corewar_vis_render_mdlb(t_data *data, t_vis *vis);
void	corewar_vis_render_btmb(t_vis *vis);
void	corewar_vis_render_gameover(t_vis *vis, t_data *data);
void	corewar_vis_render_gamestart(t_vis *vis, t_data *data);
void	corewar_vis_resize(t_vis *vis, SDL_Event *event);

void	corewar_vis_render_pc_timeout(SDL_Renderer *rend, t_carriage *carr,
		SDL_Rect box);
void	corewar_vis_render_pc_lastlive(SDL_Renderer *rend, t_carriage *carr,
		SDL_Rect box);
void	corewar_vis_render_pc_op(SDL_Renderer *rend, t_carriage *carr,
		SDL_Rect box);
void	corewar_vis_render_pc_carry(SDL_Renderer *rend, t_carriage *carr,
		SDL_Rect box);
void	corewar_vis_render_pc_id(SDL_Renderer *rend, t_carriage *carr,
		SDL_Rect box);

void	corewar_vis_render_rtext(SDL_Renderer *rend, const char *msg,
		unsigned int color, SDL_Rect box);
void	corewar_vis_render_btext(SDL_Renderer *rend, const char *msg,
		unsigned int color, SDL_Rect box);
void	corewar_vis_render_button(t_vis *vis, t_button *btn);
double	corewar_vis_pct(int min, int max, int eval);

void	corewar_vis_gameover_lock(t_buttons *btns);

void	corewar_vis_keyup(t_vis *vis, SDL_Event *event);
void	corewar_vis_keydown(t_vis *vis, SDL_Event *event);
void	corewar_vis_mousewheel(t_vis *vis, SDL_Event *event);
void	corewar_vis_mousemotion(t_vis *vis, SDL_Event *event);
void	corewar_vis_mousebuttondown(t_vis *vis, SDL_Event *event);
void	corewar_vis_mousebuttonup(t_vis *vis, SDL_Event *event);

void	corewar_vis_set_press(t_vis *vis, t_button *button);
void	corewar_vis_set_hower(t_vis *vis, t_button *button);
bool	corewar_vis_hitbox(t_vis *vis, Sint32 x, Sint32 y, SDL_Rect *box);

void	corewar_vis_pc_shown(t_vis *vis, t_carriage *carr_tmp);

void	corewar_vis_speed(t_vis *vis, bool state);
void	corewar_vis_reverse(t_vis *vis);
void	corewar_vis_quit(t_vis *vis);
void	corewar_vis_values(t_vis *vis);
void	corewar_vis_run(t_vis *vis);
void	corewar_vis_nxt(t_vis *vis);
void	corewar_mousebuttondown_left(t_vis *vis, Sint32 x, Sint32 y);

#endif
