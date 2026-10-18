/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixrod <felixrod@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 01:27:16 by felixrod          #+#    #+#             */
/*   Updated: 2026/10/16 01:29:51 by felixrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*
** TEST DE ft_lstiter
** 1. Compilar libft:  make
** 2. Descomentar el main de abajo.
** 3. Compilar y correr test:
**    cc -Wall -Wextra -Werror ft_lstiter.c -L. -lft && ./a.out
**
** CASOS A PROBAR:
** - Happy path: aplica f a cada content (1,2 -> 2,3)
** - Edge cases: también el último nodo (3 -> 4),
**               llama a f exactamente 3 veces, NULL: no llama a f
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

static int	g_calls = 0;

static void	add_one(void *content)
{
	*(int *)content += 1;
	g_calls++;
}

int	main(void)
{
	int		v[3];
	t_list	*list;

	v[0] = 1;
	v[1] = 2;
	v[2] = 3;
	list = new_node(&v[0]);
	list->next = new_node(&v[1]);
	list->next->next = new_node(&v[2]);
	printf("--- happy path ---\n");
	ft_lstiter(list, add_one);
	printf("     después de ft_lstiter: %d -> %d -> %d\n", v[0], v[1], v[2]);
	check(v[0] == 2 && v[1] == 3, "aplica f a cada content (1,2 -> 2,3)");
	printf("--- edge cases ---\n");
	check(v[2] == 4, "también el último nodo (3 -> 4)");
	check(g_calls == 3, "llama a f exactamente 3 veces");
	g_calls = 0;
	ft_lstiter(NULL, add_one);
	check(g_calls == 0, "NULL: no llama a f");
	free_list(list);
	printf("\nft_lstiter: %d KO\n", g_ko);
	return (g_ko != 0);
}
*/
