#include "pipex.h"

void	ft_freemem(char **arr)
{
	int	j;

	j = 0;
	while (arr[j])
	{
		free(arr[j]);
		j++;
	}
	free(arr);
}

void	ft_free_arg(char **cmd1_args)
{
	int	counter;

	counter = 0;
	while (cmd1_args[counter])
	{
		free(cmd1_args[counter]);
		counter++;
	}
}

void	ft_full_free(t_cmds *cmds)
{
	ft_free_arg(cmds->args1);
	ft_free_arg(cmds->args2);
	free(cmds->args1);
	free(cmds->args2);
	free(cmds->path1);
	free(cmds->path2);
}
