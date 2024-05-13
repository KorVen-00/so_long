/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abb <mben-abb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 04:11:35 by mben-abb          #+#    #+#             */
/*   Updated: 2024/03/27 01:09:56 by mben-abb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		s1_size;
	int		i;
	char	*str;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_size = ft_strlen(s1);
	str = malloc((s1_size + ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
		str[s1_size++] = s2[i++];
	str[s1_size] = '\0';
	free(s1);
	s1 = NULL;
	return (str);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;
	unsigned int	end;
	size_t			j;

	i = start;
	j = 0;
	if (s == NULL)
		return (NULL);
	end = ft_strlen(s);
	if (start >= ft_strlen(s))
		return (NULL);
	if (ft_strlen(s + start) <= len)
		len = ft_strlen(s) - start;
	substr = malloc((len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	while (j < len)
	{
		substr[j] = ((char *)s)[i];
		i++;
		j++;
	}
	substr[j] = '\0';
	return (substr);
}

char	*ft_strdup(char *str)
{
	char	*str1;
	int		i;

	i = 0;
	str1 = malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!str1)
		return (NULL);
	while (str[i])
	{
		str1[i] = str[i];
		i++;
	}
	str1[i] = '\0';
	return (str1);
}

char	*ft_strchr(char *str, int c)
{
	size_t	i;

	i = 0;
	while (i <= ft_strlen(str))
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}
