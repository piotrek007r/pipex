#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	counter;

	counter = 0;
	while (lst)
	{
		counter++;
		lst = lst->next;
	}
	return (counter);
}

// int main ()
// {
//     t_list root, el1, el2;
//     root.next = &el1;
//     el1.next = &el2;
//     el2.next = NULL;
//     printf("%d", ft_lstsize(&root));
// }