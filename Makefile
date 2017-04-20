NAME = wolf3d
MINILIB_X = libraries/minilibx_macos/libmlx.a

FLAGS = -Wall -Wextra -Werror

SRC =	\
		wolf3d.c \
		initialize_var.c
		
INPUT_OBJ =	\
		initialize_var.o \
		wolf3d.o

OBJ = $(patsubst %.c,%.o,$(addprefix ./, $(SRC)))

all: $(NAME)

$(NAME): $(OBJ) wolf3d.h
	make -C libraries/libft/
	gcc $(FLAGS) -I libraries//libft -c $(SRC)
	gcc -o $(NAME) $(OBJ) -lm -L libraries/libft/ -lft $(MINILIB_X) -framework OpenGL -framework AppKit

clean:
	make -C libraries/libft/ clean
	/bin/rm -f $(OBJ)
	/bin/rm -f $(INPUT_OBJ)

fclean: clean
	make -C libraries/libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all
	
.PHONY: clean fclean