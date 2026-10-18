/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixrod <felixrod@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 08:00:49 by felixrod          #+#    #+#             */
/*   Updated: 2026/10/01 08:31:24 by felixrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
/*
** TEST DE ft_isalpha
** 1. Compilar libft:  make
** 2. Descomentar el main de abajo.
** 3. Compilar y correr test:
**    cc -Wall -Wextra -Werror ft_isalpha.c -L. -lft && ./a.out
**
** CASOS A PROBAR:
** - Happy path: 'a', 'Z', '5', ' '
** - Edge cases: 'A' - 1 ('@'), 'Z' + 1 ('['), 'a' - 1 ('`'), 'z' + 1 ('{'),
**               EOF (-1), 0 ('\0'), 200 (byte > 127),
**               barrido -1..255 contra la libc
*/

/*
static int	g_ko = 0;

// El subject exige 1 o 0 exactos; la libc devuelve 1024, 2048... (0 / no 0)
static void	test(char *label, int c)
{
	int	ft;
	int	libc;

	ft = ft_isalpha(c);
	libc = (isalpha(c) != 0);
	printf("[%s] %-20s ft: %d  libc: %d\n",
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
		if (ft_isalpha(c) != (isalpha(c) != 0))
		{
			printf("     distinto en c = %d\n", c);
			fails++;
		}
		c++;
	}
	printf("[%s] barrido -1..255 contra isalpha (%d diferencias)\n",
		fails == 0 ? "OK" : "KO", fails);
	if (fails)
		g_ko++;
}

int	main(void)
{
	printf("--- happy path ---\n");
	test("'a'", 'a');
	test("'Z'", 'Z');
	test("'5'", '5');
	test("' '", ' ');
	printf("--- edge cases ---\n");
	test("'A' - 1 ('@')", 'A' - 1);
	test("'Z' + 1 ('[')", 'Z' + 1);
	test("'a' - 1 ('`')", 'a' - 1);
	test("'z' + 1 ('{')", 'z' + 1);
	test("EOF (-1)", EOF);
	test("0 ('\\0')", 0);
	test("200 (byte > 127)", 200);
	sweep();
	printf("\nft_isalpha: %d KO\n", g_ko);
	return (g_ko != 0);
}
*/
