#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define BUFFER_SIZE 1024

extern char **environ;
char *_userin(void);

/* envicon.c */
int envicon_shell(char **args);
int unenvicon_shell(char **args);
int envi_command(char **args);

/**
 * struct data_shell - Structure representing shell data
 *
 * @_projenv: pointer to an array of strings
 * @status_proces: Integer representing the status of the shell
 */
typedef struct data_shell
{
	char **_projenv;
	int status_proces;
} data_shell;

/* projenv.c */
void handle_projenv(char *user_input, data_shell *shell_data);
int shell_env(data_shell *shell_data);

char *_strtok(char *str, const char *delim);
char *_strdup(char *dup, char *str);


/* promshel.c */
char *promshel_rd(ssize_t *dis_input);

/* shlone.c */
int main(int arg_c, char **argv);

/* execoms.c */
int execmd(char **_argv_receiv);

/* terminate.c */
void terminate_shell(char **_get_argv, int exec_status);

/* handle.c */
char *_pathget(char *init_cmd);

/* tokey.c */
char **tokey(char *receiv_user_in, char **argv, ssize_t dis_input);

char *accept_userin(void);

void (*get_cmd(char *cmd))(void);
/* userin.c */
char *_userin(void);


/* strenv1.c */
int str_toi(char *s);
char *str_ch(char *s, char c);
int str_seg(char *s, char *charset);
int str_cmpr(char *s, char *c);

/*strenv2.c */
char *str_dup(char *dup, char *str);
char *str_tok(char *str, const char *delim);
char *env_var(const char *name);

/* funcstring.c */
int len_st(char *string);
void cp_str(char *to, char *from);
void concat_str(char *text_add, char *text);

/* function related */
char **handle_path(void);
int check_ifCommand_exist(char *string);
char **split_string(char *string);

/* func_error.c */
int err_str(char *str);
void err_print(char **av, char *err);

/*char *_strchr(char *s, char c); */
/*int _strcspn(char *s, char *charset); */
/*int _strcmp(char *s, char *c);*/

/*int _atoi(char *s); */

void free_array(char **argv);

int cd_command(char **args);
char *_getenv(const char *name);

#endif
