# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/15 21:44:11 by dde-fite          #+#    #+#              #
#    Updated: 2025/10/29 17:09:55 by dde-fite         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# *                      LIBFT-TESTER by daviddefitero                       * #
# **************************************************************************** #

# ******************************** VARIABLES  ******************************** #
# FILES
NAME		= libft_tester
LIBFT_PATH	= ../
# LIBFT_PATH	= ../42_libft
SRC			:= $(wildcard *.c libc/*.c)
DIST		= ./dist_libft

# GCC COMPILER
CC			= cc
CFLAGS		= -o ${NAME} -Wall -Wextra -Werror -lbsd

# OTHER COMMANDS
RM			= rm
CP			= cp
MKDIR			= mkdir

# COLORS
GREEN		:= \033[1;32m
BLUE		:= \033[1;34m
YELLOW		:= \033[1;33m
PURPLE		:= \033[1;35m
CYAN		:= \033[1;36m
RED			:= \033[1;31m
RESET		:= \033[0m

# ********************************** RULES  ********************************** #
${NAME}: ${SRC} ${DIST} clean
	@echo -e "${PURPLE}╔═════════════════════════════════════════════════════════════════════════╗"
	@echo "║                              LIBFT TESTER                               ║"
	@echo "║                     by daviddefitero — 42 Madrid                        ║"
	@echo -e "╚═════════════════════════════════════════════════════════════════════════╝${RESET}"
	@echo "Cloning YOUR libft ..."
	@echo ""
	@${CP} -rf ${LIBFT_PATH}/* ${DIST}
	@echo "Running YOUR Makefile (fclean, all) ..."
	@echo -e "${GREEN}"
	@${MAKE} -C ${DIST} fclean all
	@echo -e "${RESET}Compiling tester ..."
	@echo ""
	@${CC} ${CFLAGS} ${SRC} ${DIST}/libft.a
	@echo "Process completed :)"
	@echo ""

${DIST}:
	@echo "Creating the dist folder"
	@${MKDIR} -p ${DIST}

all: ${NAME}

clean:
	@echo "Cleaning temporary files ..."
	@echo ""
	@${RM} -f libft.a libft.h
	@${RM} -rf ${DIST}/*

fclean: clean
	@echo "Deleting binary file (${NAME}) ..."
	@echo ""
	@${RM} -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
