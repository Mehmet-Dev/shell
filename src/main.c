#include <stdio.h>
#include <shell.h>
#include <string.h>

void clear()
{
    printf("\e[1;1H\e[2J");
}

int main(){

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

    while(1)
    {
        char prompt[100];

        printf("$ > ");
        fgets(prompt, sizeof(prompt), stdin);
        prompt[strcspn(prompt, "\n")] = 0;

        if(strcmp("exit", prompt) == 0)
        {
            break;
        }
        else
        {
            printf("\nYou typed in: %s", prompt);
            printf("\n\n");
        }
    }
    clear();

    printf("Thank you for using turtle shell\n");
    return(0);
}