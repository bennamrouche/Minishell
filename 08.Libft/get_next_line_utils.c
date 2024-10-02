/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:32:51 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/09 01:05:44 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../00.Include/libft.h"

char	*ft_strchr_gnl(const char *str, int c, int option)
{
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	if (option == 3)
		return ((char *)ft_substr(str, 0, ft_strlen(str)));
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
		{
			if (option == 1)
				return ((char *)ft_substr(str, 0, i + 1));
			if (option == 2)
				return ((char *)ft_substr(str, i + 1,
						(ft_strlen(&str[i + 1]))));
		}
		i++;
	}
	return (NULL);
}

int	ft_strchr_check(const char *str, int c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_substr_gnl(char const *str, unsigned int start, size_t len)
{
	char	*strout;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (!str)
		return (NULL);
	if (len > ft_strlen(str))
		len = ft_strlen(str);
	strout = (char *)malloc(len * sizeof(char) + 1);
	ft_error_str(strout, 1);
	while (str[i] != '\0')
	{
		if (i >= start && j < len)
		{
			strout[j] = str[i];
			j++;
		}
		i++;
	}
	strout[j] = '\0';
	return (strout);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*sjoin;

	if (!s1 && !s2)
		return (NULL);
	if (s1 == NULL)
		return (ft_substr(s2, 0, ft_strlen(s2)));
	if (s2 == NULL)
		return (ft_substr(s1, 0, ft_strlen(s1)));
	sjoin = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	ft_error_str(sjoin, 1);
	i = 0;
	while (s1[i])
	{
		sjoin[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		sjoin[i++] = s2[j++];
	sjoin[i] = '\0';
	free(s1);
	return (sjoin);
}
