/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixrod <felixrod@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 15:34:14 by felixrod          #+#    #+#             */
/*   Updated: 2026/10/01 15:59:47 by felixrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

/*
** TEST DE ft_memcpy
** 1. Compilar libft:  make
** 2. Descomentar el main de abajo.
** 3. Compilar y correr test:
**    cc -Wall -Wextra -Werror ft_memcpy.c -L. -lft && ./a.out
**
** CASOS A PROBAR:
** - Happy path: "hola", n = 4, "hola", n = 5 (con el \0)
** - Edge cases: n = 0 (no toca nada), copia a través del \0 ("a\0b\0c"),
**               no escribe más allá de n (n = 2),
**               src = NULL con n = 0 devuelve dst, int[3] con sizeof
*/

/*
static int	g_ko = 0;

static void	test(char *label, const char *src, size_t n)
{
	char	ft[10];
	char	libc[10];
	void	*ret;
	int		ok;

	memcpy(ft, "---------", 10);
	memcpy(libc, "---------", 10);
	ret = ft_memcpy(ft, src, n);
	memcpy(libc, src, n);
	ok = (ret == ft && memcmp(ft, libc, 10) == 0);
	printf("[%s] %-30s devuelve dst: %s  buffer igual que memcpy: %s\n",
		ok ? "OK" : "KO", label, ret == ft ? "sí" : "NO",
		memcmp(ft, libc, 10) == 0 ? "sí" : "NO");
	if (!ok)
		g_ko++;
}

int	main(void)
{
	char	dst[4];
	int		src_nums[3];
	int		dst_nums[3];

	printf("--- happy path ---\n");
	test("\"hola\", n = 4", "hola", 4);
	test("\"hola\", n = 5 (con el \\0)", "hola", 5);
	printf("--- edge cases ---\n");
	test("n = 0 (no toca nada)", "hola", 0);
	test("copia a través del \\0 (\"a\\0b\\0c\")", "a\0b\0c", 5);
	test("no escribe más allá de n (n = 2)", "hola", 2);
	printf("[%s] src = NULL con n = 0 devuelve dst\n",
		ft_memcpy(dst, NULL, 0) == dst ? "OK" : "KO");
	if (ft_memcpy(dst, NULL, 0) != dst)
		g_ko++;
	src_nums[0] = -1;
	src_nums[1] = 42;
	src_nums[2] = 2147483647;
	ft_memcpy(dst_nums, src_nums, sizeof(src_nums));
	printf("[%s] int[3] con sizeof\n",
		memcmp(dst_nums, src_nums, sizeof(src_nums)) == 0 ? "OK" : "KO");
	if (memcmp(dst_nums, src_nums, sizeof(src_nums)) != 0)
		g_ko++;
	printf("\nft_memcpy: %d KO\n", g_ko);
	return (g_ko != 0);
}
*/
