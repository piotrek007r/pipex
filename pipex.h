/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruszkie <pruszkie@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:56:54 by pruszkie          #+#    #+#             */
/*   Updated: 2024/05/18 13:58:14 by pruszkie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>

typedef struct t_cmds
{
	char	*path1;
	char	*path2;
	char	*name1;
	char	*name2;
	char	**args1;
	char	**args2;
	int		id;
	int		id2;
	int		fd[2];
}			t_cmds;

// main

void		ft_gchild1_process(t_cmds *cmds, char **argv, char **envp);
void		ft_gchild2_process(t_cmds *cmds, char **argv, char **envp);
void		ft_pipex(t_cmds *cmds, char **argv, char **envp);

// Input formating

char		*ft_path_cmp(char **arr, char *cmd_mod);
char		*ft_path_find(char *cmd1, char **envp);

// free

void		ft_free_arg(char **cmd1_args);
void		ft_freemem(char **arr);
void		ft_full_free(t_cmds *cmds);

// error

void		ft_check_args(t_cmds *cmds);
void		ft_error_check(int key);
void		ft_error(t_cmds *cmds);

#endif
