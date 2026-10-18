/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixrod <felixrod@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 12:14:15 by felixrod          #+#    #+#             */
/*   Updated: 2026/10/14 12:16:09 by felixrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*
** TEST DE ft_putchar_fd
** 1. Compilar libft:  make
** 2. Descomentar el main de abajo.
** 3. Compilar y correr test:
**    cc -Wall -Wextra -Werror ft_putchar_fd.c -L. -lft && ./a.out
**
** CASOS A PROBAR:
** - Demo: Imprime "42\n" por pantalla.
** - Happy path: 'a'
** - Edge cases: '\n', '\0', 0xE9 (>127) y fd = -1 (no debe crashear).
*/

/*
static int	g_ko = 0;

// Escribe en un pipe en vez de en la pantalla y lee lo que llegó
static void	test(char *label, char c, const char *expected, int n)
{
	int		fds[2];
	char	buf[10];
	int		bytes;
	int		ok;

	pipe(fds);
	ft_putchar_fd(c, fds[1]);
	close(fds[1]);
	bytes = read(fds[0], buf, sizeof(buf));
	close(fds[0]);
	ok = (bytes == n && memcmp(buf, expected, n) == 0);
	printf("[%s] %-20s bytes escritos: %d (esperado %d)\n",
		ok ? "OK" : "KO", label, bytes, n);
	if (!ok)
		g_ko++;
}

int	main(void)
{
	printf("--- demo en pantalla ---\n");
	ft_putchar_fd('4', 1);
	ft_putchar_fd('2', 1);
	ft_putchar_fd('\n', 1);
	printf("--- happy path ---\n");
	test("'a'", 'a', "a", 1);
	printf("--- edge cases ---\n");
	test("'\\n'", '\n', "\n", 1);
	test("'\\0' (también es 1 byte)", '\0', "\0", 1);
	test("byte 0xE9 (> 127)", (char)0xe9, "\xe9", 1);
	ft_putchar_fd('a', -1);
	printf("[OK] fd = -1: no se cuelga ni peta\n");
	printf("\nft_putchar_fd: %d KO\n", g_ko);
	return (g_ko != 0);
}
*/
