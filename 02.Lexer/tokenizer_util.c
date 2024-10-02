/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:29:14 by ebennamr          #+#    #+#             */
/*   Updated: 2023/04/10 02:06:04 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../00.Include/minishell.h"

void	skip_wt_sapce(t_list **list, char *line, int *i)
{
	while (line [*i] && (line[*i] == ' ' || line[*i] == '\t'))
		*i += 1;
	add_token(list, TK_WT_SPACE, " ");
	*i -= 1;
}

void	skip_quote(t_list **list, char *line, int *i, char quote)
{
	int	ind_of_quote;

	ind_of_quote = indexofchar(&line[*i + 1], quote);
	if (ind_of_quote < 0)
		add_token(list, TK_OPEN_QUOTE, "'");
	else if (quote == '\'')
		add_token(list, TK_SINGLE_QUOTE, ft_substr(line,*i + 1, ind_of_quote));
	else if (quote == '"')
		add_token(list, TK_DOUBLE_QUOTE, ft_substr(line, *i + 1, ind_of_quote));
	if (ind_of_quote < 0)
	*i = ft_strlen(line) - 1;
	else
	*i += ind_of_quote + 1;
}

static int	check_and(char c1, char c2)
{
	if (c1 == '&' && c2 != '&')
		return (TRUE);
	return (FALSE);
}

void	skip_word(t_list **list, char *line, int *i)
{
	int	count;

	count = 0;
	while (check_and(line[*i], line[*i + 1])
		||indexofchar(SP_CHAR, line[*i]) == -1)
	{
		count++;
		*i += 1;
		if (line[*i] == 0)
			break ;
	}
	add_token(list, TK_WORD, ft_substr(line, *i - count, count));
	*i -= 1;
}
