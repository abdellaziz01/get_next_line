/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-o <abdait-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 15:39:24 by abdait-o          #+#    #+#             */
/*   Updated: 2026/11/13 15:49:22 by abdait-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

  #include "get_next_line_bonus.h"
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
	ssize_t	l1;
	ssize_t	l2;
	char	*res;
	ssize_t	i;
	ssize_t	j;

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
   l_list *exact_node(l_list *head , int fd)
{
	if(!head)
		return NULL;
	while(head)
	{
		if(head -> fd == fd)
			return head;
		head = head -> next;
	}
	return NULL;	
}
  l_list *last_node(l_list *head)
{
	if(!head)
		return NULL;
	while(head -> next != NULL)
		head = head -> next;
	return head;
}
  l_list *add_node(l_list **head, int fd)
{
    l_list *new;
    l_list *last;

    if (!head)
        return NULL;
    new = malloc(sizeof(l_list));
    if (!new)
        return NULL;
    new->fd = fd;
    new->box = NULL;
    new->next = NULL;
    if (!*head)
        *head = new;
    else
    {
        last = last_node(*head);
        last->next = new;
    }
    return new;
}