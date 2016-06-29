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
    gotoxy(10,y);
    printf("\xDB\xDB\xB2 %s \n",txt);
}

void printside(char txt[],int i,int j)
{
    int y,q;
    y=12-j+1+i;
    if(i==1){q=strlen(txt);gotoxy(80,y-1);printf("%c",201);for(i=0;i<strlen(txt)*1.5;i++)printf("%c",205);printf("%c",187);}
    gotoxy(80,y);
    printf(" %s \n",txt);
    if(i==j){gotoxy(80,y+1);printf("%c",200);for(i=0;i<q*1.5;i++)printf("%c",205);printf("%c",188);}
}

void cleanside()
{
    int i;
    for(i=5;i<15;i++)
    {
        gotoxy(80,i);
        clreol();
    }
}

void printins(char txt[],int j)
{
    int i;
    gotoxy(1,25);clreol();
    for(i=0;i<120;i++)printf("\xB2");
    gotoxy(1,26+j);
    printf("%s\n",txt);
}

void printline()
{
    int i;
    gotoxy(1,25);clreol();
    for(i=0;i<120;i++)printf("%c",220);

}

int choice()
{
    int ch;
    gotoxy(1,30);
    printf("Enter your choice:");
    ch=getch();
    return ch;
}
/*
void retomenu()
{
    printins("Press 'm' to return to Menu!",0);
    if(choice()=='m')
    {
        clrscr();
        //mainmenu();
    }
}*/

void clrctrlscr()
{
    gotoxy(1,26);clreol();
    gotoxy(1,27);clreol();
    gotoxy(1,28);clreol();
    gotoxy(1,29);clreol();
    gotoxy(1,30);clreol();
}

void loaderanim(int sp)
{
    int loader;
    system("cls");
    printitle("TEAM IRON MAN");
    gotoxy(50,10);
    printf("LOADING........");

    for(loader=52;loader<=72;loader++)
    {
        gotoxy(loader,11);Sleep(sp);printf("%c",219);
        gotoxy(66,10);printf("%d%%",(loader-51)*5);
    }
}
