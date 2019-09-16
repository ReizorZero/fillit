NAME = fillit

SRC_DIR = ./src/

OBJ_DIR = ./obj/

INC_DIR = ./inc/

LIB_DIR = ./libft/

SRC = main.c validator.c tetremin.c map.c backtracking.c catch_error.c ft_arraydel.c ft_sqrt.c

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	make -C libft/ fclean && make -C libft/
	gcc $(FLAGS) $(OBJ) -o $(NAME) -L $(LIB_DIR) -lft

$(LIB):
	make -C $(LIB_DIR)

$(OBJ_DIR):
	mkdir obj

$(OBJ_DIR)%.o: %.c
	gcc -c $(FLAGS) $< -o $@ -I $(INC_DIR)

clean:
	make -C libft/ clean
	rm -rf $(OBJ_DIR)

fclean: clean	
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all

vpath %.c $(SRC_DIR)
