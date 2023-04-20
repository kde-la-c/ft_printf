# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kde-la-c <kde-la-c@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/03 02:16:01 by kde-la-c          #+#    #+#              #
#    Updated: 2023/03/03 02:16:05 by kde-la-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
SRC			= ft_printf.c\
			src/ft_putchar_fd.c\
			src/ft_putnbr_fd.c\
			src/ft_putnbru_base_fd.c\
			src/ft_putnbrul_base_fd.c\
			src/ft_putstr_fd.c\
			src/ft_cmpchr.c\
			src/ft_strchr.c\
			src/ft_ischrrep.c\
			src/ft_strlen.c\

OBJS		= $(SRC:%.c=%.o)
INCLUDE		= ft_printf.h
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar
AFLAGS		= rc
RM			= rm
RFLAGS		= -f

all:		$(NAME)

$(NAME):	$(OBJS) $(INCLUDE)
			@$(AR) $(AFLAGS) $(NAME) $(OBJS) $(INCLUDE)
			@echo "\033[0;32m--- Printf compiled successfully! ---\033[0m"

clean:
			$(RM) $(RFLAGS) $(OBJS)
			@echo "\033[0;32m--- Objects cleaned successfully! ---\033[0m"

fclean:		clean
			$(RM) $(RFLAGS) $(NAME)
			@echo "\033[0;32m--- Archive cleaned successfully! ---\033[0m"

re:			fclean all

.PHONY:		all clean fclean re
