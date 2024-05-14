#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include "pipex.h"

void ft_child_process(cmds cmds, char **argv, char **envp)
{
	int input;
	input = open(argv[1], O_RDONLY);
	if (input == -1)
		ft_error(2);
	close(cmds.fd[0]);
	if (dup2(input, 0) == -1)
		ft_error(3);
	if (dup2(cmds.fd[1], 1) == -1)
		ft_error(3);
	execve(cmds.path1, cmds.args1, envp);
	close(cmds.fd[1]);	
}

void ft_parent_process(cmds cmds, char **argv, char **envp)
{
	int output;

	output = open(argv[4], O_WRONLY | O_CREAT, 0777);
	if (output == -1)
		ft_error(4);
	wait(0);
	close(cmds.fd[1]);	 
	if(dup2(cmds.fd[0], 0))
		ft_error(3);
	if (dup2(output, 1) == -1)
		ft_error(3);
	execve(cmds.path2, cmds.args2, envp);
	close(cmds.fd[0]);	 
	return;
}

void	ft_pipex(cmds cmds, char **argv, char **envp)
{

	if (pipe(cmds.fd) == 1)
		ft_error(1);
	

	cmds.id = fork();
	if (cmds.id == 0)
	{
		ft_child_process(cmds, argv, envp);
		printf("--ok--\n");

	}
	else
		ft_parent_process(cmds, argv, envp);
}

int	main(int argc, char **argv, char **envp)
{
	cmds	cmds;

	if(argc != 5)
		ft_error(6);
	cmds.args1 = ft_split(argv[2], ' ');
	cmds.args2 = ft_split(argv[3], ' ');
	cmds.name1 = cmds.args1[0];
	cmds.name2 = cmds.args2[0];
	cmds.path1 = ft_path_find(cmds.name1, envp);
	cmds.path2 = ft_path_find(cmds.name2, envp);
	
	ft_pipex(cmds, argv, envp);

	free(cmds.path1);
	free(cmds.path2);
	ft_free_arg(cmds.args1);
	ft_free_arg(cmds.args2);
	free(cmds.args1);
	free(cmds.args2);
}


// test:  infile.txt "grep this" "wc -l" outfile.txt


