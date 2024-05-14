/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abb <mben-abb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 01:37:19 by mben-abb          #+#    #+#             */
/*   Updated: 2024/04/09 04:38:33 by mben-abb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>

char				*get_the_line(int fd, char *line);

char				*cut_the_line(char *str);

char				*get_next_line(int fd);

char				*li_chat(char *str);

char				*ft_strjoin(char *s1, char *s2);

char				*ft_substr(char *s, unsigned int start, size_t len);

char				*ft_strdup(char *str);

char				*ft_strchr(char *str, int c);

size_t				ft_strlen(char *str);

#endif
