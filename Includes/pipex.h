#ifndef PIPEX_H
# define PIPEX_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "libft.h"
#include "ft_printf.h"

typedef struct
{
	char	*path1;
	char	*path2;
	char	*name1;
	char	*name2;
	char	**args1;
	char	**args2;
	int 	id;
	int		fd[2];
}			cmds;

void	ft_freemem(char **arr);
void 	ft_free_arg(char **cmd1_args);

// Input formating

char	*ft_path_cmp(char **arr, char *cmd_mod);
char	*ft_path_find(char *cmd1, char **envp);
char	**ft_extract_args(char *str, char *cmd_name);
char *ft_extract_name(char *str);


void ft_error(int key);



#endif
