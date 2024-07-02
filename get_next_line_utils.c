/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qacjl <qacjl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:57:54 by quenalla          #+#    #+#             */
/*   Updated: 2024/07/02 14:38:39 by qacjl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

static size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return(i);
}

static char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != c)
	{
		if (*str == '\0')
			return (str);
		str++;
	}
	return (str);
}

static char	*ft_strdup(char const *s)
{
	size_t	i;
	char	*dest;

	i = 0;
	dest = (char *)malloc(ft_strlen(s) + 1);
	if (!(s))
		return (NULL);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;
	size_t	k;
	char	*dest;

	len_s1 = ft_strlen((char *)s1);
	len_s2 = ft_strlen((char *)s2);
	i = 0;
	k = 0;
	dest = (char *)malloc(len_s1 + len_s2 + 1);
	if (!(dest))
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[k])
	{
		dest[i + k] = s2[k];
		k++;
	}
	dest[i + k] = '\0';
	return (dest);
}

static char	*ft_substr(char const *s, unsigned start, size_t len)
{
	size_t	len_src;
	size_t	i;
	char	*str;

	len_src = ft_strlen((char *)s);
	i = 0;
	if (!(s))
		return (NULL);
	if (len == 0 || start > len_src)
		str = (char *)malloc(sizeof(char) * 1);
	else if (len > (len_src - start))
		str = (char *)malloc(sizeof(char) * (len_src - start + 1));
	else
		str = (char *)malloc(sizeof(char) * (len + 1));
	if (!(str))
		return (NULL);
	while (i < len && start < len_src)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
