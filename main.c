#include "Includes/ft_printf.h"
#include "Includes/libft.h"
#include "Includes/pipex.h"
#include <stdio.h>

char	*ft_path_cmp(char **arr)
{
	char	*valid_path;
	char	*prog;
	char	*temp;
	int		counter;

	prog = "/ls";
	counter = 0;
	while (arr[counter])
	{
		temp = ft_strjoin(arr[counter], prog);
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
    char    *temp;
    char    *cmd_mod;

    temp = ft_strdup("/");
    cmd_mod = ft_strjoin(temp, cmd1);
    free(temp);
	while (*envp)
	{
		var_PATH = ft_strnstr(*envp, "PATH", ft_strlen(*envp));
		if (var_PATH)
		{
			arr = ft_split(var_PATH, ':');
            temp = ft_path_cmp(arr);
			ft_freemem(arr);
		}
		envp++;
	}
    valid_path = ft_strjoin(temp, cmd_mod);
    free(temp);
    free(cmd_mod);
	return (valid_path);
}

int	main(int argc, char **argv, char **envp)
{
	char *cmd1_path;
	char *cmd2_path;

    int i;

    i = 1;
    while(argc > i)
    {
        // printf("%s\n", argv[i]);
        i++;
    }

	cmd1_path = ft_path_find(argv[2], envp);
	cmd2_path = ft_path_find(argv[3], envp);

	printf("path: %s\n", cmd1_path);
	printf("path: %s\n", cmd2_path);
    free(cmd1_path);
    free(cmd2_path);
}

// test:  infile "ls -l" "wc -l" outfile