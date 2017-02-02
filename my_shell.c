#include "my_shell.h"

void add (char **args) {
    int sum = 0, i;
    sum += (int)strtol(args[1], NULL, 0);
    printf("%s", args[1]);
    for (i = 2; i < num_args(args); i++) {
        sum += (int)strtol(args[i], NULL, 0);
        printf(" + %s", args[i]);
    }
    printf(" = %d\n", sum);
}

int num_args(char ** args) {
    int num = 0, i;
    for (i = 0; args[i] != NULL; i++)
        num++;
    return num;
}

void print_args(char **args) {
    int i;
    printf("argc = %d, args = ", num_args(args));
    for (i = 0; args[i] != NULL; i++) {
        printf("%s, ", args[i]);
    }
    printf("\n");
}
void myCommand() {
    printf("To be added at a later date\n");
}

void sys_command(char **args) {
    pid_t child_pid, wpid;
    bool bg = false;
    int redir = 0;
    // struct sigaction SA;
    // SA.sa_sigaction = signal_handler;

    if (args[num_args(args) - 1][0] == '&') {
        bg = true;
        args[num_args(args) - 1][0] = '\0';
    }

    child_pid = fork();
    if (child_pid == 0) { //child
        redir = check_redirection(args, 1);
        if (redir != -1) {
            FILE *out;
            args[redir] = '\0';
            out = freopen(args[redir + 1], "w+", stdout);
        }
        redir = check_redirection(args, 0);
        if (redir != -1) {
            FILE *in;
            args[redir] = '\0';
            in = freopen(args[redir + 1], "r", stdin);
        }
        if (execvp(args[0], args) == -1) {
            printf("Command Failed to execute\n");
        }
        exit(0);
    } else if (child_pid == -1) {
        printf("Forking failed\n");
    } else { //parent
        if (bg)
            waitpid(-1, &wpid, WNOHANG);
        else
            waitpid(child_pid, &wpid, 0);
    }
}

void change_dir(char *dest) {
    int res = 0;
    if (dest == NULL) {
        printf("No destination specified\n");
    }
    res = chdir(dest);
    if (res == -1) {
        printf("Failed to change directory\n");
    }
}

/*void signal_handler (int sig, siginfo_t *sig_info, void *hold) {
    wait(NULL);
}*/

int check_redirection(char **args, int option) {
    int i = 0;
    for (i = 0; i < num_args(args); i++) {
        if (option == 0) {
            if (args[i][0] == '<') {
                return i;
            }
        } else if (option == 1) {
            if (args[i][0] == '>') {
                return i;
            }
        } else {
            return -1;
        }
    }
    return -1;
}