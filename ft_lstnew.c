/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixrod <felixrod@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 17:00:21 by felixrod          #+#    #+#             */
/*   Updated: 2026/10/15 17:34:13 by felixrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

/*
** TEST DE ft_lstnew
** 1. Compilar libft:  make
** 2. Descomentar el main de abajo.
** 3. Compilar y correr test:
**    cc -Wall -Wextra -Werror ft_lstnew.c -L. -lft && ./a.out
**    valgrind --leak-check=full ./a.out
**
** CASOS A PROBAR:
** - Happy path: devuelve un nodo, content es el puntero que le pasamos,
**               *(int *)content vale 42, next es NULL
** - Edge cases: content = NULL es válido
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
	t_list	*n;
	int		x;

	x = 42;
	printf("--- happy path ---\n");
	n = ft_lstnew(&x);
	check(n != NULL, "devuelve un nodo");
	check(n && n->content == &x, "content es el puntero que le pasamos");
	check(n && *(int *)n->content == 42, "*(int *)content vale 42");
	check(n && n->next == NULL, "next es NULL");
	free(n);
	printf("--- edge cases ---\n");
	n = ft_lstnew(NULL);
	check(n != NULL && n->content == NULL, "content = NULL es válido");
	free(n);
	printf("\nft_lstnew: %d KO (valgrind: 0 leaks)\n", g_ko);
	return (g_ko != 0);
}
*/
