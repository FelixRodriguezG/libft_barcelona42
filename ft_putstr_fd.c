/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixrod <felixrod@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 12:16:38 by felixrod          #+#    #+#             */
/*   Updated: 2026/10/14 12:18:27 by felixrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

/*
** TEST DE ft_putstr_fd
** 1. Compilar libft:  make
** 2. Descomentar el main de abajo.
** 3. Compilar y correr test:
**    cc -Wall -Wextra -Werror ft_putstr_fd.c -L. -lft && ./a.out
**
** CASOS A PROBAR:
** - Demo: escribe en la pantalla
** - Happy path: "hola" (sin '\n')
** - Edge cases: "" (no escribe nada), "a\nb" (con '\n' dentro),
**               "ab\0cd" (para en el \0)
*/

/*
static int	g_ko = 0;

// Escribe en un pipe en vez de en la pantalla y lee lo que llegó
static void	test(char *label, char *s, const char *expected)
{
	int		fds[2];
	char	buf[50];
	int		bytes;
	int		ok;

	pipe(fds);
	ft_putstr_fd(s, fds[1]);
	close(fds[1]);
	bytes = read(fds[0], buf, sizeof(buf));
	close(fds[0]);
	ok = (bytes == (int)strlen(expected)
			&& memcmp(buf, expected, bytes) == 0);
	printf("[%s] %-26s bytes escritos: %d (esperado %d)\n",
		ok ? "OK" : "KO", label, bytes, (int)strlen(expected));
	if (!ok)
		g_ko++;
}

int	main(void)
{
	printf("--- demo en pantalla ---\n");
	ft_putstr_fd("hola por la salida estándar (fd 1)\n", 1);
	ft_putstr_fd("hola por la salida de error (fd 2)\n", 2);
	printf("--- happy path ---\n");
	test("\"hola\" (sin '\\n')", "hola", "hola");
	printf("--- edge cases ---\n");
	test("\"\" (no escribe nada)", "", "");
	test("\"a\\nb\" (con '\\n' dentro)", "a\nb", "a\nb");
	test("\"ab\\0cd\" (para en el \\0)", "ab\0cd", "ab");
	printf("\nft_putstr_fd: %d KO\n", g_ko);
	return (g_ko != 0);
}
*/
