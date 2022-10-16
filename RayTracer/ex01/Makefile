NAME 		:= intersect_Ray_Sphere

INCS_DIR 	:= inc/
INCS 		:= struct.h

SRCS_DIR 	:= srcs/
SRCS 		:=	main.c \
	  			intersect.c \

OBJS_DIR 	:= objs/
OBJS 		:= $(SRCS:%.c=$(OBJS_DIR)%.o)

CC 			:= gcc
CC_FLAGS 	:= -Wextra -Werror -Wall
DEBUG_FLAGS := -fsanitize=address

LIGHTPURPLE	:= $(shell tput -Txterm setaf 4)
RESET		:= $(shell tput -Txterm sgr0)

all: $(NAME)

$(NAME): $(OBJS) 
	@$(CC) $(CC_FLAGS) $(DEBUG_FLAGS) $(OBJS) -o $@
	@echo -e 'Done!'

$(OBJS): $(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(INCS_DIR)$(INCS)
	@mkdir -p $(@D)
	@echo "compiling: $<"
	@$(CC) $(CC_FLAGS) $(DEBUG_FLAGS) -I$(INCS_DIR) -c $< -o $@

clean:
	@echo -e 'objects files removed'
	@rm -rf $(OBJS_DIR)

fclean: clean
	@echo -e '$(NAME) removed'
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
