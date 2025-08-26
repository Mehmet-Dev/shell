#include <stdio.h>
#include <shell.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <linux/limits.h>
#include <errno.h>

void clear()
{
    printf("\e[1;1H\e[2J");
}

void handle_help()
{
    printf("-- List of commands --\n\n");
    printf("cd [dir] <- Change directory where dir is the path or folder\n");
    printf("pwd <- Print current working directory\n");
    printf("help <- Show available commands\n");
    printf("exit <- Exit turtle shell\n\n");
}

void handle_change_directory(char *path)
{
    if(path == NULL)
    {
        path = getenv("HOME");

        if(path == NULL) {
            fprintf(stderr, "cd: HOME not set\n");
            return;
        }
    }

    if(chdir(path) == -1) {
        perror("cd");
    }
}

void create_child_process(char *arguments[])
{
    pid_t child, w;
    int status;

    child = fork();
    if (child == -1) // If child process failed to initialize
    {
        perror("Failed to fork child process, aborting");
        return;
    }

    if (child == 0)
    {
        char *command = arguments[0];
        int status_code = execvp(command, arguments);

        if (status_code == -1)
        {
            printf("Error: command %s not found!\n", command);
            exit(1);
        }
    }
    else
    {
        w = waitpid(child, &status, 0);

        if (w == -1)
        {
            perror("Forcing the child to wait failed, aborting");
            exit(-1);
        }
    }
}

int main()
{

    clear(); // Clear the console and display opening message
    printf("  /$$$$$$  /$$                 /$$ /$$\n");
    printf(" /$$__  $$| $$                | $$| $$\n");
    printf("| $$  \\__/| $$$$$$$   /$$$$$$ | $$| $$\n");
    printf("|  $$$$$$ | $$__  $$ /$$__  $$| $$| $$\n");
    printf(" \\____  $$| $$  \\ $$| $$$$$$$$| $$| $$\n");
    printf(" /$$  \\ $$| $$  | $$| $$_____/| $$| $$\n");
    printf("|  $$$$$$/| $$  | $$|  $$$$$$$| $$| $$\n");
    printf(" \\______/ |__/  |__/ \\_______/|__/|__/\n\n");

    printf("Welcome to cool shell program\n\n");

    while (1)
    {
        char prompt[1024];
        char cwd[PATH_MAX];

        if (getcwd(cwd, sizeof(cwd)) != NULL)
            printf("$ %s > ", cwd);
        else
            printf("$ > ");

        fgets(prompt, sizeof(prompt), stdin);
        prompt[strcspn(prompt, "\n")] = 0;

        if (strcmp("exit", prompt) == 0)
            break;
        else if(strcmp(prompt, "pwd") == 0)
            printf("Current working directory: %s\n", cwd);
        else if(strcmp(prompt, "help") == 0)
            handle_help();
        else if (strcmp("", prompt) == 0)
            continue;
        else
        {
            int i = 0;
            char *pointer = strtok(prompt, " ");
            char *array[64];

            while (pointer != NULL)
            {
                array[i++] = pointer;
                pointer = strtok(NULL, " ");
            }

            array[i] = NULL;

            int length = i;

            if (strcmp(array[0], "cd") == 0)
                handle_change_directory(array[1]);
            else
                create_child_process(array);
        }
    }

    clear();

    printf("Thank you for using turtle shell\n");
    return (0);
}