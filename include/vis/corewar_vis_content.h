/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_content.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 14:59:17 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/10 16:36:30 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_VIS_CONTENT_H

# define COREWAR_VIS_CONTENT_H

# include "corewar_vis_prop.h"

# define TBAR_SEP "/"

# define TBAR_STATUS_POS 0
# define TBAR_STATUS_Y TOP_BAR_Y(TBAR_STATUS_POS)
# define TBAR_BSTATUS_MSG "Pause"
# define TBAR_BSTATUS_A_MSG "CoreWars"
# define TBAR_BSTATUS_I_MSG "Start"

# define TBAR_CYCLE_POS 1
# define TBAR_CYCLE_Y TOP_BAR_Y(TBAR_CYCLE_POS)
# define TBAR_CYCLE_MSG "Cycle"

# define TBAR_NCI_POS 2
# define TBAR_NCI_Y TOP_BAR_Y(TBAR_NCI_POS)
# define TBAR_NCI_MSG "Next check in"

# define TBAR_FC_POS 3
# define TBAR_FC_Y TOP_BAR_Y(TBAR_FC_POS)
# define TBAR_FC_MSG "Forced decrease"

# define TBAR_LC_POS 4
# define TBAR_LC_Y TOP_BAR_Y(TBAR_LC_POS)
# define TBAR_LC_MSG "Lives casted"

# define TBAR_PCS_POS 5
# define TBAR_PCS_Y TOP_BAR_Y(TBAR_PCS_POS)
# define TBAR_PCS_MSG "Processes"

# define MBAR_NAME_POS 0
# define MBAR_NAME_Y(I) MID_BAR_Y(I, MBAR_NAME_POS)
# define MBAR_NAME_MSG "Player"

# define MBAR_LCL_POS 1
# define MBAR_LCL_Y(I) MID_BAR_Y(I, MBAR_LCL_POS)
# define MBAR_LCL_MSG "Last casted live"

# define MBAR_CL_POS 2
# define MBAR_CL_Y(I) MID_BAR_Y(I, MBAR_CL_POS)
# define MBAR_CL_MSG "Current lives"

# define BBAR_TIP_POS 0
# define BBAR_TIP_MSG_Y BTM_BAR_MSG_Y(BBAR_TIP_POS)
# define BBAR_TIP_MSG "Tip: select process with a mouse"

# define BBAR_NEXT_POS 1
# define BBAR_NEXT_B_Y BTM_BAR_Y(BBAR_NEXT_POS)
# define BBAR_BNEXT_MSG "Next cycle"
# define BBAR_BNEXT_A_MSG NULL
# define BBAR_BNEXT_I_MSG NULL

# define BBAR_SPEEDUP_POS 2
# define BBAR_SPEEDUP_MSG_Y BTM_BAR_MSG_Y(BBAR_SPEEDUP_POS)
# define BBAR_SPEEDUP_B_Y BTM_BAR_Y(BBAR_SPEEDUP_POS)
# define BBAR_SPEEDUP_MSG "Hold LALT & wheel UP"
# define BBAR_BSPEEDUP_MSG "SpeedUp"
# define BTBAR_BSPEEDUP_A_MSG NULL
# define BTBAR_BSPEEDUP_I_MSG NULL

# define BBAR_SLOWDOWN_POS 3
# define BBAR_SLOWDOWN_MSG_Y BTM_BAR_MSG_Y(BBAR_SLOWDOWN_POS)
# define BBAR_SLOWDOWN_B_Y BTM_BAR_Y(BBAR_SLOWDOWN_POS)
# define BBAR_SLOWDOWN_MSG "Hold LALT & wheel DOWN"
# define BBAR_BSLOWDOWN_MSG "SlowDown"
# define BBAR_BSLOWDOWN_A_MSG NULL
# define BBAR_BSLOWDOWN_I_MSG NULL

# define BBAR_SPEED_POS 4
# define BBAR_SPEED_MSG_Y BTM_BAR_MSG_Y(BBAR_SPEED_POS)
# define BBAR_SPEED_B_Y BTM_BAR_Y(BBAR_SPEED_POS)
# define BBAR_SP_MSG "Speed"

# define BBAR_DETAILS_POS 5
# define BBAR_DETAILS_MSG_Y BTM_BAR_MSG_Y(BBAR_DETAILS_POS)
# define BBAR_DETAILS_B_Y BTM_BAR_Y(BBAR_DETAILS_POS)
# define BBAR_DETAILS_MSG "Hold LALT & press F"
# define BBAR_BDETAILS_MSG "Detailed"
# define BBAR_BDETAILS_A_MSG "Simple"
# define BBAR_BDETAILS_I_MSG NULL

# define BBAR_REVERSE_POS 6
# define BBAR_REVERSE_MSG_Y BTM_BAR_MSG_Y(BBAR_REVERSE_POS)
# define BBAR_REVERSE_B_Y BTM_BAR_Y(BBAR_REVERSE_POS)
# define BBAR_REVERSE_MSG "Hold LALT & press SPACE"
# define BBAR_BREVERSE_MSG "Pc view"
# define BBAR_BREVERSE_A_MSG NULL
# define BBAR_BREVERSE_I_MSG NULL

# define BBAR_RUN_POS 7
# define BBAR_RUN_MSG_Y BTM_BAR_MSG_Y(BBAR_RUN_POS)
# define BBAR_RUN_B_Y BTM_BAR_Y(BBAR_RUN_POS)
# define BBAR_RUN_MSG "Press SPACE"
# define BBAR_BRUN_MSG "Resume"
# define BBAR_BRUN_A_MSG "Pause"
# define BBAR_BRUN_I_MSG "Start"

# define BBAR_QUIT_POS 8
# define BBAR_QUIT_MSG_Y BTM_BAR_MSG_Y(BBAR_QUIT_POS)
# define BBAR_QUIT_B_Y BTM_BAR_Y(BBAR_QUIT_POS)
# define BBAR_QUIT_MSG "Press ESC"
# define BBAR_BQUIT_MSG "Quit"
# define BBAR_BQUIT_A_MSG NULL
# define BBAR_BQUIT_I_MSG NULL

#endif
