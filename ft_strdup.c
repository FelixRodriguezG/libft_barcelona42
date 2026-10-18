/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixrod <felixrod@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 13:51:09 by felixrod          #+#    #+#             */
/*   Updated: 2026/10/09 17:58:23 by felixrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	str_len;

	str_len = ft_strlen(s) + 1;
	dup = malloc(str_len);
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s, str_len);
	return (dup);
}

/*
** TEST DE ft_strdup
** 1. Compilar libft:  make
** 2. Descomentar el main de abajo.
** 3. Compilar y correr test:
**    cc -Wall -Wextra -Werror ft_strdup.c -L. -lft && ./a.out
**    valgrind --leak-check=full ./a.out
**
** CASOS A PROBAR:
** - Happy path: la copia es "hola"
** - Edge cases: el puntero devuelto no es el original,
**               cambiar la copia no cambia el original,
**               ft_strdup("") -> "" reservada
*/

/*
static int	g_ko = 0;

static void	check(int ok, char *label)
{
	printf("[%s] %s\n", ok ? "OK" : "KO", label);
	if (!ok)
		g_ko++;
}

int	main(void)
{
	char	original[5];
	char	*copy;

	strcpy(original, "hola");
	printf("--- happy path ---\n");
	copy = ft_strdup(original);
	printf("     copia: \"%s\"\n", copy);
	check(copy && strcmp(copy, "hola") == 0, "la copia es \"hola\"");
	printf("--- edge cases ---\n");
	check(copy != original, "el puntero devuelto no es el original");
	if (copy)
		copy[0] = 'X';
	check(strcmp(original, "hola") == 0,
		"cambiar la copia no cambia el original");
	free(copy);
	copy = ft_strdup("");
	check(copy && copy[0] == '\0', "ft_strdup(\"\") -> \"\" reservada");
	free(copy);
	printf("\nft_strdup: %d KO (valgrind detecta si reservas menos"
		" de len + 1)\n", g_ko);
	return (g_ko != 0);
}
*/
