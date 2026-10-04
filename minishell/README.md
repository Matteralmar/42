# 🐚 Minishell

A lightweight UNIX shell implementation in C, replicating core bash functionality as part of the 42 School curriculum.

![Build Status](https://img.shields.io/badge/build-passing-brightgreen)
![Norminette](https://img.shields.io/badge/norminette-passing-success)
![Tests](https://img.shields.io/badge/tests-30%2F30-success)

---

## 📋 Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Project Structure](#project-structure)
- [Installation](#installation)
- [Usage](#usage)
- [Architecture](#architecture)
- [Team Contributions](#team-contributions)
- [Testing](#testing)
- [Technical Details](#technical-details)

---

## 🎯 Overview

Minishell is a simplified shell implementation that handles:
- Command execution (built-in and external)
- Input/output redirections
- Pipes and command chaining
- Environment variable management
- Signal handling
- Wildcard expansion

**Team:** `vivantso` & `gvasylie`  
**Grade:** ✅ Passing all tests (20/20 mandatory + 10/10 bonus)  
**Norminette:** ✅ Fully compliant

---

## ✨ Features

### Mandatory Features
- ✅ **Prompt display** with command history (readline)
- ✅ **Command execution** via PATH or absolute/relative paths
- ✅ **Quotes handling** (`'` single quotes, `"` double quotes)
- ✅ **Redirections**:
  - `<` input redirection
  - `>` output redirection
  - `>>` append mode
  - `<<` heredoc
- ✅ **Pipes** (`|`) for command chaining
- ✅ **Environment variables** (`$VAR`, `$?`)
- ✅ **Signal handling** (`Ctrl-C`, `Ctrl-D`, `Ctrl-\`)
- ✅ **Built-in commands**:
  - `echo` (with `-n` option)
  - `cd` (relative/absolute paths)
  - `pwd`
  - `export`
  - `unset`
  - `env`
  - `exit`

### Bonus Features
- ✅ **Logical operators** (`&&`, `||`) with priority
- ✅ **Subshells** with parentheses `( )`
- ✅ **Wildcard expansion** (`*.c`, `file?.txt`)

---

## 📁 Project Structure

```
minishell/
├── Makefile                  # Build automation
├── sources.mk                # Source file organization
├── README.md                 # Project documentation
├── test_ast.sh               # AST testing script
├── test_bonus.sh             # Bonus features tests
├── test_commands.txt         # Test commands list
├── test_fixes.sh             # Bug fixes tests
├── test_mandatory.sh         # Mandatory features tests
├── build/                    # Object files (.d dependency files)
│   ├── lexer/
│   ├── main/
│   ├── parser/
│   └── signals/
├── include/
│   └── minishell.h           # Main header with all structures
├── libft/                    # Custom C library (ft_printf, GNL, libft)
│   ├── libft.h
│   ├── Makefile
│   ├── ft_printf/            # Custom printf & dprintf implementation
│   │   ├── ft_funcs_printf.c
│   │   ├── ft_printf.c
│   │   └── ft_printf.h
│   ├── get_next_line/        # Line reading utility
│   │   ├── get_next_line_utils.c
│   │   ├── get_next_line.c
│   │   └── get_next_line.h
│   └── libft/                # Standard library reimplementation (42+ functions)
│       ├── ft_atoi.c, ft_bzero.c, ft_calloc.c, ft_isalnum.c
│       ├── ft_isalpha.c, ft_isascii.c, ft_isdigit.c, ft_isprint.c
│       ├── ft_itoa.c, ft_memchr.c, ft_memcmp.c, ft_memcpy.c
│       ├── ft_memmove.c, ft_memset.c, ft_putchar_fd.c, ft_putendl_fd.c
│       ├── ft_putnbr_fd.c, ft_putstr_fd.c, ft_split.c, ft_strchr.c
│       ├── ft_strdup.c, ft_striteri.c, ft_strjoin.c, ft_strlcat.c
│       ├── ft_strlcpy.c, ft_strlen.c, ft_strmapi.c, ft_strncmp.c
│       ├── ft_strnstr.c, ft_strrchr.c, ft_strtrim.c, ft_substr.c
│       ├── ft_tolower.c, ft_toupper.c
│       └── Linked list functions (ft_lst*.c)
└── src/
    ├── lexer/                # Tokenization (gvasylie)
    │   ├── lex.c
    │   └── lex_helper.c
    ├── parser/               # AST construction (gvasylie)
    │   ├── pars.c
    │   ├── pars_checks.c
    │   ├── pars_cmd_sub.c
    │   ├── pars_helper.c
    │   └── pars_redirs.c
    ├── main/                 # Initialization & utilities (both)
    │   ├── main.c
    │   ├── init_env.c
    │   ├── init_inf.c
    │   ├── expan.c
    │   ├── utils.c
    │   └── free_all.c
    ├── signals/              # Signal management (gvasylie)
    │   └── signals.c
    └── exec/                 # Execution engine (vivantso)
        ├── builtins/         # Built-in commands (5 files)
        │   ├── builtins.c
        │   ├── builtins_cd_pwd.c
        │   ├── builtins_echo_env.c
        │   ├── builtins_exit.c
        │   └── builtins_export.c
        ├── env/              # Environment management (2 files)
        │   ├── env.c
        │   └── env_utils.c
        ├── execute/          # Core execution (3 files)
        │   ├── exec_ast.c
        │   ├── exec_cmd.c
        │   └── exec_pipeline.c
        ├── export/           # Export functionality (2 files)
        │   ├── export.c
        │   └── export_utils.c
        ├── heredoc/          # Heredoc processing (1 file)
        │   └── heredoc.c
        ├── path/             # Command search (2 files)
        │   ├── cmd_path.c
        │   └── cmd_utils.c
        ├── redir/            # Redirections (1 file)
        │   └── redir_handlers.c
        ├── unset/            # Unset functionality (1 file)
        │   └── env_unset.c
        └── utils/            # Execution utilities (10 files)
            ├── arg_convert.c
            ├── arg_expand.c
            ├── arg_join.c
            ├── arg_split.c
            ├── arg_utils.c
            ├── glob_collect.c
            ├── glob_expand.c
            ├── glob_scan.c
            ├── wildcard_expand.c
            └── wildcard_utils.c
```

**Total:** 37 `.c` files (14 in main modules + 23 in exec/) organized in clean modules

---

## 🚀 Installation

### Prerequisites
- GCC or Clang compiler
- Make
- Readline library (`libreadline-dev` on Debian/Ubuntu)

### Build Instructions

```bash
# Clone the repository
git clone <repository-url>
cd minishell

# Compile the project
make

# Run minishell
./minishell
```

### Additional Make Commands
```bash
make clean      # Remove object files
make fclean     # Remove object files and binary
make re         # Recompile everything
```

---

## 💻 Usage

### Basic Commands
```bash
$ ./minishell
minishell$ echo "Hello, World!"
Hello, World!

minishell$ pwd
/home/user/minishell

minishell$ ls -la | grep .c | wc -l
38
```

### Environment Variables
```bash
minishell$ export MY_VAR="Hello"
minishell$ echo $MY_VAR
Hello

minishell$ echo $?
0
```

### Redirections
```bash
minishell$ echo "test" > output.txt
minishell$ cat < output.txt
test

minishell$ cat << EOF
> line 1
> line 2
> EOF
line 1
line 2
```

### Pipes and Logical Operators
```bash
minishell$ ls | grep README | cat -e
README.md$
README_EXEC.md$

minishell$ ls && pwd
[files listed]
/home/user/minishell

minishell$ false || echo "This runs"
This runs
```

### Wildcards
```bash
minishell$ echo *.c
file1.c file2.c test.c

minishell$ ls src/exec/*/*.c
[all execution source files]
```

---

## 🏗️ Architecture

### Processing Pipeline

```
Input (readline)
    ↓
Lexer (tokenization) ──→ Token stream
    ↓
Parser (AST building) ──→ Abstract Syntax Tree
    ↓
Executor (AST traversal) ──→ Command execution
    ↓
Output / Exit status
```

### Key Components

#### 1. **Lexer** (by gvasylie)
Tokenizes input into:
- Words
- Operators (`|`, `&&`, `||`, `<`, `>`, `>>`, `<<`)
- Quotes (preserving literal/expanded text)
- Parentheses for subshells

#### 2. **Parser** (by gvasylie)
Builds Abstract Syntax Tree (AST) with nodes:
- `AST_COMMAND` - Simple commands
- `AST_PIPE` - Pipeline operations
- `AST_AND` / `AST_OR` - Logical operators
- `AST_SUBSHELL` - Parenthesized commands
- Redirections attached to commands

#### 3. **Executor** (by vivantso)
Traverses AST and executes commands:
- **Builtin dispatch** with `t_builtin_map` struct
- **External commands** via PATH resolution
- **Pipe handling** with fork/dup2
- **Redirection setup** before execution
- **Environment management** (get/set/unset)

#### 4. **Signal Handler** (both)
Manages signals:
- `Ctrl-C` (SIGINT) - Interrupt
- `Ctrl-D` (EOF) - Exit
- `Ctrl-\` (SIGQUIT) - Ignored in interactive mode

---

## 👥 Team Contributions

### vivantso - Execution Engine (`src/exec/`)
**27 files in 9 modules:**

#### **Built-in Commands** (`builtins/` - 5 files)
- `builtins.c` - Professional struct-based dispatch with function pointers
- `builtins_cd_pwd.c` - Directory navigation (`cd`, `pwd`)
- `builtins_echo_env.c` - Output and environment display (`echo`, `env`)
- `builtins_exit.c` - Exit command implementation
- `builtins_export.c` - Export command implementation

#### **Environment Management** (`env/` - 2 files, `export/` - 2 files, `unset/` - 1 file)
- `env.c` + `env_utils.c` - Core environment operations
- `export.c` + `export_utils.c` - Variable validation and sorted display
- `env_unset.c` - Variable removal

#### **I/O & Execution** (`heredoc/` - 1 file, `redir/` - 1 file, `path/` - 2 files, `execute/` - 3 files)
- `heredoc.c` - Heredoc processing with temp files
- `redir_handlers.c` - All redirection types (`<`, `>`, `>>`, `<<`)
- `cmd_path.c` + `cmd_utils.c` - PATH search and external command execution
- `exec_ast.c` - Main AST dispatcher (pipes, logical ops, subshells)
- `exec_cmd.c` - Command execution logic
- `exec_pipeline.c` - Pipe management with fork

#### **Utilities** (`utils/` - 10 files)
- `arg_convert.c` - t_arg → char** conversion
- `arg_expand.c` - Variable expansion (`$VAR`, `$?`)
- `arg_join.c` - Argument joining operations
- `arg_split.c` - Wildcard result splitting
- `arg_utils.c` - Argument utility functions
- `glob_collect.c` - Wildcard match collection
- `glob_expand.c` - Wildcard expansion logic
- `glob_scan.c` - Wildcard scanning operations
- `wildcard_expand.c` - Wildcard result building
- `wildcard_utils.c` - Pattern matching and sorting

**Key Achievement:** Professional struct-based builtin dispatch system (`t_builtin_map`) with function pointers - cleaner than traditional if-else chains.

### gvasylie - Lexer, Parser & Signals (`src/lexer/`, `src/parser/`, `src/signals/`)
**8 files:**

#### **Lexer** (`lexer/` - 2 files)
- `lex.c` - Main tokenization logic
- `lex_helper.c` - Token creation and quote handling

#### **Parser** (`parser/` - 5 files)
- `pars.c` - Main AST construction
- `pars_checks.c` - Syntax validation
- `pars_cmd_sub.c` - Command and subshell parsing
- `pars_helper.c` - Utility functions
- `pars_redirs.c` - Redirection parsing

#### **Signals** (`signals/` - 1 file)
- `signals.c` - Signal handler setup (SIGINT, SIGQUIT)

**Key Achievement:** Robust AST structure supporting complex command combinations (pipes, logical operators, subshells with redirections).

### Shared Responsibilities (`src/main/`)
**6 files (collaborative):**
- `main.c` - Entry point and main loop
- `init_env.c` - Environment initialization
- `init_inf.c` - Info structure setup
- `expan.c` - Variable expansion preprocessing
- `utils.c` - Shared utilities
- `free_all.c` - Memory cleanup

---

## 🧪 Testing

### Test Suite
```bash
# Mandatory features (20 tests)
./test_mandatory.sh
# Result: ✅ 20/20

# Bonus features (10 tests)
./test_bonus.sh
# Result: ✅ 10/10
```

### Manual Testing Examples
```bash
# Complex pipes
minishell$ cat file.txt | grep pattern | sort | uniq -c | sort -nr

# Logical operators with subshells
minishell$ (cd /tmp && ls) && pwd
# Shows /tmp contents but pwd shows original directory

# Wildcards with redirections
minishell$ echo src/*/*.c > files.txt

# Heredoc with variable expansion
minishell$ cat << EOF
> User: $USER
> Home: $HOME
> EOF
```

### Norminette Compliance
```bash
norminette src/ include/
# Result: 0 errors (excluding INVALID_HEADER for missing 42 headers)
```

**Standards:**
- Max 5 functions per file
- Max 25 lines per function
- No typedefs in `.c` files
- No global variables (except for signals)

---

## 🔧 Technical Details

### Memory Management
- All malloc'd memory properly freed
- No memory leaks (verified with valgrind)
- Cleanup on exit or error

### Error Handling
- Graceful handling of:
  - Invalid syntax
  - Command not found
  - Permission denied
  - Failed redirections
  - Signal interruptions

### Process Management
- Proper fork/exec for external commands
- Correct pipe file descriptor handling
- Waitpid for child process cleanup
- Exit status propagation

### Professional Patterns

#### Struct-Based Builtin Dispatch
```c
typedef struct s_builtin_map
{
    char *name;
    int  (*func_no_info)(char **);
    int  (*func_with_info)(char **, t_info *);
    int  needs_info;
} t_builtin_map;

static const t_builtin_map g_builtins[] = {
    {"echo", builtin_echo, NULL, 0},
    {"cd", NULL, builtin_cd, 1},
    {"pwd", builtin_pwd, NULL, 0},
    // ...
};
```

**Benefits:**
- Single loop replaces multiple if-else chains
- Easy to add new builtins
- Function pointer efficiency
- Cleaner code structure

#### sources.mk Organization
All source files organized by module in a separate file:
```makefile
SRC_EXEC_BUILTINS := $(EXEC_BUILTINS)/*.c
SRC_EXEC_ENV := $(EXEC_ENV)/*.c
SRC_EXEC_EXECUTE := $(EXEC_EXECUTE)/*.c
# ... etc
```

**Benefits:**
- Makefile stays clean
- Easy module management
- Better maintainability

---

## 📊 Project Statistics

| Metric | Value |
|--------|-------|
| Total Lines of Code | ~8,000+ |
| Source Files (.c) | 37 |
| Header Files (.h) | 1 (main) + libft headers |
| Modules | 9 (exec) + 4 (other) |
| Built-in Commands | 7 |
| Supported Operators | 6 (`|`, `&&`, `||`, `<`, `>`, `>>`, `<<`) |
| Test Success Rate | 100% (30/30) |
| Norminette Errors | 0 (excluding headers) |
| Development Time | ~3 weeks |

---

## 🎓 Learning Outcomes

This project provided deep understanding of:
- **Process management** (fork, exec, wait, pipes)
- **File descriptors** (dup2, redirections)
- **Signal handling** (SIGINT, SIGQUIT)
- **Lexical analysis** and **parsing** (AST construction)
- **Memory management** (dynamic allocation, leak prevention)
- **Modular architecture** (clean code organization)
- **Team collaboration** (Git workflow, code integration)

---

## 🤝 Acknowledgments

- **42 School** for the challenging curriculum
- **Bash documentation** for reference implementation
- **gvasylie** for solid lexer/parser foundation
- **vivantso** for robust execution engine

---

## 📝 License

This project is part of the 42 School curriculum. Educational use only.

---

## 🔗 Links

- **42 School:** [www.42.fr](https://www.42.fr)

---

**Built by vivantso & gvasylie**
