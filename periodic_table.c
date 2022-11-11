#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_BLUE   "\x1b[34m"
#define ANSI_COLOR_RESET   "\x1b[0m"


int get_option(void);
int atomic_number(void);
int atomic_symbol(void);
int atomic_name(void);
int atomic_weight(void);
char block(int);
char property(int);
void show(int,char,char);

// Here is periodic table information

char name[112][20]= {"Hydrogen","Helium","Lithium","Beryllium","Boron","Carbon","Nitrogen","Oxygen","Flourine","Neon",
                     "Sodium", "Magnesium", "Aluminium", "Silicon", "Phosphorus", "Sulphuric", "Chlorine", "Argon",
                     "Potassium","Calcium","Scandium","Titanium","Vanadium","Chromium","Manganese","Iron","Cobalt","Nickel","Copper","Zinc",
                     "Gallium","Germanium","Arsenic","Selenium","Bromine","Krypton",
                     "Rubidium","Strontium","Yttrium","Zirconium","Niobium","Molybdenum","Technetium","Ruthenium","Rhodium","Palladium","Silver","Cadmium",
                     "Indium","Tin","Antimony","Tellurium","Iodine","Xenon",
                     "Cesium","Barium","Lanthanum","Cerium","Praseodymium","Neodymium","Promethium","Samarium","Europium","Gadolinium","Terbium","Dysprosium",
                     "Holmium","Erbium","Thulium","Ytterbium","Lutetium",
                     "Hafnium","Tantalum","Tungsten","Rhenium","Osmium","Iridium","Platinum","Gold","Mercury","Thallium","Lead","Bismuth","Polonium","Astatine","Radon",
                     "Francium","Radium","Actinium","Thorium","Protactinium","Uranium","Neptunium","Plutonium","Americium","Curium","Berkelium",
                     "Californium","Einsteinium","Fermium","Mendelevium","Nobelium","Lawrencium",
                     "Rutherfordium","Dubnium","Seaborgium","Bohrium","Hassium","Meitnerium","Darmstadtium","Roentgenium","Copernicium"
                    };
char symbol[112][5]= {"H","He","Li","Be","B","C","N","O","F","Ne",
                      "Na","Mg","Al","Si","P","S","Cl","Ar",
                      "K","Ca","Sc","Ti","V","Cr","Mn","Fe","Co","Ni","Cu","Zn","Ga","Ge","As","Se","Br","Kr",
                      "Rb","Sr","Y","Zr","Nb","Mo","Tc","Ru","Rh","Pd","Ag","Cd","In","Sn","Sb","Te","I","Xe",
                      "Cs","Ba","La","Ce","Pr","Nd","Pm","Sm","Eu","Gd","Tb","Dy","Ho","Er","Tm","Yb","Lu",
                      "Hf","Ta","W","Re","Os","Ir","Pt","Au","Hg","Tl","Pb","Bi","Po","At","Rn",
                      "Fr","Ra","Ac","Th","Pa","U","Np","Pu","Am","Cm","Bk","Cf","Es","Fm",",Md","No","Lr",
                      "Rf","Db","Sg","Bh","Hs","Mt","Ds","Rg","Cn"
                     };

double weight[112]= {1.00,4.00,6.94,9.01,10.81,12.01,14.00,16.00,20.00,20.18,23.00,24.31,26.99,28.08,30.97,32.06,35.45,39.09,40.07,44.95,47.86,50.94,
                     51.99,54.93,55.84,58.69,58.93,63.54,65.39,69.7,72.64,74.92,78.96,79.90,83.80,85.46,87.62,88.90,91.22,92.90,95.94,98.00,101.07,
                     102.90,106.42,107.86,112.41,114.81,118.71,121.76,127.6,126.90,131.29,13.90,137.32,138.90,140.11,140.90,144.24,145.00,
                     150.36,151.96,157.25,158.92,162.50,164.93,167.5,168.93,173.04,174.96,178.49,180.94,183.84,186.20,190.23,192.21,195.07,196.97,
                     200.59,204.38,207.20,208.98,209.00,210.00,222.00,223.00,226.00,227.00,231.03,232.03,237.00,238.03,243,244,247,247,251,252,257,258,
                     259,261,262,264,266,268,272,277,276,281,280,285
                    };


signin()
{
    system("cls");
    char user[100], password[100], usr[100], passc[100];
    int n, i;
    printf(ANSI_COLOR_YELLOW"\n\n\t\t\t\t\t===============\n");
    printf("\t\t\t\t\t||  Sign In  ||\n");
    printf("\t\t\t\t\t===============\n" ANSI_COLOR_RESET);
    printf("\n\t\t\t\tEnter your user name\n");
    printf("\t\t\t\t-------------------\n");
    printf("\t\t\t\t=> ");
    scanf("%s", &user);
    printf("\n\t\t\t\tEnter your password\n");
    printf("\t\t\t\t-------------------\n");
    printf("\t\t\t\t=> ");
    FILE *username;
    username = fopen("username.dat", "r");
    fscanf(username, "%s", &usr);
    FILE *passx;
    passx = fopen("password.dat", "r");
    fscanf(passx, "%s", &passc);
    int length;
    length = strlen(passc);
    for(i=0; i<length; i++)
    {
        password[i] = getch();
        printf("*");
    }
    password[i]='\0';

    int users = strcmp(usr, user);
    int passes = strcmp(passc, password);
    if((users == 0)&&(passes == 0))
    {
        MessageBox(0, "  Log In Successful", "Log In", MB_ICONINFORMATION | MB_OK);
        sign_option();
    }

    else
    {
        int msgboxID = MessageBox(NULL,"  Wrong Credentials\n  Do you want to try again?", "Log In", MB_ICONWARNING | MB_RETRYCANCEL);
        switch (msgboxID)
        {
        case IDRETRY:
            signin();
            break;

        case IDCANCEL:
            break;
        }
    }
}


registration()
{
    system("cls");
    char name[200], email[100], usrname[100], address[200], pass[100], pass2[100];
    int mobile;
    printf(ANSI_COLOR_YELLOW"\n\n\t\t\t\t\t====================\n");
    printf("\t\t\t\t\t||  Registration  ||\n");
    printf("\t\t\t\t\t====================\n\n"ANSI_COLOR_RESET);
    fflush(stdin);
    printf("\t\t\t\tEnter your full name\n");
    printf("\t\t\t\t--------------------\n");
    printf("\t\t\t\t=> ");
    scanf("%[^\n]s", name);
    printf("\n\t\t\t\tEnter your mobile number\n");
    printf("\t\t\t\t------------------------\n");
    printf("\t\t\t\t=> ");
    scanf("%d", &mobile);
    fflush(stdin);
    printf("\n\t\t\t\tEnter your Student ID\n");
    printf("\t\t\t\t------------------\n");
    printf("\t\t\t\t=> ");
    scanf("%[^\n]s", address);
    printf("\n\t\t\t\tEnter your e-mail\n");
    printf("\t\t\t\t-----------------\n");
    printf("\t\t\t\t=> ");
    scanf("%s", &email);
    printf("\n\t\t\t\tChoose your username\n");
    printf("\t\t\t\t--------------------\n");
    printf("\t\t\t\t=> ");
    scanf("%s", &usrname);
    fflush(stdin);
    printf("\n\t\t\t\tChoose your password\n");
    printf("\t\t\t\t--------------------\n");
    printf("\t\t\t\t=> ");
    scanf("%[^\n]s", &pass);
    fflush(stdin);
    printf("\n\t\t\t\tConfirm your password\n");
    printf("\t\t\t\t---------------------\n");
    printf("\t\t\t\t=> ");
    scanf("%[^\n]s", &pass2);
    int result;
    result = strcmp(pass, pass2);
    if(result == 0)
    {
        FILE *fptr;
        fptr = fopen("registration.txt","w");
        fprintf(fptr,"\t\t\t\tFull Name: %s\n\t\t\t\tMobile Number: +880%d\n\t\t\t\tAddress: %s\n\t\t\t\tE-mail: %s\n", name, mobile, address, email);
        fclose(fptr);

        FILE *username;
        username = fopen("username.dat", "w");
        fprintf(username, "%s", usrname);
        fclose(username);

        FILE *passx;
        passx = fopen("password.dat", "w");
        fprintf(passx, "%s", pass);
        fclose(passx);
        MessageBox(NULL,"  Registration Successful\n  Thank You", "Registration", MB_ICONINFORMATION | MB_OK);
        signin();
    }

    else
    {
        try_reg(name, mobile, address, email, usrname);
    }
}

try_reg(char name[200], int mobile, char address[200], char email[100], char usrname[100])
{
    char pass[100];
    char pass2[100];
    int res;
    res = strcmp(pass, pass2);
    do
    {
        fflush(stdin);
        MessageBox(NULL,"  Your Password didn't match\n  Retry", "Registration", MB_ICONWARNING | MB_OK);
        printf("\n\t\t\t\tChoose your password again\n");
        printf("\t\t\t\t--------------------------\n");
        printf("\t\t\t\t=> ");
        scanf("%s", &pass);
        printf("\n\t\t\t\tConfirm your password\n");
        printf("\t\t\t\t---------------------\n");
        printf("\t\t\t\t=> ");
        scanf("%s", &pass2);
    }
    while (res == 0);
    FILE *fptr;
    fptr = fopen("registration.txt","w");
    fprintf(fptr,"\t\t\t\tFull Name: %s\n\t\t\t\tMobile Number: +880%d\n\t\t\t\tAddress: %s\n\t\t\t\tE-mail: %s\n", name, mobile, address, email);
    fclose(fptr);

    FILE *username;
    username = fopen("username.dat", "w");
    fprintf(username, "%s", usrname);
    fclose(username);
    FILE *passx;
    passx = fopen("password.dat", "w");
    fprintf(passx, "%s", pass);
    fclose(passx);
    MessageBox(NULL,"  Registration Successful\n  Thank You", "Registration", MB_ICONINFORMATION | MB_OK);
    signin();
}

sign_option()
{
    system("cls");
    int z;
    printf(ANSI_COLOR_MAGENTA"\n\n\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb Student Option \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n"ANSI_COLOR_RESET);
    printf("\n\t\t\t\t\t[1] Periodic Table");
    printf("\n\t\t\t\t\t[4] Log Out");
    printf("\n\t\t\t\t\t[5] Exit!");
    printf("\n\t\t\t\t____________________________________________\n\n");
    printf("\t\t\t\tEnter your choice: ");
    scanf("%d", &z);

    switch(z)
    {

    // ############################
    // just paste your periodic table function
    // ############################
    case 1:
        priodic();
        break;

    case 2:
        break;

    case 3:
        break;

    case 4:
        menu();
        break;

    case 5:
        exit(0);
        break;

    default:
        printf(ANSI_COLOR_RED"\n\t\t\t\t[*]Invalid Choice. Press any key to continue..."ANSI_COLOR_RESET);
        getch();
        sign_option();
    }
}

menu()
{
    system("cls");
    int num,i;
    printf(ANSI_COLOR_RED"\n\n\t\t\t\t  ___________________________\n");
    printf(ANSI_COLOR_YELLOW"\t\t\t\t  ===========================\n");
    printf(ANSI_COLOR_MAGENTA"\t\t\t\t /|||||||||||||||||||||||||||\\\n");
    printf(ANSI_COLOR_GREEN"\t\t\t\t  |_________________________|\n");
    printf(ANSI_COLOR_RED"\t\t\t\t  |                         |\n");
    printf(ANSI_COLOR_BLUE"\t\t\t\t  |                         |\n");
    printf(ANSI_COLOR_YELLOW"\t\t\t\t  |     Periodic Table      |\n");
    printf(ANSI_COLOR_GREEN"\t\t\t\t  |                         |\n");
    printf(ANSI_COLOR_MAGENTA"\t\t\t\t  |_________________________|\n");
    printf(ANSI_COLOR_RED"\t\t\t\t /___________________________\\\n");
    printf(ANSI_COLOR_BLUE"\t\t\t\t|_____________________________|"ANSI_COLOR_RESET);
    printf("\n\n\t\t\t\t1. Registration\n");
    printf("\t\t\t\t2. Sign In\n");
    printf("\n\n\t\t\t\tEnter your choice : ");
    scanf("%d",&num);
    switch(num)
    {
    case 1:
        registration();
        break;

    case 2:
        signin();
        break;

    case 3:
        MessageBox(NULL,"  Thank You For Using Our Service\n  Stay With Us", "Exit", MB_ICONEXCLAMATION | MB_OK);
        exit(1);
        break;

    default:
        MessageBox(NULL,"  Wrong Input\n  Compile Again", "Error", MB_ICONWARNING | MB_OK);
        exit(1);
        break;
    }
}

int main()
{
    menu();
    getch();
}


// Here is a periodic table function work
priodic()
{


    int i=999,option;
    do
    {
        option=get_option();
        char ch1,ch2;
        switch (option)
        {
        case 1:
            i=atomic_number();
            break;
        case 2:
            i=atomic_symbol();
            break;
        case 3:
            i=atomic_name();
            printf("%d",i);
            break;
        case 4:
            i=atomic_weight();
            break;
        case 5:
            i = sign_option();
            break;
            return (0);
        default:
            system("cls");
            printf("\n\n\t\t\t\tWrong Choice!\n");
            printf("\n\t\t\t\tLet's try it again, Shall we ?\n\n");
        }
        if (i== -1)
        {
            system("cls");
            printf("\t\t\t\t\t\tOops ! \n\t\t\t\t\tNo Such element present !\n");
            printf("\t\t\t\t     Make a right choice this time !\n\n");
        }
        else if (i==999)
            continue;
        else
        {
            system("cls");
            ch1=block(i);
            ch2=property(i);
            show(i,ch1,ch2);
        }
        i=999;
    }
    while (option!=5);
    return (0);
}


int get_option(void)
{
    int option;
    printf("\n\nEnter the corresponding number :\n\n");
    printf("1. Search by ATOMIC NUMBER\n");
    printf("2. Search by ATOMIC SYMBOL\n");
    printf("3. Search by ATOMIC NAME\n");
    printf("4. Search by ATOMIC WEIGHT\n");
    printf("5. QUIT\n");
    printf("\nEnter Your Choice : ");
    scanf("%d",&option);
    return option;
}

/*Method to search element by atomic number*/
/*Returns the index of the element*/

int atomic_number(void)
{
    int n;
    printf("\nEnter the Atomic Number you want to search for : ");
    scanf("%d",&n);
    n--;
    if (n>=0 && n<112)
        return n;
    else
        return -1;
}

/*Method to search element by atomic name*/
/*Returns the index of the element*/

int atomic_name(void)
{
    char x[20];
    int i,flag=0;
    printf("\nEnter the Atomic Name you want to search for : ");
    scanf("%s",x);
    for (i=0; i<112; i++)
    {
        if (strcmp(x,name[i])==0)
        {
            flag=1;
            break;
        }
    }
    if (flag==1)
        return i;
    else
        return -1;
}

/*Method to search element by atomic symbol*/
/*Returns the index of the element*/

int
atomic_symbol(void)
{
    char x[5];
    int i,flag=0;
    printf("\nEnter the Atomic Symbol you want to search for : ");
    scanf("%s",x);
    for (i=0; i<112; i++)
    {
        if (strcmp(x,symbol[i])==0)
        {
            flag=1;
            break;
        }
    }
    if (flag==1)
        return i;
    else
        return -1;
}

/*Method to search element by their corresponding atomic weight */
/*Returns the index of the element*/

int
atomic_weight(void)
{
    double x;
    int i,flag=0;
    printf("\nEnter the Atomic Weight you want to search for : ");
    scanf("%lf",&x);
    for (i=0; i<112; i++)
    {
        if (weight[i]==x)
        {
            flag=1;
            break;
        }
    }
    if (flag==1)
        return i;
    else
        return -1;
}

/*Method to find the block in which the element falls*/
/*Returns the index of the element*/

char
block(int i)
{
    char ch=' ';
    int n=i+1;
    if(n==1 || n==3 || n==4 || n==11 || n==12 || n==19 || n==20 || n==37 || n==38 || n==55 || n==56 || n==87 || n==88)
        ch = 's';
    else if(n==2 || (n>=5 && n<=10) || (n>=13 && n<=18) || (n>=31 && n<=36) || (n>=49 && n<=54) || (n>=81 && n<=86))
        ch = 'p';
    else if((n>=21 && n<=30) || (n>=39 && n<=48) || (n>=72 && n<=80) || (n>=104 && n<=112))
        ch = 'd';
    else
        ch='f';
    return ch;
}

/*Method to find the metallic property of the element*/
/*Returns the index of the element*/

char
property(int i)
{
    int n=i+1;
    char ch=' ';
    if (n==1 || n==2 || (n>=6 && n<=10) || (n>=15 && n<=18) || (n>=34 && n<=36) || n==53 || n==54 ||n==86)
        ch='n';
    else if (n==5 || n==14 || n==32 || n==33 || n==51 ||n==52 ||n==85)
        ch='s';
    else
        ch='m';
    return ch;
}

/*Displays the search result*/
/*Displays the Atomic number, name, symbol, weight, metallic property and block*/

void
show(int i,char ch1,char ch2)
{
    printf("\n\t\t\t\t\t HERE'S YOUR SEARCH RESULT\n\n");
    printf("\n\t\t\t\t\tAtomic Number     : %d\n",(i+1));
    printf("\t\t\t\t\tAtomic Symbol     : %s\n",symbol[i]);
    printf("\t\t\t\t\tAtomic Name       : %s\n",name[i]);
    printf("\t\t\t\t\tAtomic Weight     : %.2f\n",weight[i]);
    printf("\t\t\t\t\tBlock             : %c\n",ch1);
    printf("\t\t\t\t\tMetallic property : ");
    if (ch2=='n')
        printf("Non-Metal\n");
    else if (ch2=='s')
        printf("Metalloid\n");
    else
        printf("Metal\n");
    printf("\n\t\t\t\t\t\tThank You ! \n\n\n");
}





