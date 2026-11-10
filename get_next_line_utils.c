/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-o <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 13:56:50 by abdait-o          #+#    #+#             */
/*   Updated: 2026/11/10 13:59:35 by abdait-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	ft_strlen(char *str)
{
	ssize_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		l1;
	int		l2;
	char	*res;
	int		i;
	int		j;

	if (!s1)
		s1 = "";
	if (!s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	res = malloc(l1 + l2 + 1);
	if (!res)
		return (NULL);
	j = 0;
	i = 0;
	while (s1[i])
		res[j++] = s1[i++];
	i = 0;
	while (s2[i])
		res[j++] = s2[i++];
	res[j] = '\0';
	return (res);
}

char	*read_file(int fd)
{
	char	buffer[BUFFER_SIZE];
	ssize_t	y;
	char	*res;
	ssize_t	i;

	y = read(fd, buffer, BUFFER_SIZE);
	if (y <= 0)
		return (NULL);
	res = malloc(y + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < y)
	{
		res[i] = buffer[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

ssize_t	check(char *str)
{
	ssize_t	j;

	if (!str)
		return (-1);
	j = 0;
	while (str[j] && str[j] != '\n')
		j++;
	if (str[j] == '\n')
		return (j);
	return (-1);
}

ssize_t	return_start(char *temp)
{
	ssize_t	start;
	ssize_t	len;

	len = ft_strlen(temp);
	if (check(temp) == -1)
		start = len;
	else
		start = check(temp);
	return (start);
}
