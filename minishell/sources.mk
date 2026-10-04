# sources.mk — only lists files, no rules

# directories
LEXER         := src/lexer
PARSER        := src/parser
MAIN          := src/main
SIGNALS       := src/signals
EXEC_BUILTINS := src/exec/builtins
EXEC_ENV      := src/exec/env
EXEC_EXECUTE  := src/exec/execute
EXEC_UTILS    := src/exec/utils
EXEC_HEREDOC  := src/exec/heredoc
EXEC_EXPORT   := src/exec/export
EXEC_UNSET    := src/exec/unset
EXEC_REDIR    := src/exec/redir
EXEC_PATH     := src/exec/path

# source groups
SRC_LEXER := \
  $(LEXER)/lex.c \
  $(LEXER)/lex_helper.c

SRC_PARSER := \
  $(PARSER)/pars.c \
  $(PARSER)/pars_checks.c \
  $(PARSER)/pars_cmd_sub.c \
  $(PARSER)/pars_helper.c \
  $(PARSER)/pars_redirs.c \
   $(PARSER)/paren_check.c
   
SRC_MAIN := \
  $(MAIN)/main.c \
  $(MAIN)/expan.c \
  $(MAIN)/free_all.c \
  $(MAIN)/init_env.c \
  $(MAIN)/init_inf.c \
  $(MAIN)/utils.c

SRC_SIGNALS := \
  $(SIGNALS)/signals.c \
  $(SIGNALS)/heredoc_and_child_signals.c

SRC_EXEC_BUILTINS := \
  $(EXEC_BUILTINS)/builtins.c \
  $(EXEC_BUILTINS)/builtins_cd_pwd.c \
  $(EXEC_BUILTINS)/builtins_echo_env.c \
  $(EXEC_BUILTINS)/builtins_export.c \
  $(EXEC_BUILTINS)/builtins_exit.c

SRC_EXEC_ENV := \
  $(EXEC_ENV)/env.c \
  $(EXEC_ENV)/env_utils.c

SRC_EXEC_EXPORT := \
  $(EXEC_EXPORT)/export.c \
  $(EXEC_EXPORT)/export_utils.c

SRC_EXEC_UNSET := \
  $(EXEC_UNSET)/env_unset.c

SRC_EXEC_HEREDOC := \
  $(EXEC_HEREDOC)/heredoc.c \
  $(EXEC_HEREDOC)/heredoc_utils.c \
  $(EXEC_HEREDOC)/heredoc_writer.c

SRC_EXEC_REDIR := \
  $(EXEC_REDIR)/redir_handlers.c

SRC_EXEC_PATH := \
  $(EXEC_PATH)/cmd_utils.c \
  $(EXEC_PATH)/cmd_path.c \
  $(EXEC_PATH)/builtin_fork.c \
  $(EXEC_PATH)/exec_child.c \
  $(EXEC_PATH)/exec_wait.c \
  $(EXEC_PATH)/fd_utils.c

SRC_EXEC_EXECUTE := \
  $(EXEC_EXECUTE)/exec_ast.c \
  $(EXEC_EXECUTE)/exec_cmd.c \
  $(EXEC_EXECUTE)/exec_pipeline.c

SRC_EXEC_UTILS := \
  $(EXEC_UTILS)/arg_convert.c \
  $(EXEC_UTILS)/arg_split.c \
  $(EXEC_UTILS)/arg_utils.c \
  $(EXEC_UTILS)/arg_expand.c \
  $(EXEC_UTILS)/arg_join.c \
  $(EXEC_UTILS)/wildcard_utils.c \
  $(EXEC_UTILS)/glob_collect.c \
  $(EXEC_UTILS)/glob_scan.c \
  $(EXEC_UTILS)/glob_expand.c

# master list exported to Makefile
CFILES := \
  $(SRC_LEXER) \
  $(SRC_PARSER) \
  $(SRC_MAIN) \
  $(SRC_SIGNALS) \
  $(SRC_EXEC_BUILTINS) \
  $(SRC_EXEC_ENV) \
  $(SRC_EXEC_EXPORT) \
  $(SRC_EXEC_UNSET) \
  $(SRC_EXEC_HEREDOC) \
  $(SRC_EXEC_REDIR) \
  $(SRC_EXEC_PATH) \
  $(SRC_EXEC_EXECUTE) \
  $(SRC_EXEC_UTILS)
