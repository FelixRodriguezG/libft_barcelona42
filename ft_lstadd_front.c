/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixrod <felixrod@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 17:34:58 by felixrod          #+#    #+#             */
/*   Updated: 2026/10/15 17:44:49 by felixrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

/*
** TEST DE ft_lstadd_front
** 1. Compilar libft:  make
** 2. Descomentar el main de abajo.
** 3. Compilar y correr test:
**    cc -Wall -Wextra -Werror ft_lstadd_front.c -L. -lft && ./a.out
**
** CASOS A PROBAR:
** - Happy path: el nuevo nodo es la cabeza, el antiguo primero queda detrás,
**               la lista sigue terminando en NULL
** - Edge cases: lista vacía: el nuevo pasa a ser la cabeza,
**               y su next sigue siendo NULL
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
	t_list	*a;
	t_list	*b;

	a = new_node("a");
	b = new_node("b");
	printf("--- edge cases ---\n");
	list = NULL;
	ft_lstadd_front(&list, a);
	check(list == a, "lista vacía: el nuevo pasa a ser la cabeza");
	check(a->next == NULL, "y su next sigue siendo NULL");
	printf("--- happy path ---\n");
	ft_lstadd_front(&list, b);
	check(list == b, "el nuevo nodo es la cabeza");
	check(b->next == a, "el antiguo primero queda detrás");
	check(a->next == NULL, "la lista sigue terminando en NULL");
	free_list(list);
	printf("\nft_lstadd_front: %d KO\n", g_ko);
	return (g_ko != 0);
}
*/
