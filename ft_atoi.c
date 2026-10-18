/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixrod <felixrod@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 10:28:10 by felixrod          #+#    #+#             */
/*   Updated: 2026/10/09 14:56:58 by felixrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	return (c == ' ' || c == '\n' || c == '\t'
		|| c == '\r' || c == '\v' || c == '\f');
}

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return ((int)sign * result);
}
/*
** TEST DE ft_atoi
** 1. Compilar libft:  make
** 2. Descomentar el main de abajo.
** 3. Compilar y correr test:
**    cc -Wall -Wextra -Werror ft_atoi.c -L. -lft && ./a.out
**
** CASOS A PROBAR:
** - Happy path: "42", "-42", "+42"
** - Edge cases: " \t\n\v\f\r42" (6 blancos), "   -42", "0042", "-0", "42abc",
**               "4 2", "", "   ", "+", "-", "abc", "--42", "+-42", "- 42",
**               "2147483647" (INT_MAX), "-2147483648" (INT_MIN)
*/
/* ----------------> Descomentar testear y no olvides el cierre del final<------
static int	g_ko = 0;

static void	test(char *label, const char *s)
{
	int	ft;
	int	libc;

	ft = ft_atoi(s);
	libc = atoi(s);
	printf("[%s] %-30s ft: %11d  libc: %11d\n",
		ft == libc ? "OK" : "KO", label, ft, libc);
	if (ft != libc)
		g_ko++;
}

int	main(void)
{
	printf("--- happy path ---\n");
	test("\"42\"", "42");
	test("\"-42\"", "-42");
	test("\"+42\"", "+42");
	printf("--- edge cases ---\n");
	test("\" \\t\\n\\v\\f\\r42\" (6 blancos)", " \t\n\v\f\r42");
	test("\"   -42\"", "   -42");
	test("\"0042\"", "0042");
	test("\"-0\"", "-0");
	test("\"42abc\"", "42abc");
	test("\"4 2\"", "4 2");
	test("\"\"", "");
	test("\"   \"", "   ");
	test("\"+\"", "+");
	test("\"-\"", "-");
	test("\"abc\"", "abc");
	test("\"--42\"", "--42");
	test("\"+-42\"", "+-42");
	test("\"- 42\"", "- 42");
	test("\"2147483647\" (INT_MAX)", "2147483647");
	test("\"-2147483648\" (INT_MIN)", "-2147483648");
	printf("\nft_atoi: %d KO\n", g_ko);
	return (g_ko != 0);
}*/
