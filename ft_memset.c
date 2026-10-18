/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixrod <felixrod@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 13:28:25 by felixrod          #+#    #+#             */
/*   Updated: 2026/10/01 14:07:55 by felixrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

/*
** TEST DE ft_memset
** 1. Compilar libft:  make
** 2. Descomentar el main de abajo.
** 3. Compilar y correr test:
**    cc -Wall -Wextra -Werror ft_memset.c -L. -lft && ./a.out
**
** CASOS A PROBAR:
** - Happy path: 'x', n = 5, 'x', n = 10 (todo)
** - Edge cases: n = 0 (no toca nada), '\0', n = 3, 'B' + 256 (se trunca a 'B'),
**               -1 (byte 0xFF), int[4] a 0 con sizeof
*/

/*
static int	g_ko = 0;

// Rellena dos buffers iguales, uno con ft_memset y otro con memset,
// y compara el buffer entero (también lo que hay después de n)
static void	test(char *label, int c, size_t n)
{
	char	ft[10];
	char	libc[10];
	void	*ret;
	int		ok;

	memcpy(ft, "abcdefghi", 10);
	memcpy(libc, "abcdefghi", 10);
	ret = ft_memset(ft, c, n);
	memset(libc, c, n);
	ok = (ret == ft && memcmp(ft, libc, 10) == 0);
	printf("[%s] %-28s devuelve s: %s  buffer igual que memset: %s\n",
		ok ? "OK" : "KO", label, ret == ft ? "sí" : "NO",
		memcmp(ft, libc, 10) == 0 ? "sí" : "NO");
	if (!ok)
		g_ko++;
}

int	main(void)
{
	int		nums[4];
	int		expected[4];

	printf("--- happy path ---\n");
	test("'x', n = 5", 'x', 5);
	test("'x', n = 10 (todo)", 'x', 10);
	printf("--- edge cases ---\n");
	test("n = 0 (no toca nada)", 'x', 0);
	test("'\\0', n = 3", '\0', 3);
	test("'B' + 256 (se trunca a 'B')", 'B' + 256, 4);
	test("-1 (byte 0xFF)", -1, 4);
	memset(expected, 0, sizeof(expected));
	nums[0] = 1;
	nums[1] = 2;
	nums[2] = 3;
	nums[3] = 4;
	ft_memset(nums, 0, sizeof(nums));
	printf("[%s] int[4] a 0 con sizeof\n",
		memcmp(nums, expected, sizeof(nums)) == 0 ? "OK" : "KO");
	if (memcmp(nums, expected, sizeof(nums)) != 0)
		g_ko++;
	printf("\nft_memset: %d KO\n", g_ko);
	return (g_ko != 0);
}
*/
