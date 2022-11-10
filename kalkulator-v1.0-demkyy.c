#include <stdio.h>

int OdabirMeni,provjera=0;
float UnosBroja[3];

void UnosPodataka()
{
    int i;
    for(i=0; i<2; i++)
    {
        printf("Molimo unesite %d. broj:\n",i+1);
        scanf("%f",&UnosBroja[i]);
    }
}

void operacije()
{
    provjera=1;
    if(OdabirMeni==1)
    {
        UnosBroja[2]=UnosBroja[0]+UnosBroja[1];
    }
    else if(OdabirMeni==2)
    {
        UnosBroja[2]=UnosBroja[0]-UnosBroja[1];
    }
    else if(OdabirMeni==3)
    {
        UnosBroja[2]=UnosBroja[0]*UnosBroja[1];
    }
    else if(OdabirMeni==4)
    {
        UnosBroja[2]=UnosBroja[0]/UnosBroja[1];
    }
}

void sabiranje()
{
    operacije();
    printf("\nZbir brojeva %.2f i %.2f je: %.2f\n\n",UnosBroja[0],UnosBroja[1],UnosBroja[2]);
}

void oduzimanje()
{
    operacije();
    printf("\nRazlika brojeva %.2f i %.2f je: %.2f\n\n",UnosBroja[0],UnosBroja[1],UnosBroja[2]);
}

void mnozenje()
{
    operacije();
    printf("\nProizvod brojeva %.2f i %.2f je: %.2f\n\n",UnosBroja[0],UnosBroja[1],UnosBroja[2]);
}

void dijeljenje()
{
    operacije();
    printf("\nKolicnik brojeva %.2f i %.2f je: %.2f\n\n",UnosBroja[0],UnosBroja[1],UnosBroja[2]);
}

void error12()
{
    printf("\a#ERROR: Pogresan unos, koristite 1 ili 2!\n\n");
}

void logout()
{
    printf("Hvala na koristenju aplikacije, pozdrav.\n");
}

void newline()
{
    printf("\n");
}

void main()
{
    int PrviOdabir;
    printf("Kalkulator by demkyy v1.0\n");
    do
    {
        printf("1. Start\n2. Exit\n\nOdabir: ");
        scanf("%d",&PrviOdabir);
        PrviOdabir!=1 ? : newline();
        switch(PrviOdabir)
        {
        case 1:
            do
            {
                printf("Odaberite zeljenu racunsku operaciju:\n1. Sabiranje\n2. Oduzimanje\n3. Mnozenje\n4. Dijeljenje\n-------------\n  Koristite '5' za izlaz\n\nOdabir: ");
                scanf("%d",&OdabirMeni);
                (OdabirMeni<1)||(OdabirMeni>4) ? : newline();
                switch(OdabirMeni)
                {
                case 1:
                    printf("Odabrana racunska operacija: Sabiranje\n");
                    UnosPodataka();
                    sabiranje();
                    break;
                case 2:
                    printf("Odabrana racunska operacija: Oduzimanje\n");
                    UnosPodataka();
                    oduzimanje();
                    break;
                case 3:
                    printf("Odabrana racunska operacija: Mnozenje\n");
                    UnosPodataka();
                    mnozenje();
                    break;
                case 4:
                    printf("Odabrana racunska operacija: Dijeljenje\n");
                    UnosPodataka();
                    dijeljenje();
                    break;
                case 5:
                    PrviOdabir=2;
                    logout();
                    break;
                default:
                    printf("\a#ERROR: Pogresan unos, koristite 1, 2, 3 ili 4!\n\n");
                    break;
                }
                if(provjera!=0)
                {
                    do
                    {
                        printf("Zelite li izracunati nesto novo?\n1. Da\n2. Ne\n\nOdabir: ");
                        scanf("%d",&provjera);
                        switch(provjera)
                        {
                            case 1:
                                provjera=0;
                                newline();
                                break;
                            case 2:
                                provjera=0;
                                OdabirMeni=5;
                                PrviOdabir=2;
                                logout();
                                break;
                            default:
                                error12();
                                break;
                        }
                    }
                    while(provjera!=0);
                }
            }
            while(OdabirMeni!=5);
            break;
        case 2:
            logout();
            break;
        default:
            error12();
            break;
        }
    }
    while(PrviOdabir!=2);
}
