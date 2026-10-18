/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixrod <felixrod@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 14:16:00 by felixrod          #+#    #+#             */
/*   Updated: 2026/10/05 16:21:45 by felixrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	if (siz == 0)
		return (src_len);
	i = 0;
	while (src[i] && i < siz - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

/*
** TEST DE ft_strlcpy
** 1. Compilar libft:  make
** 2. Descomentar el main de abajo.
** 3. Compilar y correr test:
**    cc -Wall -Wextra -Werror ft_strlcpy.c -L. -lft && ./a.out
**
** CASOS A PROBAR:
** - Happy path: "hola", size = 10
** - Edge cases: cabe justo (size = 5), trunca (size = 3),
**               size = 1 (solo el \0), size = 0 (no escribe nada), src vacío
*/

/*
static int	g_ko = 0;

// dst empieza lleno de 'X' para ver qué bytes se han escrito
static void	test(char *label, const char *src, size_t size,
		const char *expected_dst, size_t expected_ret)
{
	char	dst[10];
	size_t	ret;
	int		ok;

	memset(dst, 'X', 9);
	dst[9] = '\0';
	ret = ft_strlcpy(dst, src, size);
	ok = (ret == expected_ret && strcmp(dst, expected_dst) == 0);
	printf("[%s] %-30s dst: \"%s\" (esperado \"%s\")"
		"  ret: %zu (esperado %zu)\n",
		ok ? "OK" : "KO", label, dst, expected_dst, ret, expected_ret);
	if (!ok)
		g_ko++;
}

int	main(void)
{
	printf("--- happy path ---\n");
	test("\"hola\", size = 10", "hola", 10, "hola", 4);
	printf("--- edge cases ---\n");
	test("cabe justo (size = 5)", "hola", 5, "hola", 4);
	test("trunca (size = 3)", "hola", 3, "ho", 4);
	test("size = 1 (solo el \\0)", "hola", 1, "", 4);
	test("size = 0 (no escribe nada)", "hola", 0, "XXXXXXXXX", 4);
	test("src vacío", "", 10, "", 0);
	printf("\nft_strlcpy: %d KO\n", g_ko);
	return (g_ko != 0);
}
*/
