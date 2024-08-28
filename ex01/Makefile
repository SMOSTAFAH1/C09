# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shashemi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/28 09:41:55 by shashemi          #+#    #+#              #
#    Updated: 2024/08/28 09:41:56 by shashemi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME        = libft.a

CFLAGS      = -Wall -Wextra -Werror

SRC_DIR     = ./srcs/
INC_DIR     = ./includes/

SRCS        = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
OBJS        = $(addprefix $(SRC_DIR), $(SRCS:.c=.o))

AR          = ar -rcs
RM          = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $(OBJS)

$(SRC_DIR)%.o: $(SRC_DIR)%.c
	cc $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re