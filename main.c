#include "Includes/ft_printf.h"
#include "Includes/libft.h"
#include "Includes/pipex.h"

// void	ft_pipex(cmds cmds)
// {
// 	int		fd[2];
// 	int		id;
// 	int input;
// 	int output;

// 	int	i = 0;
	
	
// 	int input = open(cmds.input_path, O_RDONLY);
// }

int	main(int argc, char **argv, char **envp)
{
	cmds	cmds;

	cmds.cmd1_args = ft_split(argv[2], ' ');
	cmds.cmd2_args = ft_split(argv[3], ' ');
	cmds.cmd1_name = cmds.cmd1_args[0];
	cmds.cmd2_name = cmds.cmd1_args[0];
	cmds.cmd1_path = ft_path_find(cmds.cmd1_name, envp);
	cmds.cmd2_path = ft_path_find(cmds.cmd2_name, envp);
	
	// ft_pipex(cmds);

	free(cmds.cmd1_path);
	free(cmds.cmd2_path);
	ft_free_arg(cmds.cmd1_args);
	ft_free_arg(cmds.cmd2_args);
	free(cmds.cmd1_args);
	free(cmds.cmd2_args);
}


// test:  infile "ls -lsa" "wc" outfile

	// int i = 0;

	// printf("name: %s\n", cmds.cmd1_name);
	// printf("path: %s\n", cmds.cmd1_path);


	// while (cmds.cmd1_args[i] != NULL)
	// {
	// 	printf("cur arg %s\n", cmds.cmd1_args[i]);

	// 	i++;
	// }
	// i = 0;
	// while (cmds.cmd2_args[i] != NULL)
	// {
	// 	printf("cur arg %s\n", cmds.cmd2_args[i]);
	// 	i++;
	// }