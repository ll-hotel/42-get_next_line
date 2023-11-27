ODIR	:= .obj/
CC		:= cc
CFS		:= -Wall -Wextra -Werror

NAME	:= get_next_line.a

.PHONY: all clean fclean re

all: $(NAME)

$(ODIR):
	mkdir $@

$(NAME): $(ODIR) get_next_line.c get_next_line_utils.c get_next_line.h
	$(CC) $(CFS) -o $(ODIR)gnl.o -c get_next_line.c
	$(CC) $(CFS) -o $(ODIR)gnl_utils.o -c get_next_line_utils.c
	ld -r $(ODIR)gnl.o $(ODIR)gnl_utils.o -o $(ODIR)get_next_line.o
	ar -rc $(NAME) $(ODIR)get_next_line.o

clean:
	rm -rf $(ODIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
