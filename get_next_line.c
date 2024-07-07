/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oldget_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qacjl <qacjl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:28:07 by quenalla          #+#    #+#             */
/*   Updated: 2024/07/05 16:18:59 by qacjl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

void	ft_free_NULL(char **ptr)
{
	if (*ptr != NULL)
	{
		free(*ptr);
		ptr = NULL;
	}
}

char	*ft_join(int position, char **buffer)
{
	char	*res;
	char	*tmp;

	tmp = NULL;
	if (position <= 0)
	{
		if (**buffer == '\0')
		{
			free(*buffer);
			*buffer = NULL;
			return (NULL);
		}
		res = *buffer;
		*buffer = NULL;
		return (res);
	}
	tmp = ft_substr(*buffer, position, BUFFER_SIZE);
	res = *buffer;
	res[position] = 0;
	*buffer = tmp;
	return (res);
}

char	*ft_read(int fd, char **buffer, char *str)
{
	ssize_t	byte_read;
	char	*tmp;
	char	*check;

	check = ft_strchr(*buffer, '\n');
	byte_read = 0;
	while (check == NULL)
	{
		byte_read = read(fd, str, BUFFER_SIZE);
		if (byte_read <= 0)
			return (ft_join(byte_read, buffer));
		str[byte_read] = 0;
		tmp = ft_strjoin(*buffer, str);
		ft_free_NULL(buffer);
		*buffer = tmp;
		check = ft_strchr(*buffer, '\n');
	}
	return (ft_join(check - *buffer + 1, buffer));
}

char	*get_next_line(int fd)
{
	static char	*buffer[LIMIT_FD];
	char		*res;
	char		*str;

	if (fd < 0 || fd > LIMIT_FD || BUFFER_SIZE <= 0)
		return (NULL);
	str = (char *)malloc(BUFFER_SIZE + 1);
	if (!(str))
		return (NULL);
	if (!(buffer[fd]))
		buffer[fd] = ft_strdup("");
	res = ft_read(fd, &buffer[fd], str);
	ft_free_NULL(&str);
	return (res);
}

