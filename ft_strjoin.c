/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixrod <felixrod@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 23:39:40 by felixrod          #+#    #+#             */
/*   Updated: 2026/10/11 00:44:03 by felixrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(sizeof(char) * total_len);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, total_len);
	ft_strlcat(str, s2, total_len);
	return (str);
}

/*
** TEST DE ft_strjoin
** 1. Compilar libft:  make
** 2. Descomentar el main de abajo.
** 3. Compilar y correr test:
**    cc -Wall -Wextra -Werror ft_strjoin.c -L. -lft && ./a.out
**    valgrind --leak-check=full ./a.out
**
** CASOS A PROBAR:
** - Happy path: ("hola ", "mundo")
** - Edge cases: izquierda vacía, derecha vacía, las dos vacías
*/

/*
static int	g_ko = 0;

static void	test(char *label, const char *s1, const char *s2,
		const char *expected)
{
	char	*ret;
	int		ok;

	ret = ft_strjoin(s1, s2);
	ok = (ret != NULL && ret != s1 && ret != s2
			&& strcmp(ret, expected) == 0);
	printf("[%s] %-26s ft: \"%s\"  esperado: \"%s\"\n",
		ok ? "OK" : "KO", label, ret ? ret : "(NULL)", expected);
	if (!ok)
		g_ko++;
	free(ret);
}

int	main(void)
{
	printf("--- happy path ---\n");
	test("(\"hola \", \"mundo\")", "hola ", "mundo", "hola mundo");
	printf("--- edge cases ---\n");
	test("izquierda vacía", "", "mundo", "mundo");
	test("derecha vacía", "hola", "", "hola");
	test("las dos vacías", "", "", "");
	printf("\nft_strjoin: %d KO (cada caso comprueba también que el resultado"
		" es memoria nueva)\n", g_ko);
	return (g_ko != 0);
}
*/
