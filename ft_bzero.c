/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixrod <felixrod@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 14:10:14 by felixrod          #+#    #+#             */
/*   Updated: 2026/10/01 14:22:41 by felixrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Rellena los primeros 'n' bytes del bloque de memoria apuntado por 's'
** con ceros ('\0').
**
** Se realiza un casteo a (unsigned char *) para permitir la aritmética de
** punteros byte a byte sobre el puntero genérico (void *).
*/
void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

/*
** TEST DE ft_bzero
** 1. Compilar libft:  make
** 2. Descomentar el main de abajo.
** 3. Compilar y correr test:
**    cc -Wall -Wextra -Werror ft_bzero.c -L. -lft && ./a.out
**
** CASOS A PROBAR:
** - Happy path: n = 5, n = 10 (todo)
** - Edge cases: n = 0 (no toca nada), sigue tras un '\0' ("ab\0defghi", 6),
**               no se pasa de n (n = 1), int[4] a 0 con sizeof
*/

/*
static int	g_ko = 0;

// Compara el buffer entero con el resultado de bzero de la libc
static void	test(char *label, const char *initial, size_t n)
{
	char	ft[10];
	char	libc[10];
	int		ok;

	memcpy(ft, initial, 10);
	memcpy(libc, initial, 10);
	ft_bzero(ft, n);
	bzero(libc, n);
	ok = (memcmp(ft, libc, 10) == 0);
	printf("[%s] %-34s buffer igual que bzero: %s\n",
		ok ? "OK" : "KO", label, ok ? "sí" : "NO");
	if (!ok)
		g_ko++;
}

int	main(void)
{
	int		nums[4];
	int		expected[4];

	printf("--- happy path ---\n");
	test("n = 5", "abcdefghi", 5);
	test("n = 10 (todo)", "abcdefghi", 10);
	printf("--- edge cases ---\n");
	test("n = 0 (no toca nada)", "abcdefghi", 0);
	test("sigue tras un '\\0' (\"ab\\0defghi\", 6)", "ab\0defghi", 6);
	test("no se pasa de n (n = 1)", "abcdefghi", 1);
	memset(expected, 0, sizeof(expected));
	nums[0] = 1;
	nums[1] = 2;
	nums[2] = 3;
	nums[3] = 4;
	ft_bzero(nums, sizeof(nums));
	printf("[%s] int[4] a 0 con sizeof\n",
		memcmp(nums, expected, sizeof(nums)) == 0 ? "OK" : "KO");
	if (memcmp(nums, expected, sizeof(nums)) != 0)
		g_ko++;
	printf("\nft_bzero: %d KO\n", g_ko);
	return (g_ko != 0);
}
*/
