/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanglade <hanglade@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:35:30 by hanglade          #+#    #+#             */
/*   Updated: 2023/11/09 14:35:30 by hanglade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <stdarg.h>

/**********file**********/
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
/**********gnl**********/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef MAX_FD
#  define MAX_FD 10
# endif

typedef struct s_fd
{
	int		fd;
	char	buffer[BUFFER_SIZE + 1];
}	t_fd;

char	*ft_strdup(const char *str);
size_t	gnl_ft_strlen(char *s);
char	*get_next_line(int fd);
char	*str_init(char *s);
char	*init_buffer(int fd, t_fd *buffer_memory);
/**********memory**********/
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
/**********nbr**********/
int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);
long	ft_atol(const char *s);
/**********str**********/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *s1, const char *s2, size_t len);
char	*ft_strdup(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_toupper(int c);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
int		ft_strcmp(char *s1, char *s2);
char	*ft_strcat(char *dest, const char *src);

/**********Others**********/
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_isspace(char c);

/**list**/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstlast(t_list *lst);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstadd_back(t_list **alst, t_list *new);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **alst, t_list *new);
int		ft_lstsize(t_list *lst);
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/**ft_Printf**/
void	ft_putstr_pf(char *s, size_t *count_char);
void	ft_putchar_pf(char c, size_t *count_char);
void	ft_putnbr_pf(int nbr, size_t *count_char);
void	print_ptr_addr(void *ptr, size_t *count_char);
void	ft_puthexa_upper(unsigned int nbr, size_t *count_char);
void	ft_puthexa_lower(unsigned int nbr, size_t *count_char);
void	ft_putnbr_unsigned(unsigned int nbr, size_t *count_char);
int		ft_printf(const char *str, ...);

#endif
