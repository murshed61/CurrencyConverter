#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include <time.h>

//Function Declaration
void currencyconversion(int from,int to,float value,char* currency_name[],float bdt_to_any[],float any_to_bdt[]);
void continents();
void currency_name_of_continent(int choice,const char* file_s_for_currency[]);
void error_handling();
void exit_menu();



//MAIN Function - code start from here >
int main()
{
    system("cls");
    const char* history = "history.txt";
    const char* fileadrs_for_all_currency = "Currency_List.txt";//Specify exact file location here
    const char* file_s_for_currency[]= {"Asia_currency.txt","Europe_currency.txt","Africa_currency.txt","Australia.txt","North_america_currency.txt","South_america_currency.txt"};
    char* currency_name[]= {"BDT", "CNY", "INR", "KRW", "SAR",
                            "THB","TRY", "RUB", "IDR", "PKR","MYR","SGD","ILS","IRR",
                            "VND","JPY","PHP","KZT","LKR","AED","EUR", "GBP", "CHF", "SEK", "NOK",
                            "DKK", "HUF", "PLN", "CZK", "BGN",
                            "HRK", "RON", "UAH", "ISK","RSD",
                            "DZD", "EGP", "ZAR",
                            "NGN", "KES", "MAD", "ETB", "GHS", "TZS", "UGX", "RWF", "BWP", "ZMW", "TND", "ZWL",
                            "AUD", "NZD", "FJD", "PGK", "WST",
                            "TOP", "SBD", "VUV", "XPF", "NAD",
                            "CKD", "TVD", "VUV", "KID", "PWG",
                            "USD", "CAD", "MXN", "GTQ", "CRC",
                            "HNL", "SVC", "PAB", "JMD", "BSD",
                            "CUP", "DOP", "TTD", "BMD", "NIO",
                            "ARS", "BRL", "CLP", "COP", "PEN",
                            "VES", "BOB", "PYG", "UYU", "GYD",
                            "SRD", "ECS", "FKP", "AWG", "BZD"
                           };//currency names
    float bdt_to_any[]= {1,0.066,0.76,12.08,0.034,0.33,0.25,0.88,139.82,2.69,0.043,0.012,0.035,384.99,
                         220.18,1.34,0.52,4.25,2.95,0.033,0.0085,0.0073,0.0081,0.10,0.098,0.063,3.25,0.039,0.21,0.017,0.063,0.042,0.34,1.22,1,
                         1.25,0.28,0.17,6.79,1.34,0.093,0.50,0.10,22.84,33.93,10.98,0.12,0.19,0.029,3.29,
                         0.014,0.015,0.021,0.033,0.025,0.022,0.077,1.1152,1.02,0.17,0.007,0.014,1.115,15.79,0.0091,0.0091,0.012,0.16,0.072,4.87,
                         0.22,0.08,0.0091,1.41,0.0091,0.22,0.52,0.062,0.0091,0.33,3.19,0.045,8.04,36.12,0.034,0.303,0.063,66.33,0.35,1.91,0.35,
                         228.94,0.0072,0.016,0.018
                        };//currency rates
    float any_to_bdt[95];
    for(int i=0; i<95; i++)
    {
        any_to_bdt[i]=1/bdt_to_any[i];
    }

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
            printf(" %s |",currency_name[random_index]);
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
            if(strcmp(currency_name[i],name1)==0)
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
            printf("\tSELECTED CURRENCY IS || %s ||\n",currency_name[from-1]);
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
            if(strcmp(currency_name[i],name2)==0)
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
            printf("\tSELECTED CURRENCY IS || %s ||\n",currency_name[to-1]);
            printf("\t------------------------------\n");
            printf("\033[0m");
        }
        printf("\n\t%c Enter amount -> ",254);
        scanf("%f",&amount);

        currencyconversion(from,to,amount,currency_name,bdt_to_any,any_to_bdt);
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
        currencyconversion(from,to,amount,currency_name,bdt_to_any,any_to_bdt);
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
void currencyconversion(int from,int to,float value,char* currency_name[],float bdt_to_any[],float any_to_bdt[])
{
    FILE* file=fopen("history.txt","a");
    if(file==NULL)
    {
        printf("Memory could not be accessed\n");
    }
    for(int i=0; i<95; i++)
    {
        any_to_bdt[i]=1/bdt_to_any[i];
    }

    printf("\033[1;31m");
    if(from==to)//same currency
    {
        printf("\n\n\t<=--------------------------------------------=>\n");
        printf("\t\t%.2f %s TO %s = %.2f %s\n",value,currency_name[from-1],currency_name[to-1],value,currency_name[to-1]);
        printf("\t<=--------------------------------------------=>\n");
        fprintf(file,"\n%.2f %s TO %s = %.2f %s",value,currency_name[from-1],currency_name[to-1],value,currency_name[to-1]);
    }
    else if(from==1)//bdt_to_any
    {
        float calculated_any_value=bdt_to_any[to-1]*value;
        printf("\n\n\t<=--------------------------------------------=>\n");
        printf("\t\t%.2f %s TO %s = %.2f %s\n",value,currency_name[from-1],currency_name[to-1],calculated_any_value,currency_name[to-1]);
        printf("\t<=--------------------------------------------=>\n");
        fprintf(file,"\n%.2f %s TO %s = %.2f %s\n",value,currency_name[from-1],currency_name[to-1],calculated_any_value,currency_name[to-1]);
    }
    else if(to==1)//any_to_bdt
    {
        float calculated_bdt_value = any_to_bdt[from-1]*value;
        printf("\n\n\t<=--------------------------------------------=>\n");
        printf("\t\t%.2f %s TO %s = %.2f %s\n",value,currency_name[from-1],currency_name[to-1],calculated_bdt_value,currency_name[to-1]);
        printf("\t<=--------------------------------------------=>\n");
        fprintf(file,"\n%.2f %s TO %s = %.2f %s\n",value,currency_name[from-1],currency_name[to-1],calculated_bdt_value,currency_name[to-1]);
    }
    else if(from!=to)//ANY TO ANY
    {
        float anyToBdt = any_to_bdt[from-1]*value;
        float calculated_any = bdt_to_any[to-1]*anyToBdt;

        printf("\n\n\t<=--------------------------------------------=>\n");
        printf("\t\t%.2f %s TO %s = %.2f %s\n",value,currency_name[from-1],currency_name[to-1],calculated_any,currency_name[to-1]);
        printf("\t<=--------------------------------------------=>\n");
        fprintf(file,"\n%.2f %s TO %s = %.2f %s\n",value,currency_name[from-1],currency_name[to-1],calculated_any,currency_name[to-1]);
    }
    printf("\033[0m");
    fclose(file);
    
    
    
}