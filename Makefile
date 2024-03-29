CC=cc
CFLAGS=-Wall -Wextra -Werror
NAME=so_long
NAMEB=so_long_b


OBJ=so_long.o \
	read_map.o \
	check_extenstion.o \
	get_next_line/get_next_line.o \
	get_next_line/get_next_line_utils.o \
	handle_map/is_5_comp.o \
	handle_map/is_ECP_exist.o \
	handle_map/is_rectangular.o \
	handle_map/is_closed_by_walls.o \
	handle_map/is_only_one_ep.o \
	handle_map/is_there_newline.o \
	helped_functions/put_allimg_to_wind.o \
	helped_functions/collect_size.o \
	helped_functions/get_cord_player.o \
	helped_functions/fill_image_addr.o \
	helped_functions/free_mlx_res.o \
	helped_functions/flood_fil.o \
	helped_functions/check_path.o \
	helped_functions/free_splited_elements.o \
	handle_norm/init_struct_var.o \
	handle_norm/map_errors.o \
	handle_norm/path_flood_fil.o \
	handle_norm/hooks_and_free.o \
	handle_norm/top_down_event.o \
	handle_norm/right_left_event.o \

OBJS=bonus_part/so_long_bonus.o \
	read_map.o \
	check_extenstion.o \
	get_next_line/get_next_line.o \
	get_next_line/get_next_line_utils.o \
	handle_map/is_5_comp_bonus.o \
	handle_map/is_ECP_exist.o \
	handle_map/is_rectangular.o \
	handle_map/is_closed_by_walls.o \
	handle_map/is_only_one_ep.o \
	handle_map/is_there_newline.o \
	helped_functions/put_allimg_to_wind.o \
	helped_functions/collect_size.o \
	helped_functions/get_cord_player.o \
	helped_functions/fill_image_addr.o \
	helped_functions/free_mlx_res.o \
	helped_functions/flood_fil.o \
	helped_functions/check_path.o \
	helped_functions/free_splited_elements.o \
	helped_functions/anime1.o \
	handle_norm/init_struct_var.o \
	handle_norm/map_errors_bonus.o \
	handle_norm/path_flood_fil.o \
	handle_norm/hooks_and_free.o \
	handle_norm/top_down_event.o \
	handle_norm/right_left_event.o \

all:$(NAME)

$(NAME):$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) ft_printf/libftprintf.a libft/libft.a -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -o $(NAME)

bonus: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) ft_printf/libftprintf.a libft/libft.a -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -o $(NAMEB)

clean:
	rm -f $(OBJ) $(OBJS)

fclean:
	rm -f $(NAME) $(NAMEB) $(OBJ) $(OBJS)

re:fclean all
