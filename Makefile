NAME = wolf3d
MINILIB_X = libraries/minilibx_macos/libmlx.a

FLAGS = -Wall -Wextra -Werror

SRC =	\
		srcs/wolf3d.c \
		srcs/distances.c \
		srcs/initialize_var.c \
		srcs/movement.c \
		srcs/hooks.c \
		srcs/images.c \
		srcs/maps.c \
		srcs/map_two.c
		
INPUT_OBJ =	\
		initialize_var.o \
		distances.o \
		wolf3d.o \
		movement.o \
		hooks.o \
		images.o \
		maps.o \
		map_two.o

OBJ = $(patsubst %.c,%.o,$(addprefix ./, $(SRC)))

all: $(NAME)

$(NAME): $(OBJ) includes/wolf3d.h
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