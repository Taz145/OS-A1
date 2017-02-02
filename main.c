#include "my_shell.h"
#include "tic.h"
extern char **getln();

int main() {
    int i;
    char **args;
    char cwd[1000];
    while (1) {
        getcwd(cwd, sizeof(cwd));
        printf("%s $>", cwd);
        args = getln();
        if (strcmp(args[0], "exit") == 0) {
            exit(0);
        } else if (strcmp(args[0], "args") == 0) {
            print_args(args);
            printf("\n");
        } else if (strcmp(args[0], "add") == 0) {
            if (num_args(args) < 2) {
                printf("Usage: add <number 1> <number 2> [number 3] ... \n"
                       "add 0x before the number to change it to hexadecimal\n");
            } else {
                add(args);
            }
        } else if (strcmp(args[0], "tictac") == 0) {
            tic_tac();
        } else if (strcmp(args[0], "cd") == 0) {
            change_dir(args[1]);
        } else {
            sys_command(args);
        }
    }
}

