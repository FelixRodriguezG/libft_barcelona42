/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixrod <felixrod@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 21:00:39 by felixrod          #+#    #+#             */
/*   Updated: 2026/10/10 23:38:11 by felixrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	Reserva memoria (con malloc(3)) y devuelve una subcadena de caracteres
 *	de la cadena ‘s’.
 *	La subcadena comienza en el índice ‘start’ y tiene una longitud máxima
 *	‘len’.
 *	Si start >= ft_strlen(s): devuelve una cadena vacía reservada
 *	(ft_strdup("")), no NULL.
 *	Reserva solo lo necesario: min(len, ft_strlen(s) - start) + 1.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*sub_str;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	sub_str = (char *)malloc(sizeof(char) * (len +1));
	if (!sub_str)
		return (NULL);
	ft_strlcpy(sub_str, s + start, len + 1);
	return (sub_str);
}

/*
** TEST DE ft_substr
** 1. Compilar libft:  make
** 2. Descomentar el main de abajo.
** 3. Compilar y correr test:
**    cc -Wall -Wextra -Werror ft_substr.c -L. -lft && ./a.out
**    valgrind --leak-check=full ./a.out
**
** CASOS A PROBAR:
** - Happy path: ("hola mundo", 5, 5), ("hola mundo", 0, 4)
** - Edge cases: len más grande que lo que queda, start == strlen(s),
**               start fuera de la cadena, len = 0, s vacío,
**               len = SIZE_MAX (start + len desborda)
*/

/*
static int	g_ko = 0;

static void	test(char *label, const char *s, unsigned int start, size_t len,
		const char *expected)
{
	char	*ret;
	int		ok;

	ret = ft_substr(s, start, len);
	ok = (ret != NULL && strcmp(ret, expected) == 0);
	printf("[%s] %-34s ft: \"%s\"  esperado: \"%s\"\n",
		ok ? "OK" : "KO", label, ret ? ret : "(NULL)", expected);
	if (!ok)
		g_ko++;
	free(ret);
}

int	main(void)
{
	printf("--- happy path ---\n");
	test("(\"hola mundo\", 5, 5)", "hola mundo", 5, 5, "mundo");
	test("(\"hola mundo\", 0, 4)", "hola mundo", 0, 4, "hola");
	printf("--- edge cases ---\n");
	test("len más grande que lo que queda", "hola mundo", 5, 100, "mundo");
	test("start == strlen(s)", "hola", 4, 3, "");
	test("start fuera de la cadena", "hola", 100, 3, "");
	test("len = 0", "hola", 1, 0, "");
	test("s vacío", "", 0, 5, "");
	test("len = SIZE_MAX (start + len desborda)", "hola mundo", 5, SIZE_MAX,
		"mundo");
	printf("\nft_substr: %d KO (valgrind: la reserva debe ser la del resultado,"
		" no la de len)\n", g_ko);
	return (g_ko != 0);
}
*/
