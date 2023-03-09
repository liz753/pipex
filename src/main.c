/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrank <lfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:33:42 by lfrank            #+#    #+#             */
/*   Updated: 2023/02/01 13:37:30 by lfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_close_fd(int *fd)
{
	close(fd[0]);
	close(fd[1]);
}

/* 
pid = process identifier 
int fd[2] is an array that will hold two file descriptors;
pipe(fd) call finds the next two available fds and associates each with 
the appropriate end of the created pipe. fd[0] ist the read end and
fd[1] is the write end. 
pid = fork() creates child process that is a clone of the parent;
if pid == 0, then this is the child process;
We use one pid since we wait for the first child to be done before 
we fork again.
We divide the pipex workload on two child processes, while the
parent waits for the job to be done and supervise the children’s status.
The wait() function suspends execution of its calling process until
stat_loc information is available for a terminated child process.If pid is 0, 
the call waits for any child process in the process group 
of the caller. 
 */

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			ft_error_message(E_PIPE, "Errno", 1);
		pid = fork();
		if (pid == -1)
			ft_error_message(E_FORK, "Errno", 1);
		else if (pid == 0)
			ft_child1_process(argv, envp, fd);
		else
		{
			wait(NULL);
			pid = fork();
			if (pid == 0)
				ft_child2_process(argv, envp, fd);
		}
		ft_close_fd(fd);
	}
	else if (argc != 5 || envp[0][0] == '\n')
		ft_error_message(E_ARG, "Errno", 1);
	return (0);
}
