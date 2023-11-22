#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>
// Structure Defination
struct Records
{
    char currency_name[5];
    char fav_currency[5];
    float value;
    float value2;
};
// Global variables
char sign_in_user_name[20];
struct Records struct_data[100];
// Function Declarations
void input_clear();
void pause();
void login_page();
void sign_in();
void sign_up();
void simplified_version();
void login_page_error();
void invalid_input();
int check_username(char user[]);
void main_menu();
void data_read_from_files();
void search_to_convert(int ch);
void manual_convert(int ch);
void show_list(int ch);
void favourites();
void settings();
void history();
void error_handling(int ch);
void exit_menu(int ch);
void currencyconversion(int from, int to, float value, int ch);
void continents();
void currency_name_of_continent(int choice, const char *file_s_for_currency[]);
void read_from_file();
void edit_data();
void restore_data();
void read_favourites();
void edit_favourites();
void disassemble(char buffer[]);
int check_entry(char input[]);
int check_index(char input[]);
void change_password();
int check_password();
void discard_username_password();
void allocate_new_username(char pass[]);
int count_currency();

// Program Starts From Here
int main()
{
    login_page();
}
void login_page()
{
    system("cls");
    printf("\033[0;36m");
    printf("\t\t\t\t\t\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\////////////////////\n");
    printf("\t\t\t\t\t    %c Welcome to Currency Converter %c\n", 175, 174);
    printf("\t\t\t\t\t////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n\n");
    printf("\033[0m");
    printf("\033[1;32m");
    printf("\t\t\t\t\t\t\t|LOGIN PAGE|\n");
    printf("\t\t\t======================================================================\n");
    printf("\t\t\t\t\t[1] Sign in   [2] Sign Up   [3] Guest Mode\n");
    printf("\t\t\t======================================================================\n");
    
    int ch;
    printf("%c Choose an option %c", 254,175);
    printf("\033[0m");
    scanf(" %d", &ch);
    input_clear();
    switch (ch)
    {
    case 1:
        sign_in();
        break;
    case 2:
        sign_up(0);
        break;
    case 3:
        simplified_version();
        break;
    default:
        login_page_error();
    }
}
void login_page_error()
{
    invalid_input();
    pause();
    login_page();
}
void sign_up(int r)
{
    system("cls");
    printf("+------------------+\n");
    printf("Enter Username:\n");
    printf("+------------------+\n");
    printf("%c", 175);
    char user[20];
    char pass[20];
    scanf("%s", user);
    input_clear();
    FILE *userpointer = fopen("files/username_list.txt", "a");
    FILE *userFav = fopen("files/user.txt", "a");
    FILE *Fav = fopen("files/Favourites.txt", "a");
    if (userpointer == NULL || userFav == NULL || Fav == NULL)
    {
        perror("Server Error\n");
        pause();
        login_page();
    }
    else
    {
        int c = check_username(user);
        if (c == 1)
        {
            ++r;
            printf("Username Taken\n");
            if (r < 2)
            {
                pause();
                sign_up(1);
            }
            else
            {
                fclose(userpointer);
                fclose(userFav);
                fclose(Fav);
                pause();
                login_page();
            }
        }
        else
        {

            fprintf(userpointer, "%s,", user);
            fprintf(userFav, "%s,", user);
            fprintf(Fav, "                                                              ,");
        }
    }
    fclose(userpointer);
    fclose(userFav);
    fclose(Fav);
    printf("+------------------+\n");
    printf("Enter Password: \n");
    printf("+------------------+\n");
    printf("%c", 175);
    scanf("%s", pass);
    input_clear();
    FILE *passpointer = fopen("files/password_list.txt", "a");
    if (passpointer == NULL)
    {
        perror("Server Error\n");
        pause();
        login_page();
    }
    else
    {
        fprintf(passpointer, "%s,", pass);
    }
    fclose(passpointer);
    printf("Your Username and Password\n");
    printf("-->>%s\n", user);
    printf("-->>%s\n", pass);
    pause();
    login_page();
}
void sign_in()
{
    char pass[20];
    char buffer1[100], buffer2[100];
    int found1 = 0, found2 = 0, count1 = 1, count2 = 1;
    printf("Enter your username\n");
    printf("-->>");
    scanf("%s", sign_in_user_name);
    input_clear();
    FILE *userpointer = fopen("files/username_list.txt", "r");
    if (userpointer == NULL)
    {
        perror("Server Error\n");
        pause();
        login_page();
    }
    else
    {

        while (fscanf(userpointer, "%[^,],", buffer1) == 1)
        {
            count1++;
            if (strcmp(buffer1, sign_in_user_name) == 0)
            {
                found1 = 1;
                break;
            }
        }
        fclose(userpointer);
        if (found1)
        {
            printf("Hello %s Enter your Password\n", sign_in_user_name);
            printf("-->>");
            scanf("%s", pass);
            input_clear();
            FILE *passpointer = fopen("files/password_list.txt", "r");
            if (passpointer == NULL)
            {
                perror("Server Error\n");
                pause();
                login_page();
            }
            else
            {

                while (fscanf(passpointer, "%[^,],", buffer2) == 1)
                {
                    count2++;
                    if (strcmp(buffer2, pass) == 0)
                    {

                        if (count1 == count2)
                        {
                            found2 = 1;
                            printf("Password Matched\n");
                            break;
                        }
                    }
                }
                fclose(passpointer);
                if (found2)
                {
                    pause();
                    main_menu();
                }
                else
                {
                    printf("Password Wrong\n");
                    pause();
                    login_page();
                }
            }
        }
        else if (!found1)
        {
            printf("User Not Found\n");
            pause();
            login_page();
        }
    }
    pause();
    login_page();
}
void input_clear()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}
void pause()
{
    int c;
    printf("\nPress Enter to continue\n");
    while ((c = getchar()) != '\n')
        ;
}
void invalid_input()
{
    printf("--=* Error: Invalid Input *=--\n");
}
void simplified_version()
{
    system("cls");

    data_read_from_files();
    printf("\033[0;36m");
    printf("\t\t\t\t\t\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\////////////////////\n");
    printf("\t\t\t\t\t    %c Welcome to Currency Converter %c\n", 175, 174);
    printf("\t\t\t\t\t////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n\n");
    printf("\033[0m");
    printf("\033[1;32m"); // Green color code
    printf("\t\t\t\t\t\t\t|GUEST MODE|\n");
    printf("\t\t\t\t\t\t*************************\n");
    printf("\t\t\t\t\t\t*    %c MENU OPTIONS %c   *\n", 175, 174);
    printf("\t\t\t\t\t\t* [1] SEARCH TO CONVERT *\n");
    printf("\t\t\t\t\t\t* [2] MANUAL CONVERSION *\n");
    printf("\t\t\t\t\t\t* [3] CURRENCY LIST     *\n");
    printf("\t\t\t\t\t\t* [4] Log Out           *\n");
    printf("\t\t\t\t\t\t*************************\n");
    printf("\t\t\t\t\t\t%c Enter Choice -> ", 254);
    printf("\033[0m");
    int ch;
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        search_to_convert(0);
        break;
    case 2:
        manual_convert(0);
        break;
    case 3:
        show_list(0);
        break;
    case 4:
        login_page();
        break;
    default:
        error_handling(0);
        break;
    }
    pause();
    simplified_version();
}
int check_username(char user[])
{
    int found = 0;
    char buffer[50];
    FILE *user_list = fopen("files/username_list.txt", "r");
    if (user_list == NULL)
    {
        return 1;
    }
    else
    {
        while (fscanf(user_list, "%[^,],", buffer) != EOF)
        {
            if (strcmp(buffer, user) == 0)
            {
                found = 1;
                break;
            }
        }
    }
    fclose(user_list);
    return found;
}
void main_menu()
{
    system("cls");
    data_read_from_files();
    printf("\033[0;36m");
    printf("\t\t\t\t\t\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\////////////////////\n");
    printf("\t\t\t\t\t    %c Welcome to Currency Converter %c\n", 175, 174);
    printf("\t\t\t\t\t////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n");
    printf("\033[0m");
    printf("\033[1;32m"); // Green color code
    printf("\n");
    printf("\t\t\t\t\t\tUser: %s\n",sign_in_user_name);
    printf("\t\t\t\t\t\t*************************\n");
    printf("\t\t\t\t\t\t*    %c MENU OPTIONS %c   *\n", 175, 174);
    printf("\t\t\t\t\t\t* [1] SEARCH TO CONVERT *\n");
    printf("\t\t\t\t\t\t* [2] MANUAL CONVERSION *\n");
    printf("\t\t\t\t\t\t* [3] CURRENCY LIST     *\n");
    printf("\t\t\t\t\t\t* [4] Recently Searched *\n");
    printf("\t\t\t\t\t\t* [5] Settings          *\n");
    printf("\t\t\t\t\t\t* [6] Favourites        *\n");
    printf("\t\t\t\t\t\t* [7] Log Out           *\n");
    printf("\t\t\t\t\t\t*************************\n");
    printf("\t\t\t\t\t\t%c Enter Choice -> ", 254);
    printf("\033[0m");
    int ch;
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        search_to_convert(1);
        break;
    case 2:
        manual_convert(1);
        break;
    case 3:
        show_list(1);
        break;
    case 4:
        history();
        break;
    case 5:
        settings();
        break;
    case 6:
        favourites();
        break;
    case 7:
        login_page();
        break;
    default:
        error_handling(1);
        break;
    }
}
void data_read_from_files()
{
    FILE *names = fopen("files/cur_name_list.txt", "r");
    if (names == NULL)
    {
        perror("Error Opening File For Names");
        pause();
        login_page();
    }
    else
    {
        char buffer[5];
        for (int i = 0; i < 95; i++)
        {
            fscanf(names, "%[^,],", buffer);
            strcpy(struct_data[i].currency_name, buffer);
        }
        fclose(names);
    }
    FILE *names2 = fopen("files/bdt_to_any.txt", "r");
    if (names2 == NULL)
    {
        perror("Error Opening File For currency");
        pause();
        login_page();
    }
    else
    {
        float amount;
        for (int i = 0; i < 95; i++)
        {
            fscanf(names2, "%f,", &amount);
            struct_data[i].value = amount;
        }
        fclose(names2);
    }
    for (int i = 0; i < 95; i++)
    {
        struct_data[i].value2 = 1 / struct_data[i].value;
    }
}
void exit_menu(int ch)
{
    if (ch == 1)
    {
        int c;
        while ((c = getchar()) != '\n' && c != EOF)
            ;
        printf("\033[0;44m");
        char close;
        printf("\n %c Enter   (+) for More Conversion   (?) for About us   (X) for Exit... -> ", 254);
        printf("\033[0m");
        scanf(" %c", &close);
        if (close == 'x' || close == 'X')
        {
            printf("\033[1;31m\n Thank You <3\n\033[0m");
            exit(0);
        }
        else if (close == '?')
        {
            system("cls");
            printf("\033[1;31m");
            printf("\n %c About Us %c\n", 175, 174);
            printf(" ------------\n");
            printf(" \n\n <> DAFFODIL INTERNATIONAL UNIVERSITY:\n");
            printf(" -------------------------------------\n\n");
            printf(" <> PROJECT NAME: [ CURRENCY CONVERTER ]\n\n");
            printf(" <> GROUP NAME: [ The Code Miners ]\n\n");
            printf(" <> GROUP MEMBERS:\n\n");
            printf(" 1. SHISHIR KARMOKAR	ID - 0242320005101254\n");
            printf(" 2. GULAM MURSHED 	ID - 0242320005101336\n");
            printf(" 3. ANAMIKA AKTER	ID - 0242320005101101\n");
            printf(" 4. BIJOY SARKER	ID - 0242320005101219\n\n");
            printf("    [ A Project by \"CODE MINERS\" ]\n");
            printf("\033[0m");
            exit_menu(ch);
        }
        else if (close == '+')
        {
            main_menu();
        }
        else
        {
            error_handling(ch);
        }
        printf("\033[0m");
    }
    else
    {
        int c;
        while ((c = getchar()) != '\n' && c != EOF)
            ;
        printf("\033[0;44m");
        char close;
        printf("\n %c Enter   (+) for More Conversion   (?) for About us   (X) for Exit... -> ", 254);
        printf("\033[0m");
        scanf(" %c", &close);
        if (close == 'x' || close == 'X')
        {
            printf("\033[1;31m\n Thank You <3\n\033[0m");
            exit(0);
        }
        else if (close == '?')
        {
            system("cls");
            printf("\033[1;31m");
            printf("\n %c About Us %c\n", 175, 174);
            printf(" ------------\n");
            printf(" \n\n <> DAFFODIL INTERNATIONAL UNIVERSITY:\n");
            printf(" -------------------------------------\n\n");
            printf(" <> PROJECT NAME: [ CURRENCY CONVERTER ]\n\n");
            printf(" <> GROUP NAME: [ The Code Miners ]\n\n");
            printf(" <> GROUP MEMBERS:\n\n");
            printf(" 1. SHISHIR KARMOKAR	ID - 0242320005101254\n");
            printf(" 2. GULAM MURSHED 	ID - 0242320005101336\n");
            printf(" 3. ANAMIKA AKTER	ID - 0242320005101101\n");
            printf(" 4. BIJOY SARKER	ID - 0242320005101219\n\n");
            printf("    [ A Project by \"CODE MINERS\" ]\n");
            printf("\033[0m");
            exit_menu(ch);
        }
        else if (close == '+')
        {
            simplified_version();
        }
        else
        {
            error_handling(ch);
        }
        printf("\033[0m");
    }
}
void error_handling(int ch)
{
    if (ch == 1)
    {
        printf("\033[0;31m\n\tSomething is Wrong!!\n\033[0m");
        exit_menu(ch); // function to function call
    }
    else
    {
        printf("\033[0;31m\n\tSomething is Wrong!!\n\033[0m");
        exit_menu(ch); // function to function call
    }
}
void search_to_convert(int ch)
{
    int from;
    int to;
    float amount;
    srand(time(NULL));
    char name1[4];
    char name2[4];
    int num_currencies = 95;

    // time.h - random currency generator
    printf("\033[0;34m");
    printf("\n\t----------------------------------------------------------------------------------------------\n");
    printf("\t| Popular Currencies of the Day: |");
    for (int i = 0; i < 10; i++)
    {
        int random_index = rand() % num_currencies;
        printf(" %s |", struct_data[random_index].currency_name);
    }
    printf("\n\t----------------------------------------------------------------------------------------------\n");
    printf("\033[0m");

    printf("\n\t%c Enter the name of the currency you want to convert FROM -> ", 254);

    scanf("%s", name1);

    for (int i = 0; i < 3; i++)
    {
        name1[i] = toupper(name1[i]);
    }
    bool found1 = false;
    for (int i = 0; i < 95; i++)
    {
        if (strcmp(struct_data[i].currency_name, name1) == 0)
        {
            found1 = true;
            from = i + 1;
            break;
        }
        else if (i == 94)
        {
            printf("\033[0;31m\n\tCURRENCY NOT FOUND!\n\033[0m");
            error_handling(ch);
        }
    }
    if (found1)
    {
        printf("\033[1;32m");
        printf("\t------------------------------\n");
        printf("\tSELECTED CURRENCY IS || %s ||\n", struct_data[from - 1].currency_name);
        printf("\t------------------------------\n");
        printf("\033[0m");
    }
    printf("\n\t%c Enter name of the currency you want to convert TO -> ", 254);
    scanf("%s", name2);
    for (int i = 0; i < 3; i++)
    {
        name2[i] = toupper(name2[i]);
    }
    bool found2 = false;
    for (int i = 0; i < 95; i++)
    {
        if (strcmp(struct_data[i].currency_name, name2) == 0)
        {
            found2 = true;
            to = i + 1;
            break;
        }
        else if (i == 94)
        {
            printf("\033[0;31m\n\tCURRENCY NOT FOUND!\n\033[0m");
            exit_menu(ch);
        }
    }
    if (found2)
    {
        printf("\033[1;32m");
        printf("\t------------------------------\n");
        printf("\tSELECTED CURRENCY IS || %s ||\n", struct_data[to - 1].currency_name);
        printf("\t------------------------------\n");
        printf("\033[0m");
    }
    printf("\n\t%c Enter amount -> ", 254);
    scanf("%f", &amount);
    currencyconversion(from, to, amount, ch);
    exit_menu(ch);
}
void currencyconversion(int from, int to, float value, int ch)
{
    if (ch == 1)
    {
        FILE *file = fopen("files/history.txt", "a");
        if (file == NULL)
        {
            printf("Memory could not be accessed\n");
        }

        printf("\033[0;31m");
        if (from == to) // same currency
        {
            printf("\n\n\t<=--------------------------------------------=>\n");
            printf("\t\t%.2f %s TO %s = %.2f %s\n", value, struct_data[from - 1].currency_name, struct_data[to - 1].currency_name, value, struct_data[to - 1].currency_name);
            printf("\t<=--------------------------------------------=>\n");
            fprintf(file, "\n%.2f %s TO %s = %.2f %s", value, struct_data[from - 1].currency_name, struct_data[to - 1].currency_name, value, struct_data[to - 1].currency_name);
        }
        else if (from == 1) // bdt_to_any
        {
            float calculated_any_value = struct_data[to - 1].value * value;
            printf("\n\n\t<=--------------------------------------------=>\n");
            printf("\t\t%.2f %s TO %s = %.2f %s\n", value, struct_data[from - 1].currency_name, struct_data[to - 1].currency_name, calculated_any_value, struct_data[to - 1].currency_name);
            printf("\t<=--------------------------------------------=>\n");
            fprintf(file, "\n%.2f %s TO %s = %.2f %s\n", value, struct_data[from - 1].currency_name, struct_data[to - 1].currency_name, calculated_any_value, struct_data[to - 1].currency_name);
        }
        else if (to == 1) // any_to_bdt
        {
            float calculated_bdt_value = struct_data[from - 1].value2 * value;
            printf("\n\n\t<=--------------------------------------------=>\n");
            printf("\t\t%.2f %s TO %s = %.2f %s\n", value, struct_data[from - 1].currency_name, struct_data[to - 1].currency_name, calculated_bdt_value, struct_data[to - 1].currency_name);
            printf("\t<=--------------------------------------------=>\n");
            fprintf(file, "\n%.2f %s TO %s = %.2f %s\n", value, struct_data[from - 1].currency_name, struct_data[to - 1].currency_name, calculated_bdt_value, struct_data[to - 1].currency_name);
        }
        else if (from != to) // ANY TO ANY
        {
            float anyToBdt = struct_data[from - 1].value2 * value;
            float calculated_any = struct_data[to - 1].value * anyToBdt;

            printf("\n\n\t<=--------------------------------------------=>\n");
            printf("\t\t%.2f %s TO %s = %.2f %s\n", value, struct_data[from - 1].currency_name, struct_data[to - 1].currency_name, calculated_any, struct_data[to - 1].currency_name);
            printf("\t<=--------------------------------------------=>\n");
            fprintf(file, "\n%.2f %s TO %s = %.2f %s\n", value, struct_data[from - 1].currency_name, struct_data[to - 1].currency_name, calculated_any, struct_data[to - 1].currency_name);
        }
        printf("\033[0m");
        fclose(file);
    }
    else
    {
        printf("\033[0;31m");
        if (from == to) // same currency
        {
            printf("\n\n\t<=--------------------------------------------=>\n");
            printf("\t\t%.2f %s TO %s = %.2f %s\n", value, struct_data[from - 1].currency_name, struct_data[to - 1].currency_name, value, struct_data[to - 1].currency_name);
            printf("\t<=--------------------------------------------=>\n");
        }
        else if (from == 1) // bdt_to_any
        {
            float calculated_any_value = struct_data[to - 1].value * value;
            printf("\n\n\t<=--------------------------------------------=>\n");
            printf("\t\t%.2f %s TO %s = %.2f %s\n", value, struct_data[from - 1].currency_name, struct_data[to - 1].currency_name, calculated_any_value, struct_data[to - 1].currency_name);
            printf("\t<=--------------------------------------------=>\n");
        }
        else if (to == 1) // any_to_bdt
        {
            float calculated_bdt_value = struct_data[from - 1].value2 * value;
            printf("\n\n\t<=--------------------------------------------=>\n");
            printf("\t\t%.2f %s TO %s = %.2f %s\n", value, struct_data[from - 1].currency_name, struct_data[to - 1].currency_name, calculated_bdt_value, struct_data[to - 1].currency_name);
            printf("\t<=--------------------------------------------=>\n");
        }
        else if (from != to) // ANY TO ANY
        {
            float anyToBdt = struct_data[from - 1].value2 * value;
            float calculated_any = struct_data[to - 1].value * anyToBdt;

            printf("\n\n\t<=--------------------------------------------=>\n");
            printf("\t\t%.2f %s TO %s = %.2f %s\n", value, struct_data[from - 1].currency_name, struct_data[to - 1].currency_name, calculated_any, struct_data[to - 1].currency_name);
            printf("\t<=--------------------------------------------=>\n");
        }
        printf("\033[0m");
    }
}
void manual_convert(int ch)
{
    const char *file_s_for_currency[] = {"files/Asia_currency.txt", "files/Europe_currency.txt", "files/Africa_currency.txt", "files/Australia.txt", "files/North_america_currency.txt", "files/South_america_currency.txt"};
    int continent_from;
    int from;
    int continent_to;
    int to;
    float amount;

    continents();
    scanf("%d", &continent_from);
    if (continent_from > 0 && continent_from <= 6)
    {
        currency_name_of_continent(continent_from, file_s_for_currency);
    }
    else
    {
        error_handling(ch);
    }

    printf("\033[1;36m");
    printf("\n\n %c Please Choose & Enter a Number %c\n", 254, 254);
    printf(" ------------------------------------\n");
    printf(" %c Currency To Convert FROM -> ", 175);
    printf("\033[0m");
    scanf("%d", &from);
    if ((continent_from == 1) && (from > 20 || from < 1))
    {
        error_handling(ch);
    }
    else if ((continent_from != 1) && (from > 15 || from < 1))
    {
        error_handling(ch);
    }

    // Taking input continent_to and to
    continents();
    scanf("%d", &continent_to);

    if (continent_to > 0 && continent_to <= 6)
    {
        currency_name_of_continent(continent_to, file_s_for_currency);
    }
    else
    {
        error_handling(ch);
    }
    printf("\033[1;36m");
    printf("\n\n %c Please Choose & Enter a Number %c\n", 254, 254);
    printf(" ------------------------------------\n");
    printf(" %c Currency To Convert TO -> ", 175);
    printf("\033[0m");
    scanf("%d", &to);
    if ((to > 20 || to < 1) && (continent_to == 1))
    {
        error_handling(ch);
    }
    else if ((to > 15 || to < 1) && (continent_to > 1))
    {
        error_handling(ch);
    }

    printf("\033[1;32m");
    printf("\n\n %c Please Enter The Amount To CONVERT -> ", 175);
    printf("\033[0m");
    scanf("%f", &amount);

    switch (continent_from)
    {
    case 1:
        from = from;
        break;
    case 2:
        from = from + 20;
        break;
    case 3:
        from = from + 35;
        break;
    case 4:
        from = from + 50;
        break;
    case 5:
        from = from + 65;
        break;
    case 6:
        from = from + 80;
        break;
    }
    switch (continent_to)
    {
    case 1:
        to = to;
        break;
    case 2:
        to = to + 20;
        break;
    case 3:
        to = to + 35;
        break;
    case 4:
        to = to + 50;
        break;
    case 5:
        to = to + 65;
        break;
    case 6:
        to = to + 80;
        break;
    }
    if (to <= 0 && to > 95)
    {
        error_handling(ch);
    }
    currencyconversion(from, to, amount, ch);
    exit_menu(ch);
}
void show_list(int ch)
{
    printf("\033[0;36m ||ALL CURRENCY LIST||\n\n\033[0m");
    FILE *files = fopen("files/Currency_List.txt", "r");
    if (files == NULL)
    {
        printf("\033[0;31m\n\tFailed to open FILE!\n\033[0m");
        error_handling(ch);
    }
    else
    {
        char buffer[1024];
        while (fgets(buffer, sizeof(buffer), files) != NULL)
        {

            printf("\033[1;36m%s\033[0m", buffer);
        }
    }
    fclose(files);
    printf("\033[0;36m\n\n %c Press enter to continue...\033[0m", 254);
    getchar();
    exit_menu(ch);
}
void favourites()
{
    system("cls");
    printf("\n=========================================================================\n");
    printf("[1] Read your favorites   [2] Edit your favorites   [3] Back to Main Menu\n");
    printf("\n=========================================================================\n");
    printf("-->> ");
    int ch;
    scanf("%d", &ch);
    if (ch == 1)
    {
        read_favourites();
    }
    if (ch == 2)
    {
        edit_favourites();
    }
    if (ch == 3)
    {
        main_menu();
    }
    else
    {
        input_clear();
        pause();
        main_menu();
    }
    pause();
    favourites();
}
void settings()
{
    system("cls");
    printf("*******************************\n");
    printf("*    WELCOME TO ADMIN PANEL    *\n");
    printf("*******************************\n\n");

    printf("  1. Read Data\n");
    printf("  2. Edit Data\n");
    printf("  3. Restore Default Values\n");
    printf("  4. Change Password\n");
    printf("  5. Exit From Admin Panel\n");
    printf("  6. Exit From program\n");
    printf("-->>");
    int ch;
    scanf("%d", &ch);
    input_clear();
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
    else if (ch == 4)
    {
        change_password();
    }
    else if (ch == 5)
    {
        main_menu();
    }
    else if (ch == 6)
    {
        printf("\nThank you<3\n");
        exit(0);
    }
    else
    {
        printf("Invalid Input\n");
    }
    pause();
    settings();
}
void history()
{
    FILE *history = fopen("files/history.txt", "r");
    if (history == NULL)
    {
        printf("Failed to Open FILE\n");
        error_handling(1);
    }
    else
    {
        char hi_buffer[1024];
        while (fgets(hi_buffer, sizeof(hi_buffer), history) != NULL)
        {
            printf("%s", hi_buffer);
        }
        printf("\n");
    }
    fclose(history);
    printf("Press [1] to clear history [2]Continue\n-->>>");
    int ch2;
    scanf("%d", &ch2);
    if (ch2 == 1)
    {
        FILE *history = fopen("files/history.txt", "w");
        if (history == NULL)
        {
            printf("Could not access memory\n");
            error_handling(1);
        }
        else
        {
            printf("Memory cleared\n");
            exit_menu(1);
        }
    }
    else if (ch2 == 2)
    {
        exit_menu(1);
    }
    else
    {
        error_handling(1);
    }
}
void continents()
{
    printf("\033[0;34m");
    printf("\n");
    printf("   ------------   --------------   --------------   -----------------   ----------------------   ---------------------\n");
    printf("   | (1) ASIA |   | (2) EUROPE |   | (3) AFRICA |   | (4) AUSTRALIA |   | (5) NORTH AMERICA  |   | (6) SOUTH AMERICA | \n");
    printf("   ------------   --------------   --------------   -----------------   ----------------------   ---------------------\n");
    printf("\n %c Please Choose Continent %c\n", 254, 254);
    printf(" ---------------------------\n");
    printf(" %c Enter a Number -> ", 175);
    printf("\033[0m");
}
void currency_name_of_continent(int choice, const char *file_s_for_currency[])
{
    printf("\033[0;35m");
    FILE *files = fopen(file_s_for_currency[choice - 1], "r");
    if (files == NULL)
    {
        printf("Failed to Open Files\n");
        error_handling(1);
    }
    else
    {
        char buffer[500];
        while (fgets(buffer, sizeof(buffer), files) != NULL)
        {
            printf("%s", buffer);
        }
    }
    fclose(files);
    printf("\033[0m");
}
void read_from_file()
{
    FILE *read = fopen("files/cur_name_list.txt", "r");
    if (read == NULL)
    {
        perror("Error opening cur_name_list.txt");
        pause();
        settings();
    }
    else
    {
        FILE *read2 = fopen("files/bdt_to_any.txt", "r");
        if (read2 == NULL)
        {
            perror("Error opening bdt_to_any.txt");
            pause();
            settings();
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
                    printf("| 1 BDT = %.3f  %s|\n", number, buffer);
                    printf("+------------------------+\n");
                }
                else
                {
                    printf("File ended or error\n");
                    pause();
                    settings();
                }
            }
        }
        fclose(read);
        fclose(read2);
    }
    pause();
    settings();
}
void edit_data()
{
    printf("+----------------------------------------------------+\n");
    printf("| Enter Currency Name to Edit Value (in respect to BDT) |\n");
    printf("+----------------------------------------------------+\n");
    printf("-->>");
    char name2[4];
    long int position = -1;
    scanf("%s", name2);
    for (int i = 0; i < 3; i++)
    {
        name2[i] = toupper(name2[i]);
    }
    FILE *read = fopen("files/cur_name_list.txt", "r");
    if (read == NULL)
    {
        perror("Error opening cur_name_list.txt");
        pause();
        settings();
    }
    else
    {
        FILE *read2 = fopen("files/bdt_to_any.txt", "r+");
        if (read2 == NULL)
        {
            perror("Error opening bdt_to_any.txt");
            pause();
            settings();
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
                    if (strcmp(buffer, name2) == 0)
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
                int ch = 0;
                scanf("%f", &value);
                fseek(read2, position, SEEK_SET);
                if (value < 10)
                {
                    fprintf(read2, "%.3f", value);
                    ch++;
                }
                else if (value > 10 && value < 100)
                {
                    fprintf(read2, "%.2f", value);
                    ch++;
                }
                else
                {
                    printf("CAN'T EDIT VALUE GREATER THEN 99\n");
                }
                if (ch)
                {
                    printf("+------------------------+\n");
                    printf("|        SUCCEED         |\n");
                    printf("| 1 BDT = %.3f %s     |\n", value, buffer);
                    printf("+------------------------+\n");
                    input_clear();
                }
                else
                {
                    input_clear();
                }
            }
            else
            {
                printf("Not Found!\n");
                pause();
                settings();
            }
        }
        fclose(read);
        fclose(read2);
    }

    pause();
    settings();
}
void restore_data()
{
    FILE *read = fopen("files/Backup.txt", "r");
    if (read == NULL)
    {
        perror("Error opening file:");
        pause();
        settings();
    }
    else
    {
        FILE *write = fopen("files/bdt_to_any.txt", "w");
        if (write == NULL)
        {
            perror("Error Opening File:");
            pause();
            settings();
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
    settings();
}
void read_favourites()
{
    FILE *read = fopen("files/Favourites.txt", "r+");
    FILE *user = fopen("files/user.txt", "r");
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
                if (strcmp(buffer, sign_in_user_name) == 0)
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
        fclose(read);
        fclose(user);
        printf("+----------------+\n");
    }
}
void edit_favourites()
{
    system("cls");
    input_clear();
    printf("\n=======================================\n");
    printf("[1] Clear Favorites   [2] Add Favorites\n");
    printf("\n=======================================\n");
    printf("-->> ");
    int ch;
    scanf("%d", &ch);
    if (ch == 1)
    {

        int found = 0;
        FILE *read = fopen("files/Favourites.txt", "r+");
        FILE *user = fopen("files/user.txt", "r+");
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
                    if (strcmp(buffer, sign_in_user_name) == 0)
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
        input_clear();
        int count = 0;
        int cur_count = count_currency();
        cur_count = cur_count - 1;
        printf("\n=============================================\n");
        printf("Add Favorite Characters (Already Added %d ,Now you can add %d Currency | Enter 0 to stop)\n", cur_count, 5 - cur_count);
        printf("\n=============================================\n");
        printf("-->>\n");
        if (cur_count == 5)
        {
            printf("MAXIMUM AMOUNT REACHED\n");
            pause();
            favourites();
        }
        for (int i = 0; i < 5 - cur_count; i++)
        {
            char temp[10];
            scanf(" %9s", temp);
            int loop_size = strlen(temp);
            for (int j = 0; j < loop_size; j++)
            {
                temp[j] = toupper(temp[j]);
            }

            if (strcmp(temp, "0") == 0)
            {
                break;
            }
            int found = check_entry(temp);
            if (found == 1&&strlen(temp)==3)
            {
                strcpy(struct_data[i].fav_currency, temp);
                count++;
            }
            else
            {
                printf("Not In List(Skipped)\n");
            }
        }

        int found2 = 0;
        FILE *read = fopen("files/Favourites.txt", "r+");
        FILE *user = fopen("files/user.txt", "r+");
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
                    if (strcmp(buffer, sign_in_user_name) == 0)
                    {
                        found2 = 1;
                        break;
                    }
                }
                pointer2 = ftell(read);
            }
            if (found2)
            {
                pointer2 = pointer2 + cur_count * 4;
                fseek(read, pointer2, SEEK_SET);
                for (int i = 0; i < count; i++)
                {
                    fprintf(read, "%s+", struct_data[i].fav_currency);
                }
                printf("Succesfully Added\n");
                input_clear();
                pause();
            }
        }
        fclose(read);
        fclose(user);
        favourites();
    }
    favourites();
}
void disassemble(char buffer[])
{
    const char *limiter = "+";
    char *token = strtok(buffer, limiter);

    printf("Favourites:\n");
    while (token != NULL)
    {
        char temp[6];
        strcpy(temp, token);
        int n = check_index(temp);
        if (n < 0)
            break;
        printf("%s = %.3f BDT\n", token, struct_data[n].value);
        token = strtok(NULL, limiter);
    }
    input_clear();
    pause();
    favourites();
}
int check_entry(char input[])
{
    int found = 0;
    for (int i = 0; i < 95; i++)
    {
        if (strcmp(struct_data[i].currency_name, input) == 0)
        {
            found = 1;
            break;
        }
    }
    return found;
}
int check_index(char input[])
{
    int found = -1;
    for (int i = 0; i < 95; i++)
    {
        if (strcmp(struct_data[i].currency_name, input) == 0)
        {
            found = i;
            break;
        }
    }
    return found;
}
int count_currency()
{
    char buffer[50];
    char buffer2[1000];
    FILE *read = fopen("files/Favourites.txt", "r+");
    FILE *user = fopen("files/user.txt", "r+");
    if (read == NULL || user == NULL)
    {
        perror("Failed to open files\n");
    }
    else
    {
        while (fscanf(user, "%[^,],", buffer) == 1)
        {
            if (fscanf(read, "%[^,],", buffer2) == 1)
            {
                if (strcmp(buffer, sign_in_user_name) == 0)
                {
                    break;
                }
            }
        }
    }

    const char *limiter = "+";
    char *token = strtok(buffer2, limiter);
    int count = 0;
    while (token != NULL)
    {
        count++;
        token = strtok(NULL, limiter);
    }
    return count;
}
void change_password()
{
    int found = check_password();
    if (found)
    {
        printf("Enter New Password:\n");
        char pass[20];
        scanf("%s", pass);
        discard_username_password();
        allocate_new_username(pass);
    }
    else
    {
        input_clear();
        printf("Wrong password\n");
        pause();
        settings();
    }
}
int check_password()
{
    int found2 = 0, count1 = 0, count2 = 0;
    char buffer1[20];
    char buffer2[20];
    char pass[20];
    FILE *userpointer = fopen("files/username_list.txt", "r");
    if (userpointer == NULL)
    {
        perror("Server Error\n");
    }
    else
    {
        while (fscanf(userpointer, "%[^,],", buffer1) == 1)
        {
            count1++;
            if (strcmp(buffer1, sign_in_user_name) == 0)
            {
                break;
            }
        }
        fclose(userpointer);
        printf("Hello %s Enter your Password\n", sign_in_user_name);
        printf("-->>");
        scanf("%s", pass);
        FILE *passpointer = fopen("files/password_list.txt", "r");
        if (passpointer == NULL)
        {
            perror("Server Error\n");
        }
        else
        {

            while (fscanf(passpointer, "%[^,],", buffer2) == 1)
            {
                count2++;
                if (strcmp(buffer2, pass) == 0)
                {

                    if (count1 == count2)
                    {
                        found2 = 1;
                        break;
                    }
                }
            }
            fclose(passpointer);
        }
    }
    return found2;
}
void discard_username_password()
{
    int count1 = 0, count2 = 0;
    char buffer1[20];
    FILE *open_username = fopen("files/username_list.txt", "r+");
    FILE *open_password = fopen("files/password_list.txt", "r+");
    if (open_username == NULL || open_password == NULL)
    {
        perror("Error");
    }
    int position = ftell(open_username);
    char buffer[20];
    while (fscanf(open_username, "%[^,],", buffer) == 1)
    {
        count1++;
        if (strcmp(buffer, sign_in_user_name) == 0)
        {
            break;
        }
        position = ftell(open_username);
    }
    int len1 = strlen(buffer);
    for (int i = 0; i < len1; i++)
    {
        fseek(open_username, position, SEEK_SET);
        fprintf(open_username, "$");
        position++;
    }

    fclose(open_username);
    position = ftell(open_password);
    while (fscanf(open_password, "%[^,],", buffer1) == 1)
    {
        count2++;
        if (count1 == count2)
        {
            break;
        }
        position = ftell(open_password);
    }
    int len = strlen(buffer1);
    for (int i = 0; i < len; i++)
    {
        fseek(open_password, position, SEEK_SET);
        fprintf(open_password, "$");
        position++;
    }

    fclose(open_password);
}
void allocate_new_username(char pass[])
{
    FILE *open_username = fopen("files/username_list.txt", "a");
    FILE *open_password = fopen("files/password_list.txt", "a");
    if (open_password == NULL || open_username == NULL)
    {
        perror("Error\n");
    }
    else
    {

        fprintf(open_username, "%s,", sign_in_user_name);
        fprintf(open_password, "%s,", pass);
    }
    fclose(open_password);
    fclose(open_username);

    printf("Successfully Changed Password, Please Re login\n");
    input_clear();
    pause();
    login_page();
}
