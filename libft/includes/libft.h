/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:16:44 by fsanches          #+#    #+#             */
/*   Updated: 2022/07/25 19:11:27 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 100
#endif

#ifndef OPEN_MAX
#define OPEN_MAX 100
#endif

typedef struct s_list
{
	void *content;
	struct s_list *next;
} t_list;

// Part 1 Functions
int ft_isalpha(int c);
int ft_isdigit(int c);
int ft_isalnum(int c);
int ft_isascii(int c);
int ft_isprint(int c);
size_t ft_strlen(const char *s);
void *ft_memset(void *s, int c, size_t n);
void ft_bzero(void *s, size_t n);
void *ft_memcpy(void *dst, const void *src, size_t n);
void *ft_memmove(void *dst, const void *src, size_t n);
size_t ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t ft_strlcat(char *dst, const char *src, size_t dstsize);
int ft_toupper(int c);
int ft_tolower(int c);
char *ft_strchr(const char *s, int c);
char *ft_strrchr(const char *s, int c);
int ft_strncmp(const char *s1, const char *s2, size_t n);
void *ft_memchr(const void *s, int c, size_t n);
int ft_memcmp(const void *s1, const void *s2, size_t n);
char *ft_strnstr(const char *big, const char *little, size_t len);
int ft_atoi(const char *str);
void *ft_calloc(size_t nelem, size_t elsize);
char *ft_strdup(const char *s);
int ft_strcmp(char *s1, char *s2);

// Part 2 Functions
char *ft_substr(char const *s, unsigned int start, size_t len);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strjoin_free(char *s1, char const *s2);
char *ft_strtrim(char const *s1, char const *set);
char **ft_split(char const *s, char c);
char *ft_itoa(int n);
char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
void ft_striteri(char *s, void (*f)(unsigned int, char *));
void ft_putchar_fd(char c, int fd);
void ft_putstr_fd(char *s, int fd);
void ft_putendl_fd(char *s, int fd);
void ft_putnbr_fd(int n, int fd);
char *ft_strndup(const char *s1, size_t n);

// Bonus Functions
t_list *ft_lstnew(void *content);
void ft_lstadd_front(t_list **lst, t_list *new);
int ft_lstsize(t_list *lst);
t_list *ft_lstlast(t_list *lst);
void ft_lstadd_back(t_list **lst, t_list *new);
void ft_lstdelone(t_list *lst, void (*del)(void *));
void ft_lstclear(t_list **lst, void (*del)(void *));
void ft_lstiter(t_list *lst, void (*f)(void *));
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// PrintF
int ft_printf(const char *received_str, ...);
int scan_string(const char flag, va_list args);
// print utils
int len_putnum(int num);
int len_puthex(unsigned int num, int islower);
int len_putpointer(unsigned long int pointer);
int len_putchar(int c);
int len_putstr(char *s);
int len_putunsigned(unsigned int num);

char *ft_utoa(unsigned int num, char *str, int base);
char *ft_ultoa(unsigned long int num, char *str, int base);
char *ft_rev_string(char *string);

// get_next_line()
char *get_next_line(int fd);
ssize_t read_file(int fd, char **buffer, char **buff_read, char **line);
char *get_line(char **buff_read, char **line);

#endif