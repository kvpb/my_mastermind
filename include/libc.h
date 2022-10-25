/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbertin <kbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 13:02:21 by kbertin           #+#    #+#             */
/*   Updated: 2014/11/30 23:52:01 by kbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBC_H
# define LIBC_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

/*typedef struct		s_list
{
	void*			content;
	size_t			content_size;
	struct s_list*	next;
}					t_list;*/
// libft.pdf

/*void				ft_print_alphabet(void);
void				ft_print_reverse_alphabet(void);
void				ft_print_numbers(void);
void				ft_is_negative(int n);
void				ft_print_comb(void);
void				ft_print_comb2(void);
void				ft_putnbr(int nb);
void				ft_print_combn(int n);*/
// j02.pdf
/*void				ft_ft(int *nbr);
void				ft_ultimate_ft(int *********nbr);
void				ft_swap(int *a, int *b);
void				ft_div_mod(int a, int b, int *div, int *mod);
void				ft_ultimate_div_mod(int *a, int *b);
void				ft_putstr(char *str);
int					ft_strlen(char *str);
char*				ft_strrev(char *str);
int					ft_atoi(char *str);
void				ft_sort_integer_table(int *tab, int size);*/
// j03.pdf
/*int					ft_iterative_factorial(int nb);
int					ft_recursive_factorial(int nb);
int					ft_iterative_power(int nb, int power);
int					ft_recursive_power(int nb, int power);
int					ft_fibonacci(int index);
int					ft_sqrt(int nb);
int					ft_is_prime(int nb);
int					ft_find_next_prime(int nb);
int					ft_eight_queens_puzzle(void);
void				ft_eight_queens_puzzle_2(void);*/
// j04.pdf
/*void				ft_putstr(char *str);
void				ft_putnbr(int nb);
int					ft_atoi(char *str);
char*				ft_strcpy(char *dest, char *src);
char*				ft_strncpy(char *dest, char *src, unsigned int n);
char*				ft_strstr(char *str, char *to_find);
int					ft_strcmp(char *s1, char *s2);
int					ft_strncmp(char *s1, char *s2, unsigned int n);
char*				ft_strupcase(char *str);
char*				ft_strlowcase(char *str);
char*				ft_strcapitalize(char *str);
int					ft_str_is_alpha(char *str);
int					ft_str_is_numeric(char *str);
int					ft_str_is_lowercase(char *str);
int					ft_str_is_uppercase(char *str);
int					ft_str_is_printable(char *str);
char*				ft_strcat(char *dest, char *src);
char*				ft_strncat(char *dest, char *src, int nb);
unsigned int		ft_strlcat(char *dest, char *src, unsigned int size);
unsigned int		ft_strlcpy(char *dest, char *src, unsigned int size);
void				ft_putnbr_base(int nbr, char *base);
int					ft_atoi_base(char *str, char *base);
void				ft_putstr_non_printable(char *str);
void*				ft_print_memory(void *addr, unsigned int size);*/
// j05.pdf
/*void				ft_putchar(char c);
void				ft_swap(int *a, int *b);
void				ft_putstr(char *str);
int					ft_strlen(char *str);
int					ft_strcmp(char *s1, char *s2);*/
// j06.pdf
/*char*				ft_strdup(char *src);
int*				ft_range(int min, int max);
int					ft_ultimate_range(int **range, int min, int max);
char*				ft_concat_params(int argc, char **argv);
char**				ft_split_whitespaces(char *str);
void				ft_print_words_tables(char **tab);
char*				ft_convert_base(char *nbr, char *base_from, char *base_to);
char**				ft_split(char *str, char *charset);*/
// j07.pdf
/*char**				ft_split_whitespaces(char *str);
struct s_stock_par*	ft_param_to_tab(int ac, char **av);
void				ft_show_tab(struct s_stock_par *par);*/
// j08.pdf
/*void*				ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void*				ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
void*				ft_memccpy(void *restrict dst, const void *restrict src, int c, size_t n);
void*				ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char*				ft_strdup(const char *s1);
char*				ft_strcpy(char * dst, const char * src);
char*				ft_strncpy(char * dst, const char * src, size_t len);
char*				ft_strcat(char *restrict s1, const char *restrict s2);
char*				ft_strncat(char *restrict s1, const char *restrict s2, size_t n);
size_t				ft_strlcat(char * restrict dst, const char * restrict src, size_t dstsize);
char*				ft_strchr(const char *s, int c);
char*				ft_strrchr(const char *s, int c);
char*				ft_strstr(const char *haystack, const char *needle);
char*				ft_strnstr(const char *haystack, const char *needle, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void*				ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char*				ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char*				ft_strmap(char const *s, char (*f)(char));
char*				ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char*				ft_strsub(char const *s, unsigned int start, size_t len);
char*				ft_strjoin(char const *s1, char const *s2);
char*				ft_strtrim(char const *s);
char**				ft_strsplit(char const *s, char c);
char*				ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list*				ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list*				ft_lstmap(t_list *lst, t_list * (*f)(t_list *elem));
size_t				ft_strnlen(const char *s, size_t maxlen);
char*				ft_strndup(const char *s1, size_t n);
char*				ft_stpcpy(char * dst, const char * src);
char*				ft_stpncpy(char * dst, const char * src, size_t len);
size_t				ft_strlcpy(char * restrict dst, const char * restrict src, size_t dstsize);
char*				ft_strcasestr(const char *haystack, const char *needle);
char*				ft_strcasestr_l(const char *haystack, const char *needle, locale_t loc);
int					ft_atoi_l(const char *str, locale_t loc);
int					ft_isnumber(int c);
int					ft_toupper_l(int c, locale_t loc);
int					ft_tolower_l(int c, locale_t loc);*/
// libft.pdf
//int					strlen(char* s);
//char*				strrev(char* s);
//char*				strcpy(char* s_2, char* s);
//char*				strcat(char *s_2, char *s);
//int					strcmp(char* s_1, char* s_2);
//int					strncmp(const char* s_1, const char* s_2, size_t n);
//char*				itoa(int i);
char* i_to_a(int i);
char* ui_to_a(unsigned int i);

#endif
