/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrank <lfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:45:49 by lfrank            #+#    #+#             */
/*   Updated: 2023/02/01 11:14:02 by lfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* condition if len is equal to 0,
	it returns the string from start until the end */

char	*ft_modsubstr(char *s, unsigned int start, size_t len)
{
	char	*str;

	if (ft_strlen(s) == 0)
		return (NULL);
	if (start > ft_strlen(s))
	{
		len = 0;
		start = 0;
	}
	if (start + len > ft_strlen(s) || len == 0)
		len = ft_strlen(s) - start;
	if (len > ft_strlen(s))
		len = ft_strlen(s + start);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, (s + start), len + 1);
	return (str);
}

char	*ft_read_and_stash(char *stash, int fd, int *nbrc)
{
	char	*buf;
	char	*new_stash;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (stash);
	*nbrc = read(fd, buf, BUFFER_SIZE);
	if (*nbrc == -1)
		new_stash = NULL;
	else if (*nbrc > 0)
	{
		buf[*nbrc] = '\0';
		new_stash = ft_strjoin_gnl(stash, buf);
	}
	else
	{
		new_stash = ft_strjoin_gnl(stash, "");
	}
	free (buf);
	return (new_stash);
}

char	*ft_get_and_free_stash(char **stash, int len, int set_stash_null)
{
	char	*line;

	line = ft_modsubstr(*stash, 0, len);
	free(*stash);
	if (set_stash_null)
		*stash = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	int			line_len;
	int			nbrc;
	char		*old_stash;

	nbrc = 0;
	while (fd >= 0 && BUFFER_SIZE > 0 && nbrc >= 0)
	{
		old_stash = stash;
		if (ft_strchr(stash, '\n'))
		{
			line_len = ft_strlen_n(stash) + 1;
			stash = ft_modsubstr(old_stash, line_len, 0);
			return (ft_get_and_free_stash(&old_stash, line_len, 0));
		}
		else
		{
			stash = ft_read_and_stash(old_stash, fd, &nbrc);
			free(old_stash);
			if (nbrc == 0)
				return (ft_get_and_free_stash(&stash, 0, 1));
		}
	}
	return (NULL);
}
