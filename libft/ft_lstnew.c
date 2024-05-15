/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruszkie <pruszkie@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 11:29:53 by pruszkie          #+#    #+#             */
/*   Updated: 2024/04/21 11:29:55 by pruszkie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

t_list *ft_lstnew(void *content)
{
    t_list *new_node;
    new_node = malloc(sizeof(t_list));
    if (new_node == NULL)
        return (NULL);
    new_node->content = content;
    new_node->next = NULL;
    return new_node;
}

// int main()
// {
//     char *str = "This is sparta!";
//     t_list *new_node = ft_lstnew(str);
//     printf("Content of node: %s", (char *)new_node->content);
// }
