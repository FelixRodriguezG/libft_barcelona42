/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixrod <felixrod@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 13:18:05 by felixrod          #+#    #+#             */
/*   Updated: 2026/10/01 14:09:46 by felixrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

/*
** TEST DE ft_strlen
** 1. Compilar libft:  make
** 2. Descomentar el main de abajo.
** 3. Compilar y correr test:
**    cc -Wall -Wextra -Werror ft_strlen.c -L. -lft && ./a.out
**
** CASOS A PROBAR:
** - Happy path: "hola", "hola mundo"
** - Edge cases: "" (vacía), "a" (un carácter), "ab\0cd" (para en el \0),
**               "\xe9t\xe9" (bytes > 127), 1000 'x'
*/

/*
static int	g_ko = 0;

static void	test(char *label, const char *s)
{
	size_t	ft;
	size_t	libc;

	ft = ft_strlen(s);
	libc = strlen(s);
	printf("[%s] %-26s ft: %zu  libc: %zu\n",
		ft == libc ? "OK" : "KO", label, ft, libc);
	if (ft != libc)
		g_ko++;
}

int	main(void)
{
	char	long_str[1001];

	memset(long_str, 'x', 1000);
	long_str[1000] = '\0';
	printf("--- happy path ---\n");
	test("\"hola\"", "hola");
	test("\"hola mundo\"", "hola mundo");
	printf("--- edge cases ---\n");
	test("\"\" (vacía)", "");
	test("\"a\" (un carácter)", "a");
	test("\"ab\\0cd\" (para en el \\0)", "ab\0cd");
	test("\"\\xe9t\\xe9\" (bytes > 127)", "\xe9t\xe9");
	test("1000 'x'", long_str);
	printf("\nft_strlen: %d KO\n", g_ko);
	return (g_ko != 0);
}
*/
