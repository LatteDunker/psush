

#ifndef _CMD_PARSE_H
# define _CMD_PARSE_H

# define MAX_STR_LEN 2000

# define CD_CMD  "cd"
# define CWD_CMD "cwd"
# define ECHO_CMD "echo"
# define QUIT_CMD "quit"
# define HISTORY_CMD "history"
# define HIST 10

# define PIPE_DELIM  "|"
# define SPACE_DELIM " "
# define REDIR_IN    "<"
# define REDIR_OUT   ">"
//# define BACKGROUND_CHAR   "&"

# define PROMPT_STR "psush"

// This enumeration is used when determining ifthe re direction
// characters (the < and >) were used on a command.
typedef enum {
    REDIRECT_NONE
    , REDIRECT_FILE
    , REDIRECT_PIPE
    , BACKGROUND_PROC
} redir_t;

// A list of param_t elements.
typedef struct param_s {
    char *param;
    struct param_s *next;
} param_t;

// A linked list that has a linked list as a member.
typedef struct cmd_s {
    char    *raw_cmd;
    char    *cmd;
    int     param_count;
    param_t *param_list;
    redir_t input_src;
    redir_t output_dest;
    char    *input_file_name;
    char    *output_file_name;
    int     list_location; // zero based
    struct cmd_s *next;
} cmd_t;

typedef struct cmd_list_s {
    cmd_t *head;
    cmd_t *tail;
    int count;
} cmd_list_t;

void parse_commands(cmd_list_t *cmd_list);
void free_list(struct cmd_list_s *);
void print_list(struct cmd_list_s *);
void free_cmd(struct cmd_s *);
void print_cmd(struct cmd_s *);
void exec_commands(cmd_list_t *cmds);
int process_user_input_simple(void);
void simple_argv(int argc, char *argv[]);

#endif // _CMD_PARSE_H
