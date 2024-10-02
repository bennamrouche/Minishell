/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:51:26 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/10 22:05:49 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../00.Include/minishell.h"

static char	*get_prompt_ex_st(void)
{
	char	*status;
	char	*tmp;

	status = NULL;
	if (g_pub.exit_status == 130)
		return (ft_strjoin(RED, "SIGINT"));
	else if (g_pub.exit_status == 131)
		return (ft_strjoin(RED, "SIGQUIT"));
	else if (g_pub.exit_status == 137)
		return (ft_strjoin(RED, "SIGKILL"));
	else if (g_pub.exit_status == 143)
		return (ft_strjoin(RED, "SIGTERM"));
	else if (g_pub.exit_status == 0)
		return (ft_strjoin(WHITE, "0"));
	else
	{
		status = ft_itoa(g_pub.exit_status);
		tmp = ft_strjoin(RED, status);
		return (free(status), tmp);
	}
}

char	*get_pwd(void)
{
	char	cwd[PATH_MAX];

	getcwd(cwd, sizeof(cwd));
	ft_error_str(cwd, 1);
	return (ft_strdup(cwd));
}

char	*get_prompt(char *pwd)
{
	char	*prompt;
	char	*tmp;

	if (strcmp(pwd, "/") == 0)
	{
		free(pwd);
		pwd = strdup("/☣️ ROOT");
	}
	if (ft_strrchr(pwd, '/') != NULL)
	{
		prompt = ft_strjoin_gnl((ft_strjoin(PROMPT_P1,
						ft_strrchr(pwd, '/') + 1)), PROMPT_P2);
		tmp = get_prompt_ex_st();
		prompt = ft_strjoin_gnl(prompt, tmp);
		prompt = ft_strjoin_gnl(prompt, PROMPT_P3);
		return (free(pwd), free(tmp), prompt);
	}
	return (free(pwd), PROMPT);
}

static void	sort_list(t_list *list, int i)
{
	int		len;
	t_list	*head;
	char	*tmp;

	len = ft_lstsize(list);
	while (i < len)
	{
		head = list;
		while (head->next != NULL)
		{
			if (ft_strcmp(head->value, (head->next)->value) > 0)
			{
				tmp = head->next->value;
				head->next->value = head->value;
				head->value = tmp;
			}
				head = head->next;
		}
		i++;
	}
}

t_list	*get_ls(void)
{
	t_list			*list;
	DIR				*op_dir;
	char			*path;
	struct dirent	*ent;

	list = NULL;
	path = get_pwd();
	op_dir = opendir(path);
	ft_error_str(op_dir, 2);
	while (1)
	{
		ent = readdir(op_dir);
		if (ent == NULL)
			break ;
		ft_lstadd_back(&list, ft_lstnew(0, ft_strdup(ent->d_name), NULL));
	}
	closedir(op_dir);
	if (list != NULL)
		sort_list(list, 0);
	return (free(path), free(ent), list);
}
