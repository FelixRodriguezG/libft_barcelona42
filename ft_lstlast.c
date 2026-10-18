/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixrod <felixrod@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 23:34:19 by felixrod          #+#    #+#             */
/*   Updated: 2026/10/15 23:38:09 by felixrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/*
** TEST DE ft_lstlast
** 1. Compilar libft:  make
** 2. Descomentar el main de abajo.
** 3. Compilar y correr test:
**    cc -Wall -Wextra -Werror ft_lstlast.c -L. -lft && ./a.out
**
** CASOS A PROBAR:
** - Happy path: devuelve el último nodo (c)
** - Edge cases: NULL -> NULL, un solo nodo -> ese nodo
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

static void	free_list(t_list *lst)
{
	t_list	*next_node;

	while (lst)
	{
		next_node = lst->next;
		free(lst);
		lst = next_node;
	}
}

int	main(void)
{
	t_list	*list;
	t_list	*last;

	list = new_node("a");
	list->next = new_node("b");
	last = new_node("c");
	list->next->next = last;
	printf("--- happy path ---\n");
	printf("     ft_lstlast(a -> b -> c)->content = \"%s\"\n",
		(char *)ft_lstlast(list)->content);
	check(ft_lstlast(list) == last, "devuelve el último nodo (c)");
	printf("--- edge cases ---\n");
	check(ft_lstlast(NULL) == NULL, "NULL -> NULL");
	check(ft_lstlast(last) == last, "un solo nodo -> ese nodo");
	free_list(list);
	printf("\nft_lstlast: %d KO\n", g_ko);
	return (g_ko != 0);
}
*/
