#include<stdio.h>
int main()
{
    while(1)
    {
    int exit;
    char currencyname[][10]={"BDT","USD","AUD","INR","GBP","SGD","JPY","RUB","EUR","CAD"};
    float usdtoanylist[]={109.86,1,1.56,82.64,0.80,1.36,146.06,94.80,0.93,1.36};
    float anytousdlist[]={0.0091,1,0.64,0.012,1.26,0.74,0.0068,0.011,1.08,0.74};
    int from=0,to=0,value=0;
    printf("Options: 1.BDT 2.USD 3.AUD 4.INR 5.GBP 6.SGD 7.JPY 8.RUB 9.EUR 10.CAD\n");
    printf("Currency to convert from==> ");
    scanf("%d",&from);
    printf("Currency to convert to==> ");
    scanf("%d",&to);
    printf("\n%s to %s\n\n",currencyname[from-1],currencyname[to-1]);
    printf("Amount to convert==> ");
    scanf("%d",&value);

    printf("\n\n");

    if(from!=to)
    {
    if(from==2)//usd to any
        {
           float takenvalue = usdtoanylist[to-1];
           printf("%d %s to %s is => %.2f %s\n\n",value,currencyname[from-1],currencyname[to-1],takenvalue*value,currencyname[to-1]);
        }

        else if(to==2)//any to usd
        {
            float anyvalue = anytousdlist[from-1];
            printf("%d %s to %s is => %.2f %s\n\n",value,currencyname[from-1],currencyname[to-1],anyvalue*value,currencyname[to-1]);
        }
        else//any to any
        {
            float anytousd = anytousdlist[from-1];
            float tousd = anytousd*value;
            printf("%d %s to %s is => %.2f %s\n\n",value,currencyname[from-1],currencyname[to-1],usdtoanylist[to-1]*tousd,currencyname[to-1]);
        }
    }
    else if(from==to)
    {
        float values=(float)value;
        printf("%d %s to %s is => %.2f %s\n\n",value,currencyname[from-1],currencyname[to-1],values,currencyname[to-1]);
    }
        printf("Exit?\n\n1.Yes 2.No\n\n");
        scanf("%d",&exit);
        switch(exit)
        {
        case 1:
            printf("Exiting....");
            return 0;
        case 2:
            continue;
        }

    }
}
