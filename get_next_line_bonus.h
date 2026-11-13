/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-o <abdait-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 13:48:11 by abdait-o          #+#    #+#             */
/*   Updated: 2026/11/13 15:54:32 by abdait-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

 
typedef struct tk_list
{
    int fd;
    char *box;
    struct tk_list *next;
}l_list;

# include <stdlib.h>
# include <unistd.h>
 

char	*get_next_line(int fd);
ssize_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
l_list *exact_node(l_list *head , int fd);
l_list *last_node(l_list *head);
l_list *add_node(l_list **head, int fd);
char	*copy_to1(char *s1, char *s2, ssize_t start);
char	*copy_to2(char *s1, char *s2, ssize_t start);

#endif