NAME := save_ppm

INCS_DIR := inc/
INCS := camera.h

SRCS_DIR := srcs/
SRCS := main.c \
	  	camera.c \
	  	utils.c \

OBJS_DIR = objs/
OBJS = $(SRCS:%.c=$(OBJS_DIR)%.o)

CC = gcc
CC_FLAGS = -Wextra -Werror -Wall
DEBUG_FLAGS = -fsanitize=address

all: $(NAME)

$(NAME): $(OBJS) 
	@$(CC) $(CC_FLAGS) $(DEBUG_FLAGS) $(OBJS) -o $@


$(OBJS): $(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(INCS_DIR)$(INCS)
	@mkdir -p $(@D)
	@$(CC) $(CC_FLAGS) $(DEBUG_FLAGS) -I$(INCS_DIR) -c $< -o $@

clean:
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
