/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_config.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:19:12 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/17 17:51:40 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_CONFIG_H

# define COREWAR_CONFIG_H

# define N_OPS 16u
# define N_REGS 16u

# define REG 1u
# define DIR 2u
# define IND 3u

# define TYPE_SIZE 3u
# define OP_SIZE 1u
# define ARGS_TYPES_SIZE 1u
# define REG_SIZE 4u
# define REG_LINK_SIZE 1u
# define DIR_SIZE REG_SIZE
# define IND_SIZE 2u

# define MAGIC_HEADER 0xea83f3
# define MAGIC_NULL 0

# define MIN_CHAMPIONS 1u
# define MAX_CHAMPIONS 4u
# define MAX_PLAYERS MAX_CHAMPIONS
# define MIN_PLAYERS MIN_CHAMPIONS

# define BASE_ARENA_SIZE 1024u
# define ARENA_SIZE (MAX_CHAMPIONS * BASE_ARENA_SIZE)
# define IDX_MOD (int)(ARENA_SIZE / 8)

# define MAGIC_HEADER_LENGTH 4u
# define MAGIC_NULL_LENGTH 4u
# define NAME_LENGTH 128u
# define CODE_SIZE_LENGTH 4u
# define COMMENT_LENGTH 2048u
# define CODE_LENGTH (ARENA_SIZE / 6u)

# define CYCLES_TO_CHECK 1536u
# define MIN_LIVE 21u
# define CYCLE_DELTA 50u
# define MAX_CHECKS 10u

# define DUMP_BYTES_PER_LINE 32u

#endif
