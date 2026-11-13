/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-o <abdait-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 13:43:46 by abdait-o          #+#    #+#             */
/*   Updated: 2026/11/13 16:53:38 by abdait-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

  #include "get_next_line_bonus.h"


static ssize_t	check(char *str)
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
 static char	*read_file(int fd) 
{
	char	*buffer;
	ssize_t	y;

	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	y = read(fd, buffer, BUFFER_SIZE);
	if (y <= 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[y] = '\0';
	return (buffer);
}
static ssize_t	return_start(char *temp)
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

static char	*if_null(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}
char *clear_node(l_list **head , l_list *new)
{
	l_list *current;
	if(*head == new)
	{
		*head = new -> next;
	}
	else
	{
		current = *head;
		while(current && current-> next != new)
			current = current -> next;
		if(current)
			current -> next = new -> next;
	}
	free(new -> box);
	free (new);
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*res;
	ssize_t		start;
	char		*new_temp;
	static  l_list *head = NULL;
	l_list *new;
	if(!exact_node(head , fd))
	{
		new = add_node(&head , fd);
		if(!new)
			return NULL;
	}
	else
		new = exact_node(head , fd);
	new -> box = return_str(new -> box, fd);
	if (!new -> box || !new -> box[0])
		return clear_node(&head , new);
	start = return_start(new -> box);
	res = malloc(start + 2);
	if (!res)
		return (if_null(&new -> box));
	res = copy_to1(res, new -> box, start);
	new_temp = malloc(ft_strlen(new -> box) - start + 1);
	if (!new_temp)
	{
		free(res);
		return (if_null(&new -> box));
	}
	new_temp = copy_to2(new_temp, new -> box, start);
	free(new -> box);
	new -> box = new_temp;
	return (res);
}
 