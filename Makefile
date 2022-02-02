.DEFAULT_GOAL	=	all

NAME			=	match_star

SRC_DIR			=	sources

SRC_FILES		=	main.c \
					ft_get_filename_list.c \
					ft_print_filename_list.c \
					ft_del_content.c \
					match_star.c \
					ft_is_dot_dir.c \
					ft_is_root_dir.c \
					ft_expand_star.c \
					ft_get_dir_list.c

OBJ_DIR			=	objects

OBJ_FILES		=	${addprefix ${OBJ_DIR}/,${SRC_FILES:.c=.o}}

LIB_DIR			=	libft
LIB				=	-L${LIB_DIR} -lft

HEADER_DIR		=	-I includes -I libft/inc

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror -g

MKD				=	mkdir -p ${@D}
RM				=	rm -rf

all: ${NAME}

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c
	${MKD}
	${CC} ${CFLAGS} ${HEADER_DIR} -c $< -o $@

${NAME}: ${OBJ_FILES}
	make all -C ${LIB_DIR}
	${CC} ${CFLAGS} ${OBJ_FILES} ${LIB} ${HEADER_DIR} -o ${NAME}

clean:
	${RM} ${OBJ_DIR}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY:	all clean fclean re