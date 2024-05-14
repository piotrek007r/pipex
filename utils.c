#include "Includes/pipex.h"


void	ft_freemem(char **arr)
{
    int j;

    j = 0;
	while (arr[j])
	{
		free(arr[j]);
		j++;
	}
	free(arr);
}

void ft_free_arg(char **cmd1_args)
{
	int counter;

	counter = 0;
	while(cmd1_args[counter])
	{
		free(cmd1_args[counter]);
		counter++;
	}
}

// char	*ft_path_cmp(char **arr)
// {
// 	int		counter;
// 	char	*valid_path;
// 	char	*prog;
// 	char	*temp;

// 	counter = 0;
// 	while (arr[counter])
// 	{
// 		temp = ft_strjoin(arr[counter], prog);
// 		if (access(temp, X_OK) == 0)
// 		{
// 			valid_path = temp;
// 			break ;
// 		}
// 		counter++;
// 		free(temp);
// 	}
//     return (valid_path);
// }

// char	*ft_path_find(char **envp)
// {
// 	int		counter;
// 	char	*valid_path;
// 	char	*var_PATH;
// 	char	**arr;

// 	counter = 0;
// 	while (envp[counter])
// 	{
// 		var_PATH = ft_strnstr(envp[counter], "PATH", ft_strlen(envp[counter]));
// 		if (var_PATH)
// 		{
// 			arr = ft_split(var_PATH, ':');
//             valid_path = ft_path_cmp(arr);
// 			ft_freemem(arr);

// 		}
// 		counter++;
// 	}
// 	return (valid_path);
// }