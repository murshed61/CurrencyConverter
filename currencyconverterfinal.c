#include <stdio.h>
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

void currencyconversion(int from,int to,float value)
{
    for(int i=0; i<95; i++)
    {
        any_to_bdt[i]=1/bdt_to_any[i];
    }


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
}

int main()
{
    //welcome heading
    printf("\t\t\t\t\t\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\////////////////////\n");
    printf("\t\t\t\t\t    %c Welcome to Currency Converter %c\n",175,174);
    printf("\t\t\t\t\t////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n");
    int i = 0, r = 0;

    do
    {
        int from,to,continent_from,continent_to;
        float amount;

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
            printf("Something is Wrong!!\n");
            break;
        }

        printf("\n\n %c Please Choose & Enter a Number %c\n",254,254);
        printf(" ------------------------------------\n");
        printf(" %c Currency To Convert From -> ",175);
        scanf("%d",&from);

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
            printf("Something is Wrong!!\n");
            break;
        }

        printf("\n\n %c Please Choose & Enter a Number %c\n",254,254);
        printf(" ------------------------------------\n");
        printf(" %c Currency To Convert To -> ",175);
        scanf("%d",&to);

        //Taking input Amount of money
        printf("\n %c Please Enter The Amount To CONVERT -> ",175);
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
        currencyconversion(from,to,amount);


        //last code
        char close;
        printf("\n %c Enter   (+) for More Convertion   (?) for About us   (x) for Exit...\n %c ",254,175);
        scanf(" %c",&close);
        if (close == 'x' || close =='X')
        {
            break;
        }
        else if (close == '?')
        {
            printf("\n %c About Us %c\n",175,174);
            printf(" ------------\n");
            printf(" A Project by \"CODE MINERS\"!\n\n");
            printf(" 1. Shishir Karmokar - 254\n");
            printf(" 2. Gulam Murshed - 336\n");
            printf(" 3. Anamika Akter - 101\n");
            printf(" 4. Bijoy Krishna Sarker - 219\n\n");

        }
        else if (close == '+')
        {
            r++;
        }
        i++;

    }
    while(i==r);

    printf(" Thank You <3\n");

    return 0;
}

void continents()
{
    printf("\n");
    printf("   ------------   --------------   --------------   -----------------   ----------------------   ---------------------\n");
    printf("   | (1) ASIA |   | (2) EUROPE |   | (3) AFRICA |   | (4) AUSTRALIA |   | (5) NORTHA AMERICA |   | (6) SOUTH AMERICA |\n");
    printf("   ------------   --------------   --------------   -----------------   ----------------------   ---------------------\n");
    printf("\n %c Please Choose Continent %c\n",254,254);
    printf(" ---------------------------\n");
    printf(" %c Enter a Number -> ",175);
}
void asia_currencys()
{
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
}
void europe_currencys()
{
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
    printf(" [16] Bosnian Convertible Mark (BAM)\n");
    printf(" [17] Macedonian Denar (MKD)\n");
    printf(" [18] Albanian Lek (ALL)\n");
    printf(" [19] Belarusian Ruble (BYN)\n");
    printf(" [20] Moldovan Leu (MDL)\n");
}
void africa_currencys()
{
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
}
void australia_currencys()
{
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
}
void north_america_currencys()
{
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
}
void south_america_currencys()
{
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
}
