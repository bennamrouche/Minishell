/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:47:47 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/09 01:05:44 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../00.Include/libft.h"

static int	w_part(const char *set, const char str)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == str)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		mlawl;
	int		finallen;
	int		mlakhr;

	if (!s1 || !set)
		return (NULL);
	mlawl = 0;
	mlakhr = ft_strlen(s1);
	while (s1[mlawl] && w_part(set, s1[mlawl]))
		mlawl++;
	while (mlakhr > 0 && w_part(set, s1[mlakhr - 1]))
		mlakhr--;
	finallen = (mlakhr - mlawl);
	return (ft_substr(s1, mlawl, finallen));
}
