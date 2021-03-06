/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chandsom <chandsom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 22:12:08 by chandsom          #+#    #+#             */
/*   Updated: 2021/01/23 05:35:54 by chandsom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	size_t count;

	count = 0;
	while (s[count])
	{
		if (s[count] == c)
			return (&(s[count]));
		count++;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*dst;
	size_t			i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	dst = (char*)malloc(sizeof(*dst) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dst)
		return (NULL);
	while (*s1 != '\0')
		dst[i++] = *s1++;
	while (*s2 != '\0')
		dst[i++] = *s2++;
	dst[i] = '\0';
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dst;

	i = 0;
	if (!s1)
		return (NULL);
	dst = (char *)malloc(sizeof(char) * (ft_strlen((char *)s1) + 1));
	if (!(dst))
		return (NULL);
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
