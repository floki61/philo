NAME = philo
FLAGS = -Wall -Wextra -Werror -pthread

SRCS =	philosophers.c		\
		checker.c			\
		print.c 			\
		sonar.c 			\
		threads.c 			\
		tools.c				\
		
all : $(NAME)

$(NAME) : $(SRCS)
	@gcc $(FLAGS) $(SRCS) -o $(NAME)

clean :
	@rm -rf $(NAME)
fclean :
	@rm -rf $(NAME)

re: fclean all