# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aamajane <aamajane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/05 19:45:53 by aamajane          #+#    #+#              #
#    Updated: 2022/08/23 18:20:41 by aamajane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_M	=	push_swap

NAME_B	=	checker

LIBPS_M	=	srcs/libps_m.a

LIBPS_B	=	srcs/libps_b.a

LIBFT	=	libft/libft.a

SRCS_M	=	srcs/midpoint_sort.c \
			srcs/creat_stack.c \
			srcs/check_error.c \
			srcs/rev_rotate.c \
			srcs/push_swap.c \
			srcs/hard_sort.c \
			srcs/utils_1.c \
			srcs/utils_2.c \
			srcs/rotate.c \
			srcs/swap.c \
			srcs/push.c

OBJS_M	=	$(SRCS_M:.c=.o)

SRCS_B	=	srcs/creat_stack.c \
			srcs/check_error.c \
			srcs/rev_rotate.c \
			srcs/checker.c \
			srcs/utils_1.c \
			srcs/rotate.c \
			srcs/swap.c \
			srcs/push.c

OBJS_B	=	$(SRCS_B:.c=.o)

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

LIB		=	ar -rcs

RM		=	rm -rf


all:		$(NAME_M)

bonus:		$(NAME_B)

$(NAME_M):	$(LIBPS_M) $(LIBFT)
			@$(CC) $(CFLAGS) $(LIBPS_M) $(LIBFT) -o $(NAME_M)

$(NAME_B):	$(LIBPS_B) $(LIBFT)
			@$(CC) $(CFLAGS) $(LIBPS_B) $(LIBFT) -o $(NAME_B)

$(LIBPS_M):	$(OBJS_M)
			@$(LIB) $(LIBPS_M) $(OBJS_M)

$(LIBPS_B):	$(OBJS_B)
			@$(LIB) $(LIBPS_B) $(OBJS_B)

$(LIBFT):
			@cd libft && make

.c.o:
			@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
			@$(RM) $(OBJS_M) $(OBJS_B) $(LIBPS_M) $(LIBPS_B) $(LIBFT)
			@cd libft && make clean

fclean:		clean
			@$(RM) $(NAME_M) $(NAME_B)

re:			fclean all

.PHONY:		all bonus clean fclean re
