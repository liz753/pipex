/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrank <lfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:33:47 by lfrank            #+#    #+#             */
/*   Updated: 2023/02/01 13:43:10 by lfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../libs/libft/libft.h"
# include "error.h"

# define TRUE 1
# define FALSE 0

char	**ft_get_path(char **envp);
char	*ft_get_cmd_path(char **envp, char *cmd);
void	ft_child1_process(char **argv, char **envp, int *fd);
void	ft_child2_process(char **argv, char **envp, int *fd);
void	ft_error_message(char *str, char *message, int error);
void	ft_run_command(char *cmd1, char **envp);
void	ft_close_fd(int *fd);

#endif