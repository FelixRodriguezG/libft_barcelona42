/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixrod <felixrod@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 23:52:32 by felixrod          #+#    #+#             */
/*   Updated: 2026/10/15 23:53:23 by felixrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

/*
** TEST DE ft_lstdelone
** 1. Compilar libft:  make
** 2. Descomentar el main de abajo.
** 3. Compilar y correr test:
**    cc -Wall -Wextra -Werror ft_lstdelone.c -L. -lft && ./a.out
**    valgrind --leak-check=full ./a.out
**
** CASOS A PROBAR:
** - Happy path: llama a del una sola vez, con el content del nodo
** - Edge cases: el nodo siguiente sigue vivo e intacto
*/

/*
static int	g_ko = 0;

static void	check(int ok, char *label)
{
	printf("[%s] %s\n", ok ? "OK" : "KO", label);
	if (!ok)
		g_ko++;
}

// Crea el nodo a mano para no depender de ft_lstnew
static t_list	*new_node(void *content)
{
	t_list	*n;

	n = malloc(sizeof(t_list));
	n->content = content;
	n->next = NULL;
	return (n);
}

static int	g_calls = 0;
static void	*g_deleted = NULL;

// Apunta qué content se ha borrado y cuántas veces
static void	del(void *content)
{
	g_calls++;
	g_deleted = content;
	free(content);
}

static char	*new_str(char *s)
{
	char	*copy;
	int		i;

	copy = malloc(10);
	i = 0;
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

int	main(void)
{
	t_list	*a;
	t_list	*b;
	void	*content_a;

	a = new_node(new_str("a"));
	b = new_node(new_str("b"));
	a->next = b;
	content_a = a->content;
	printf("--- happy path ---\n");
	ft_lstdelone(a, del);
	check(g_calls == 1, "llama a del una sola vez");
	check(g_deleted == content_a, "con el content del nodo");
	printf("--- edge cases ---\n");
	check(((char *)b->content)[0] == 'b' && b->next == NULL,
		"el nodo siguiente sigue vivo e intacto");
	free(b->content);
	free(b);
	printf("\nft_lstdelone: %d KO (valgrind: 0 leaks y ningún invalid free)\n",
		g_ko);
	return (g_ko != 0);
}
*/
