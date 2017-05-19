/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 19:29:44 by maissa-b          #+#    #+#             */
/*   Updated: 2016/02/04 19:29:45 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell.h>

static	void	sig_handler(int key)
{
	kill(SIGINT, key);
}

static	void	sig_catch(void)
{
	signal(2, sig_handler);
}

static	void	check_cmd_type(t_env *e, char *cmd)
{
	t_elem	*elem;
	char	**cmd2;

	elem = NULL;
	cmd2 = NULL;
	cmd2 = ft_strsplit(cmd, ' ');
	if ((elem = find_addr_env("_", e->head)))
		elem->content = ft_free_and_dup(elem->content, cmd2[0]);
	else
		create_elem(e, "_", cmd2[0]);
	if ((parse_builtin(e, cmd2)) == 0)
	{
		exec_binary(e, cmd2);
	}
	ft_tabclr(cmd2);
}

static	int		exec_cmd(t_env *e)
{
	char	*buff;
	char	**cmd;
	int		i;
	int		code;

	i = -1;
	buff = NULL;
	set_prompt(e);
	buff = get_cmd(e);
	if ((code = is_error(buff)) != 0)
		ft_errors(NULL, code);
	else
	{
		cmd = ft_strsplit(buff, ';');
		while (cmd[++i])
			check_cmd_type(e, cmd[i]);
		ft_tabclr(cmd);
	}
	ft_strdel(&buff);
	return (0);
}

int				main(int argc, char **argv, char **envp)
{
	t_env	*e;

	(void)argc;
	(void)argv;
	e = init_list();
	(!(*envp)) ? get_backup_envcpy(e) : get_envcpy(e, envp);
	clear_sh(envp);
	sig_catch();
	shlvl(e->head, 0);
	while (1)
		exec_cmd(e);
	clear_env(&e);
	return (0);
}
