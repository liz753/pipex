/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_message.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrank <lfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:33:28 by lfrank            #+#    #+#             */
/*   Updated: 2023/02/01 12:51:45 by lfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error_message(char *str, char *message, int error)
{
	if (!str)
		perror("Error with pipex");
	else
	{
		ft_putstr_fd(str, 2);
		perror(message);
	}
	exit(error);
}
