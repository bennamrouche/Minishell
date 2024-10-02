/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 23:53:56 by reben-ha          #+#    #+#             */
/*   Updated: 2023/04/12 01:50:42 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../00.Include/minishell.h"

static char	*generator_tmp(void)
{
	char		*gen_tmp;
	char		*tmp;
	int			*num;
	int 		fd;

	num = malloc(4);
	fd = read(open("/dev/urandom", O_RDONLY), num, 4);
	tmp = ft_itoa(*num);
	close(fd);
	gen_tmp = ft_strjoin("/tmp/tmp-", tmp);
	return (free(num), free(tmp), gen_tmp);
}

static void	ft_read_tmp(char *tmp_file, char *limiter)
{
	char	*str;
	int		fd_tmp;

	fd_tmp = open(tmp_file, O_RDWR | O_TRUNC | O_CREAT, 0600);
	ft_error(fd_tmp, 1);
	while (1)
	{
		str = readline("Heredoc > ");
		if (!str || ft_strcmp(str, limiter) == 0)
			break ;
		ft_printf(fd_tmp, "%s\n", str);
		free(str);
	}
	free(str);
	close(fd_tmp);
}

static char	*here_doc(char *delimiter)
{
	char	*tmp_file;

	tmp_file = generator_tmp();
	ft_read_tmp(tmp_file, delimiter);
	if (g_pub.is_sigset)
		unlink(tmp_file);
	return (tmp_file);
}

static void	change_value(t_list *lst, char *new_value)
{
	char	*tmp;

	tmp = lst->value;
	lst->value = new_value;
	free(tmp);
}

void	run_here_doc(t_tree *tree)
{
	t_list	*lst;
	char	*tmp_file;

	if (!tree)
		return ;
	run_here_doc(tree->left);
	run_here_doc(tree->right);
	if (!tree->redirect_mode)
		return ;
	tree->redirect_mode = concater_heredoc(tree->redirect_mode);
	lst = tree->redirect_mode;
	while (lst && !g_pub.is_sigset)
	{
		if (lst->type == TK_HERE_DOC)
		{
			tmp_file = here_doc(lst->next->value);
			change_value(lst->next, tmp_file);
		}
		lst = lst->next;
	}
}
