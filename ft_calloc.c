/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixrod <felixrod@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 12:25:59 by felixrod          #+#    #+#             */
/*   Updated: 2026/10/09 13:31:36 by felixrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	num_bytes;

	if (size && nmemb && (nmemb > SIZE_MAX / size))
		return (NULL);
	num_bytes = nmemb * size;
	ptr = malloc(num_bytes);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, num_bytes);
	return (ptr);
}

/*
** TEST DE ft_calloc
** 1. Compilar libft:  make
** 2. Descomentar el main de abajo.
** 3. Compilar y correr test:
**    cc -Wall -Wextra -Werror ft_calloc.c -L. -lft && ./a.out
**    valgrind --leak-check=full ./a.out
**
** CASOS A PROBAR:
** - Happy path: ft_calloc(100, sizeof(int)) no es NULL,
**               los 400 bytes están a 0
** - Edge cases: ft_calloc(0, 0) devuelve un puntero que se puede liberar,
**               ft_calloc(0, 10) devuelve un puntero que se puede liberar,
**               overflow: ft_calloc(SIZE_MAX, 2) -> NULL,
**               overflow: ft_calloc(SIZE_MAX / 2 + 1, 2) -> NULL,
**               overflow: ft_calloc(SIZE_MAX, SIZE_MAX) -> NULL
*/

/*
static int	g_ko = 0;

static void	check(int ok, char *label)
{
	printf("[%s] %s\n", ok ? "OK" : "KO", label);
	if (!ok)
		g_ko++;
}

// Comprueba que los n bytes están a 0, no solo el principio
static int	all_zero(unsigned char *p, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (p[i] != 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(void)
{
	int		*nums;
	char	*p;

	printf("--- happy path ---\n");
	nums = ft_calloc(100, sizeof(int));
	check(nums != NULL, "ft_calloc(100, sizeof(int)) no es NULL");
	check(nums && all_zero((unsigned char *)nums, 100 * sizeof(int)),
		"los 400 bytes están a 0");
	free(nums);
	printf("--- edge cases ---\n");
	p = ft_calloc(0, 0);
	check(p != NULL,
		"ft_calloc(0, 0) devuelve un puntero que se puede liberar");
	free(p);
	p = ft_calloc(0, 10);
	check(p != NULL,
		"ft_calloc(0, 10) devuelve un puntero que se puede liberar");
	free(p);
	p = ft_calloc(SIZE_MAX, 2);
	check(p == NULL, "overflow: ft_calloc(SIZE_MAX, 2) -> NULL");
	free(p);
	p = ft_calloc(SIZE_MAX / 2 + 1, 2);
	check(p == NULL, "overflow: ft_calloc(SIZE_MAX / 2 + 1, 2) -> NULL");
	free(p);
	p = ft_calloc(SIZE_MAX, SIZE_MAX);
	check(p == NULL, "overflow: ft_calloc(SIZE_MAX, SIZE_MAX) -> NULL");
	free(p);
	printf("\nft_calloc: %d KO (pásalo también por valgrind)\n", g_ko);
	return (g_ko != 0);
}
*/
