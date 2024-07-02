/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qacjl <qacjl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:57:56 by quenalla          #+#    #+#             */
/*   Updated: 2024/07/02 15:52:32 by qacjl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"


static char	*ft_set_line(char *line_buffer)
{
	char	*res;
	ssize_t	i;

	i = 0;
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	if (line_buffer[i] == 0 || line_buffer[1] == 0)
		return (NULL);
	res = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - i);
	if (!(res))
	{
		free(res);
		res = NULL;
	}
	line_buffer[i + 1] = '\0';
	return (res);
}

static char	*ft_line(int fd, char *res, char *buffer)
{
	ssize_t	byte_read;
	char	*tmp;

	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(res);
			return (NULL);
		}
		else if (byte_read == 0)
			break;
		buffer[byte_read] = '\0';
		if (!(res))
			res = ft_strdup("");
		tmp = res;
		res = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break;
	}
	return (res);
}

char	*get_next_line(int fd)
{
	static char		*res;
	char			*str;
	char			*buffer;

	if(fd < 0 || MAX_FD < fd || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!(buffer))
		return (NULL);
	str = ft_line(fd, res, buffer);
	free(buffer);
	buffer = NULL;
	if (!(str))
		return (NULL);
	res = ft_set_line(ft_line);
	return (str);
}
