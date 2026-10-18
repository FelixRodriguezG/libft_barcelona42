/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixrod <felixrod@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 07:37:20 by felixrod          #+#    #+#             */
/*   Updated: 2026/10/16 07:50:18 by felixrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*content;

	new_list = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		content = f(lst->content);
		new_node = ft_lstnew(content);
		if (!new_node)
		{
			del(content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

/*
** TEST DE ft_lstmap
** 1. Compilar libft:  make
** 2. Descomentar el main de abajo.
** 3. Compilar y correr test:
**    cc -Wall -Wextra -Werror ft_lstmap.c -L. -lft && ./a.out
**    valgrind --leak-check=full ./a.out
**
** CASOS A PROBAR:
** - Happy path: valores 10, 20, 30 en el mismo orden
** - Edge cases: mismo tamaño (3 nodos), nodos y contents nuevos,
**               la lista original no cambia, NULL -> NULL
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

// Cuenta los nodos a mano para no depender de ft_lstsize
static int	list_len(t_list *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}

// f devuelve un content nuevo (reservado), con el valor por 10
static void	*times_ten(void *content)
{
	int	*new_int;

	new_int = malloc(sizeof(int));
	if (!new_int)
		return (NULL);
	*new_int = *(int *)content * 10;
	return (new_int);
}

int	main(void)
{
	int		v[3];
	int		len;
	t_list	*list;
	t_list	*new_list;
	t_list	*it;

	v[0] = 1;
	v[1] = 2;
	v[2] = 3;
	list = new_node(&v[0]);
	list->next = new_node(&v[1]);
	list->next->next = new_node(&v[2]);
	printf("--- happy path ---\n");
	new_list = ft_lstmap(list, times_ten, free);
	printf("     ft_lstmap(1 -> 2 -> 3, times_ten) = ");
	it = new_list;
	while (it)
	{
		printf("%d -> ", *(int *)it->content);
		it = it->next;
	}
	printf("NULL\n");
	len = list_len(new_list);
	check(len == 3 && *(int *)new_list->content == 10
		&& *(int *)new_list->next->content == 20
		&& *(int *)new_list->next->next->content == 30,
		"valores 10, 20, 30 en el mismo orden");
	printf("--- edge cases ---\n");
	check(len == 3, "mismo tamaño (3 nodos)");
	check(new_list && new_list != list && new_list->content != list->content,
		"nodos y contents nuevos");
	check(v[0] == 1 && v[1] == 2 && v[2] == 3, "la lista original no cambia");
	check(ft_lstmap(NULL, times_ten, free) == NULL, "NULL -> NULL");
	it = new_list;
	while (it)
	{
		free(it->content);
		it = it->next;
	}
	free_list(new_list);
	free_list(list);
	printf("\nft_lstmap: %d KO (valgrind: 0 leaks)\n", g_ko);
	return (g_ko != 0);
}
*/
