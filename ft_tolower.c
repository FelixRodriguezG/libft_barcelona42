/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixrod <felixrod@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 16:15:46 by felixrod          #+#    #+#             */
/*   Updated: 2026/10/01 16:17:11 by felixrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

/*
** TEST DE ft_tolower
** 1. Compilar libft:  make
** 2. Descomentar el main de abajo.
** 3. Compilar y correr test:
**    cc -Wall -Wextra -Werror ft_tolower.c -L. -lft && ./a.out
**
** CASOS A PROBAR:
** - Happy path: 'A', 'Z', 'M'
** - Edge cases: 'a' (ya minúscula), '5' (no es letra), 'A' - 1 ('@'),
**               'Z' + 1 ('['), EOF (-1), 0 ('\0'), 200 (byte > 127),
**               barrido -1..255 contra la libc
*/

/*
static int	g_ko = 0;

// Aquí sí importa el valor exacto
static void	test(char *label, int c)
{
	int	ft;
	int	libc;

	ft = ft_tolower(c);
	libc = tolower(c);
	printf("[%s] %-20s ft: %4d  libc: %4d\n",
		ft == libc ? "OK" : "KO", label, ft, libc);
	if (ft != libc)
		g_ko++;
}

static void	sweep(void)
{
	int	c;
	int	fails;

	fails = 0;
	c = -1;
	while (c <= 255)
	{
		if (ft_tolower(c) != tolower(c))
		{
			printf("     distinto en c = %d\n", c);
			fails++;
		}
		c++;
	}
	printf("[%s] barrido -1..255 contra tolower (%d diferencias)\n",
		fails == 0 ? "OK" : "KO", fails);
	if (fails)
		g_ko++;
}

int	main(void)
{
	printf("--- happy path ---\n");
	test("'A'", 'A');
	test("'Z'", 'Z');
	test("'M'", 'M');
	printf("--- edge cases ---\n");
	test("'a' (ya minúscula)", 'a');
	test("'5' (no es letra)", '5');
	test("'A' - 1 ('@')", 'A' - 1);
	test("'Z' + 1 ('[')", 'Z' + 1);
	test("EOF (-1)", EOF);
	test("0 ('\\0')", 0);
	test("200 (byte > 127)", 200);
	sweep();
	printf("\nft_tolower: %d KO\n", g_ko);
	return (g_ko != 0);
}
*/
