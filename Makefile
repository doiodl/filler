# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: btheia <btheia@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/10 21:07:00 by flogan            #+#    #+#              #
#    Updated: 2020/03/07 19:02:00 by btheia           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIS_ASM =		visual
ASM =		    btheia.filler
NAME =			$(DIS_ASM) $(ASM)
LIBFT_A =		libftprintf.a
LIBFT =			ft_printf/
LIBFT_DIR_A =  	ft_printf/libftprintf.a
KEY =

COMP =			gcc -g $(KEY) -I include -I ft_printf/includes -c -o

OBJ_DIR =		obj/

ASM_DIR =	        src/
DIS_ASM_DIR =	    vis/

ASM_SRC =   main.c \
			alg.c \
			alg2.c \
			alg3.c \
			gnl.c \
			parse_fl.c \
			

DIS_ASM_SRC =       gnl2.c \
					cyrcle.c \
					help.c \
					help2.c \
					main_vis.c \
					vis_s.c \

ASM_OBJ =		    $(ASM_SRC:%.c=%.o)
DIS_ASM_OBJ =		$(DIS_ASM_SRC:%.c=%.o)

OBJ =			    $(ASM_OBJ) $(DIS_ASM_OBJ)

SRC_PATH_ASM =     $(ASM_SRC:%=$(ASM_DIR)%)
SRC_PATH_DIS_ASM = $(DIS_ASM_SRC:%=$(DIS_ASM_DIR)%)

SRC_PATH =		   $(SRC_PATH_ASM) $(SRC_PATH_DIS_ASM)

OBJ_PATH_ASM =	    $(addprefix $(OBJ_DIR), $(ASM_OBJ))
OBJ_PATH_DIS_ASM =	$(addprefix $(OBJ_DIR), $(DIS_ASM_OBJ))

OBJ_PATH =		    $(OBJ_PATH_ASM) $(OBJ_PATH_DIS_ASM)

all:			color do_libft $(OBJ_DIR) $(NAME)
				@echo "\\n"DONE FILLER AND VIS"\\n"

$(OBJ_DIR):
				@mkdir -p $(OBJ_DIR)
				@echo Create: Object directory

$(NAME):        $(OBJ_PATH)
				@gcc $(KEY) $(OBJ_PATH_ASM) $(LIBFT_DIR_A) -o $(ASM) \
					-I include -I $(LIBFT)includes -lncurses
				@gcc -L ~/.brew/lib -lSDL2 -lSDL2_ttf -I include/ -I ft_printf/includes/ ft_printf/libftprintf.a $(OBJ_PATH_DIS_ASM) -o $(DIS_ASM)

$(OBJ_PATH_ASM):	        $(SRC_PATH_ASM)
							@$(MAKE) $(ASM_OBJ)

$(OBJ_PATH_DIS_ASM):	    $(SRC_PATH_DIS_ASM)
							@$(MAKE) $(DIS_ASM_OBJ)


$(ASM_OBJ):		        $(LIBFT_DIR_A)
						@echo Create: $(@:obj/%=%)"\x1b[1A\x1b[M"
						@$(COMP) $(OBJ_DIR)$@ $(ASM_DIR)$(@:%.o=%.c)

$(DIS_ASM_OBJ):		    $(LIBFT_DIR_A)
						@echo Create: $(@:obj/%=%)"\x1b[1A\x1b[M"
						@gcc -I ~/.brew/include/ -I include/ -I ft_printf/includes/ -c -o $(OBJ_DIR)$@ $(DIS_ASM_DIR)$(@:%.o=%.c)


do_libft:
				@make -C $(LIBFT)

color:.
				@echo "\x1b[36m""\x1b[1A\x1b[M"

clean:			color
				@/bin/rm -rf $(OBJ_DIR) $(FT_PRINTF_A) $(LIBFT_A)
				@make -C $(LIBFT) clean
				@echo Cleaned libft object files

fclean:			clean
				@/bin/rm -f $(NAME) $(FT_PRINTF_A) $(LIBFT_A)
				@make -C $(LIBFT) fclean
				@echo Cleaned $(NAME)

re: 			fclean all

.PHONY:			all clean flcean re color
