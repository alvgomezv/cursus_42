/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:08:11 by alvgomez          #+#    #+#             */
/*   Updated: 2023/01/23 19:15:28 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr_gnl(char *s, int start, int len)
{
	int		i;
	char	*str1;	

	i = 0;
	if (!s || len <= 0)
		return (0);
	if (start >= ft_strlen_gnl(s))
		return (0);
	if ((start + len) >= ft_strlen_gnl(s))
		str1 = (char *)malloc((ft_strlen_gnl(s) - start + 1) * sizeof(char));
	else
		str1 = (char *)malloc((len + 1) * sizeof(char));
	if (!str1)
		return (0);
	while (s[start] && i < len)
	{
		str1[i] = s[start];
		i++;
		start++;
	}
	str1[i] = '\0';
	return (str1);
}

int	ft_strlen_gnl(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

static char	*aux_strjoin(char *s1, char *s2, int a, int b)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc((b + 1) * sizeof(char));
	if (str == 0)
		return (0);
	while (i < a)
	{
		str[i] = s1[i];
		i++;
	}
	a = 0;
	while (i < b)
	{
		str[i] = s2[a];
		i++;
		a++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		a;
	int		b;
	char	*str;

	a = ft_strlen_gnl(s1);
	b = a + ft_strlen_gnl(s2);
	str = aux_strjoin(s1, s2, a, b);
	free (s1);
	return (str);
}

char	*ft_strchr_gnl(char *s, int c)
{
	char	*str;
	char	ch;
	int		len;
	int		i;

	if (s == NULL)
		return (0);
	len = ft_strlen_gnl(s) + 1;
	i = 0;
	str = (char *)s;
	ch = (char) c;
	while (i < len)
	{
		if (str[i] == ch)
			return (&str[i]);
		i++;
	}
	if (ch == '\0')
		return (&str[i]);
	return (NULL);
}
