# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vzhao <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/02 22:24:07 by vzhao             #+#    #+#              #
#    Updated: 2019/12/12 11:04:39 by vzhao            ###   ########.fr        #
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
	./$(NAME) 5 10 15 20
	./$(NAME) 1 10 15 20
	./$(NAME) 10 10 15 20
	./$(NAME) 10000 `cat strip.txt`
	@echo "-----------------------------------------------"

norm:
	$(NORM) 

.PHONY: clean test norm all
