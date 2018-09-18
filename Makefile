SRC1	=	antia.c			\
			camera.c		\
			cartoon.c		\
			cone.c			\
			colour.c		\
			colour_code.c	\
			colour_math.c	\
			colour_math_2.c	\
			cylinder.c		\
			dithering.c		\
			draw.c			\
			effects.c		\
			hooks.c			\
			intersec.c 		\
			light.c

SRC2	=	main.c			\
			math.c			\
			map.c			\
			mvcam.c			\
			progress_text.c	\
			plane.c			\
			print_text.c	\
			rays.c 			\
			read_file.c		\
			read_file_2.c	\
			read_file_3.c	\
			reflection.c	\
			screen.c 		\
			shapes.c 		\
			sphere.c 		\
			solve_quad.c	\
			tracers.c 		\
			vector.c 		\
			vector_math.c	\
			vector_math_2.c	\
			vvector.c		\
			world_editor.c

SRC_PATH	=	src/

SRC		=	$(addprefix $(SRC_PATH), $(SRC1)) $(addprefix $(SRC_PATH), $(SRC2))

NORM1	=	$(addprefix $(SRC_PATH), $(SRC1))

NORM2	=	$(addprefix $(SRC_PATH), $(SRC2))

OBJS_PATH	=	./objs/

OBJ1	= $(SRC1:.c=.o)

OBJ2	= $(SRC2:.c=.o)

OBJS	=	$(addprefix $(OBJS_PATH), $(OBJ1)) $(addprefix $(OBJS_PATH), $(OBJ2))

LIB		=	./libft/libft.a

HEAD	=	-I./headers -I./libft

INC		=	./headers/main.h

FLAGS	=	-framework SDL2

SFLAGS	=	$(shell sdl2-config --cflags)

SFLAGSLIB =	$(shell sdl2-config --libs)

SLIB 	= -I /goinfre/wvon-gra/.brew/include/SDL2

WFLAGS	=	-lsdl2 -I ../SDL2/include

ERROR	=	-Werror -Wall -Wextra -Wuninitialized

NAME	= RT

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\033[0;32m------- COMPILLING ISH --------\033[0m"
	@if [ ! -f $(LIB) ]; then make -C ./libft; fi;
	@gcc $(ERROR) -o $(NAME) $(OBJS) -I ../SDL2/include -I./libft -I./headers ./libft/libft.a -framework SDL2

$(OBJS_PATH)%.o: $(SRC_PATH)%.c
	@echo "\033[0;32m------- COMPILLING $@ --------\033[0m"
	@mkdir -p $(OBJS_PATH)
	@gcc $(ERROR) -o $@ -c $< $(HEAD)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(OBJS_PATH)

re: fclean all

norm:
	@norminette $(NORM1)
	@norminette $(NORM2)



