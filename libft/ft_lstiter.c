/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruszkie <pruszkie@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:51:10 by pruszkie          #+#    #+#             */
/*   Updated: 2024/04/21 15:25:58 by pruszkie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//void foo()
//{
//	printf("Inserted\n");
//}

void ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL)
		return;

	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

//int main ()
//{
//	t_list root, el;
//	root.next = &el;
//	el.next = NULL;

//	ft_lstiter(&root, &foo);
//}

/*When we say "applying a function to the content," it means passing the content of each node to the function as an argument. It does not mean modifying the content itself within the ft_lstiter function.

So, in the context of ft_lstiter, "applying a function to the content" indeed means calling the function f with the content of each node (lst->content) as its argument, as demonstrated in f(lst->content). This allows you to perform some operation on the content of each node without modifying the content itself.

If you want to modify the content of each node within ft_lstiter, you would need to pass the address of the content pointer (&lst->content) to the function f. Then, within f, you could modify the content by dereferencing the content pointer.*/
