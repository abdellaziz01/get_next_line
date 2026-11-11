/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-o <abdait-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 13:48:11 by abdait-o          #+#    #+#             */
/*   Updated: 2026/11/11 17:32:36 by abdait-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

 
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
ssize_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*read_file(int fd);
ssize_t	check(char *str);
ssize_t	return_start(char *temp);

#endif
