/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_color.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 19:41:31 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/10 14:48:45 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_VIS_COLOR_H

# define COREWAR_VIS_COLOR_H

# define A(RGBA) (Uint8)((RGBA >> 24u) & 255u)
# define R(RGBA) (Uint8)((RGBA >> 16u) & 255u)
# define G(RGBA) (Uint8)((RGBA >> 8u) & 255u)
# define B(RGBA) (Uint8)(RGBA & 255u)

# define RGBA_TEXT 0xFF66686Au
# define RGBA_TEXT2 0xFFCCCCCCu
# define RGBA_TEXT3 0xAAACACACu
# define RGBA_TEXTS 0xFF78A42Bu
# define RGBA_BUTTON 0xEA444444u
# define PRESS -20
# define HOWER 20

# define RGBA_CARR 0x9FB4B4B4u
# define CARR_OP 0x9Fu

# define RGBA_BG 0xFF2B2B2Bu
# define RGBA_SHADOW 0xFF44454Au

# define EDGE_BRIGHT 0x64u
# define RGBA_VALUE_BRIGHT 0xFFD2B4B4u
# define RGBA_VALUE_DARK 0xFF141414u

# define RGBA_PLAYER0 0xFF65655Cu
# define RGBA_PLAYER 0xFF78A42Bu
# define RGBA_PLAYER2 0xFF804980u
# define RGBA_PLAYER3 0xFF999900u
# define RGBA_PLAYER4 0xFFB96D40u
# define PROCESS_INF_OP 0xD0u
# define PLAYER_BAR_OP 0xCCu
# define PLAYER_SHADOW_OP 0x30u

static const unsigned int	g_color[MAX_PLAYERS + 1] =
{
	RGBA_PLAYER0,
	RGBA_PLAYER,
	RGBA_PLAYER2,
	RGBA_PLAYER3,
	RGBA_PLAYER4
};

#endif
