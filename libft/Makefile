# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/21 20:30:28 by dderevyn          #+#    #+#              #
#    Updated: 2019/05/25 16:17:20 by dderevyn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libft.a
OBJS_PATH =	.object/
SRCS_PATH =	source/
INCS_PATH =	include/
CC =		clang
CFLAGS =	-Wall -Wextra -Werror -Ofast
RM =		rm -rf

LIBFT_INCS_PATH =	$(INCS_PATH)
LIBFT_INCS =		libft.h \
					libft_def.h
LIBFT_SRCS_PATH =	$(SRCS_PATH)
LIBFT_SRCS =		ft_abs.c \
					ft_atoibase.c \
					ft_itoabase.c \
					ft_memalloc.c \
					ft_memcmp.c \
					ft_memdel.c \
					ft_memmove.c \
					ft_memset.c \
					ft_nbr_len.c \
					ft_strchr.c \
					ft_strdel.c \
					ft_strfrepl.c \
					ft_strin.c \
					ft_strjoin.c \
					ft_strlen.c \
					ft_strncmp.c \
					ft_strncpy.c \
					ft_strndup.c \
					ft_strneject.c \
					ft_strnew.c \
					ft_strnin.c \
					ft_strninject.c \
					ft_strrchr.c \
					ft_swap.c
LIBFT_OBJS_PATH =	$(OBJS_PATH)
LIBFT_OBJS =		$(LIBFT_SRCS:%.c=$(LIBFT_OBJS_PATH)%.o)

GNL_PATH = 		$(SRCS_PATH)ft_gnl/
GNL_INCS_PATH =	$(GNL_PATH)$(INCS_PATH)
GNL_INCS =		ft_gnl_def.h
GNL_SRCS_PATH =	$(GNL_PATH)
GNL_SRCS =		ft_gnl.c
GNL_OBJS_PATH =	$(OBJS_PATH)ft_gnl/
GNL_OBJS =		$(GNL_SRCS:%.c=$(GNL_OBJS_PATH)%.o)

PRINTF_PATH =		$(SRCS_PATH)ft_printf/
PRINTF_INCS_PATH =	$(PRINTF_PATH)$(INCS_PATH)
PRINTF_INCS =		ft_printf.h \
					ft_printf_def.h
PRINTF_SRCS_PATH =	$(PRINTF_PATH)
PRINTF_SRCS =		ft_printf.c \
					ft_printf_cspf.c \
					ft_printf_diouxx.c \
					ft_printf_fill_funs.c \
					ft_printf_hash_zero_blank_plus.c \
					ft_printf_parse.c \
					ft_printf_prec.c \
					ft_printf_width.c \
					ft_printf_mod0_b_cap_udo.c \
					ft_printf_0_base.c \
					ft_printf_lhllhhl.c \
					ft_printf_zjt.c \
					ft_printf_r.c \
					ft_printf_unicode.c \
					ft_printf_parce_funs.c \
					ft_printf_color.c
PRINTF_OBJS_PATH =	$(OBJS_PATH)ft_printf/
PRINTF_OBJS =		$(PRINTF_SRCS:%.c=$(PRINTF_OBJS_PATH)%.o)

all: $(NAME)

$(NAME): $(LIBFT_OBJS) $(PRINTF_OBJS) $(GNL_OBJS)
	@ar rc $(NAME) $^
	@ranlib $(NAME)

$(LIBFT_OBJS_PATH)%.o: $(LIBFT_SRCS_PATH)%.c
	@mkdir -p $(LIBFT_OBJS_PATH)
	@mkdir -p $(GNL_OBJS_PATH)
	@mkdir -p $(PRINTF_OBJS_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@ \
	-I$(INCS_PATH) \
	-I$(GNL_INCS_PATH) \
	-I$(PRINTF_INCS_PATH)

clean:
	@$(RM) $(OBJS_PATH)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

norm:
	@norminette \
	$(addprefix $(INCS_PATH),$(LIBFT_INCS)) \
	$(addprefix $(SRCS_PATH),$(LIBFT_SRCS)) \
	$(addprefix $(GNL_SRCS_PATH),$(GNL_SRCS)) \
	$(addprefix $(GNL_INCS_PATH),$(GNL_INCS)) \
	$(addprefix $(PRINTF_SRCS_PATH),$(PRINTF_SRCS)) \
	$(addprefix $(PRINTF_INCS_PATH),$(PRINTF_INCS))

.PHONY: all clean fclean re norm
