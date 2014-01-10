##
## Makefile for w3d in /home/sebastien/travaux/Wolf3d
## 
## Made by Sebastien Chapuis
## Login   <sebastien@epitech.net>
## 
## Started on  Sun Dec 22 12:34:46 2013 Sebastien Chapuis
## Last update Fri Jan 10 23:12:36 2014 sebastien
##

SRC	= main.c \
	  print_line.c \
	  events.c \
	  get_next_line.c \
	  map.c \
	  list_linked.c \
	  find_wall.c \
	  event_key.c \
	  move_head.c \
	  keyboard.c \
	  utils.c

NAME	= wolf3d

CFLAGS  = -L/usr/lib64 -lmlx_$(HOSTTYPE) -L/usr/lib64/X11 -lXext -lX11 -I /usr/include/X11/ -lm

OBJ	= $(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	@echo -e "\033[32m[build]" | tr -d '\n'
	gcc $(OBJ) -o $(NAME) $(CFLAGS)
	@echo -e "\033[0m" | tr -d '\n'

clean:
	@echo -e "\033[31m[clean] " | tr -d '\n'
	rm -f $(OBJ)
	@echo -e "\033[0m" | tr -d '\n'

fclean:	clean
	@echo -e "\033[31m[fclean] " | tr -d '\n'
	rm -f $(NAME)
	@echo -e "\033[0m" | tr -d '\n'

re:	fclean all
