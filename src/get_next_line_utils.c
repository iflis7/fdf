/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadi <hsaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:21:18 by hsaadi            #+#    #+#             */
/*   Updated: 2022/07/17 10:28:56 by hsaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"
#include "../include/libft/libft.h"

int	ft_chrstr(char *str, int c)
{
	if (!str)
		return (0);
	if (c == '\0')
		return (1);
	while (*str)
		if (*(str++) == (char)c)
			return (1);
	return (0);
}

char	*ft_strjoinning(char *s1, char *s2)
{
	char	*str;
	size_t	i;

	if (!s1)
		s1 = ft_calloc(sizeof(char), 1);
	if (!s1 || !s2)
		return (NULL);
	str = ft_calloc(sizeof(char), (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[ft_strlen(s1) + i] = s2[i];
		i++;
	}
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}
