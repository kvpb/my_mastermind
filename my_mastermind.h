/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbertin <kbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 13:02:21 by kbertin           #+#    #+#             */
/*   Updated: 2014/11/30 22:55:49 by kbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				ft_putchar(char c);
void				ft_putstr(char const *str);
size_t				ft_strlen(char *str);
char				*ft_strcpy(char *dest, char *src);
char				*ft_strncpy(char *dest, char *src, size_t n);
char				*ft_strdup(char *src);
int					ft_strcmp(char *s1, char *s2);
int					ft_strncmp(char *s1, char *s2, size_t n);
char				*ft_strcat(char *dest, char *src);
char				*ft_strncat(char *dest, char *src, int nb);
size_t				ft_strlcat(char *dest, char *src, size_t size);
char				*ft_strstr(char *str, char *to_find);
char				*ft_strnstr(char *str, char *to_find, size_t n);
char				*ft_strchr(char *str, char c);
char				*ft_strrchr(char *str, char c);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_atoi(char *str);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				*ft_memdup(const void *src, size_t size);
char				*ft_strrev(char *str);


#endif
