#include "Pich.h"



void printitle(char txt[])
{
    int i,j,k;
    for(i=0;i<120;i++)printf("\xB2");
    j=strlen(txt)/2;
    k=60-j;
    gotoxy(k,1);
    printf(" %s \n",txt);
}

void printcont(char txt[],int i,int j)
{
    int y;
    y=12-j+1+i;
    gotoxy(30,y);
    printf("\xDB\xDB\xDB\xDB\xB2 %s \n",txt);
}

void printins(char txt[],int j)
{
    int i;
    gotoxy(1,25);clreol();
    for(i=0;i<120;i++)printf("\xB2");
    gotoxy(1,26+j);
    printf("%s\n",txt);
}

char choice()
{
    char ch;
    gotoxy(1,30);
    printf("Enter your choice:");
    ch=getch();
    return ch;
}

void retomenu()
{
    printins("Press 'm' to return to Menu!",0);
    if(choice()=='m')
    {
        clrscr();
        //mainmenu();
    }
}

void clrctrlscr()
{
    gotoxy(1,26);clreol();
    gotoxy(1,27);clreol();
    gotoxy(1,28);clreol();
    gotoxy(1,29);clreol();
    gotoxy(1,30);clreol();
}
