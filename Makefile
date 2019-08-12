# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/11 22:45:16 by daniel            #+#    #+#              #
#    Updated: 2019/05/25 16:24:24 by dderevyn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		corewar
OBJS_PATH =	.object/
SRCS_PATH =	source/
INCS_PATH =	include/
CC =		clang
UNAME_S :=	$(shell uname -s)
CFLAGS =	-Wall -Wextra -Werror -Ofast
RM =		rm -rf

OK_STRING =	[$(NAME) created]
COLOR_OFF =	\033[0m# Text Reset
RED =		\033[0;31m# Red
GREEN =		\033[0;32m# Green
PURPLE =	\033[0;35m# Purple

ifeq ($(UNAME_S),Linux)

CLIBS_PATH =		/home/linuxbrew/.linuxbrew/lib/
CLIBS_INCS_PATH =	/home/linuxbrew/.linuxbrew/include/
CLINKER_FLAGS =		-Wl,-rpath=$(CLIBS_PATH) -L$(CLIBS_PATH)

else ifeq ($(UNAME_S),Darwin)

CLIBS_PATH =		/Users/dderevyn/.brew/lib/
CLIBS_INCS_PATH =	/Users/dderevyn/.brew/include/
CLINKER_FLAGS =		-Wl,-rpath,$(CLIBS_PATH) -L$(CLIBS_PATH)

else

$(error Error: Your system is unsupported)

endif

CLIBS =				-lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer

LIBFT_PATH =		libft/
LIBFT_INCS_PATH =	$(LIBFT_PATH)$(INCS_PATH)
CLINKER_FLAGS +=	-L$(LIBFT_PATH)
CLIBS +=			-lft

COREWAR_INCS_PATH =	$(INCS_PATH)
COREWAR_INCS =		corewar.h \
					corewar_config.h \
					corewar_def.h
COREWAR_SRCS_PATH =	$(SRCS_PATH)
COREWAR_SRCS =		corewar.c \
					corewar_exec_carr.c \
					corewar_exit.c \
					corewar_init.c \
					corewar_utils.c \
					corewar_vm.c
COREWAR_OBJS_PATH =	$(OBJS_PATH)
COREWAR_OBJS =		$(COREWAR_SRCS:%.c=$(COREWAR_OBJS_PATH)%.o)

VIS_INCS_PATH =	$(INCS_PATH)vis/
VIS_INCS =		corewar_vis.h \
				corewar_vis_color.h \
				corewar_vis_content.h \
				corewar_vis_def.h \
				corewar_vis_prop.h
VIS_SRCS_PATH =	$(SRCS_PATH)vis/
VIS_SRCS =		corewar_vis.c \
				corewar_vis_handle_utils.c \
				corewar_vis_handle_wheel.c \
				corewar_vis_init.c \
				corewar_vis_key_handle.c \
				corewar_vis_lock.c \
				corewar_vis_mods.c \
				corewar_vis_mods2.c \
				corewar_vis_motion_handle.c \
				corewar_vis_mouse_handle.c \
				corewar_vis_render_arena.c \
				corewar_vis_render_btmb.c \
				corewar_vis_render_mdlb.c \
				corewar_vis_render_pc.c \
				corewar_vis_render_pc_msg.c \
				corewar_vis_render_topb.c \
				corewar_vis_render_topb2.c \
				corewar_vis_render_utils.c
VIS_OBJS_PATH =	$(OBJS_PATH)vis/
VIS_OBJS =		$(VIS_SRCS:%.c=$(VIS_OBJS_PATH)%.o)

OP_INCS_PATH =	$(INCS_PATH)op/
OP_INCS =		corewar_op.h \
				corewar_op_def.h
OP_SRCS_PATH =	$(SRCS_PATH)op/
OP_SRCS =		corewar_op.c \
				corewar_op2.c \
				corewar_op3.c \
				corewar_op4.c
OP_OBJS_PATH =	$(OBJS_PATH)op/
OP_OBJS =		$(OP_SRCS:%.c=$(OP_OBJS_PATH)%.o)

PARSE_INCS_PATH =	$(INCS_PATH)parse/
PARSE_INCS =		corewar_parse.h \
					corewar_parse_def.h
PARSE_SRCS_PATH =	$(SRCS_PATH)parse/
PARSE_SRCS =		corewar_parse.c \
					corewar_parse_champion.c \
					corewar_parse_options.c
PARSE_OBJS_PATH =	$(OBJS_PATH)parse/
PARSE_OBJS =		$(PARSE_SRCS:%.c=$(PARSE_OBJS_PATH)%.o)

all: $(NAME)

$(NAME): $(COREWAR_OBJS) $(VIS_OBJS) $(OP_OBJS) $(PARSE_OBJS) | libft.a
	@$(CC) $(CFLAGS) -o $@ $^ $(CLINKER_FLAGS) $(CLIBS)
	@printf "\n$(GREEN)$(OK_STRING)$(COLOR_OFF)\n"

libft.a:
	@make $@ -s -C $(LIBFT_PATH)

$(COREWAR_OBJS_PATH)%.o: $(COREWAR_SRCS_PATH)%.c
	@mkdir -p $(COREWAR_OBJS_PATH)
	@mkdir -p $(VIS_OBJS_PATH)
	@mkdir -p $(OP_OBJS_PATH)
	@mkdir -p $(PARSE_OBJS_PATH)
	@$(CC) $(CFLAGS) -o $@ -c $< \
	-I$(LIBFT_INCS_PATH) \
	-I$(CLIBS_INCS_PATH) \
	-I$(COREWAR_INCS_PATH) \
	-I$(VIS_INCS_PATH) \
	-I$(OP_INCS_PATH) \
	-I$(PARSE_INCS_PATH)
	@printf "$(PURPLE)*$(COLOR_OFF)"

clean:
	@make $@ -s -C $(LIBFT_PATH)
	@$(RM) $(OBJS_PATH)

fclean: clean
	@make $@ -s -C $(LIBFT_PATH)
	@$(RM) $(NAME)
	@printf "$(RED)remove $(NAME)$(COLOR_OFF)\n"

re: fclean all

norm:
	@make $@ -s -C $(LIBFT_PATH)
	@norminette \
	$(addprefix $(COREWAR_INCS_PATH),$(COREWAR_INCS)) \
	$(addprefix $(COREWAR_SRCS_PATH),$(COREWAR_SRCS)) \
	$(addprefix $(VIS_INCS_PATH),$(VIS_INCS)) \
	$(addprefix $(VIS_SRCS_PATH),$(VIS_SRCS)) \
	$(addprefix $(OP_INCS_PATH),$(OP_INCS)) \
	$(addprefix $(OP_SRCS_PATH),$(OP_SRCS)) \
	$(addprefix $(PARSE_INCS_PATH),$(PARSE_INCS)) \
	$(addprefix $(PARSE_SRCS_PATH),$(PARSE_SRCS))

.PHONY: all clean fclean re norm
