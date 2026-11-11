/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-o <abdait-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 13:43:41 by abdait-o          #+#    #+#             */
/*   Updated: 2026/11/11 17:32:29 by abdait-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 
#include "get_next_line.h"

static char	*return_str(char *temp, int fd)
{
	char	*new_temp = NULL;
	char	*s1;

	while (check(temp) == -1)
	{
		 
		s1 = read_file(fd);
		if (!s1)
			break ;
		new_temp = temp;
		temp = ft_strjoin(new_temp, s1);
		free(s1);
		if (!temp)
		{
			free(new_temp);
			return (NULL);
		}
		free(new_temp);
	}
	return (temp);
}

char	*if_null(char *str)
{
	free(str);
	str = NULL;
	return (NULL);
}

char	*copy_to1(char *s1, char *s2, ssize_t start)
{
	ssize_t	i;

	i = 0;
	while (i <= start)
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

char	*copy_to2(char *s1, char *s2, ssize_t start)
{
	ssize_t	i;
	ssize_t	len;

	len = ft_strlen(s2);
	i = 0;
	while (i < len - start - 1)
	{
		s1[i] = s2[start + 1 + i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

char	*get_next_line(int fd)
{
	char		*res;
	ssize_t		start;
	static char	*temp = NULL;
	char		*new_temp;

	temp = return_str(temp, fd);
	if (!temp || !temp[0])
		return (if_null(temp));
	start = return_start(temp);
	res = malloc(start + 2);
	if (!res)
		return (if_null(temp));
	res = copy_to1(res, temp, start);
	new_temp = malloc(ft_strlen(temp) - start + 1);
	if (!new_temp)
	{
		free(res);
		return (if_null(temp));
	}
	new_temp = copy_to2(new_temp, temp, start);
	free(temp);
	temp = new_temp;
	return (res);
}
