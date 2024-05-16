#include "pipex.h"

void	ft_gchild1_process(t_cmds *cmds, char **argv, char **envp)
{
	int	input;

	input = open(argv[1], O_RDONLY);
	if (input == -1)
		ft_error(cmds);
	close(cmds->fd[0]);
	if (dup2(input, 0) == -1)
		ft_error(cmds);
	if (dup2(cmds->fd[1], 1) == -1)
		ft_error(cmds);
	if (execve(cmds->path1, cmds->args1, envp) == -1)
		ft_error(cmds);
	close(cmds->fd[1]);
}

void	ft_gchild2_process(t_cmds *cmds, char **argv, char **envp)
{
	int	output;

	output = open(argv[4], O_WRONLY | O_CREAT, 0777);
	if (output == -1)
		ft_error(cmds);
	wait(0);
	close(cmds->fd[1]);
	if (dup2(cmds->fd[0], 0))
		ft_error(cmds);
	if (dup2(output, 1) == -1)
		ft_error(cmds);
	execve(cmds->path2, cmds->args2, envp);
	ft_error(cmds);
	close(cmds->fd[0]);
	return ;
}

void	ft_pipex(t_cmds *cmds, char **argv, char **envp)
{
	if (pipe(cmds->fd) == -1)
		ft_error(cmds);
	cmds->id = fork();
	if (cmds->id == 0)
	{
		cmds->id2 = fork();
		if (cmds->id2 == 0)
			ft_gchild1_process(cmds, argv, envp);
		else
			ft_gchild2_process(cmds, argv, envp);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_cmds	cmds;

	if (argc != 5)
		ft_error_check(1);
	cmds.args1 = ft_split(argv[2], ' ');
	cmds.args2 = ft_split(argv[3], ' ');
	ft_check_args(&cmds);
	cmds.name1 = cmds.args1[0];
	cmds.name2 = cmds.args2[0];
	cmds.path1 = ft_path_find(cmds.name1, envp);
	cmds.path2 = ft_path_find(cmds.name2, envp);
	ft_pipex(&cmds, argv, envp);
	ft_full_free(&cmds);
}

// test:  infile.txt "grep this" "wc -l" outfile.txt
// test shell: < infile.txt grep this | wc -l > outfile.txt

// compile with: gcc *.c libft/*.c ft_printf/*.c -o pipex
