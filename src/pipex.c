/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrank <lfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:33:45 by lfrank            #+#    #+#             */
/*   Updated: 2023/02/01 13:52:15 by lfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* 
create argument vector
execve runs command given by path, returns if something went wrong, exits
if everything went well. 
If execve() does return to the calling process, an error has occurred; the
return value will be -1 and the global variable errno is set to indicate
the error. If everything goes well, it doesn't return and no code will be
executed afterwards.
 */

void	ft_run_command(char *cmd1, char **envp)
{
	char	**cmd_parts;
	char	*path;
	int		i;

	path = NULL;
	cmd_parts = ft_split(cmd1, ' ');
	path = ft_get_cmd_path(envp, cmd_parts[0]);
	if (!path || !cmd_parts)
	{
		i = -1;
		while (cmd_parts[++i])
			free (cmd_parts[i]);
		free (cmd_parts);
		ft_error_message(E_CMD, "Errno", 1);
	}
	execve(path, cmd_parts, envp);
	ft_error_message(E_EXECVE, "Errno", 1);
}

/* 
dup2(fd[1], STDOUT_FILENO): what we normally would write on the standard output
e.g. the terminal, is instead put in the fd[1] (which is the write end of the 
pipe)
dup2(file1, STDIN_FILENO): duplicates the file descriptor file1 to the 
standard input file descriptor --> what we receive from the standard input, e.g.
the keyboard, is instead read from file1 (redirection). 
Then we close file1 which is no longer needed in child since stdin is a copy 
(the content of the file is now stored in stdin);
close fd[0] because fd is unused and fd[1] since it's no longer needed.

dup2() will first close its second parameter, which is a file descriptor, 
if necessary. Thus, stdin (which is open by default) is first closed, 
which will remove its reference to the default keyboard file.
Then the stdin of the child2 process will be able to receive data via fd[0] 
instead of from the keyboard.
*/

void	ft_child1_process(char **argv, char **envp, int *fd)
{
	int		file1;

	file1 = open(argv[1], O_RDONLY, 0644);
	if (file1 == -1)
		ft_error_message(E_OPENI, "Errno", 0);
	dup2(fd[1], STDOUT_FILENO);
	dup2(file1, STDIN_FILENO);
	close(file1);
	ft_close_fd(fd);
	ft_run_command(argv[2], envp);
}

/* 
O_CREAT: The file is created if it does not exist.
O_TRUNC: if the file already exists, it will be overwritten 
(the file will be truncated to length 0)
„0644“ (rw-r—r—) is the file permission mode: 
the owner has read and write permissions, 
while others have only read permissions.
dup2: fds[0] (the read end of pipe) donates its data to stdin
close fd[1] because fd is unused and fds[0] since the data
is in stdin. 
*/

void	ft_child2_process(char **argv, char **envp, int *fd)
{
	int		file2;

	file2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file2 == -1)
		ft_error_message(E_OPENO, "Errno", 1);
	dup2(fd[0], STDIN_FILENO);
	dup2(file2, STDOUT_FILENO);
	close(file2);
	ft_close_fd(fd);
	ft_run_command(argv[3], envp);
}
