#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

int num_args(char **args);
void add(char **args);
void myCommand();
void sys_command(char **args);
void print_args(char **args);
void change_dir(char *dest);
int check_redirection(char **args, int option);