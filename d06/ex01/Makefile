# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vzhao <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/02 22:24:07 by vzhao             #+#    #+#              #
#    Updated: 2019/12/12 11:19:40 by vzhao            ###   ########.fr        #
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
	./$(NAME) hotspots1.txt
	./$(NAME) hotspots2.txt
	@echo "-----------------------------------------------"

norm:
	$(NORM) 

.PHONY: clean test norm all
