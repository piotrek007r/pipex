/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruszkie <pruszkie@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 11:30:23 by pruszkie          #+#    #+#             */
/*   Updated: 2024/04/21 13:48:04 by pruszkie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//void del_string(void *content)
//{
//	free(content);
//}

void ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst == NULL)
		return;
	(*del)(lst->content);
	free(lst);
}

//int main()
//{
//	t_list *root;
//	root = malloc(sizeof(t_list));
//	root->content = (char *)malloc(sizeof(char) * strlen("To delete")+1);
//	strcpy(root->content, "To delete");
//	root->next = NULL;

//	printf("before deleting %s\n", (char *)root->content);

//	ft_lstdelone(root, &del_string);

//	printf("after deleting %s\n", (char *)root->content);
//}
