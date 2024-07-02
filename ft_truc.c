/*char	*ft_line(int fd, char *res, char *buffer)
{
	ssize_t	byte_read;
	char	*tmp;
	char	*return_line;

	byte_read = 1;
	tmp = NULL;
	return_line = ft_strchr(str, '\n');
	while(return_line == NULL)
	{
		byte_read = read(fd, str, BUFFER_SIZE);
		if (byte_read <= 0)
			return (strjoin(*buffer, str));
		str[byte_read] = 0;
		tmp = ft_strjoin(*buffer, str);
		ft_free(buffer);
		*buffer = tmp;
		return_line = ft_strchr(*buffer, '\n');
	}
	return (join_line(return_line - *buffer + 1, buffer));
}
*/
