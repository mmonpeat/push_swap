NAME	= libft.a

HEADER	= libft.h

INCLUDE = -I./

SRCS	= ft_isalpha.c ft_isdigit.c \
		ft_isalnum.c ft_isascii.c \
		ft_isprint.c ft_strlen.c \
		ft_memset.c ft_bzero.c \
		ft_memcpy.c ft_memmove.c \
		ft_strlcpy.c ft_strlcat.c \
		ft_toupper.c ft_tolower.c \
		ft_strchr.c ft_strrchr.c \
		ft_strncmp.c ft_memchr.c \
		ft_memcmp.c  ft_strnstr.c \
		ft_atoi.c \
		ft_strdup.c ft_calloc.c \
		ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c \
		ft_substr.c ft_strmapi.c \
		ft_striteri.c ft_itoa.c \
		ft_strjoin.c ft_strtrim.c \
		ft_split.c \

OBJS	= ${SRCS:.c=.o}

DEPS 	= $(addsuffix .d, $(basename ${OBJS}))

CC	= gcc

CFLAGS	= -Wall -Wextra -Werror

%.o : %.c Makefile
	@${CC} -MT $@ ${CFLAGS} -MMD -MP ${INCLUDE} -c $< -o $@

all:		${NAME}

${NAME}:	${OBJS}
	@ar src ${NAME} ${OBJS}

-include	${DEPS}

clean:
			@rm -rf ${OBJS} ${DEPS}

fclean:		clean
			@rm -rf ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
