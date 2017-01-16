# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/07 16:55:33 by mbarbari          #+#    #+#              #
#    Updated: 2017/01/06 14:30:06 by barbare          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC ?= gcc
CX ?= clang++
CFLAGS += -Wall -Wextra -Werror -Iinc/

PARSE_SRCS = 	src/foreach.c \
  				src/parse_function.c \
  				src/parse_type.c \
  				src/parser.c

PARSE_INCS = 	inc/parser.h \
  				inc/parser_union.h

COM_OBJS = $(patsubst src/%.c,obj/%.o,$(PARSE_SRCS))

RM ?= rm -f
MKDIR ?= mkdir

all: parse.a

print-% : ; $(info $* is $(flavor $*) variable set to [$($*)]) @true

parse.a: $(COM_OBJS)
	$(AR) -rcs $^ $?

obj/%.o: src/%.c $(PARSE_INCS)
	$(MKDIR) -p $(dir $@)
	$(CC) -c $(CFLAGS) $(INC) $< -o $@

clean:
	$(RM) $(COM_OBJS)

fclean: clean
	$(RM) cli
	$(RM) $(COM_OBJS)

re: fclean all

.PHONY: clean fclean re all
