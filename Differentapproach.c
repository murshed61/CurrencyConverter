#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
void adminpanel();
void read_from_file();
void edit_data();
void restore_data();
void access_admin();
void pause();

int main()
{
    access_admin();
}
void access_admin()
{
    system("cls");
    char *user[] = {"Morshed", "Shishir", "Anamika", "Bijoy"};
    char password[] = "Azxcvbnm1";
    char username[20];
    char pass[20];
    printf("+--------------------------+\n");
    printf("| Enter Username:          |\n");
    printf("+--------------------------+\n");
    printf("-->>");
    scanf("%s", username);
    int found = 0;
    int choice = 5;
    for (int i = 0; i < 4; i++)
    {
        if (strcmp(user[i], username) == 0)
        {
            found = 1;
            choice = i + 1;
            break;
        }
    }
    if (found)
    {
        printf("+-----------------------------------------+\n");
        printf("| Hey %s, Enter Your Admin Password:      |\n", user[choice - 1]);
        printf("+-----------------------------------------+\n");
        printf("-->>");
        scanf("%s", pass);
        if (strcmp(pass, password) == 0)
        {
            printf("\nValid Password\n");
            pause();
            adminpanel();
        }
        else
        {
            printf("\nWrong password\n");
            pause();
            access_admin();
        }
    }
    else
    {
        printf("Sorry User Not Found\n");
        pause();
        main();
    }
}
void adminpanel()
{
    system("cls");
    printf("*******************************\n");
    printf("*    WELCOME TO ADMIN PANEL    *\n");
    printf("*******************************\n\n");

    printf("  1. Read Data\n");
    printf("  2. Edit Data\n");
    printf("  3. Restore Default Values\n");
    printf("  4. Exit From Admin Panel\n");
    printf("  5. Exit From program\n");
    printf("-->>");
    int ch;
    scanf("%d", &ch);
    if (ch == 1)
    {
        read_from_file();
    }
    else if (ch == 2)
    {
        edit_data();
    }
    else if (ch == 3)
    {
        restore_data();
    }
    else if(ch == 4)
    {
        main();
    }
    else if(ch == 5)
    {
        printf("\nThank you<3\n");
        exit(0);
    }
    else
    {
        printf("Invalid Input\n");
    }
    pause();
    adminpanel();
}
void read_from_file()
{
    FILE *read = fopen("cur_name_list.txt", "r");
    if (read == NULL)
    {
        perror("Error opening cur_name_list.txt");
        pause();
        adminpanel();
    }
    else
    {
        FILE *read2 = fopen("bdt_to_any.txt", "r");
        if (read2 == NULL)
        {
            perror("Error opening bdt_to_any.txt");
            pause();
            adminpanel();
        }

        else
        {
            char buffer[10];
            float number;
            while (fscanf(read, "%[^,],", buffer) == 1)
            {
                if (fscanf(read2, "%f,", &number) == 1)
                {
                    printf("+------------------------+\n");
                    printf("| 1 %s = %.3f BDT |\n", buffer, number);
                    printf("+------------------------+\n");
                }
                else
                {
                    printf("File ended or error\n");
                    pause();
                    adminpanel();
                }
            }
        }
        fclose(read);
        fclose(read2);
    }
    pause();
    adminpanel();
}
void edit_data()
{
    printf("+----------------------------------------------------+\n");
    printf("| Enter Currency Name to Edit Value (in respect to BDT) |\n");
    printf("+----------------------------------------------------+\n");
    printf("-->>");
    char name[4];
    long int position = -1;
    scanf("%s", name);
    for (int i = 0; i < 3; i++)
    {
        name[i] = toupper(name[i]);
    }
    FILE *read = fopen("cur_name_list.txt", "r");
    if (read == NULL)
    {
        perror("Error opening cur_name_list.txt");
        pause();
        adminpanel();
    }
    else
    {
        FILE *read2 = fopen("bdt_to_any.txt", "r+");
        if (read2 == NULL)
        {
            perror("Error opening bdt_to_any.txt");
            pause();
            adminpanel();
        }

        else
        {
            char buffer[10];
            float number;
            int found = 0;
            while (fscanf(read, "%[^,],", buffer) == 1)
            {
                if (fscanf(read2, "%f,", &number) == 1)
                {
                    if (strcmp(buffer, name) == 0)
                    {
                        printf("+--------------------------+\n");
                        printf("| Selected Currency to Edit |\n");
                        printf("| 1 BDT = %.3f %s         |\n", number, buffer);
                        printf("+--------------------------+\n");

                        found = 1;
                        break;
                    }
                    position = ftell(read2);
                }
            }
            if (found)
            {
                printf("Enter new value:\n-->> ");

                float value;
                scanf("%f", &value);
                fseek(read2, position, SEEK_SET);
                fprintf(read2, "%.3f", value);
                printf("+------------------------+\n");
                printf("|        SUCCEED         |\n");
                printf("| 1 BDT = %.3f %s     |\n", value, buffer);
                printf("+------------------------+\n");
            }
            else
            {
                printf("Not Found!\n");
                pause();
                adminpanel();
            }
        }
        fclose(read);
        fclose(read2);
    }
    pause();
    adminpanel();
}
void restore_data()
{
    FILE *read = fopen("Backup.txt", "r");
    if (read == NULL)
    {
        perror("Error opening file:");
        pause();
        adminpanel();
    }
    else
    {
        FILE *write = fopen("bdt_to_any.txt", "w");
        if (write == NULL)
        {
            perror("Error Opening File:");
            pause();
            adminpanel();
        }
        else
        {
            char buffer[100];
            while (fgets(buffer, sizeof(buffer), read) != NULL)
            {
                fprintf(write, "%s", buffer);
            }
            printf("+----------------------------+\n");
            printf("| Successfully Restored to Default |\n");
            printf("+----------------------------+\n");
        }

        fclose(write);
    }
    fclose(read);
    pause();
    adminpanel();
}
void pause()
{
    int c;
    printf("\nPress Enter to continue\n");
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    getchar();
}
