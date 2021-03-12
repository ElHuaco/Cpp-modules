# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/22 09:25:30 by aleon-ca          #+#    #+#              #
#    Updated: 2021/03/12 15:16:48 by alejandro        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.cpp

OBJS = $(SRCS:.cpp=.o)

NAME = serials.out

FLAGS = -Wall -Wextra -Werror
CLANG = clang++ $(FLAGS)

RM = rm -f

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CLANG) $(OBJS) -o $(NAME)

clean:		
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:			fclean all

test:		re
	./$(NAME) 
	./$(NAME) 
	./$(NAME) 
	./$(NAME) 
	./$(NAME) 

.PHONY:		all clean fclean re
