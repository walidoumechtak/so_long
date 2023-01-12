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
	handle_map/is_closed_by_walls.o \
	handle_map/is_only_one_ep.o \
	helped_functions/put_allimg_to_wind.o \
	helped_functions/collect_size.o \
	helped_functions/get_cord_player.o \
	helped_functions/fill_image_addr.o \
	helped_functions/free_mlx_res.o \

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