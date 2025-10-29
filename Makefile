# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/15 21:44:11 by dde-fite          #+#    #+#              #
#    Updated: 2025/10/29 20:07:54 by dde-fite         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# *                         LIBFT-TESTER by dde-fite                         * #
# **************************************************************************** #

# ******************************** VARIABLES  ******************************** #
SHELL := /bin/bash

# FILES
NAME			= libft_tester
LIBFT_PATH		= ..
# LIBFT_PATH	= ../42_libft
SRC_FOLDER		= src
INCLUDE_FOLDER	= include
DIST_FOLDER		= dist_libft
BUILD_FOLDER	= build
SRC				:= $(shell find $(SRC_FOLDER) -type f -name "*.c")
SRC_FILES		:= $(patsubst $(SRC_FOLDER)/%, %, $(SRC))
OBJ				:= $(patsubst $(SRC_FOLDER)/%.c,$(BUILD_FOLDER)/%.o,$(SRC))
TOTAL			:= $(words $(SRC))

# GCC COMPILER
CC				= cc
# Delete -g
CFLAGS			= -Wall -Werror -Wextra -I$(INCLUDE_FOLDER) -I${DIST_FOLDER}

# COMMANDS
RM				= rm
MKDIR			= mkdir
CP				= cp

# COLORS
GREEN			:= \033[1;32m
BLUE			:= \033[1;34m
YELLOW			:= \033[1;33m
PURPLE			:= \033[1;35m
CYAN			:= \033[1;36m
RED				:= \033[1;31m
RESET			:= \033[0m

# BAR
BAR_LEN			:= 100

# ********************************** RULES  ********************************** #

${NAME}: clean ${SRC} ${DIST_FOLDER}/libft.a
	@echo -e "\n${PURPLE}"
	@echo "      dMP     dMP dMMMMb  dMMMMMP dMMMMMMP      dMMMMMMP dMMMMMP .dMMMb dMMMMMMP dMMMMMP dMMMMb "
	@echo "     dMP     amr dMP dMP dMP        dMP           dMP   dMP     dMP  VP   dMP   dMP     dMP dMP "
	@echo "    dMP     dMP dMMMMK  dMMMP      dMP           dMP   dMMMP    VMMMb    dMP   dMMMP   dMMMMK^  "
	@echo "   dMP     dMP dMP aMF dMP        dMP           dMP   dMP     dP  dMP   dMP   dMP     dMP AMF   "
	@echo "  dMMMMMP dMP dMMMMP  dMP        dMP           dMP   dMMMMMP  VMMMP^   dMP   dMMMMMP dMP dMP    "
	@echo -e "${RED}"
	@echo "                                    by dde-fite - 42 Madrid                                     "
	@echo -e "${RESET}\nCreating build folder if does not exist ...\n"
	@${MKDIR} -p ${BUILD_FOLDER}
	@${MKDIR} -p ${dir $(OBJ)}
	@echo -e "Compiling tester ...\n${YELLOW}"
	@count=0; \
	for file in ${SRC_FILES}; do \
		${CC} ${CFLAGS} -c -o ${BUILD_FOLDER}/$${file%.c}.o ${SRC_FOLDER}/$$file; \
		count=$$((count + 1)); \
		progress=$$((count * 100 / ${TOTAL})); \
		hashes_len=$$((progress * ${BAR_LEN} / 100)); \
		hashes=$$(printf '%0.s#' $$(seq 1 $$hashes_len)); \
		spaces_len=$$((BAR_LEN - hashes_len)); \
		spaces=$$(printf '%0.s ' $$(seq 1 $$spaces_len)); \
		printf "\r[%s%s] %d%%" "$$hashes" "$$spaces" "$$progress"; \
	done; \
	echo
	@echo -e "${RESET}\nLinking objects ...\n	"
	@$(CC) $(CFLAGS) $(OBJ) ${DIST_FOLDER}/libft.a -o $(NAME)
	@echo -e "${GREEN}Process completed :)${RESET}"
	@echo ""

${DIST_FOLDER}:
	@echo -e "Creating the DIST_FOLDER folder\n"
	@${MKDIR} -p ${DIST_FOLDER}
	@echo -e "Cloning YOUR libft ...\n"
	@rsync -av --exclude='$(notdir $(CURDIR))/' --exclude='.git/' ${LIBFT_PATH}/ ${DIST_FOLDER}/

${DIST_FOLDER}/libft.a: ${DIST_FOLDER}
	@echo -e "${GREEN}--------------LIBFT-COMPILATION---------------"
	@${MAKE} -C ${DIST_FOLDER} fclean all
	@echo -e "${GREEN}-----------END-OF-LIBFT-COMPILATION-----------${RESET}\n"

all: ${NAME}

clean:
	@echo "Deleting ${BUILD_FOLDER} and cloned libft(not the original) ..."
	@echo ""
	@${RM} -rf ${BUILD_FOLDER} ${DIST_FOLDER}

fclean: clean
	@echo "Deleting binary file (${NAME}) ..."
	@echo ""
	@${RM} -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
