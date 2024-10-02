/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:20:26 by ebennamr          #+#    #+#             */
/*   Updated: 2023/04/09 01:05:13 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../00.Include/minishell.h"

void	add_to_env(char *content)
{
	int		env_len;
	char	**tmp;
	int		i;

	i = 0;
	tmp = g_pub.env;
	env_len = (int)ft_matlen(g_pub.env);
	g_pub.env = malloc(sizeof(char *) * (env_len + 2));
	ft_error_str(g_pub.env, 1);
	while (i < env_len)
	{
		g_pub.env[i] = tmp[i];
		i++;
	}
	g_pub.env[i] = content;
	g_pub.env[i + 1] = NULL;
	free(tmp);
}

void	set_shlvl(void)
{
	char	*old_value;
	char	*new_value;
	int		value;

	old_value = expand_env("SHLVL");
	new_value = NULL;
	if (old_value == NULL)
		export_to_env("SHLVL", "1", OPT_CREAT);
	else
	{
		value = ft_atoi(old_value);
		if (value >= 999)
			export_to_env("SHLVL", "1", OPT_CREAT);
		else if (value < 0)
			export_to_env("SHLVL", "0", OPT_CREAT);
		else
		{
			new_value = ft_itoa(value + 1);
			ft_error_str(new_value, 1);
			export_to_env("SHLVL", new_value, OPT_CREAT);
		}
	}
	free(old_value);
	free(new_value);
}

void	fill_key_value_opt(char *arg, char **key, char **value, int *opt)
{
	int	index;

	index = indexofchar(arg, '=');
	if (index >= 1 && arg[index - 1] == '+')
	{
		*key = ft_substr(arg, 0, index - 1);
		*value = ft_substr(arg, index + 1, ft_strlen(&arg[index + 1]));
		*opt = OPT_APPEND;
	}
	else
	{
		*key = ft_substr(arg, 0, index);
		*value = ft_substr(arg, index + 1, ft_strlen(&arg[index + 1]));
		*opt = OPT_CREAT;
	}
}
