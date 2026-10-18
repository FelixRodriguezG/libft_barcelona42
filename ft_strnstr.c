/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixrod <felixrod@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 00:58:09 by felixrod          #+#    #+#             */
/*   Updated: 2026/10/08 09:21:20 by felixrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*little)
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] && little[j] && (i + j) < len)
		{
			if (big[i + j] == little[j])
				j++;
			else
				break ;
		}
		if (little[j] == '\0')
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}

/*
** TEST DE ft_strnstr
** 1. Compilar libft:  make
** 2. Descomentar el main de abajo.
** 3. Compilar y correr test:
**    cc -Wall -Wextra -Werror ft_strnstr.c -L. -lft && ./a.out
**
** CASOS A PROBAR:
** - Happy path: "mundo" en "hola mundo", "adios" en "hola mundo"
** - Edge cases: needle vacío, needle vacío con len = 0, len = 0,
**               needle cortado por len (len = 9), needle cabe justo (len = 10),
**               coincidencia parcial ("aab" en "aaab"),
**               needle más largo que big, len mayor que big
*/

/*
static int	g_ko = 0;

// expected_pos = -1 significa que se espera NULL
static void	test(char *label, const char *big, const char *little,
		size_t len, long expected_pos)
{
	char	*ret;
	long	pos;

	ret = ft_strnstr(big, little, len);
	pos = -1;
	if (ret)
		pos = (long)(ret - big);
	printf("[%s] %-38s ft: ", pos == expected_pos ? "OK" : "KO", label);
	if (pos == -1)
		printf("NULL    ");
	else
		printf("big + %-2ld", pos);
	if (expected_pos == -1)
		printf(" esperado: NULL\n");
	else
		printf(" esperado: big + %ld\n", expected_pos);
	if (pos != expected_pos)
		g_ko++;
}

int	main(void)
{
	printf("--- happy path ---\n");
	test("\"mundo\" en \"hola mundo\"", "hola mundo", "mundo", 10, 5);
	test("\"adios\" en \"hola mundo\"", "hola mundo", "adios", 10, -1);
	printf("--- edge cases ---\n");
	test("needle vacío", "hola", "", 4, 0);
	test("needle vacío con len = 0", "hola", "", 0, 0);
	test("len = 0", "hola", "h", 0, -1);
	test("needle cortado por len (len = 9)", "hola mundo", "mundo", 9, -1);
	test("needle cabe justo (len = 10)", "hola mundo", "mundo", 10, 5);
	test("coincidencia parcial (\"aab\" en \"aaab\")", "aaab", "aab", 4, 1);
	test("needle más largo que big", "hola", "hola mundo", 20, -1);
	test("len mayor que big", "hola", "la", 100, 2);
	printf("\nft_strnstr: %d KO\n", g_ko);
	return (g_ko != 0);
}
*/
