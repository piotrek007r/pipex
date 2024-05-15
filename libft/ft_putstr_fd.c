/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piotr <piotr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:48:37 by pruszkie          #+#    #+#             */
/*   Updated: 2024/05/14 23:02:15 by piotr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	counter;

	counter = 0;
	while (s[counter] != '\0')
	{
		if (write(fd, &s[counter], 1) == -1)
			return;
		counter++;
	}
}
