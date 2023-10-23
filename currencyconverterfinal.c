#include <stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<stdbool.h>
#include<ctype.h>
#include <time.h>
void currencyconversion(int from,int to,float value,char* currency_name[],float bdt_to_any[],float any_to_bdt[])
{
    for(int i=0; i<95; i++)
    {
        any_to_bdt[i]=1/bdt_to_any[i];
    }

    printf("\033[0;46m");
    if(from==to)//same currency
    {
        printf("\t------------ -------------- ---------------------\n");
        printf("\t%.2f %s TO %s = %.2f %s\n",value,currency_name[from-1],currency_name[to-1],value,currency_name[to-1]);
        printf("\t------------ -------------- ---------------------\n");
    }
    else if(from==1)//bdt_to_any
    {
        float calculated_any_value=bdt_to_any[to-1]*value;
        printf("\t------------ -------------- ---------------------\n");
        printf("\t%.2f %s TO %s = %.2f %s\n",value,currency_name[from-1],currency_name[to-1],calculated_any_value,currency_name[to-1]);
        printf("\t------------ -------------- ---------------------\n");
    }
    else if(to==1)//any_to_bdt
    {
        float calculated_bdt_value = any_to_bdt[from-1]*value;
        printf("\t------------ -------------- ---------------------\n");
        printf("\t%.2f %s TO %s = %.2f %s\n",value,currency_name[from-1],currency_name[to-1],calculated_bdt_value,currency_name[to-1]);
        printf("\t------------ -------------- ---------------------\n");
    }
    else if(from!=to)//ANY TO ANY
    {
        float anyToBdt = any_to_bdt[from-1]*value;
        float calculated_any = bdt_to_any[to-1]*anyToBdt;
        printf("\t------------ -------------- ---------------------\n");
        printf("\t%.2f %s TO %s = %.2f %s\n",value,currency_name[from-1],currency_name[to-1],calculated_any,currency_name[to-1]);
        printf("\t------------ -------------- ---------------------\n");
    }
    printf("\033[0m");
}

int main()
{
    system("cls");
    char *currency_name[]= {"BDT", "CNY", "INR", "KRW", "SAR",
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
                            "SRD", "ECS", "FKP", "AWG", "BZD"//
                           };
    float bdt_to_any[]= {1,0.066,0.76,12.08,0.034,0.33,0.25,0.88,139.82,2.69,0.043,0.012,0.035,384.99,
                         220.18,1.34,0.52,4.25,2.95,0.033,0.0085,0.0073,0.0081,0.10,0.098,0.063,3.25,0.039,0.21,0.017,0.063,0.042,0.34,1.22,1,
                         1.25,0.28,0.17,6.79,1.34,0.093,0.50,0.10,22.84,33.93,10.98,0.12,0.19,0.029,3.29,
                         0.014,0.015,0.021,0.033,0.025,0.022,0.077,1.1152,1.02,0.17,0.007,0.014,1.115,15.79,0.0091,0.0091,0.012,0.16,0.072,4.87,
                         0.22,0.08,0.0091,1.41,0.0091,0.22,0.52,0.062,0.0091,0.33,3.19,0.045,8.04,36.12,0.034,0.303,0.063,66.33,0.35,1.91,0.35,
                         228.94,0.0072,0.016,0.018
                        };
    float any_to_bdt[200];

    //welcome heading

    printf("\033[0;36m");
    printf("\t\t\t\t\t\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\////////////////////\n");
    printf("\t\t\t\t\t    %c Welcome to Currency Converter %c\n",175,174);
    printf("\t\t\t\t\t////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n");
    printf("\033[0m");

    while(1)
    {
        int from,to,continent_from,continent_to;
        float amount;
        int ch;
        printf("\033[32m");

        printf("*****************************************\n");
        printf("           MENU OPTIONS                 \n");
        printf("[1] SEARCH TO CONVERT                 \n");
        printf("[2] MANUAL CONVERSION                 \n");
        printf("[3] CURRENCY LIST                     \n");
        printf("*****************************************\n");
        printf("Enter Choice-->> ");

        // Reset text color to default
        printf("\033[0m");

        scanf("%d",&ch);
        if(ch==1)
        {

            srand(time(NULL));
            char name1[3];
            char name2[3];
            int num_currencies = sizeof(currency_name) / sizeof(currency_name[0]);

            printf("-------------------------------------------------------------------------------------------");
            printf("\nPopular Currencies of the Day: ");



            for (int i = 0; i < 10; i++)
            {
                int random_index = rand() % num_currencies;
                printf("%c %s ", 254,currency_name[random_index]);
            }
            printf("\n-------------------------------------------------------------------------------------------");
            printf("\n\n");


            printf("Enter the name of the currency you want to convert from:(usd,bdt,cny,etc....)%c%c",254,175);

            scanf("%s",&name1);

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
                    printf("CURRENCY NOT FOUND\n");
                    exit_menu();
                }
            }
            if(found1)
            {
                printf("------------------------------\n");
                printf("SELECTED CURRENCY IS || %s ||\n",currency_name[from-1]);
                printf("------------------------------\n");
            }
            printf("Enter name of the currency you want to convert to-->");
            scanf("%s",&name2);
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
                    printf("CURRENCY NOT FOUND\n");
                    exit_menu();
                }
            }
            if(found2)
            {
                printf("------------------------------\n");
                printf("SELECTED CURRENCY IS || %s ||\n",currency_name[to-1]);
                printf("------------------------------\n");
            }
            printf("Enter amount-->");
            scanf("%f",&amount);
            currencyconversion(from,to,amount,currency_name,bdt_to_any,any_to_bdt);
            exit_menu();
        }

        else if(ch==2)
        {

            //Taking input continent_from and from
            continents();


            scanf("%d",&continent_from);

            switch (continent_from)
            {
            case 1:
                asia_currencys();
                break;
            case 2:
                europe_currencys();
                break;
            case 3:
                africa_currencys();
                break;
            case 4:
                australia_currencys();
                break;
            case 5:
                north_america_currencys();
                break;
            case 6:
                south_america_currencys();
                break;

            default:
                error_handling();
                break;
            }
            printf("\033[0;31m");
            printf("\033[0;44m");
            printf("\n\n %c Please Choose & Enter a Number %c\n",254,254);
            printf(" ------------------------------------\n");
            printf(" %c Currency To Convert From -> ",175);
            scanf("%d",&from);
            printf("\033[0m");
            if(continent_from==1&&from>20||from<1)
            {

                error_handling();
            }
            else if(continent_from!=1&&from>15||from<1)
            {
                error_handling();
            }
            //Taking input continent_to and to
            continents();
            scanf("%d",&continent_to);

            switch (continent_to)
            {
            case 1:
                asia_currencys();
                break;
            case 2:
                europe_currencys();
                break;
            case 3:
                africa_currencys();
                break;
            case 4:
                australia_currencys();
                break;
            case 5:
                north_america_currencys();
                break;
            case 6:
                south_america_currencys();
                break;

            default:
                error_handling();
                break;
            }
            printf("\033[0;42m");
            printf("\n\n %c Please Choose & Enter a Number %c\n",254,254);
            printf(" ------------------------------------\n");
            printf(" %c Currency To Convert To -> ",175);
            scanf("%d",&to);
            printf("\033[0m");
            if(to>20||to<1&&continent_to==1)
            {
                error_handling();
            }
            else if(to>15||to<1&&continent_to>1)
            {
                error_handling();
            }

            printf("\033[0;41m");
            printf("\n %c Please Enter The Amount To CONVERT -> ",175);
            scanf("%f",&amount);
            printf("\033[0m");
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
            printf("||ALL CURRENCY LIST||\n");
            for(int i = 0; i<95; i++)
            {
                printf("|%d| %s \n",i+1,currency_name[i]);
            }
            getchar();
            exit_menu();

        }
        else
        {
            error_handling();
        }

    }
    return 0;


}

void continents()
{
    printf("\033[0;32m");
    printf("\n");
    printf("   ------------   --------------   --------------   -----------------   ----------------------   ---------------------\n");
    printf("   | (1) ASIA |   | (2) EUROPE |   | (3) AFRICA |   | (4) AUSTRALIA |   | (5) NORTH AMERICA  |   | (6) SOUTH AMERICA | \n");
    printf("   ------------   --------------   --------------   -----------------   ----------------------   ---------------------\n");
    printf("\n %c Please Choose Continent %c\n",254,254);
    printf(" ---------------------------\n");
    printf(" %c Enter a Number -> ",175);
    printf("\033[0m");
}
void asia_currencys()
{
    printf("\033[0;35m");
    printf("\n %c ASIA's Available Currencys %c\n",254,254);
    printf(" ------------------------------------\n");
    printf("  [1] Bangladeshi Taka (BDT)\n");
    printf("  [2] Chinese Yuan (CNY)\n");
    printf("  [3] Indian Rupee (INR)\n");
    printf("  [4] South Korean Won (KRW)\n");
    printf("  [5] Saudi Riyal (SAR)\n");
    printf("  [6] Thai Baht (THB)\n");
    printf("  [7] Turkish Lira (TRY)\n");
    printf("  [8] Russian Ruble (RUB)\n");
    printf("  [9] Indonesian Rupiah (IDR)\n");
    printf(" [10] Pakistani Rupee (PKR)\n");
    printf(" [11] Malaysian Ringgit (MYR)\n");
    printf(" [12] Singapore Dollar (SGD)\n");
    printf(" [13] Israeli New Shekel (ILS)\n");
    printf(" [14] Iranian Rial (IRR)\n");
    printf(" [15] Vietnamese Dong (VND)\n");
    printf(" [16] Japanese Yen (JPY)\n");
    printf(" [17] Philippine Peso (PHP)\n");
    printf(" [18] Kazakhstani Tenge (KZT)\n");
    printf(" [19] Sri Lankan Rupee (LKR)\n");
    printf(" [20] United Arab Emirates Dirham (AED)\n");
    printf("\033[0m");
}
void europe_currencys()
{
    printf("\033[0;35m");
    printf("\n %c EUROPE's Available Currencys %c\n",254,254);
    printf(" ------------------------------------\n");
    printf("  [1] Euro (EUR)\n");
    printf("  [2] British Pound Sterling (GBP)\n");
    printf("  [3] Swiss Franc (CHF)\n");
    printf("  [4] Swedish Krona (SEK)\n");
    printf("  [5] Norwegian Krone (NOK)\n");
    printf("  [6] Danish Krone (DKK)\n");
    printf("  [7] Hungarian Forint (HUF)\n");
    printf("  [8] Polish Zloty (PLN)\n");
    printf("  [9] Czech Koruna (CZK)\n");
    printf(" [10] Bulgarian Lev (BGN)\n");
    printf(" [11] Croatian Kuna (HRK)\n");
    printf(" [12] Romanian Leu (RON)\n");
    printf(" [13] Ukrainian Hryvnia (UAH)\n");
    printf(" [14] Icelandic Krona (ISK)\n");
    printf(" [15] Serbian Dinar (RSD)\n");
    printf("\033[0m");
}
void africa_currencys()
{
    printf("\033[0;35m");
    printf("\n %c AFRICA's Available Currencys %c\n",254,254);
    printf(" ------------------------------------\n");
    printf("  [1] Algerian Dinar (DZD)\n");
    printf("  [2] Egyptian Pound (EGP)\n");
    printf("  [3] South African Rand (ZAR)\n");
    printf("  [4] Nigerian Naira (NGN)\n");
    printf("  [5] Kenyan Shilling (KES)\n");
    printf("  [6] Moroccan Dirham (MAD)\n");
    printf("  [7] Ethiopian Birr (ETB)\n");
    printf("  [8] Ghanaian Cedi (GHS)\n");
    printf("  [9] Tanzanian Shilling (TZS)\n");
    printf(" [10] Ugandan Shilling (UGX)\n");
    printf(" [11] Rwandan Franc (RWF)\n");
    printf(" [12] Botswana Pula (BWP)\n");
    printf(" [13] Zambian Kwacha (ZMW)\n");
    printf(" [14] Tunisian Dinar (TND)\n");
    printf(" [15] Zimbabwean Dollar (ZWL)\n");
    printf("\033[0m");
}
void australia_currencys()
{
    printf("\033[0;35m");
    printf("\n %c AUSTRALIA's Available Currencys %c\n",254,254);
    printf(" ------------------------------------\n");
    printf("  [1] Australian Dollar (AUD)\n");
    printf("  [2] New Zealand Dollar (NZD)\n");
    printf("  [3] Fijian Dollar (FJD)\n");
    printf("  [4] Papua New Guinean Kina (PGK)\n");
    printf("  [5] Samoan Tala (WST)\n");
    printf("  [6] Tongan Pa'anga (TOP)\n");
    printf("  [7] Solomon Islands Dollar (SBD)\n");
    printf("  [8] Vanuatu Vatu (VUV)\n");
    printf("  [9] New Caledonian Franc (XPF)\n");
    printf(" [10] Nauruan Dollar (NAD)\n");
    printf(" [11] Cook Islands Dollar (CKD)\n");
    printf(" [12] Tuvaluan Dollar (TVD)\n");
    printf(" [13] Ni-Vanuatu Vatu (VUV)\n");
    printf(" [14] Kiribati Dollar (KID)\n");
    printf(" [15] Palauan Dollar (PWG)\n");
    printf("\033[0m");
}
void north_america_currencys()
{
    printf("\033[0;35m");
    printf("\n %c NORTHA AMERICA's Available Currencys %c\n",254,254);
    printf(" ------------------------------------\n");
    printf("  [1] United States Dollar (USD)\n");
    printf("  [2] Canadian Dollar (CAD)\n");
    printf("  [3] Mexican Peso (MXN)\n");
    printf("  [4] Guatemalan Quetzal (GTQ)\n");
    printf("  [5] Costa Rican Colon (CRC)\n");
    printf("  [6] Honduran Lempira (HNL)\n");
    printf("  [7] Salvadoran Colon (SVC)\n");
    printf("  [8] Panamanian Balboa (PAB)\n");
    printf("  [9] Jamaican Dollar (JMD)\n");
    printf(" [10] Bahamian Dollar (BSD)\n");
    printf(" [11] Cuban Peso (CUP)\n");
    printf(" [12] Dominican Peso (DOP)\n");
    printf(" [13] Trinidad and Tobago Dollar (TTD)\n");
    printf(" [14] Bermudian Dollar (BMD)\n");
    printf(" [15] Nicaraguan Cordoba (NIO)\n");
    printf("\033[0m");
}
void south_america_currencys()
{
    printf("\033[0;35m");
    printf("\n %c SOUTH AMERICA's Available Currencys %c\n",254,254);
    printf(" ------------------------------------\n");
    printf("  [1] Argentine Peso (ARS)\n");
    printf("  [2] Brazilian Real (BRL)\n");
    printf("  [3] Chilean Peso (CLP)\n");
    printf("  [4] Colombian Peso (COP)\n");
    printf("  [5] Peruvian Sol (PEN)\n");
    printf("  [6] Venezuelan Bolivar (VES)\n");
    printf("  [7] Bolivian Boliviano (BOB)\n");
    printf("  [8] Paraguayan Guarani (PYG)\n");
    printf("  [9] Uruguayan Peso (UYU)\n");
    printf(" [10] Guyanese Dollar (GYD)\n");
    printf(" [11] Surinamese Dollar (SRD)\n");
    printf(" [12] Ecuadorian Sucre (ECS)\n");
    printf(" [13] Falkland Islands Pound (FKP)\n");
    printf(" [14] Aruban Florin (AWG)\n");
    printf(" [15] Belize Dollar (BZD)\n");
    printf("\033[0m");
}
void error_handling()
{
    system("cls");
    printf("\033[0;41m\n\tSomething is Wrong!!\n\033[0m");
    printf("\033[0;45m");
    int close;
    printf("\n %c Enter   (1) for More Conversion   (2) for About us   (3) for Exit...\n %c ",254,175);
    scanf("%d",&close);
    getchar();
    printf("\033[0m");
    if (close == 3)
    {
        printf("Thank You <3\n");
        exit(0);
    }
    else if (close == 2)
    {
        printf("\n %c About Us %c\n",175,174);
        printf(" ------------\n");
        printf(" A Project by \"CODE MINERS\"!\n\n");
        printf(" 1. Shishir Karmokar - 254\n");
        printf(" 2. Gulam Murshed - 336\n");
        printf(" 3. Anamika Akter - 101\n");
        printf(" 4. Bijoy Krishna Sarker - 219\n\n");
        error_handling(1);
    }
    else if (close == 1)
    {
        main();
    }
    else
    {
        printf("\n\tSomething is Wrong!!\n");
        error_handling();

    }
    printf("\033[0m");


}
void exit_menu()
{
    printf("\033[0;45m");
    int close;
    printf("\n %c Enter   (1) for More Conversion   (2) for About us   (3) for Exit...\n %c ",254,175);
    scanf("%d",&close);
    getchar();
    printf("\033[0m");
    if (close == 3)
    {
        printf("Thank You <3\n");
        exit(0);
    }
    else if (close == 2)
    {
        printf("\n %c About Us %c\n",175,174);
        printf(" ------------\n");
        printf(" A Project by \"CODE MINERS\"!\n\n");
        printf(" 1. Shishir Karmokar - 254\n");
        printf(" 2. Gulam Murshed - 336\n");
        printf(" 3. Anamika Akter - 101\n");
        printf(" 4. Bijoy Krishna Sarker - 219\n\n");
        error_handling(1);
    }
    else if (close == 1)
    {
        main();
    }
    else
    {
        printf("\n\tSomething is Wrong!!\n");
        error_handling();

    }
    printf("\033[0m");


}
