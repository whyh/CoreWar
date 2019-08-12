/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_prop.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 19:43:40 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/11 16:05:57 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_VIS_PROP_H

# define COREWAR_VIS_PROP_H

# define MAX_WIN_W 1800
# define MAX_WIN_H 1105
# define STANDARD_BORDER_H 30
# define PAD 5
# define ARENA_W (1500)
# define N_COLUMNS 75
# define SHADOW_SIZE 3

# define L_CHAR_H 70
# define L_CHAR_W 35
# define CHAR_H 50
# define CHAR_W 25
# define M_CHAR_H 25
# define S_CHAR_H 20
# define S_CHAR_W 12
# define XS_CHAR_H 13
# define XS_CHAR_W 7
# define BAR_W (MAX_WIN_W - ARENA_W - (PAD * 2))
# define BAR_X (ARENA_W + PAD)

# define BYTE_SIZE 15
# define BYTE_SHADOW 2

# define BUTTON_W (MAX_WIN_W - ARENA_W - (PAD * 2))
# define BUTTON_H 70
# define S_BUTTON_W 100
# define S_BUTTON_H 30
# define MESSAGE_W(BTN_H) (BTN_H == BUTTON_H ? CHAR_W : S_CHAR_W)
# define MESSAGE_H(BTN_H) (BTN_H == BUTTON_H ? CHAR_H : S_CHAR_H)
# define BUTTON_MSG_X(BTN_W, MSG_W) ((BTN_W / 2) - (MSG_W / 2))
# define BUTTON_MSG_Y(BTN_H, MSG_H) ((BTN_H / 2) - (MSG_H / 2))

# define TOP_BAR_D 30
# define TOP_BAR_POS_Y PAD
# define STS_PAD (BUTTON_H - (TOP_BAR_D / 2))
# define TOP_BAR_Y(N) (TOP_BAR_POS_Y + (TOP_BAR_D * N) + (N > 0 ? STS_PAD : 0))

# define MID_BAR_POS_Y 250
# define MID_BAR_D 50
# define N_MID_BAR_EL 3
# define MID_BAR_I_Y(I) ((MID_BAR_D * I) + (M_CHAR_H * N_MID_BAR_EL * I))
# define MID_BAR_Y(I, N) (MID_BAR_POS_Y + (M_CHAR_H * N + 1) + MID_BAR_I_Y(I))
# define P_SHADOW_H 80

# define BTM_BAR_POS_Y 790
# define BTM_BAR_D 35
# define BTM_BAR_Y(N) (BTM_BAR_POS_Y + (BTM_BAR_D * N))
# define BTM_BAR_MSG_X (BAR_X + S_BUTTON_W + PAD)
# define BTM_BAR_MSG_Y(N) (BTM_BAR_Y(N) + (S_CHAR_H / 2))

# define CAR_INF_W 200
# define CAR_INF_H 485

# define PROCESS_H (S_CHAR_H + PAD)

#endif
