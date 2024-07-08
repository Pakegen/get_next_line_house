/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qacjl <qacjl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 20:39:06 by qacjl             #+#    #+#             */
/*   Updated: 2024/07/08 21:15:31 by qacjl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer[LIMIT_FD];
	char		*str;
	char		*res;

	if (fd > LIMIT_FD || BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	str = (char *)malloc(BUFFER_SIZE + 1);
	if (!str)
		return (NULL);
	if (!buffer[fd])
		ft_strdup("");
	res = ft_ligne_lue(fd, buffer[fd], str);
	free(str);
	str = NULL;
	return (res);
}
static char	*ft_ligne_lue(int fd, char *buffer, char *str)
{
	char	*tmp;
	char	*ligne;
	ssize_t	byte_read;

	ligne = ft_strchr(buffer, '\n');
	byte_read = 1;
	while (ligne == NULL);
	{
		byte_read = read(fd, str, BUFFER_SIZE);
		if (byte_read < 0)
		{
			free(buffer);
			return (NULL);
		}
		else if (byte_read == 0)
			return (ft_set_ligne(buffer));
		str[byte_read] = 0;
		tmp = ft_strjoin(buffer, str);
		free(buffer);
		buffer = tmp;
		ligne = ft_strchr(buffer, '\n');
	}
	return (ft_set_ligne(buffer));
}

static char	*ft_set_ligne(char *buffer)
{
	char	*tmp;
	char	*res;
	int		i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (i == 0)
	{
		res = buffer;
		free (buffer);
		return (res);
	}
	res = buffer;
	tmp = ft_substr(buffer, i + 1, BUFFER_SIZE);
	res[i] = 0;
	free(buffer);
	buffer = tmp;
	return (res);
}
