/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:23:53 by alvgomez          #+#    #+#             */
/*   Updated: 2023/01/10 19:13:30 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <ctype.h>
# include <stdarg.h>
# include <signal.h>

typedef struct s_stack
{
	int	val;
	int	pos;
	int	mov;
}				t_stack;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int				ft_atoi(const char *str);

void			ft_bzero(void *s, size_t n);

void			*ft_calloc(size_t nitems, size_t size);

int				ft_isalnum(int argument);

int				ft_isalpha(int argument);

int				ft_isascii(int argument);

int				ft_isdigit(int argument);

int				ft_isprint(int argument);

void			*ft_memchr(const void *s, int c, size_t n);

int				ft_memcmp(const void *str1, const void *str2, size_t n);

void			*ft_memcpy(void *dest, const void *src, size_t n);

void			*ft_memmove(void *dst, const void *src, size_t len);

void			*ft_memset(void *str, int c, size_t n);

char			*ft_strchr(const char *s, int c);

char			*ft_strdup(const char *s1);

size_t			ft_strlen(const char *s);

size_t			ft_strlcpy(char *dest, char *src, size_t size);

size_t			ft_strlcat(char *dst, const char *src, size_t size);

int				ft_strncmp(const char *s1, const char *s2, size_t n);

char			*ft_strnstr(const char *big, const char *little, size_t len);

char			*ft_strrchr(const char *s, int c);

int				ft_tolower(int c);

int				ft_toupper(int c);

char			**ft_split(char const *s, char c);

char			*ft_strjoin(char const *s1, char const *s2);

char			*ft_strtrim(char const *s1, char const *set);

char			*ft_substr(char const *s, unsigned int start, size_t len);

char			*ft_itoa(int n);

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void			ft_striteri(char *s, void (*f)(unsigned int, char*));

void			ft_putchar_fd(char c, int fd);

void			ft_putstr_fd(char *s, int fd);

void			ft_putendl_fd(char *s, int fd);

void			ft_putnbr_fd(int n, int fd);

t_list			*ft_lstnew(void *content);

void			ft_lstadd_front(t_list **lst, t_list *new);

int				ft_lstsize(t_list *lst);

t_list			*ft_lstlast(t_list *lst);

void			ft_lstadd_back(t_list **lst, t_list *new);

void			ft_lstdelone(t_list *lst, void (*del)(void *));

void			ft_lstclear(t_list **lst, void (*del)(void *));

void			ft_lstiter(t_list *lst, void (*f)(void *));

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

int				ft_printf(const char *arg, ...);

int				ft_putchar(int c);

int				ft_putnbr(int nb);

int				ft_putstr(char *str);

int				ft_hexadecimal(unsigned int nbr, char *base);

int				ft_unsigned_putnbr(unsigned int nb);

int				ft_void_hexadecimal(void *ptr);

t_stack			**create_stack(int n);

t_stack			**create_stack_to_zero(int n);

int				stack_len(t_stack **stack);

int				repeted(t_stack **stack, int pos);

void			find_positions(t_stack **stack, int len);

void			find_moves(t_stack **stack);

void			algorithm(t_stack **stack_1, t_stack **stack_2);

void			put_in_order_array(int *array, int len);

void			swap(t_stack **stack, char x);

void			push(t_stack **stack_1, t_stack **stack_2, char x);

void			reverse_rotate(t_stack **stack, char x);

void			rotate(t_stack **stack, char x);

void			swap_both(t_stack **stack_1, t_stack **stack_2);

void			rotate_both(t_stack **stack_1, t_stack **stack_2);

void			reverse_rotate_both(t_stack **stack_1, t_stack **stack_2);

void			print_stack(t_stack **stack, int number, char letter);

//void			find_moves(t_stack **stack);

int				is_it_in_order_1(t_stack **stack);

int				is_it_in_order_2(t_stack **stack);

int				find_lowest_pos(t_stack **stack);

int				find_highest_pos(t_stack **stack);

int				find_place_from_pos(t_stack **stack, int pos);

t_stack			**push_swap_split(char **argv);

void			there_is_an_error(void);

int				is_it_a_string(char *str);

int				which_move_3_options(t_stack **stack_1,
					t_stack **stack_2, int j);

void			move_place_to_the_top(t_stack **stack, int i, char x);

void			move_both_places_to_the_top(t_stack **stack_1,
					t_stack **stack_2, int i, int j);

int				how_many_moves_to_the_top_from_place(t_stack **stack, int i);

void			push_all_to_B_but_3_smallest_half_first(t_stack **stack_1,
					t_stack **stack_2);

void			aux_algorithm(t_stack **stack_1,
					t_stack **stack_2, int *move_i, int *move_j);

void			aux_main(t_stack **stack_1, char **argv, int argc);

void			resolve_stack_1_of_three(t_stack **stack_1);

void			resolve_stack_1_of_two(t_stack **stack_1);

void			push_all_to_b_but_3_smallest_half_first(t_stack **stack_1,
					t_stack **stack_2);

void			algorithm_stack_two_to_stack_one(t_stack **stack_1,
					t_stack **stack_2, int move_i, int move_j);

void			aux_algorithm(t_stack **stack_1,
					t_stack **stack_2, int *move_i, int *move_j);

void			aux_move_1(t_stack **stack_1,
					t_stack **stack_2, int value_1, int value_2);

void			aux_move_2(t_stack **stack_1,
					t_stack **stack_2, int value_1, int value_2);

void			aux_move_3(t_stack **stack_1,
					t_stack **stack_2, int value_1, int value_2);

void			aux_move_4(t_stack **stack_1,
					t_stack **stack_2, int value_1, int value_2);

#endif