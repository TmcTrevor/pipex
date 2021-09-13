# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mokhames <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/08 13:09:39 by mokhames          #+#    #+#              #
#    Updated: 2021/09/08 13:09:41 by mokhames         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= pipex.a
PROG	= pipex

SRCS 	= srcs/pipex.c srcs/cmd_utils.c 
OBJS 	= ${SRCS:.c=.o}
MAIN	= srcs/pipex.c

SRCS_B	= srcs/pipex_bonus.c srcs/cmd_utils.c srcs/bonus_cmd_utils.c GNL/get_next_line.c
OBJS_B	= ${SRCS_B:.c=.o}
MAIN_B	= srcs/pipex_bonus.c

HEADER	= -I./includes/

CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror -g

.c.o:		%.o : %.c
					@gcc ${CFLAGS} ${HEADER} -c $< -o $(<:.c=.o)

$(NAME):	${OBJS}
					@echo "\033[33m----Compiling lib----"
					@make re -C ./libft
					@cp libft/libft.a ./$(NAME)
					@ar -rcs ${NAME} ${OBJS}
					@$(CC) $(NAME) ${MAIN} -o ${PROG}
					@echo "\033[32mPipex Compiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ\n"

all: 		${NAME}

bonus:		${OBJS_B}
					@echo "\033[33m----Compiling lib----"
					@make re -C ./libft
					@cp libft/libft.a ./$(NAME)
					@ar -rcs ${NAME} ${OBJS_B}
					@$(CC) $(NAME) ${MAIN_B} -o ${PROG}
					@echo "\033[32mPipex Compiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ\n"

clean:
					@make clean -C ./libft
					@rm -f ${OBJS} ${OBJS_B}

fclean: 	clean
					@make fclean -C ./libft
					@rm -f $(NAME)
					@rm -f ${PROG}
					@echo "\n\033[31mDeleting EVERYTHING! ⌐(ಠ۾ಠ)¬\n"

re:			fclean all

party:
					@printf "\033c"
					@echo "\n\033[35m♪┏(・o･)┛♪"
					@sleep 1
					@printf "\033c"
					@echo "\033[1;33m♪┗(・o･)┓♪"
					@sleep 1
					@printf "\033c"
					@echo "\n\033[36m♪┏(・o･)┛♪"
					@sleep 1
					@printf "\033c"
					@echo "\033[34m♪┗(・o･)┓♪\n"

.PHONY: all clean fclean re bonus party
