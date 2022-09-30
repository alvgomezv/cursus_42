/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:18:13 by alvgomez          #+#    #+#             */
/*   Updated: 2022/09/30 13:28:29 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static int	word_count(char const *s, char c)
{
	int	word_count;
	int	i;

	word_count = 0;
	i = 0;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			word_count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (word_count);
}

static char	*fill_array(char *s, char c)
{
	int		i;
	int		length;
	char	*str;

	i = 0;
	length = 0;
	while (s[length] != c && s[length])
		length++;
	str = (char *)malloc((length + 1) * sizeof(char));
	if (!str)
		return (0);
	while (s[i] != c && s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_free(char **str, int i)
{
	while (i >= 0)
	{
		free(str[i]);
		str[i] = 0;
		i--;
	}
	free(str);
	str = 0;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;

	i = 0;
	str = (char **)malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!str)
		return (0);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			str[i] = fill_array((char *)s, c);
			if (!str[i])
				return (ft_free(str, i));
			i++;
			while (*s != c && *s)
				s++;
		}
	}
	str[i] = 0;
	return (str);
}

/*int main(void)
{
	char **str;
	int i;
	
	i = 0;
	str = ft_split("hola", ' ');
	while (i < 9)
	{
		printf("%s\n", str[i]);
		i++;
	}
}*/

/*int main(void)
{
    char **tabstr;
	int i;
	
	i = 0;
	if (!(tabstr = ft_split("lorem ipsum dolor sit amet, 
	consectetur adipiscing elit. Sed non risus. Suspendisse", ' ')))
        printf("NULL");
    else
    {
        while (tabstr[i] != NULL)
        {
            printf("%s\n", tabstr[i]);
            i++;
        }
    }
}*/