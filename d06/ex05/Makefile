# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vzhao <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/02 22:24:07 by vzhao             #+#    #+#              #
#    Updated: 2019/12/12 22:53:46 by vzhao            ###   ########.fr        #
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
	./$(NAME) 5 1 1
	./$(NAME) 5 2 1
	./$(NAME) 30 3 5
	@echo "-----------------------------------------------"

norm:
	$(NORM) 

.PHONY: clean test norm all
