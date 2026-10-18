/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixrod <felixrod@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 09:04:41 by felixrod          #+#    #+#             */
/*   Updated: 2026/10/14 09:14:36 by felixrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
static void	f_toupper_even(unsigned int i, char *c)
{
	if (i % 2 == 0 && *c >= 'a' && *c <= 'z')
		*c -= 32;
}

int	main(void)
{
	// 1. Cadena en la pila (Stack) -> No requiere free()
	char	stack_str[] = "hello world!";

	printf("--- Test 1: Stack ---\n");
	printf("Antes:  %s\n", stack_str);
	ft_striteri(stack_str, f_toupper_even);
	printf("Después: %s\n\n", stack_str);

	// 2. Cadena en memoria dinámica (Heap) -> Requiere free()
	char	*heap_str = strdup("hello world!");

	if (heap_str)
	{
		printf("--- Test 2: Heap ---\n");
		printf("Antes:  %s\n", heap_str);
		ft_striteri(heap_str, f_toupper_even);
		printf("Después: %s\n", heap_str);
		
		// LIBERACIÓN OBLIGATORIA para evitar leaks
		free(heap_str);
	}

	// 3. Casos límite (NULL) -> No debe crashgear ni hacer nada
	ft_striteri(NULL, f_toupper_even);
	ft_striteri(stack_str, NULL);

	return (0);
}*/

/*
** TEST DE ft_striteri
** 1. Compilar libft:  make
** 2. Descomentar el main de abajo.
** 3. Compilar y correr test:
**    cc -Wall -Wextra -Werror ft_striteri.c -L. -lft && ./a.out
**
** CASOS A PROBAR:
** - Happy path: modifica la propia cadena ("abcd"),
**               llama a f una vez por carácter (4)
** - Edge cases: cadena vacía: no llama a f
*/

/*
static int	g_ko = 0;
static int	g_calls = 0;

static void	check(int ok, char *label)
{
	printf("[%s] %s\n", ok ? "OK" : "KO", label);
	if (!ok)
		g_ko++;
}

// Recibe un puntero al carácter: así puede modificarlo en la cadena
static void	add_index(unsigned int i, char *c)
{
	*c = *c + i;
	g_calls++;
}

int	main(void)
{
	char	s[5];
	char	empty[1];

	strcpy(s, "aaaa");
	printf("--- happy path ---\n");
	ft_striteri(s, add_index);
	printf("     \"aaaa\" después de ft_striteri: \"%s\"\n", s);
	check(strcmp(s, "abcd") == 0, "modifica la propia cadena (\"abcd\")");
	check(g_calls == 4, "llama a f una vez por carácter (4)");
	printf("--- edge cases ---\n");
	g_calls = 0;
	empty[0] = '\0';
	ft_striteri(empty, add_index);
	check(g_calls == 0, "cadena vacía: no llama a f");
	printf("\nft_striteri: %d KO\n", g_ko);
	return (g_ko != 0);
}
*/
