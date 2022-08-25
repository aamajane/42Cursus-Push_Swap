# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aamajane <aamajane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/05 16:02:21 by aamajane          #+#    #+#              #
#    Updated: 2022/02/21 18:30:13 by aamajane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRCS	=	ft_atoi.c \
			ft_split.c \
			ft_strlen.c \
			ft_strlcpy.c \
			ft_strncmp.c \
			ft_putendl_fd.c \
			ft_lstnew_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstadd_front_bonus.c

OBJS	=	$(SRCS:.c=.o)

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

LIB		=	ar -rcs

RM		=	rm -f


all:		$(NAME)

$(NAME):	$(OBJS)
			@$(LIB) $(NAME) $(OBJS)

clean:
			@$(RM) $(OBJS) $(BONUS_O)

fclean:		clean
			@$(RM) $(NAME)

.c.o:
			@${CC} ${CFLGS} -c $< -o ${<:.c=.o}

re:			fclean all

.PHONY:		all bonus clean fclean re
