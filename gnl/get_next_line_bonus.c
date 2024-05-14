/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abb <mben-abb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 04:23:09 by mben-abb          #+#    #+#             */
/*   Updated: 2024/04/09 04:37:43 by mben-abb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_the_line(int fd, char *line)
{
	char	*buffer;
	int		char_readed;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	char_readed = read(fd, buffer, BUFFER_SIZE);
	while (char_readed > 0)
	{
		buffer[char_readed] = '\0';
		if (!line)
			line = ft_strdup(buffer);
		else
			line = ft_strjoin(line, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
		char_readed = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	if (!line)
		return (NULL);
	if (line[0] == '\0')
		return (NULL);
	return (line);
}

char	*cut_the_line(char *str)
{
	int		count;
	char	*line;

	count = 0;
	if (str == NULL)
		return (NULL);
	while (str[count] && str[count] != '\n')
		count++;
	if (str[count] == '\n')
		count++;
	line = ft_substr(str, 0, count);
	if (!line)
		return (NULL);
	return (line);
}

char	*li_chat(char *str)
{
	int		i;
	char	*chyata;
	int		len;

	len = ft_strlen(str);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	chyata = ft_substr(str, i, len - i);
	if (!chyata)
		return (NULL);
	return (chyata);
}

char	*get_next_line(int fd)
{
	static char	*holder[OPEN_MAX];
	char		*line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, "", 0) < 0)
	{
		free(holder[fd]);
		holder[fd] = NULL;
		return (NULL);
	}
	line = get_the_line(fd, holder[fd]);
	if (line == NULL)
		return (NULL);
	holder[fd] = li_chat(line);
	temp = cut_the_line(line);
	free(line);
	line = temp;
	if (!line)
		return (NULL);
	return (line);
}
