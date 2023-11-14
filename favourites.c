#include <stdio.h>
#include <string.h>
#include <ctype.h>
typedef struct favourites
{
    char add[4];
} fav;
void favourites(char name[]);
void edit_favourites(char name[]);
void read_favourites(char name[]);
void disassemble(char buffer[]);
void erase(char name[]);
void pause();
int main()
{
    char name[20];
    printf("Enter username\n");
    scanf("%s", name);
    favourites(name);
}
void favourites(char name[])
{

    printf("[1]Read your favourites [2] Edit your favourites[3]Back to Main Menu\n-->>");
    int ch;
    scanf("%d", &ch);
    if (ch == 1)
    {
        read_favourites(name);
    }
    if (ch == 2)
    {
        edit_favourites(name);
    }
    if (ch == 3)
    {
    }
}
void read_favourites(char name[])
{
    FILE *read = fopen("Favourites.txt", "r+");
    FILE *user = fopen("user.txt", "r");
    if (read == NULL || user == NULL)
    {
        perror("Failed to open files\n");
    }
    else
    {
        char buffer[50];
        char buffer2[1000];
        while (fscanf(user, "%[^,],", buffer) == 1)
        {
            if (fscanf(read, "%[^,],", buffer2) == 1)
            {
                if (strcmp(buffer, name) == 0)
                {
                    if (isalpha(buffer2[0]))
                    {
                        disassemble(buffer2);
                    }
                    else
                    {
                        printf("No entry\n");
                    }
                }
            }
        }
    }
    fclose(read);
    fclose(user);
}
void edit_favourites(char name[])
{
    printf("%s's Favourite Currencies:\n");
    read_favourites(name);
    printf("\n[1]Clear Favourites [2]Add Favouries\n-->>");
    int ch;
    scanf("%d", &ch);
    if (ch == 1)
    {

        int found = 0;
        FILE *read = fopen("Favourites.txt", "r+");
        FILE *user = fopen("user.txt", "r+");
        long long int pointer = ftell(read);
        if (read == NULL || user == NULL)
        {
            perror("Failed to open files\n");
        }
        else
        {
            char buffer[50];
            char buffer2[1000];
            while (fscanf(user, "%[^,],", buffer) == 1)
            {
                if (fscanf(read, "%[^,],", buffer2) == 1)
                {
                    if (strcmp(buffer, name) == 0)
                    {
                        found = 1;
                        break;
                    }
                }
                pointer = ftell(read);
            }
            if (found)
            {
                fseek(read, pointer, SEEK_SET);
                fprintf(read, "                                                              ,");
                printf("Succesfully erased\n");
            }
        }
        fclose(read);
        fclose(user);
    }
    else if (ch == 2)
    {

        printf("Add Favourites Characters(upto 5/Enter 0 to stop)\n-->>");
        fav data[6];
        int count = 0;
        for (int i = 0; i < 5; i++)
        {
            scanf("%s", data[i].add);
            if (strcmp(data[i].add, "0") == 0)
            {
                break;
            }
            count++;
        }

        int found2 = 0;
        FILE *read = fopen("Favourites.txt", "r+");
        FILE *user = fopen("user.txt", "r+");
        long long int pointer2 = ftell(read);
        if (read == NULL || user == NULL)
        {
            perror("Failed to open files\n");
        }
        else
        {
            char buffer[50];
            char buffer2[1000];
            while (fscanf(user, "%[^,],", buffer) == 1)
            {
                if (fscanf(read, "%[^,],", buffer2) == 1)
                {
                    if (strcmp(buffer, name) == 0)
                    {
                        found2 = 1;
                        break;
                    }
                }
                pointer2 = ftell(read);
            }
            if (found2)
            {
                fseek(read, pointer2, SEEK_SET);
                for (int i = 0; i < count; i++)
                {
                    fprintf(read, "%s+", data[i].add);
                }
                printf("Succesfully Added\n");
            }
        }
        fclose(read);
        fclose(user);
    }
}
void disassemble(char buffer[])
{
    const char *limiter = "+";
    char *token = strtok(buffer, limiter);

    printf("Favourites:\n");
    while (token != NULL)
    {
        printf("%s\n", token);
        token = strtok(NULL, limiter);
    }
    
}
void pause()
{
    int c;
    printf("\nPress Enter to continue\n");
    while ((c = getchar()) != '\n' && c != EOF);
    getchar();
}
void erase(char name[])
{
    int found = 0;
    FILE *read = fopen("Favourites.txt", "r+");
    FILE *user = fopen("user.txt", "r+");
    long long int pointer = ftell(read);
    if (read == NULL || user == NULL)
    {
        perror("Failed to open files\n");
    }
    else
    {
        char buffer[50];
        char buffer2[1000];
        while (fscanf(user, "%[^,],", buffer) == 1)
        {
            if (fscanf(read, "%[^,],", buffer2) == 1)
            {
                if (strcmp(buffer, name) == 0)
                {
                    found = 1;
                    break;
                }
            }
            pointer = ftell(read);
        }
        if (found)
        {
            fseek(read, pointer, SEEK_SET);
            fprintf(read, "                                                              ,");
            printf("Succesfully erased\n");
        }
    }
    fclose(read);
    fclose(user);
    
}