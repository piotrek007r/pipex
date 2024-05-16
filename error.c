#include "pipex.h"

void	ft_check_args(t_cmds *cmds)
{
	if (cmds->args1[0] == NULL && cmds->args2[0] == NULL)
	{
		free(cmds->args1);
		free(cmds->args2);
		ft_error_check(2);
	}
	else if (cmds->args1[0] == NULL)
	{
		ft_free_arg(cmds->args2);
		free(cmds->args1);
		free(cmds->args2);
		ft_error_check(2);
	}
	else if (cmds->args2[0] == NULL)
	{
		ft_free_arg(cmds->args1);
		free(cmds->args1);
		free(cmds->args2);
		ft_error_check(2);
	}
}

void	ft_error_check(int key)
{
	if (key == 1)
		ft_printf("Error: Invalid number of arguments\n");
	if (key == 2)
		ft_printf("Error: Bad address\n");
	exit(EXIT_FAILURE);
}

void	ft_error(t_cmds *cmds)
{
	ft_full_free(cmds);
	perror("Error: ");
	exit(EXIT_FAILURE);
}
