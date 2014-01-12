##
## Makefile for w3d in /home/sebastien/travaux/Wolf3d
## 
## Made by Sebastien Chapuis
## Login   <sebastien@epitech.net>
## 
## Started on  Sun Dec 22 12:34:46 2013 Sebastien Chapuis
## Last update Sun Jan 12 18:04:55 2014 sebastien
##

NAME	= wolf3d

SRC	= main.c \
	  print_line.c \
	  events.c \
	  get_next_line.c \
	  map.c \
	  list_map.c \
	  list_func.c \
	  find_wall.c \
	  event_key.c \
	  event_walk.c \
	  free_structs.c \
	  move_head.c \
	  utils.c \
	  check.c

OBJ	= $(SRC:.c=.o)

CFLAGS  = -L/usr/lib64 -lmlx_$(HOSTTYPE) -L/usr/lib64/X11 -lXext -lX11 -I /usr/include/X11/ -lm

CC	= gcc

RM	= rm -f


all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
