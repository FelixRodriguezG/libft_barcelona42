/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixrod <felixrod@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 08:32:41 by felixrod          #+#    #+#             */
/*   Updated: 2026/10/01 08:34:19 by felixrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
/*
** TEST DE ft_isdigit
** 1. Compilar libft:  make
** 2. Descomentar el main de abajo.
** 3. Compilar y correr test:
**    cc -Wall -Wextra -Werror ft_isdigit.c -L. -lft && ./a.out
**
** CASOS A PROBAR:
** - Happy path: '0', '7', 'a', ' '
** - Edge cases: '0' - 1 ('/'), '9' + 1 (':'), '9', EOF (-1), 0 ('\0'),
**               200 (byte > 127), barrido -1..255 contra la libc
*/

/*
static int	g_ko = 0;

// El subject exige 1 o 0 exactos; la libc devuelve 1024, 2048... (0 / no 0)
static void	test(char *label, int c)
{
	int	ft;
	int	libc;

	ft = ft_isdigit(c);
	libc = (isdigit(c) != 0);
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
		if (ft_isdigit(c) != (isdigit(c) != 0))
		{
			printf("     distinto en c = %d\n", c);
			fails++;
		}
		c++;
	}
	printf("[%s] barrido -1..255 contra isdigit (%d diferencias)\n",
		fails == 0 ? "OK" : "KO", fails);
	if (fails)
		g_ko++;
}

int	main(void)
{
	printf("--- happy path ---\n");
	test("'0'", '0');
	test("'7'", '7');
	test("'a'", 'a');
	test("' '", ' ');
	printf("--- edge cases ---\n");
	test("'0' - 1 ('/')", '0' - 1);
	test("'9' + 1 (':')", '9' + 1);
	test("'9'", '9');
	test("EOF (-1)", EOF);
	test("0 ('\\0')", 0);
	test("200 (byte > 127)", 200);
	sweep();
	printf("\nft_isdigit: %d KO\n", g_ko);
	return (g_ko != 0);
}
*/
