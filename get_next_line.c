/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-o <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 13:51:25 by abdait-o          #+#    #+#             */
/*   Updated: 2026/11/10 13:59:17 by abdait-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*return_str(char *temp, int fd)
{
	char	*new_temp;
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

// char *get_next_line(int fd)
// {
//     int i;
//     int len;
//     char *res;
//     int start;
//     static char *temp = NULL;
//     char *new_temp;

//     while(check(temp) == -1)
//     {
//         s1 = read_file(fd);
//         if(!s1)
//             break ;
//         new_temp = temp;
//         temp = ft_strjoin(new_temp , s1);
//          free(s1);
//         if(!temp)
//         {
//             free(new_temp);
//             return (NULL);
//         }
//         free(new_temp);
//     }
//     if (!temp || !temp[0])
//     {
//         free(temp);
//         temp = NULL;
//         return (NULL);
//     }
//     len = ft_strlen(temp);
//     if(check(temp) == -1)
//         start = len;
//     else
//         start = check(temp);
//     res = malloc(start + 2);
//     if(!res)
//     {
//         free(temp);
//         temp = NULL;
//         return (NULL);
//     }
//     i = 0;
//     while(i <= start)
//     {
//         res[i] = temp[i];
//         i++;
//     }
//     res[i] = '\0';
//     new_temp = malloc(len - start + 1);
//     if(!new_temp)
//     {
//         free(res);
//         free(temp);
//         temp = NULL;
//         return (NULL);
//     }
//     i = 0;
//     while(i < len - start - 1)
//     {
//         new_temp[i] = temp[start + 1 + i];
//         i++;
//     }
//     new_temp[i] = '\0';
//     free(temp);
//     temp = new_temp;
//     return (res);
// }
