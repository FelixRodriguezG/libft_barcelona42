/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixrod <felixrod@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 21:36:41 by felixrod          #+#    #+#             */
/*   Updated: 2026/10/09 18:23:22 by felixrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Compara los primeros 'n' bytes de las zonas de memoria 's1' y 's2'.
** Tratando cada byte como un 'unsigned char', evalúa byte a byte de
** izquierda a derecha.
**
** Retorna:
** - Un entero menor, igual o mayor que cero si 's1' es, respectivamente,
**   menor, igual o mayor que 's2'.
** - Cero (0) si los primeros 'n' bytes son idénticos o si 'n' es igual a 0.
*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*src1;
	unsigned char	*src2;

	if (n == 0)
		return (0);
	src1 = (unsigned char *)s1;
	src2 = (unsigned char *)s2;
	while (n--)
	{
		if (*src1 != *src2)
			return (*src1 - *src2);
		src1++;
		src2++;
	}
	return (0);
}

/*
** TEST DE ft_memcmp
** 1. Compilar libft:  make
** 2. Descomentar el main de abajo.
** 3. Compilar y correr test:
**    cc -Wall -Wextra -Werror ft_memcmp.c -L. -lft && ./a.out
**
** CASOS A PROBAR:
** - Happy path: "hola" vs "hola", "hola" vs "hole", "hole" vs "hola"
** - Edge cases: diferencia más allá de n (n = 3), n = 0,
**               sigue tras el \0 ("a\0b" vs "a\0c"),
**               unsigned: "\x80" vs "\x01", unsigned: "\xff" vs "\0"
*/

/*
static int	g_ko = 0;

static int	sign(int n)
{
	return ((n > 0) - (n < 0));
}

// Solo importa el signo (-1, 0, 1), no el valor exacto
static void	test(char *label, const char *a, const char *b, size_t n)
{
	int	ft;
	int	libc;

	ft = sign(ft_memcmp(a, b, n));
	libc = sign(memcmp(a, b, n));
	printf("[%s] %-38s ft: %2d  libc: %2d\n",
		ft == libc ? "OK" : "KO", label, ft, libc);
	if (ft != libc)
		g_ko++;
}

int	main(void)
{
	printf("--- happy path ---\n");
	test("\"hola\" vs \"hola\"", "hola", "hola", 4);
	test("\"hola\" vs \"hole\"", "hola", "hole", 4);
	test("\"hole\" vs \"hola\"", "hole", "hola", 4);
	printf("--- edge cases ---\n");
	test("diferencia más allá de n (n = 3)", "hola", "hole", 3);
	test("n = 0", "abc", "xyz", 0);
	test("sigue tras el \\0 (\"a\\0b\" vs \"a\\0c\")", "a\0b", "a\0c", 3);
	test("unsigned: \"\\x80\" vs \"\\x01\"", "\x80", "\x01", 1);
	test("unsigned: \"\\xff\" vs \"\\0\"", "\xff", "\0", 1);
	printf("\nft_memcmp: %d KO\n", g_ko);
	return (g_ko != 0);
}
*/
