# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vzhao <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/02 22:24:07 by vzhao             #+#    #+#              #
#    Updated: 2019/12/12 22:53:12 by vzhao            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = executable
INC = *.h
SRCS = *.c
FLAGS = -Wall -Werror -Wextra -I $(INC) $(SRCS)
NORM = norminette -R CheckForbiddenSourceHeader

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -o $(NAME)

clean:
	/bin/rm -f $(NAME)

re: clean all

test: re
	@echo "-----------------------------------------------"
	./$(NAME) 3 4 1
	./$(NAME) 3 4 5
	./$(NAME) 0 0 1
	./$(NAME) 1 2 10
	@echo "-----------------------------------------------"

norm:
	$(NORM) 

.PHONY: clean test norm all
