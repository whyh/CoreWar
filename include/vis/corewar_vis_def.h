/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_def.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 20:41:42 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/17 15:27:38 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_VIS_DEF_H

# define COREWAR_VIS_DEF_H

# include <stdbool.h>
# include "SDL2/SDL.h"
# include "corewar_config.h"

# define WIN_NAME "CoreWars"

# define FONT_REG "vm/resource/font/Roboto-Regular.ttf"
# define FONT_BOLD "vm/resource/font/Roboto-Bold.ttf"
# define IMG_BG "vm/resource/image/Mob_psycho_100.png"
# define IMG_GAMESTART "vm/resource/image/game_start.png"
# define IMG_GAMEOVER "vm/esource/image/game_over.png"
# define MUSIC_BG "vm/resource/music/Smeared.mp3"

# define TIMEOUT_MS 50
# define MIN_TYMEOUT_MS 0
# define MAX_TIMEOUT_MS 100
# define D_TIMEOUT_MS 10

typedef struct		s_keydown
{
	bool			esk;
	bool			space;
	bool			lalt;
	bool			f;
	bool			mbl;
}					t_keydown;

typedef	struct		s_button
{
	bool			press;
	bool			hower;
	bool			active;
	const char		*msg;
	const char		*alt_msg;
	const char		*init_msg;
	bool			bg_shown;
	SDL_Rect		bg;
}					t_button;

typedef struct		s_buttons
{
	t_button		status;
	t_button		speed_up;
	t_button		slow_down;
	t_button		run;
	t_button		quit;
	t_button		reverse;
	t_button		detail;
	t_button		next;
}					t_buttons;

typedef struct		s_vis
{
	SDL_Window		*win;
	SDL_Renderer	*rend;
	bool			game_start;
	bool			game_over;
	Sint32			m_x;

	Sint32			m_y;
	float			scale;
	unsigned int	timeout;
	unsigned int	color[ARENA_SIZE];
	t_buttons		btns;
	t_keydown		keydown;
}					t_vis;

#endif
