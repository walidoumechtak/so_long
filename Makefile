CC=cc
CFLAGS=-Wall -Wextra -Werror
NAME=so_long


OBJ=so_long.o \
	read_map.o \
	get_next_line/get_next_line.o \
	get_next_line/get_next_line_utils.o \
	handle_map/is_5_comp.o \
	handle_map/is_ECP_exist.o \
	handle_map/is_rectangular.o \

all:$(NAME)

$(NAME):$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) ft_printf/libftprintf.a libft/libft.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME) $(OBJ)

re:fclean all

git:
	git add . && git commit -m "go" && git push