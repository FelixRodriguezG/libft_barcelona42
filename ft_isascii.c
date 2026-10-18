/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixrod <felixrod@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 12:25:56 by felixrod          #+#    #+#             */
/*   Updated: 2026/10/01 12:31:43 by felixrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
/*
** TEST DE ft_isascii
** 1. Compilar libft:  make
** 2. Descomentar el main de abajo.
** 3. Compilar y correr test:
**    cc -Wall -Wextra -Werror ft_isascii.c -L. -lft && ./a.out
**
** CASOS A PROBAR:
** - Happy path: 'a', ' '
** - Edge cases: 0, 127, -1, 128, 255, INT_MIN, INT_MAX,
**               barrido -1..255 contra la libc
*/

/* ------------------------------------------------> Borrar para testear <------
static int	g_ko = 0;

// El subject exige 1 o 0 exactos; la libc devuelve 1024, 2048... (0 / no 0)
static void	test(char *label, int c)
{
	int	ft;
	int	libc;

	ft = ft_isascii(c);
	libc = (isascii(c) != 0);
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
		if (ft_isascii(c) != (isascii(c) != 0))
		{
			printf("     distinto en c = %d\n", c);
			fails++;
		}
		c++;
	}
	printf("[%s] barrido -1..255 contra isascii (%d diferencias)\n",
		fails == 0 ? "OK" : "KO", fails);
	if (fails)
		g_ko++;
}

int	main(void)
{
	printf("--- happy path ---\n");
	test("'a'", 'a');
	test("' '", ' ');
	printf("--- edge cases ---\n");
	test("0", 0);
	test("127", 127);
	test("-1", -1);
	test("128", 128);
	test("255", 255);
	test("INT_MIN", INT_MIN);
	test("INT_MAX", INT_MAX);
	sweep();
	printf("\nft_isascii: %d KO\n", g_ko);
	return (g_ko != 0);
}
*/
