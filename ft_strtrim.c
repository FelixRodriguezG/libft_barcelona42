/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixrod <felixrod@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 00:45:08 by felixrod          #+#    #+#             */
/*   Updated: 2026/10/11 03:05:58 by felixrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief  Recorta los caracteres indicados en 'set' al inicio y final de 's1'.
**
** @param  s1   Cadena de caracteres original que se va a recortar.
** @param  set  Conjunto de caracteres que se deben eliminar.
**
** @return Puntero a la nueva cadena recortada (reserva memoria con malloc),
**         o NULL si falla la reserva o los parámetros son inválidos.
**
** @note   - Avanza 'start' desde 0 mientras el carácter pertenezca a 'set'.
**         - Retrocede 'end' desde el final (ft_strlen) mientras el carácter
**           anterior pertenezca a 'set'.
**         - Si toda la cadena es recortada (start >= end), ft_substr se
**           encarga de devolver una cadena vacía "" asignada en memoria.
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	new_len;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	new_len = end - start;
	return (ft_substr(s1, start, new_len));
}

/*
** TEST DE ft_strtrim
** 1. Compilar libft:  make
** 2. Descomentar el main de abajo.
** 3. Compilar y correr test:
**    cc -Wall -Wextra -Werror ft_strtrim.c -L. -lft && ./a.out
**    valgrind --leak-check=full ./a.out
**
** CASOS A PROBAR:
** - Happy path: ("  hola  ", " "), ("xxhola mundoxx", "x")
** - Edge cases: solo a la izquierda, solo a la derecha,
**               los del medio se quedan, todo está en set, set vacío (copia),
**               s vacío, última letra también en set
*/

/*
static int	g_ko = 0;

static void	test(char *label, const char *s, const char *set,
		const char *expected)
{
	char	*ret;
	int		ok;

	ret = ft_strtrim(s, set);
	ok = (ret != NULL && strcmp(ret, expected) == 0);
	printf("[%s] %-34s ft: \"%s\"  esperado: \"%s\"\n",
		ok ? "OK" : "KO", label, ret ? ret : "(NULL)", expected);
	if (!ok)
		g_ko++;
	free(ret);
}

int	main(void)
{
	printf("--- happy path ---\n");
	test("(\"  hola  \", \" \")", "  hola  ", " ", "hola");
	test("(\"xxhola mundoxx\", \"x\")", "xxhola mundoxx", "x", "hola mundo");
	printf("--- edge cases ---\n");
	test("solo a la izquierda", "  hola", " ", "hola");
	test("solo a la derecha", "hola  ", " ", "hola");
	test("los del medio se quedan", " h o l a ", " ", "h o l a");
	test("todo está en set", "aaaa", "a", "");
	test("set vacío (copia)", "  hola  ", "", "  hola  ");
	test("s vacío", "", " ", "");
	test("última letra también en set", "ab hola ba", "ab ", "hol");
	printf("\nft_strtrim: %d KO\n", g_ko);
	return (g_ko != 0);
}
*/
