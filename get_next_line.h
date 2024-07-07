/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qacjl <qacjl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:56:51 by quenalla          #+#    #+#             */
/*   Updated: 2024/07/05 15:30:10 by qacjl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include<unistd.h>
# include<stdio.h>
# include<fcntl.h>
# include<stdlib.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
# endif


#ifndef LIMIT_FD
# define LIMIT_FD 1024
#endif

char	*get_next_line(int fd);

size_t	ft_strlen(char *str);

char	*ft_strchr(const char *s, int c);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_substr(char const *s, unsigned start, size_t len);

char	*ft_strdup(char const *s);

#endif
