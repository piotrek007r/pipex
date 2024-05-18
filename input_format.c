/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruszkie <pruszkie@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:58:02 by pruszkie          #+#    #+#             */
/*   Updated: 2024/05/18 13:58:30 by pruszkie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_path_cmp(char **arr, char *cmd_mod)
{
	char	*valid_path;
	char	*temp;
	int		counter;

	counter = 0;
	valid_path = NULL;
	while (arr[counter])
	{
		temp = ft_strjoin(arr[counter], cmd_mod);
		if (access(temp, X_OK) == 0)
		{
			valid_path = temp;
			break ;
		}
		free(temp);
		counter++;
	}
	return (valid_path);
}

char	*ft_path_find(char *cmd1, char **envp)
{
	char	*valid_path;
	char	*var_path;
	char	**arr;
	char	*temp;
	char	*cmd_mod;

	valid_path = NULL;
	temp = ft_strdup("/");
	cmd_mod = ft_strjoin(temp, cmd1);
	free(temp);
	while (*envp)
	{
		var_path = ft_strnstr(*envp, "PATH", 4);
		if (var_path)
		{
			arr = ft_split(var_path, ':');
			valid_path = ft_path_cmp(arr, cmd_mod);
			ft_freemem(arr);
		}
		envp++;
	}
	free(cmd_mod);
	return (valid_path);
}
