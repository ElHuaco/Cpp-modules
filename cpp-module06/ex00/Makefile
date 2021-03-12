# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aleon-ca <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/22 09:25:30 by aleon-ca          #+#    #+#              #
#    Updated: 2021/03/12 19:34:57 by alejandro        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = convert.cpp

OBJS = $(SRCS:.cpp=.o)

NAME = convert.out

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
	./$(NAME) 42
	./$(NAME) -42
	./$(NAME) 0
	./$(NAME) 0.0f
	./$(NAME) 420.042f
	./$(NAME) -420.042f
	./$(NAME) inf
	./$(NAME) -inf
	./$(NAME) inff
	./$(NAME) -inff
	./$(NAME) nan
	./$(NAME) -nan
	./$(NAME) nanf
	./$(NAME) -nanf
	./$(NAME) 0.000000000000000000000000000000000000000000000000000000000000123455689090909
	./$(NAME) B
	./$(NAME) B0000B

.PHONY:		all clean fclean re
