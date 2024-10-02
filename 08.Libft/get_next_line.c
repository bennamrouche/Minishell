/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:32:54 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/09 01:05:44 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../00.Include/libft.h"

static char	*ft_read_join(int fd, char *save_area, int *fail)
{
	char		*buffer;

	buffer = (char *)malloc(BUFFER_SIZE * sizeof(char) + 1);
	ft_error_str(buffer, 1);
	while ((*fail) > 0 && ft_strchr_check(save_area, '\n') == 0)
	{
		(*fail) = read(fd, buffer, BUFFER_SIZE);
		if ((*fail) == -1)
		{
			free(save_area);
			save_area = NULL;
			return (free(buffer), buffer = NULL);
		}
		buffer[(*fail)] = '\0';
		save_area = ft_strjoin_gnl(save_area, buffer);
	}
	free(buffer);
	return (save_area);
}

char	*get_next_line(int fd)
{
	static char	*save_area;
	char		*result;
	char		*temp;
	int			fail;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	fail = 1;
	save_area = ft_read_join(fd, save_area, &fail);
	if (fail == 0 && save_area[0] == '\0')
		return (free(save_area), save_area = NULL);
	else if (fail == 0)
	{
		result = ft_strchr_gnl(save_area, '\n', 3);
		free(save_area);
		save_area = NULL;
	}
	else
	{
		result = ft_strchr_gnl(save_area, '\n', 1);
		temp = save_area;
		save_area = ft_strchr_gnl(save_area, '\n', 2);
		free(temp);
	}
	return (result);
}
