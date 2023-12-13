#ifndef OUR_MAIN_H
#define OUR_MAIN_H


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>

extern char **environ;

char *_get_line(void);
char **our_tokenizer(char *atika);
void _free_free(char **esra);
int execute_fun(char **ranim, char **ala, int ind);
void _error(char *path, char *command, int ind);
char *ourPath(char *ranim);
char *_environ(char *var);
void rev_str(char *a, int n);
char *ranim(int x);
int alrady_exist(char *ranim);
void check_command(char **ranim, char *arv[], int *fuad, int ind);
void _exit_exit(char **ranim, int *fuad);
void  put_environ(char **ranim, int *fuad);

#endif
