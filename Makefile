NAME_CLIENT = client
NAME_SERVER = server
LIBFT_DIR= ./lib/libft
LIBS	=  -L./lib/libft -lft
HEADERS	:= -I ./include

all:$(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT):
	@cd $(LIBFT_DIR) && make all
	@cc -Wall -Wextra -Werror src/client.c $(LIBS) $(HEADERS) -o $(NAME_CLIENT)
	@echo "client is done"
	
$(NAME_SERVER):
	@cc -Wall -Wextra -Werror src/server.c $(LIBS) $(HEADERS) -o $(NAME_SERVER)
	@echo "server is done"
clean:
	@cd $(LIBFT_DIR) && make clean
	@rm -f server
	@rm -f client
	@echo "all objects and executable files have been deleted"

fclean: clean
	@cd $(LIBFT_DIR) && make fclean
	@echo "all files have been deleted"

bonus: fclean
	@cd $(LIBFT_DIR) && make all
	@cc -Wall -Wextra -Werror src_bonus/client_bonus.c $(LIBS) $(HEADERS) -o $(NAME_CLIENT)
	@cc -Wall -Wextra -Werror src_bonus/server_bonus.c $(LIBS) $(HEADERS) -o $(NAME_SERVER)


re: fclean all

.PHONY: all clean fclean re 