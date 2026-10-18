/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixrod <felixrod@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 15:07:55 by felixrod          #+#    #+#             */
/*   Updated: 2026/10/07 17:12:55 by felixrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			i;
	unsigned char	uc;

	i = 0;
	uc = (unsigned char)c;
	while (s[i] != '\0')
		i++;
	while (1)
	{
		if ((unsigned char)s[i] == uc)
			return ((char *)&s[i]);
		if (i == 0)
			break ;
		i--;
	}
	return (NULL);
}

/*
** TEST DE ft_strrchr
** 1. Compilar libft:  make
** 2. Descomentar el main de abajo.
** 3. Compilar y correr test:
**    cc -Wall -Wextra -Werror ft_strrchr.c -L. -lft && ./a.out
**
** CASOS A PROBAR:
** - Happy path: 'o' en "hola hola" (la última), 'z' en "hola" (no está)
** - Edge cases: 'h' solo en la posición 0, 'a' en la última posición,
**               '\0' (puntero al terminador), 'a' en "", '\0' en "",
**               'o' + 256 (se convierte a 'o')
*/

/*
static int	g_ko = 0;

static void	test(char *label, const char *s, int c)
{
	char	*ft;
	char	*libc;

	ft = ft_strrchr(s, c);
	libc = strrchr(s, c);
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
	test("'o' en \"hola hola\" (la última)", "hola hola", 'o');
	test("'z' en \"hola\" (no está)", "hola", 'z');
	printf("--- edge cases ---\n");
	test("'h' solo en la posición 0", "hola", 'h');
	test("'a' en la última posición", "hola", 'a');
	test("'\\0' (puntero al terminador)", "hola", '\0');
	test("'a' en \"\"", "", 'a');
	test("'\\0' en \"\"", "", '\0');
	test("'o' + 256 (se convierte a 'o')", "hola hola", 'o' + 256);
	printf("\nft_strrchr: %d KO\n", g_ko);
	return (g_ko != 0);
}
*/
