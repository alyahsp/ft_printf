# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 14:17:48 by spalmaro          #+#    #+#              #
#    Updated: 2017/02/02 13:26:02 by spalmaro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIB_O = ft_memset.o ft_bzero.o ft_memcpy.o ft_memccpy.o ft_memmove.o       \
		ft_memchr.o ft_memcmp.o ft_strlen.o ft_strdup.o ft_strcpy.o           \
		ft_strncpy.o ft_strcat.o ft_strncat.o ft_strlcat.o ft_strchr.o        \
		ft_strrchr.o ft_strstr.o ft_strnstr.o ft_strcmp.o ft_strncmp.o        \
		ft_atoi.o ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o         \
		ft_isprint.o ft_toupper.o ft_tolower.o ft_memalloc.o ft_memdel.o      \
		ft_strnew.o ft_strdel.o ft_strclr.o ft_striter.o ft_striteri.o        \
		ft_strmap.o ft_strmapi.o ft_strequ.o ft_strnequ.o ft_strsub.o         \
		ft_strjoin.o ft_strtrim.o ft_strsplit.o ft_itoa.o ft_putchar.o        \
		ft_putstr.o ft_putendl.o ft_putnbr.o ft_putchar_fd.o ft_putstr_fd.o   \
		ft_putendl_fd.o ft_putnbr_fd.o ft_lstnew.o ft_lstdelone.o ft_lstdel.o \
		ft_lstadd.o ft_lstiter.o ft_lstmap.o ft_base_size.o ft_strtoupper.o \
		ft_strtolower.o ft_ulltoa_base.o ft_lltoa_base.o ft_itoa_base.o \
		ft_strndup.o bitlen.o ft_wcslen.o ft_putnchar.o

C_FILES = ft_printf.c ft_is.c format.c ft_add_lmod.c convertdioux.c \
			convertsp.c convertc.c convertls.c convertlc.c convertp.c\

LIB_PATH = -I ./libft/

HEADER_FLAG = -I ./includes/

SRC_PATH = ./src/

SRC_O = $(C_FILES:.c=.o)

LIB = ./libft/

CC = gcc

CFLAGS = -Wall -Wextra -Werror

.PHONY : all clean fclean re

all: $(NAME)

$(NAME):
	@make -C $(LIB)
	@$(CC) -c $(CFLAGS) $(addprefix $(SRC_PATH), $(C_FILES)) $(LIB_PATH) $(HEADER_FLAG)
	@ar rc $(NAME) $(SRC_O) $(addprefix $(LIB), $(LIB_O))
	@ranlib $(NAME)
	@echo "\t\033[33;32m'MAKE' ->\t\033[1;34m$(NAME)\033[0m :\tLibrary compilation completed sucessfully !"

clean:
	@make -C $(LIB) clean
	@rm -f $(SRC_O)

fclean: clean
	make -C $(LIB) fclean
	rm -f $(NAME)

re: fclean all
