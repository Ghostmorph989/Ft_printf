rm -rf ./a.out && make re && gcc -Wall -Werror -Wextra  ft_printf.c main.c -L. -lftprintf -lft && ./a.out && make fclean
