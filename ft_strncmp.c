/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixrod <felixrod@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 16:47:50 by felixrod          #+#    #+#             */
/*   Updated: 2026/10/08 09:59:57 by felixrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (n--)
	{
		if (*str1 != *str2 || !*str1)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (0);
}

/*
** TEST DE ft_strncmp
** 1. Compilar libft:  make
** 2. Descomentar el main de abajo.
** 3. Compilar y correr test:
**    cc -Wall -Wextra -Werror ft_strncmp.c -L. -lft && ./a.out
**
** CASOS A PROBAR:
** - Happy path: "hola" vs "hola", "hola" vs "hole", "hole" vs "hola"
** - Edge cases: diferencia más allá de n (n = 3), n = 0,
**               prefijo: "hol" vs "hola", prefijo: "hola" vs "hol", "" vs "",
**               "" vs "a", para en el \0 ("abc\0x" vs "abc\0y"),
**               unsigned: "\x80" vs "a", n = SIZE_MAX
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

	ft = sign(ft_strncmp(a, b, n));
	libc = sign(strncmp(a, b, n));
	printf("[%s] %-40s ft: %2d  libc: %2d\n",
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
	test("prefijo: \"hol\" vs \"hola\"", "hol", "hola", 10);
	test("prefijo: \"hola\" vs \"hol\"", "hola", "hol", 10);
	test("\"\" vs \"\"", "", "", 5);
	test("\"\" vs \"a\"", "", "a", 5);
	test("para en el \\0 (\"abc\\0x\" vs \"abc\\0y\")", "abc\0x", "abc\0y", 5);
	test("unsigned: \"\\x80\" vs \"a\"", "\x80", "a", 1);
	test("n = SIZE_MAX", "hola", "hole", SIZE_MAX);
	printf("\nft_strncmp: %d KO\n", g_ko);
	return (g_ko != 0);
}
*/
