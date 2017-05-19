/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissa-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 19:30:47 by maissa-b          #+#    #+#             */
/*   Updated: 2016/02/04 19:31:22 by maissa-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL_H
# define FT_MINISHELL_H

# include <dirent.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
# include <libft.h>

# define ENV_OP "i"
# define CD_OP "LP"

/*
**	elem :
*/

typedef	struct		s_elem
{
	char			*name;
	char			*content;
	char			*old_content;

	struct s_elem	*next;
	struct s_elem	*prev;
}					t_elem;

/*
**	environment list :
*/

typedef	struct		s_env
{
	size_t			size;
	t_elem			*head;
	t_elem			*foot;
}					t_env;

/*
**	options struct :
*/

typedef	struct		s_opt
{
	int				e_i;
}					t_opt;

/*
**	ft_binaries.c :
*/

int					exec_path(t_env *e, char *way, char **cmd);
char				*is_bin(t_env *e, char **cmd);
int					exec_binary(t_env *e, char **cmd);

/*
**	ft_builtin_cd.c :
*/

int					builtin_cd(t_env *e, char **cmd);

/*
**	ft_builtin_env.c :
*/

int					builtin_env(t_env *e, char **cmd);

/*
**	ft_builtin_exit.c :
*/

int					ft_exit(t_env *e, char **cmd);

/*
**	ft_builtin_export.c :
*/

int					ft_export(t_env *e, char *cmd);
int					builtin_export(t_env *e, char **cmd);

/*
**	ft_builtin_setenv.c :
*/

int					ft_setenv(t_env *e, char **cmd);

/*
**	ft_builtin_unsetenv.c :
*/

int					builtin_unseting(t_env *e, char **cmd);

/*
**	ft_builtins.c :
*/

int					check_builtin(char *str);
void				exec_builtin(t_env *e, char **cmd);
int					parse_builtin(t_env *e, char **cmd);

/*
**	ft_check_errors.c :
*/

int					illegal_option(char *str, char c);
int					is_error(char *buff);
int					ft_errors(char *cmd, int i);
int					access_dir(char *dir);

/*
**	ft_clear_list.c
*/

int					del_elem(t_env *e, t_elem *head, int i);
int					clear_env(t_env **e);

/*
**	ft_env_utils.c :
*/

t_env				*env_cpy(t_env *e);
t_env				*parse_link(t_env *e, char *env_v);
int					print_env(t_elem *e);
void				get_backup_envcpy(t_env *e);
void				get_envcpy(t_env *e, char **env);

/*
**	ft_list_env.c :
*/

t_env				*init_list(void);
void				add_elem(t_env *e, t_elem *elem);
void				create_elem(t_env *e, char *name, char *content);

/*
**	ft_opts.c :
*/

t_opt				*init_opt(void);
t_opt				*del_opt(t_opt *opt);
int					check_opt(t_opt *opt, int i, char *str, char **cmd);

/*
**	ft_parse.c :
*/

char				*get_cmd(t_env *e);

/*
**	ft_tools.c :
*/

void				set_prompt(t_env *e);
void				clear_sh(char **envp);
int					shlvl(t_elem *elem, int code);
t_elem				*find_addr_env(char *name, t_elem *e);

#endif
