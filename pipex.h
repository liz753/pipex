
#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "libs/libft/libft.h"

void	child(char **argv, char **envp, int *fd);
void	parent(char **argv, char **envp, int *fd);

#endif