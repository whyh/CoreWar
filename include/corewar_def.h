/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_def.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:48:20 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/18 20:14:10 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_DEF_H

# define COREWAR_DEF_H

# include "corewar_config.h"
# include "corewar_vis_def.h"

typedef struct			s_player
{
	unsigned int		pos;
	const char			*name;
	const char			*comment;
	unsigned int		code_size;
	unsigned int		last_live;
	unsigned int		n_lives;
}						t_player;

typedef struct			s_carriage
{
	unsigned int		id;
	SDL_Rect			hitbox;
	bool				shown;
	bool				carry;
	unsigned char		op;
	unsigned int		last_live;
	unsigned int		timeout;
	int					pos;
	unsigned int		delta_pos;
	unsigned int		args_values[3];
	unsigned char		args_types[3];
	unsigned int		regs[N_REGS + 1];
	struct s_carriage	*next;
}						t_carriage;

typedef struct			s_data
{
	unsigned int		dump;
	unsigned int		check;
	unsigned int		cycle;
	unsigned int		leader;
	unsigned int		ctc;
	unsigned int		n_live;
	unsigned int		n_carrs;
	unsigned int		n_a_carrs;
	unsigned int		n_players;
	t_player			players[MAX_PLAYERS];
	unsigned char		arena[ARENA_SIZE];
	t_carriage			*carr;
}						t_data;

typedef void			(*t_function)(t_data *data, t_carriage *carr,
						t_vis *vis);

#endif
