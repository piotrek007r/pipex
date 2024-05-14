#ifndef PIPEX_H
# define PIPEX_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"
#include "ft_printf.h"

typedef struct
{
	char	*cmd1_path;
	char	*cmd2_path;
	char	*cmd1_name;
	char	*cmd2_name;
	char	**cmd1_args;
	char	**cmd2_args;
    char    *input_path;
    char    *output_path;

}			cmds;

void	ft_freemem(char **arr);
void ft_free_arg(char **cmd1_args);

// Input formating

char	*ft_path_cmp(char **arr, char *cmd_mod);
char	*ft_path_find(char *cmd1, char **envp);
char	**ft_extract_args(char *str, char *cmd_name);
char *ft_extract_name(char *str);





#endif
