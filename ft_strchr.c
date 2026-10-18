/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixrod <felixrod@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 23:19:22 by felixrod          #+#    #+#             */
/*   Updated: 2026/10/07 20:43:16 by felixrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((unsigned char)s[i] == (unsigned char)c)
		return ((char *)&s[i]);
	return (NULL);
}

/*
** TEST DE ft_strchr
** 1. Compilar libft:  make
** 2. Descomentar el main de abajo.
** 3. Compilar y correr test:
**    cc -Wall -Wextra -Werror ft_strchr.c -L. -lft && ./a.out
**
** CASOS A PROBAR:
** - Happy path: 'l' en "hola", 'o' en "hola hola" (la primera),
**               'z' en "hola" (no está)
** - Edge cases: '\0' (puntero al terminador), 'a' en "", '\0' en "",
**               'h' (posición 0), 'l' + 256 (se convierte a 'l'),
**               byte 0xE9 buscado como 233, byte 0xE9 buscado como (char)
*/

/*
static int	g_ko = 0;

static void	test(char *label, const char *s, int c)
{
	char	*ft;
	char	*libc;

	ft = ft_strchr(s, c);
	libc = strchr(s, c);
	printf("[%s] %-34s ft: ", ft == libc ? "OK" : "KO", label);
	if (ft)
		printf("s + %-4ld", (long)(ft - s));
	else
		printf("NULL    ");
	printf(" libc: ");
	if (libc)
		printf("s + %ld\n", (long)(libc - s));
	else
		printf("NULL\n");
	if (ft != libc)
		g_ko++;
}

int	main(void)
{
	printf("--- happy path ---\n");
	test("'l' en \"hola\"", "hola", 'l');
	test("'o' en \"hola hola\" (la primera)", "hola hola", 'o');
	test("'z' en \"hola\" (no está)", "hola", 'z');
	printf("--- edge cases ---\n");
	test("'\\0' (puntero al terminador)", "hola", '\0');
	test("'a' en \"\"", "", 'a');
	test("'\\0' en \"\"", "", '\0');
	test("'h' (posición 0)", "hola", 'h');
	test("'l' + 256 (se convierte a 'l')", "hola", 'l' + 256);
	test("byte 0xE9 buscado como 233", "caf\xe9", 0xe9);
	test("byte 0xE9 buscado como (char)", "caf\xe9", (char)0xe9);
	printf("\nft_strchr: %d KO\n", g_ko);
	return (g_ko != 0);
}
*/
