/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixrod <felixrod@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 12:30:15 by felixrod          #+#    #+#             */
/*   Updated: 2026/10/14 12:36:58 by felixrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	number;
	char	char_nbr;

	number = n;
	if (number < 0)
	{
		number = -number;
		ft_putchar_fd('-', fd);
	}
	if (number > 9)
		ft_putnbr_fd((number / 10), fd);
	char_nbr = (number % 10) + '0';
	ft_putchar_fd(char_nbr, fd);
}

/*
** TEST DE ft_putnbr_fd
** 1. Compilar libft:  make
** 2. Descomentar el main de abajo.
** 3. Compilar y correr test:
**    cc -Wall -Wextra -Werror ft_putnbr_fd.c -L. -lft && ./a.out
**
** CASOS A PROBAR:
** - Demo: escribe en la pantalla
** - Happy path: 42, -42
** - Edge cases: 0, -5, 10, 100, INT_MAX, INT_MIN
*/

/*
static int	g_ko = 0;

// Escribe en un pipe y compara con lo que escribiría printf("%d")
static void	test(char *label, int n)
{
	int		fds[2];
	char	buf[20];
	char	expected[20];
	int		bytes;
	int		ok;

	pipe(fds);
	ft_putnbr_fd(n, fds[1]);
	close(fds[1]);
	bytes = read(fds[0], buf, sizeof(buf) - 1);
	close(fds[0]);
	if (bytes < 0)
		bytes = 0;
	buf[bytes] = '\0';
	sprintf(expected, "%d", n);
	ok = (strcmp(buf, expected) == 0);
	printf("[%s] %-10s ft: \"%s\"  esperado: \"%s\"\n",
		ok ? "OK" : "KO", label, buf, expected);
	if (!ok)
		g_ko++;
}

int	main(void)
{
	printf("--- demo en pantalla ---\n");
	ft_putnbr_fd(INT_MIN, 1);
	write(1, "\n", 1);
	printf("--- happy path ---\n");
	test("42", 42);
	test("-42", -42);
	printf("--- edge cases ---\n");
	test("0", 0);
	test("-5", -5);
	test("10", 10);
	test("100", 100);
	test("INT_MAX", INT_MAX);
	test("INT_MIN", INT_MIN);
	printf("\nft_putnbr_fd: %d KO\n", g_ko);
	return (g_ko != 0);
}
*/
