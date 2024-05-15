/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruszkie <pruszkie@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 11:29:37 by pruszkie          #+#    #+#             */
/*   Updated: 2024/04/21 12:23:46 by pruszkie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

t_list *ft_lstlast(t_list *lst)
{
    if (lst == NULL)
        return (NULL);
    t_list *current;

    current = lst;

    while (current->next != NULL)
        current = current->next;
    return current;
}

// int main ()
// {
//     t_list root, node2, node3;
//     root.content = "head node";
//     root.next = &node2;
//     node2.content = "node2";
//     node2.next = &node3;
//     node3.content = "last node";
//     node3.next = NULL;

//     t_list *last_node = ft_lstlast(&root);
//     printf("Returned node: %s\n", (char *)last_node->content);
// }
