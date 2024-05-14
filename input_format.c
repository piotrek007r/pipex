#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
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
	char	*var_PATH;
	char	**arr;
	char	*temp;
	char	*cmd_mod;

	valid_path = NULL;
	temp = ft_strdup("/");
	cmd_mod = ft_strjoin(temp, cmd1);
	free(temp);
	while (*envp)
	{
		var_PATH = ft_strnstr(*envp, "PATH", 4);
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

// char *ft_extract_name(char *str)
// {
// 	int counter;
// 	char *cmd_name;
// 	counter = 0;
// 	while (ft_isalpha(str[counter]))
// 		counter++;
// 	cmd_name = malloc(sizeof(char) * counter + 1);
// 	ft_strlcpy(cmd_name, str, counter + 1);
// 	return (cmd_name);
// }

// char	**ft_extract_args(char *str, char *cmd_path)
// {
// 	int arg_count;
// 	int counter;
// 	char **args_list;
// 	int args_start;

// 	counter = 0;
// 	arg_count = 1;
// 	while (str[counter++] != '-' && str[counter])
// 		args_start = counter + 1;
// 	while (str[counter])
// 	{
// 		if (ft_isalpha(str[counter]))
// 			arg_count++;
// 		counter++;
// 	}
// 	args_list = malloc(sizeof(char *) * (ft_strlen(cmd_path) + (arg_count + 1) + 1));
// 	args_list[0] =  cmd_path;
// 	counter = 1;
// 	while(arg_count > counter)
// 	{
// 		if (ft_isalpha(str[args_start]))
// 		{
// 			args_list[counter] = ft_substr(str, args_start, 1);
// 			counter++;
// 		}
// 		args_start++;
// 	}
// 	args_list[arg_count] = NULL;
// 	return (args_list);
// }

