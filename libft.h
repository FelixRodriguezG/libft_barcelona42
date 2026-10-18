/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixrod <felixrod@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 08:47:16 by felixrod          #+#    #+#             */
/*   Updated: 2026/10/01 10:09:07 by felixrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <ctype.h>    /* -> Clasificación y conversión de caracteres
                             (isalpha, isdigit, toupper, etc.) */
# include <limits.h>   /* -> Límites de tipos enteros estándar
                             (INT_MAX, INT_MIN, etc.) */
# include <stdbool.h>  /* -> Tipo booleano (bool, true, false) */
# include <stddef.h>   /* -> Define size_t y la macro NULL */
# include <stdint.h>   /* -> Tipos de entero con ancho fijo y límites
                             asociados (SIZE_MAX) */
# include <stdio.h>    /* -> Entrada/Salida estándar
                             (printf para depuración) */
# include <stdlib.h>   /* -> Gestión de memoria (malloc, free) y utilidades
                             como exit */
# include <string.h>   /* -> Funciones estándar de cadenas y memoria
                             (referencia/testing) */
# include <unistd.h>   /* -> Llamadas al sistema POSIX (write, read, etc.) */

/*
** =============================================================================
** 1. COMPROBACIÓN Y MANIPULACIÓN DE CARACTERES (<ctype.h>)
** =============================================================================
*/

int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);

/*
** =============================================================================
** 2. MANIPULACIÓN DE MEMORIA ESTRUCTURADA (<string.h>)
** =============================================================================
*/

void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);

/*
** =============================================================================
** 3. MANIPULACIÓN DE CADENAS DE CARACTERES (<string.h> / <bsd/string.h>)
** =============================================================================
*/

size_t			ft_strlen(const char *src);
size_t			ft_strlcpy(char *dst, const char *src, size_t siz);
size_t			ft_strlcat(char *dest, const char *src, size_t dsize);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strdup(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

/*
** =============================================================================
** 4. CONVERSIÓN DE DATOS (<stdlib.h>)
** =============================================================================
*/

int				ft_atoi(const char *nptr);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);

/*
** =============================================================================
** 4. RESERVAR MEMORIA DINAMICA
** =============================================================================
*/

void			*ft_calloc(size_t nmemb, size_t size);

/*
** =============================================================================
** 5. MANIPULACIÓN DE LISTAS
** =============================================================================
*/

/* ESTRUCTURA Y TYPE DEFINITION PARA LISTAS */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
unsigned int	ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

/*
** =============================================================================
** 6. MACROS CONSTANTES
** =============================================================================
*/

/*
** Tamaños por defecto para lectura de archivos (ej. get_next_line / I/O).
** Se protege con #ifndef para poder sobreescribirlo al compilar con -D.
*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

/*
** Secuencias de escape ANSI para dar formato y color a las salidas por consola.
*/
# ifndef COLOR_RESET
#  define COLOR_RESET	"\033[0m"	/* Restablece el color/estilo por defecto */
#  define COLOR_RED		"\033[31m"	/* Rojo (ej. mensajes de error o FAIL) */
#  define COLOR_GREEN	"\033[32m"	/* Verde (ej. mensajes de éxito o OK) */
#  define COLOR_YELLOW	"\033[33m"	/* Amarillo (ej. advertencias o WARNING) */
#  define COLOR_BLUE	"\033[34m"	/* Azul (ej. información o cabeceras) */
#  define COLOR_MAGENTA	"\033[35m"	/* Magenta / Púrpura */
#  define COLOR_CYAN	"\033[36m"	/* Cian / Azul claro */
# endif

#endif
