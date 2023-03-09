/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrank <lfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:33:22 by lfrank            #+#    #+#             */
/*   Updated: 2023/02/01 10:49:59 by lfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define E_ARG "Wrong number of arguments or environ variables are empty.\n"
# define E_PIPE "Pipe error occurred.\n"
# define E_FORK "Fork could not create a child process.\n"
# define E_OPENO "Can't open the outfile.\n"
# define E_OPENI "Can't open the infile.\n"
# define E_EXECVE "Execve failed.\n"
# define E_CMD "Command not found.\n"
# define E_ENVP "Error occurred while duplicating environ variable PATH.\n"
# define E_ENVPATH "Can't find environ variable PATH.\n"

#endif