#include "Includes/ft_printf.h"
#include "Includes/libft.h"
#include "Includes/pipex.h"
#include <stdio.h>

char	*ft_path_cmp(char **arr, char *cmd_mod)
{
	char	*valid_path;
	char	*temp;
	int		counter;

	counter = 0;
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
	char	*var_PATH;
	char	**arr;
	char	*temp;
	char	*cmd_mod;

	temp = ft_strdup("/");
	cmd_mod = ft_strjoin(temp, cmd1);
	free(temp);
	while (*envp)
	{
		var_PATH = ft_strnstr(*envp, "PATH", ft_strlen(*envp));
		if (var_PATH)
		{
			arr = ft_split(var_PATH, ':');
			valid_path = ft_path_cmp(arr, cmd_mod);
			ft_freemem(arr);
		}
		envp++;
	}
	free(cmd_mod);
	return (valid_path);
}

char	**ft_extract_args(char *str, char *cmd_name)
{
	int arg_count;
	int counter;
	char **args_list;

	counter = 0;
	arg_count = 1;
	while (str[counter] != '-')
		counter++;
	while (str[counter++])
		if (ft_isalpha(str[counter]))
		{
			arg_count++;
		}
	args_list = malloc(ft_strlen(cmd_name) + (arg_count + 1) + 1);
	args_list[0] =  cmd_name;
	counter = 1;
	while (counter > args_list)
	{
		args_list[counter] = ft_strdup() // here i finished
	}
	printf("%d\n", arg_count);
}

char *ft_extract_name(char *str)
{
	int counter;
	char *cmd_name;

	counter = 0;
	while (ft_isalpha(str[counter]))
		counter++;
	cmd_name = malloc(sizeof(char) * counter + 1);
	ft_strlcpy(cmd_name, str, counter);
	return (cmd_name);
}

int	main(int argc, char **argv, char **envp)
{
	char	*cmd1_path;
	char	*cmd2_path;
	char	*cmd1_name;
	char	*cmd2_name;	
	char	**cmd1_args;
	char	**cmd2_args;

	cmd1_name = ft_extract_name(argv[2]);
	cmd1_path = ft_path_find(cmd1_name, envp);
	cmd2_path = ft_path_find(argv[3], envp);
	cmd1_args = ft_extract_args(argv[2], cmd1_name);
	printf("path: %s\n", cmd1_path);
	// printf("path: %s\n", cmd2_path);
	free(cmd1_name);
	// free(cmd2_name);
	free(cmd1_path);
	free(cmd2_path);
}

// test:  infile "ls" "wc" outfile