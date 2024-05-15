/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piotr <piotr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:58:55 by pruszkie          #+#    #+#             */
/*   Updated: 2024/05/14 23:01:40 by piotr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	unsigned int	counter;

	counter = 0;
	while (s[counter])
	{
		if (write(fd, &s[counter], 1) == -1)
			return;
		counter++;
	}
	if (write(fd, "\n", 1) == -1)
		return;
}
