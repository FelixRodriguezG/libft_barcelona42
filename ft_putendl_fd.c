/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixrod <felixrod@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 12:37:13 by felixrod          #+#    #+#             */
/*   Updated: 2026/10/14 12:38:45 by felixrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

/*
** TEST DE ft_putendl_fd
** 1. Compilar libft:  make
** 2. Descomentar el main de abajo.
** 3. Compilar y correr test:
**    cc -Wall -Wextra -Werror ft_putendl_fd.c -L. -lft && ./a.out
**
** CASOS A PROBAR:
** - Demo: escribe en la pantalla
** - Happy path: "hola" (añade el '\n')
** - Edge cases: "" (solo el '\n'), "hola\n" (dos saltos)
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
	ft_putendl_fd(s, fds[1]);
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
	ft_putendl_fd("hola por la salida estándar (fd 1)", 1);
	ft_putendl_fd("hola por la salida de error (fd 2)", 2);
	printf("--- happy path ---\n");
	test("\"hola\" (añade el '\\n')", "hola", "hola\n");
	printf("--- edge cases ---\n");
	test("\"\" (solo el '\\n')", "", "\n");
	test("\"hola\\n\" (dos saltos)", "hola\n", "hola\n\n");
	printf("\nft_putendl_fd: %d KO\n", g_ko);
	return (g_ko != 0);
}
*/
