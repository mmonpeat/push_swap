NAME = push_swap

HEADER = push_swap.h

INCLUDE = -I./ -I needs/libft -I needs/printf

SRCS = main.c push_swap.c scanner.c utils.c double_moves.c moves.c checker.c sort_small.c sort_big.c

RUTAS = needs/libft/libft.a needs/printf/libftprintf.a

OBJS = $(addprefix ${OBJ_DIR}/,$(SRCS:.c=.o))

DEPS = $(addsuffix .d,$(basename ${OBJS}))

CFLAGS = -Wall -Wextra -Werror -g

GREEN = \033[1;92m
RED = \033[1;91m
NC = \033[0m

OBJ_DIR = obj

${OBJ_DIR}/%.o : %.c Makefile
	@mkdir -p ${OBJ_DIR}
	@${CC} -MT $@ ${CFLAGS} -MMD -MP ${INCLUDE} -c $< -o $@

all:
	@${MAKE} -C needs/libft
	@${MAKE} -C needs/printf
	@${MAKE} ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} ${RUTAS} -o ${NAME}
	@echo "$(GREEN)push_swap compiled$(NC)"

-include ${DEPS}

clean:
	@${MAKE} -s clean -C needs/libft
	@${MAKE} -s clean -C needs/printf
	@rm -rf ${OBJ_DIR}
	@echo "$(RED)\nDestruction successful\n$(NC)"

fclean: clean
	@${MAKE} -s fclean -C needs/libft
	@${MAKE} -s fclean -C needs/printf
	@rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re
