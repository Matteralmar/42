#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"

extern volatile int				g_heredoc_sig;

# ifndef ENV_CAPACITY
#  define ENV_CAPACITY 512
# endif

// Exit codes
# define EXIT_SUCCESS 0
# define EXIT_GENERAL_ERROR 1
# define EXIT_MISUSE 2
# define EXIT_CMD_NOT_EXEC 126
# define EXIT_CMD_NOT_FOUND 127
# define EXIT_SIGNAL_BASE 128
# define EXIT_SIGINT 130

// File permissions
# define FILE_PERM_DEFAULT 0644
# define FILE_PERM_HEREDOC 0600

// Resource limits
# define MAX_INPUT_LENGTH 131072
# define MAX_SUBSHELL_DEPTH 100

typedef enum e_tokens_type
{
	PIPE_TOKEN,
	WORD_TOKEN,
	AND_TOKEN,
	OR_TOKEN,
	EOF_TOKEN,
	REDIN_TOKEN,
	REDOUT_TOKEN,
	REDAPP_TOKEN,
	HEREDOC_TOKEN,
	PAREN_L_TOKEN,
	PAREN_R_TOKEN,
	INVALID_TOKEN,
}	t_tokens_type;

typedef enum e_quote
{
	NO_QUOTE,
	SINGLE_QUOTE,
	DOUBLE_QUOTE
}	t_quote;

typedef enum e_split_join
{
	SPLIT,
	JOIN,
}	t_split_join;

typedef struct s_tokens
{
	t_tokens_type	type;
	t_quote			q_type;
	char			*text;
	t_split_join	word_join;
	struct s_tokens	*next;
}	t_tokens;

typedef enum e_ast_type
{
	AST_COMMAND,
	AST_PIPE,
	AST_AND,
	AST_OR,
	AST_SUBSHELL,
	AST_REDIR_IN,
	AST_REDIR_OUT,
	AST_REDIR_APPEND,
	AST_HEREDOC
}	t_ast_type;

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}	t_bool;

typedef struct s_word_part
{
	t_bool				expand;
	char				*text;
	t_quote				q_type;
	struct s_word_part	*next;
}	t_word_part;

typedef struct s_arg
{
	t_word_part		*word_parts;
	struct s_arg	*next;
}	t_arg;

typedef struct s_redir
{
	int				fd;
	t_ast_type		type;
	t_word_part		*filename_parts;
	struct s_redir	*next;
}	t_redir;

typedef struct s_ast
{
	t_ast_type		type;
	t_arg			*args;
	t_redir			*redirs;
	t_redir			*start_redirs;
	struct s_ast	*left;
	struct s_ast	*right;
}	t_ast;

typedef struct s_env
{
	char	**vars;
	size_t	cap;
}	t_env;

typedef struct s_info
{
	t_env		*envs;
	t_tokens	*tokens;
	t_ast		*ast;
	int			last_exit_status;
	int			interactive;
}	t_info;

typedef struct s_builtin_map
{
	char	*name;
	int		(*func_no_info)(char **);
	int		(*func_with_info)(char **, t_info *);
	int		needs_info;
}	t_builtin_map;

//--------------------main--------------------\\

				// expan.c
int				handle_dollar_star(char *input, size_t *i, int *dollar);
void			init_word_part(t_word_part *wp, t_quote q_type, char *text);
				// utils.c
int				is_invalid_next(const char *input, size_t i);
void			join_or_split(t_tokens **tokens, t_split_join split_join);
t_split_join	word_join_or_split(char ch);
int				is_fd_before_redir(t_tokens *tok);
int				process_argument(t_ast *cmd, t_arg **curr_arg,
					t_tokens *tokens);
				// init_inf.c
t_info			*init_info(void);
				// free_all.c
void			free_ll(t_info *info);
void			free_ast(t_ast *node);
void			free_args(t_arg *args);
void			free_redirs(t_redir *redir);
				// init_env.c
int				init_env(char **env, t_info *info);

//--------------------lexer--------------------\\

				// lex.c
t_tokens		*lex(size_t i, char *input);
				// lex_helper.c
int				is_token(char ch);
void			ft_lstclr_tokns(t_tokens **lst);
int				create_token(t_tokens **tokens, t_tokens_type token_type,
					t_quote quote_type, char *text);
t_tokens_type	check_operator(const char *input, size_t *i);

//--------------------signal--------------------\\

				// signals.c
void			sig_recv(void);
void			handle_heredoc_signal(int signum);
void			sig_init_child(void);
void			sig_init_heredoc(void);
void			sig_ignore_int_quit(void);
void			default_int_quit(void);

//--------------------parser--------------------\\

				// pars.c
t_ast			*yacc(t_tokens **tokens);
t_ast			*parser(t_tokens **tokens);
				// pars_checks.c
int				check_oper(t_tokens *tokens, int start);
int				check_redir(t_tokens *tokens);
				// pars_helper.c
void			next_token(t_tokens **tokens);
t_ast			*new_node(t_ast_type type, t_redir *start_redir);
void			free_cmd(t_ast *cmd);
int				handle_new_arg(t_ast *cmd, t_arg **curr_arg);
int				handle_split(t_tokens **tokens, t_arg **curr_arg);
				// pars_redirs.c
t_redir			*redirs(t_tokens **tokens, int fd);
void			ft_addback_redir(t_redir **lst, t_redir *new);
int				make_words(t_word_part **first, t_quote q_type, char *text,
					t_split_join split_join);
void			free_word_parts(t_word_part *p);
				// pars_cmd_sub.c
t_ast			*subshell(t_tokens **tokens, t_redir *start_redirs);
t_ast			*cmd(t_tokens **tokens, t_redir *start_redirs,
					int fd, t_arg *curr_arg);
void			ft_addback_arg(t_arg **lst, t_arg *new);
t_arg			*new_arg(void);
				// print_ast.c
void			print_ast(t_ast *node, int depth);
				// parren_check.c
int				paren_err(t_tokens *tokens);

//---------------------exec---------------------\\

				// arg_convert.c
char			**args_to_array(t_arg *args, t_info *info);
				// arg_utils.c
char			*expand_and_join_parts(t_word_part *parts, t_info *info);
char			*join_and_trim_parts(t_word_part *parts);
				// exec_ast.c
int				exec_ast(t_ast *ast, t_info *info);
				// heredoc module
char			*generate_heredoc_filename(void);
int				read_heredoc(char *delimiter, t_bool expand, t_info *info);
int				handle_heredoc(t_redir *curr, t_info *info);
int				wait_heredoc_child(int pid, int pipe_fd[2]);
t_bool			should_expand_heredoc(t_word_part *parts);
void			cleanup_heredocs(t_redir *redirs, t_redir *failed);
t_redir			*process_heredocs(t_redir *redirs, t_info *info);
int				preprocess_heredocs(t_ast *ast, t_info *info);
void			heredoc_child(int *pipe_fd, char *delim, t_bool exp,
					t_info *info);
void			write_heredoc_lines(int fd, char *delimiter, t_bool expand,
					t_info *info);
				// exec_redir.c
int				setup_redirections(t_redir *redirs, t_info *info);
				// exec_redir_handlers.c
int				handle_redir_in(t_redir *curr);
int				handle_redir_out(t_redir *curr);
int				handle_redir_append(t_redir *curr);
char			*join_and_trim_parts(t_word_part *parts);
				// glob/wildcard utils
char			**init_matches_array(int *capacity);
void			free_matches(char **matches, int count);
char			**scan_directory(const char *pattern, int *count);
				// exec_cmd.c
char			*find_cmd_path(char *cmd, t_info *info);
int				exec_simple_cmd(t_ast *ast, t_info *info);
				// exec_cmd_utils.c
char			*search_in_path(char *cmd, char **paths);
void			free_paths(char **paths);
int				exec_builtin_with_redir(t_ast *ast, t_info *info);
int				exec_external_cmd(t_ast *ast, t_info *info, char *cmd_path,
					char **args_arr);
int				wait_builtin_child(pid_t pid);
void			fork_builtin_child(t_ast *ast, t_info *info, char **args_arr);
void			exec_child(t_ast *ast, t_info *info, char *cmd_path,
					char **args_arr);
int				wait_and_cleanup(pid_t pid);
int				handle_fork_error(void);
void			restore_fds_and_cleanup(int saved_fds[2], char **args_arr);
void			save_std_fds(int saved_fds[2]);
				// exec_pipeline.c
int				exec_pipeline(t_ast *ast, t_info *info);
				// builtins.c
int				is_builtin(char *cmd);
int				exec_builtin(char **args, t_info *info);
				// builtins_echo_env.c
int				builtin_env(t_info *info);
int				builtin_echo(char **args);
				// builtins_cd_pwd.c
int				builtin_cd(char **args, t_info *info);
int				builtin_pwd(char **args);
				// builtins_export.c
int				builtin_export(char **args, t_info *info);
int				builtin_unset(char **args, t_info *info);
int				builtin_exit(char **args, t_info *info);
				// env.c
char			*get_env_var(t_env *env, char *var);
int				set_env_var(t_env *env, char *var, char *value);
				// env_utils.c
int				count_env_vars(char **env);
void			free_env_arr(char **env);
int				find_env_index(t_env *env, char *var);
char			**create_new_env(char **old_env, int new_size);
				// env_unset.c
int				unset_env_var(t_env *env, char *var);
				// export.c
int				is_valid_identifier(char *str);
char			*extract_var_name(char *str);
char			*extract_var_value(char *str);
int				print_export_vars(char **env);
				// export_utils.c
char			**alloc_sorted_env(char **env, int count);
void			sort_env_array(char **sorted_env, int count);
void			print_sorted_env(char **sorted_env);
				// wildcard_utils.c
int				match_pattern(const char *str, const char *pattern);
void			bubble_sort(char **matches, int count);
char			*build_result(char **matches, int count);
int				add_match(char ***matches, int *count, int *cap, char *name);
				// wildcard_expand.c
char			*expand_wildcard(const char *pattern);
				// arg_split.c
int				contains_wildcard_expansion(t_arg *arg);
int				count_words(const char *str);
int				add_split_words(char **arr, int idx, char *expanded);
				// arg_utils.c
char			*expand_and_join_parts(t_word_part *parts, t_info *info);
				// arg_expand.c
char			*expand_exit_status(char *str, t_info *info);
char			*expand_env_var(char *str, size_t i, t_info *info);
char			*expand_variable(char *str, t_info *info);
char			*get_var_value(char *text, size_t *i, t_info *info);
char			*join_segment(char *result, char *segment);
char			*add_literal(char *result, char *text, size_t *i);
char			*expand_variables_in_text(char *text, t_info *info);
int				update_last_status(t_info *info, int status);

#endif
