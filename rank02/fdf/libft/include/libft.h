/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bverdeci <bverdeci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:48:02 by bverdeci          #+#    #+#             */
/*   Updated: 2023/05/25 18:43:00 by bverdeci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

// includes
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stddef.h>
# include <fcntl.h>

/* -------- GET_NEXT_LINE -------- */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

char	*get_next_line(int fd);
int		ft_is_in_list(t_list *stock);
int		ft_count_from_list(t_list *stock);
void	ft_clearlst(t_list **stock);
void	ft_read_and_add(int fd, t_list **stock);
void	ft_add_link(t_list **stock, char *buff, int output);
char	*ft_add_from_list(t_list *stock, int len);
void	ft_update_stock(t_list **stock);

/* -------- FT_PRINTF -------- */
typedef struct s_data
{
	va_list	va;
	int		len;
	int		error;
}			t_data;

//definition of fonctions prototypes

int		ft_printf(const char *fmt, ...);
void	ft_putchar(int c, t_data *frame);
void	ft_putstr(char *s, t_data *frame);
void	ft_putnbr(int n, t_data *frame);
void	ft_putpointer(unsigned long int pointer, t_data *frame);
void	ft_hexa_min(unsigned int pointer, t_data *frame);
void	ft_hexa_maj(unsigned int pointer, t_data *frame);
void	ft_putunsigned(unsigned int n, t_data *frame);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
long	ft_atoil(const char *str);
int		ft_atoi_base(const char *str, const char *base);
char	*ft_strdup(const char *s1);
void	*ft_calloc(size_t count, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(char *content);
void	ft_lstadd_front(t_list **lst, t_list *new_el);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new_el);
#endif
