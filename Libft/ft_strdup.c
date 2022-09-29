/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:59:36 by alvgomez          #+#    #+#             */
/*   Updated: 2022/09/21 14:11:29 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	i = 0;
	while (s1[i] != '\0')
		i++;
	s2 = (char *)malloc((i + 1) * sizeof(char));
	if (s2 != 0)
	{
		i = 0;
		while (s1[i] != '\0')
		{
			s2[i] = s1[i];
			i++;
		}
		s2[i] = '\0';
		return (s2);
	}
	return (0);
}

/*int main(void)
{
    char *path1;
	char *path2;
    char *temp = "hola";

    path1 = strdup(temp);
	path2 = ft_strdup(temp);
    printf("%s\n", path1);
	printf("%s\n", path2);
    free(path1);
	free(path2);

	return (0);
}*/