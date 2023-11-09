#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include <time.h>
//Structure Declaration
typedef struct records
{
    char currency_name[5];
    float value;
    float value2;
}data;
//Function Declaration
void currencyconversion(int from,int to,float value,data record[]);
void continents();
void currency_name_of_continent(int choice,const char* file_s_for_currency[]);
void error_handling();
void exit_menu();
void read_data_from_files(data input[]);
void pause();
void adminpanel();
void read_from_file();
void edit_data();
void restore_data();
void access_admin();

//MAIN Function - code start from here >
int main()
{
    system("cls");
    data record[95];
    const char* fileadrs_for_all_currency = "Currency_List.txt";//Specify exact file location here
    const char* file_s_for_currency[]= {"Asia_currency.txt","Europe_currency.txt","Africa_currency.txt","Australia.txt","North_america_currency.txt","South_america_currency.txt"};

    read_data_from_files(record);
    //welcome heading
    printf("\033[0;36m");
    printf("\t\t\t\t\t\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\////////////////////\n");
    printf("\t\t\t\t\t    %c Welcome to Currency Converter %c\n",175,174);
    printf("\t\t\t\t\t////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n");
    printf("\033[0m");


    int from,to,continent_from,continent_to;
    float amount;
    int ch;
    printf("\033[32m");//Green color code
    printf("\n");
    printf("\t\t\t\t\t\t*************************\n");
    printf("\t\t\t\t\t\t*    %c MENU OPTIONS %c   *\n",175,174);
    printf("\t\t\t\t\t\t* [1] SEARCH TO CONVERT *\n");
    printf("\t\t\t\t\t\t* [2] MANUAL CONVERSION *\n");
    printf("\t\t\t\t\t\t* [3] CURRENCY LIST     *\n");
    printf("\t\t\t\t\t\t* [4] Show History      *\n");
    printf("\t\t\t\t\t\t* [5] Admin Panel       *\n");
    printf("\t\t\t\t\t\t*************************\n");
    printf("\t\t\t\t\t\t%c Enter Choice -> ",254);
    printf("\033[0m");// Reset text color to default

    scanf("%d",&ch);
    if(ch==1)
    {

        srand(time(NULL));
        char name1[4];
        char name2[4];
        int num_currencies = 95;

        //time.h - random currency generator
        printf("\033[0;34m");
        printf("\n\t----------------------------------------------------------------------------------------------\n");
        printf("\t| Popular Currencies of the Day: |");
        for (int i = 0; i < 10; i++)
        {
            int random_index = rand() % num_currencies;
            printf(" %s |",record[random_index].currency_name);
        }
        printf("\n\t----------------------------------------------------------------------------------------------\n");
        printf("\033[0m");


        printf("\n\t%c Enter the name of the currency you want to convert FROM -> ",254);

        scanf("%s",name1);

        for(int i = 0; i<3; i++)
        {
            name1[i]=toupper(name1[i]);
        }
        bool found1 = false;
        for(int i = 0; i<95; i++)
        {
            if(strcmp(record[i].currency_name,name1)==0)
            {
                found1 = true;
                from = i+1;
                break;
            }
            else if(i==94)
            {
                printf("\033[0;31m\n\tCURRENCY NOT FOUND!\n\033[0m");
                error_handling();
            }
        }
        if(found1)
        {
            printf("\033[0;32m");
            printf("\t------------------------------\n");
            printf("\tSELECTED CURRENCY IS || %s ||\n",record[from-1].currency_name);
            printf("\t------------------------------\n");
            printf("\033[0m");
        }
        printf("\n\t%c Enter name of the currency you want to convert TO -> ",254);
        scanf("%s",name2);
        for(int i = 0; i<3; i++)
        {
            name2[i]=toupper(name2[i]);
        }
        bool found2 = false;
        for(int i = 0; i<95; i++)
        {
            if(strcmp(record[i].currency_name,name2)==0)
            {
                found2 = true;
                to = i+1;
                break;
            }
            else if(i==94)
            {
                printf("\033[0;31m\n\tCURRENCY NOT FOUND!\n\033[0m");
                exit_menu();
            }
        }
        if(found2)
        {
            printf("\033[0;32m");
            printf("\t------------------------------\n");
            printf("\tSELECTED CURRENCY IS || %s ||\n",record[to-1].currency_name);
            printf("\t------------------------------\n");
            printf("\033[0m");
        }
        printf("\n\t%c Enter amount -> ",254);
        scanf("%f",&amount);

        currencyconversion(from,to,amount,record);
        exit_menu();
    }

    else if(ch==2)
    {

        //Taking input continent_from and from
        continents();
        scanf("%d",&continent_from);
        if(continent_from>0&&continent_from<=6)
        {
            currency_name_of_continent(continent_from,file_s_for_currency);
        }
        else
        {
            error_handling();
        }


        printf("\033[1;36m");
        printf("\n\n %c Please Choose & Enter a Number %c\n",254,254);
        printf(" ------------------------------------\n");
        printf(" %c Currency To Convert FROM -> ",175);
        printf("\033[0m");
        scanf("%d",&from);
        if(continent_from==1 && from>20 || from<1)
        {
            error_handling();
        }
        else if(continent_from!=1 && from>15 || from<1)
        {
            error_handling();
        }


        //Taking input continent_to and to
        continents();
        scanf("%d",&continent_to);

        if(continent_to>0&&continent_to<=6)
        {
            currency_name_of_continent(continent_to,file_s_for_currency);
        }
        else
        {
            error_handling();
        }
        printf("\033[1;36m");
        printf("\n\n %c Please Choose & Enter a Number %c\n",254,254);
        printf(" ------------------------------------\n");
        printf(" %c Currency To Convert TO -> ",175);
        printf("\033[0m");
        scanf("%d",&to);
        if(to>20 || to<1 && continent_to==1)
        {
            error_handling();
        }
        else if((to>15 || to<1) && (continent_to>1))
        {
            error_handling();
        }

        printf("\033[1;32m");
        printf("\n\n %c Please Enter The Amount To CONVERT -> ",175);
        printf("\033[0m");
        scanf("%f",&amount);

        switch (continent_from)
        {
        case 1:
            from=from;
            break;
        case 2:
            from=from+20;
            break;
        case 3:
            from=from+35;
            break;
        case 4:
            from = from+50;
            break;
        case 5:
            from = from+65;
            break;
        case 6:
            from = from+80;
            break;
        }
        switch (continent_to)
        {
        case 1:
            to=to;
            break;
        case 2:
            to=to+20;
            break;
        case 3:
            to=to+35;
            break;
        case 4:
            to=to+50;
            break;
        case 5:
            to=to+65;
            break;
        case 6:
            to=to+80;
            break;
        }
        if(to<=0&&to>95)
        {
            error_handling();
        }
        currencyconversion(from,to,amount,record);
        exit_menu();
    }
    else if(ch==3)
    {
        printf("\033[0;36m ||ALL CURRENCY LIST||\n\n\033[0m");
        FILE* files = fopen(fileadrs_for_all_currency,"r");
        if(files==NULL)
        {
            printf("\033[0;31m\n\tFailed to open FILE!\n\033[0m");
            error_handling();
        }
        else
        {
            char buffer[1024];
            while(fgets(buffer,sizeof(buffer),files)!=NULL)
            {

                printf("\033[1;36m%s\033[0m",buffer);
            }
        }
        fclose(files);
        printf("\033[0;36m\n\n %c Press enter to continue...\033[0m",254);
        getchar();
        exit_menu();
    }
    else if(ch==4)
    {
        FILE* history=fopen("history.txt","r");
        if(history==NULL)
        {
            printf("Failed to Open FILE\n");
            error_handling();
        }
        else
        {
            char hi_buffer[1024];
            while(fgets(hi_buffer,sizeof(hi_buffer),history)!=NULL)
            {
                printf("%s",hi_buffer);
            }
            printf("\n");
        }
        fclose(history);
        printf("Press [1] to clear history [2]Continue\n-->>>");
        int ch2;
        scanf("%d",&ch2);
        if(ch2==1)
        {
            FILE* history=fopen("history.txt","w");
            if(history==NULL)
            {
                printf("Could not access memory\n");
                error_handling();
            }
            else
            {
                printf("Memory cleared\n");
                exit_menu();
            }
        }
        else if(ch2==2)
        {
            exit_menu();
        }
        else
        {
            error_handling();
        }
    }
    else if(ch==5)
    {
        access_admin();
    }
    else
    {
        error_handling();
    }

    return 0;


}

//Function Definition
void continents()
{
    printf("\033[0;34m");
    printf("\n");
    printf("   ------------   --------------   --------------   -----------------   ----------------------   ---------------------\n");
    printf("   | (1) ASIA |   | (2) EUROPE |   | (3) AFRICA |   | (4) AUSTRALIA |   | (5) NORTH AMERICA  |   | (6) SOUTH AMERICA | \n");
    printf("   ------------   --------------   --------------   -----------------   ----------------------   ---------------------\n");
    printf("\n %c Please Choose Continent %c\n",254,254);
    printf(" ---------------------------\n");
    printf(" %c Enter a Number -> ",175);
    printf("\033[0m");
}
void currency_name_of_continent(int choice,const char* file_s_for_currency[])
{
    printf("\033[0;35m");
    FILE* files=fopen(file_s_for_currency[choice-1],"r");
    if(files==NULL)
    {
        printf("Failed to Open Files\n");
        error_handling();
    }
    else
    {
        char buffer[500];
        while(fgets(buffer,sizeof(buffer),files)!=NULL)
        {
            printf("%s",buffer);
        }
    }
    fclose(files);
    printf("\033[0m");
}
void error_handling()
{
    printf("\033[0;31m\n\tSomething is Wrong!!\n\033[0m");
    exit_menu(); //function to function call

}
void exit_menu()
{
    int c;
    while((c=getchar())!='\n'&&c!=EOF);
    printf("\033[0;44m");
    char close;
    printf("\n %c Enter   (+) for More Conversion   (?) for About us   (X) for Exit... -> ",254);
    printf("\033[0m");
    scanf(" %c",&close);
    if (close == 'x'||close == 'X')
    {
        printf("\033[1;31m\n Thank You <3\n\033[0m");
        exit(0);
    }
    else if (close == '?')
    {
        system("cls");
        printf("\033[1;31m");
        printf("\n %c About Us %c\n",175,174);
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
        exit_menu();
    }
    else if (close == '+')
    {
        main();
    }
    else
    {
        error_handling();

    }
    printf("\033[0m");

}
void currencyconversion(int from,int to,float value,data record[])
{
    FILE* file=fopen("history.txt","a");
    if(file==NULL)
    {
        printf("Memory could not be accessed\n");
    }

    printf("\033[1;31m");
    if(from==to)//same currency
    {
        printf("\n\n\t<=--------------------------------------------=>\n");
        printf("\t\t%.2f %s TO %s = %.2f %s\n",value,record[from-1].currency_name,record[to-1].currency_name,value,record[to-1].currency_name);
        printf("\t<=--------------------------------------------=>\n");
        fprintf(file,"\n%.2f %s TO %s = %.2f %s",value,record[from-1].currency_name,record[to-1].currency_name,value,record[to-1].currency_name);
    }
    else if(from==1)//bdt_to_any
    {
        float calculated_any_value=record[to-1].value*value;
        printf("\n\n\t<=--------------------------------------------=>\n");
        printf("\t\t%.2f %s TO %s = %.2f %s\n",value,record[from-1].currency_name,record[to-1].currency_name,calculated_any_value,record[to-1].currency_name);
        printf("\t<=--------------------------------------------=>\n");
        fprintf(file,"\n%.2f %s TO %s = %.2f %s\n",value,record[from-1].currency_name,record[to-1].currency_name,calculated_any_value,record[to-1].currency_name);
    }
    else if(to==1)//any_to_bdt
    {
        float calculated_bdt_value = record[from-1].value2*value;
        printf("\n\n\t<=--------------------------------------------=>\n");
        printf("\t\t%.2f %s TO %s = %.2f %s\n",value,record[from-1].currency_name,record[to-1].currency_name,calculated_bdt_value,record[to-1].currency_name);
        printf("\t<=--------------------------------------------=>\n");
        fprintf(file,"\n%.2f %s TO %s = %.2f %s\n",value,record[from-1].currency_name,record[to-1].currency_name,calculated_bdt_value,record[to-1].currency_name);
    }
    else if(from!=to)//ANY TO ANY
    {
        float anyToBdt = record[from-1].value2*value;
        float calculated_any = record[to-1].value*anyToBdt;

        printf("\n\n\t<=--------------------------------------------=>\n");
        printf("\t\t%.2f %s TO %s = %.2f %s\n",value,record[from-1].currency_name,record[to-1].currency_name,calculated_any,record[to-1].currency_name);
        printf("\t<=--------------------------------------------=>\n");
        fprintf(file,"\n%.2f %s TO %s = %.2f %s\n",value,record[from-1].currency_name,record[to-1].currency_name,calculated_any,record[to-1].currency_name);
    }
    printf("\033[0m");
    fclose(file);

    
    
    
}
void read_data_from_files(data input[])
{
     FILE* names=fopen("cur_name_list.txt","r");
     if(names==NULL)
     {
        perror("Error Opening File");
        pause();
        error_handling();
       
     }
     else
     {
        char buffer[5];
        for(int i = 0;i<95;i++)
        {
            fscanf(names, "%[^,],", buffer);
            strcpy(input[i].currency_name,buffer);
        }
        fclose(names);
     }
     FILE* names2=fopen("bdt_to_any.txt","r");
     if(names2==NULL)
     {
        perror("Error Opening File");
        pause();
        error_handling();
       
     }
     else
     {
        float amount;
        for(int i = 0;i<95;i++)
        {
            fscanf(names2, "%f,",&amount);
            input[i].value=amount;
        }
        fclose(names2);
     }
    for(int i=0; i<95; i++)
    {
        input[i].value2=1/input[i].value;
    }
}
void pause()
{
    int c;
    printf("\nPress Enter to continue\n");
    while ((c = getchar()) != '\n' && c != EOF);
    getchar();
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