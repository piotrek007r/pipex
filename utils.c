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

void ft_error(int key)
{
	if (key == 1)
		ft_printf("Error! Unable to connect with pipe\n");
	if (key == 2)
		ft_printf("Error! Can't open from input file\n");
	if (key == 3)
		ft_printf("Error! Unable to open new fd\n");
	if (key == 2)
		ft_printf("Error! Can't open from output file fd\n");
	exit(1);
}