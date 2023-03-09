/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrank <lfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:33:35 by lfrank            #+#    #+#             */
/*   Updated: 2023/02/01 13:53:13 by lfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* 
strdup of the env_path for security reasons 
(we don't want to modify the real path)
 */

char	**ft_get_path(char **envp)
{
	char	*envp_path;
	char	**path_parts;
	int		i;

	envp_path = NULL;
	path_parts = NULL;
	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH", ft_strlen(envp[i])))
		{
			envp_path = ft_strdup(envp[i]);
			if (!envp_path)
				ft_error_message(E_ENVP, "Errno", 1);
			break ;
		}
		i++;
	}
	if (!envp_path)
		ft_error_message(E_ENVPATH, "Errno", 1);
	path_parts = ft_split(envp_path, ':');
	free(envp_path);
	return (path_parts);
}

/* 
if execve fails, we free and we try a new path
validation of the cmd: 
access checks every path in the envp_path if we get access 
and modification permission.
Upon successful completion, the value 0 is returned; 
otherwise the value -1 is returned and the global variable 
errno is set to indicate the error.
 */

char	*ft_get_cmd_path(char **envp, char *cmd_part)
{
	char	**path_parts;
	char	*check_path;
	char	*cmd;
	int		i;

	i = 0;
	if (access(cmd_part, F_OK | X_OK) == 0)
		return (cmd_part);
	path_parts = ft_get_path(envp);
	cmd = ft_strjoin("/", cmd_part);
	while (path_parts[i])
	{
		check_path = ft_strjoin(path_parts[i], cmd);
		if (access(check_path, F_OK | X_OK) == 0)
			break ;
		free (check_path);
		check_path = NULL;
		i++;
	}
	i = -1;
	while (path_parts[++i])
		free(path_parts[i]);
	free(path_parts);
	free (cmd);
	return (check_path);
}
