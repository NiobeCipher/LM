#include "Pich.h"
#include "DFunc.h"
#include "DStruct.h"

void addbook(void);
int loadbook(void);
void mainmenu(void);
void viewbooks(void);
void sortbook(int);
void findbook(int);
void findstu(int);
int checkid(int);
void delbook(void);
void delstu(void);
void tobookfile(int);
void restorebook(void);
void issue(void);
int viewissue(void);
void returnbook(void);
int checksid(int);
void student(void);
int loadstu(void);
void viewstu(void);
void showissue(void);
void issuemenu(void);
void bookmenu(void);
void stumenu(void);
int choice(void);
void printline(void);
void cleanside(void);


FILE *Stark;



void mainmenu()
{
    int c;
    a:
    //printcont("1 - Books",1,cont);
    //printcont("2 - Students",2,cont);
    //printcont("3 - Issue Books",3,cont);
    //printcont("4 - Exit",4,cont);

    //start_scr:
    //loadata();
    loaderanim(30);
    clrscr();

    printitle("STARK LIBRARY");
    for(c=3;c<25;c++){gotoxy(60,c);printf("\xB2");}
    //printf("\xDB\xDB\xDB\xDB\xB2 1. Add Books   ");
    gotoxy(9,10);
    printf("\xDB\xDB\xDB\xDB\xB2 1 - Books \n");
    gotoxy(9,11);
    printf("\xDB\xDB\xDB\xDB\xB2 2 - Students \n");
    gotoxy(9,12);
    printf("\xDB\xDB\xDB\xDB\xB2 3 - Issue Books \n");
    gotoxy(9,13);
    printf("\xDB\xDB\xDB\xDB\xB2 4 - Exit \n");
    //printcont("Student ID:",0,2);
    //printcont("Password  :",1,2);
    //printf("\nPress 'L' to Login!\tPress 'R' to Register!");
    //printins("Press 'L' to Login!\tPress 'R' to Register!\tPress 'X' to exit!",0);
    printins("Press one of given keys to continue!",0);
    textcolor(9);
    gotoxy(75,8);
    cprintf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(75,9);
    cprintf("\xDB\xDB\xDB\xDB\xB2 SOCHEAT SOU");gotoxy(102,9);cprintf("\xB2");
    gotoxy(75,10);
    cprintf("\xDB\xDB\xDB\xDB\xB2 SEREYVONG HOUR");gotoxy(102,10);cprintf("\xB2");
    gotoxy(75,11);
    cprintf("\xDB\xDB\xDB\xDB\xB2 PUY YEAV");gotoxy(102,11);cprintf("\xB2");
    gotoxy(75,12);
    cprintf("\xDB\xDB\xDB\xDB\xB2 BROSTOCH PANG");gotoxy(102,12);cprintf("\xB2"); //gotoxy(67,11);printf("\xB2");
    gotoxy(75,13);
    cprintf("\xDB\xDB\xDB\xDB\xB2 SEREY ROS");gotoxy(102,13);cprintf("\xB2");
    gotoxy(75,14);
    cprintf("\xDB\xDB\xDB\xDB\xB2 SOPHAL CHAN");gotoxy(102,14);cprintf("\xB2");
    gotoxy(75,15);
    cprintf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    while(!kbhit())
    {
        _setcursortype(0);
        textcolor(random(15)+1);
        gotoxy(83,4);
        cprintf("TEAM IRON MAN");
        gotoxy(83,5);
        cprintf("TEAM NUMBER 2");
    }
    _setcursortype(2);
    //loadata();
    //_setcursortype(0);
    //options=choice();
    //_setcursortype(2);


    switch(choice())
    {
    case '1' :
        {
            bookmenu();
            break;
        }
    case '2' :
        {
            stumenu();
            break;
        }
    case '3' :
        {
            issuemenu();
            break;
        }
    case '4' :
        {
            exit(0);
            break;
        }
    case 'x' : case 'X' : exit(0);
    default :
    {
        printins("Wrong Key! Please try again, sir!",0);
        Sleep(500);
        goto a;
    }
    }
}
void stumenu()
{
    int cont=4,st;
    do{
        clrscr();
        printitle("STARK LIBRARY");
        printcont("1 - Add Students",1,cont);
        printcont("2 - View Students",2,cont);
        printcont("3 - Delete Student",3,cont);
        printcont("4 - Search Student",4,cont);
        st=choice();
        switch(st)
        {
        case '1' :
            {
                student();
                break;
            }
        case '2' :
            {
                viewstu();;
                break;
            }
        case '3' :
            {
                delstu();
                break;
            }
        case '4' :
            {
                do{
                    clrscr();
                    printitle("STARK LIBRARY");
                    printline();
                    printcont("1 - Search By ID",1,2);
                    printcont("2 - Search By Title",2,2);
                    switch(choice())
                    {
                        case '1' : findbook(1);break;
                        case '2' : findbook(0);break;
                    }
                    printins("Press any key to search again!",0);
                    printins("Press Esc to go back to Menu!",1);
                }while(choice()!=27);
                stumenu();
            }
        case 27 : mainmenu();
        default :
            {
            printins("Wrong Key! Please try again, sir!",0);
            Sleep(500);break;
            }
        }
    }while(st!=27);
}

void bookmenu()
{
    int cont=4,st;
    do{
        clrscr();
        printitle("STARK LIBRARY");
        printcont("1 - Add Book",1,cont);
        printcont("2 - View Book",2,cont);
        printcont("3 - Delete Book",3,cont);
        printcont("4 - Search Book",4,cont);
        printline();
        st=choice();
        switch(st)
        {
        case '1' :
            {
                addbook();
                break;
            }
        case '2' :
            {
                viewbooks();
                break;
            }
        case '3' :
            {
                delbook();
                break;
            }
        case '4' :
            {
                do{
                    clrscr();
                    printitle("STARK LIBRARY");
                    printline();
                    printcont("1 - Search By ID",1,2);
                    printcont("2 - Search By Title",2,2);
                    switch(choice())
                    {
                        case '1' : {findbook(1);break;}
                        case '2' : {findbook(0);break;}
                    }
                    printins("Press any key to search again!",0);
                    printins("Press Esc to go back to Menu!",1);
                }while(choice()!=27);
                bookmenu();
            }
        case 27 : mainmenu();
        default :
            {
                printins("Wrong Key! Please try again, sir!",0);
                Sleep(500);break;
            }
        }
    }while(st!=27);
}

void issuemenu()
{
    int cont=3,st;
    do{
        clrscr();
        printitle("STARK LIBRARY");
        printcont("1 - View Issued Book",1,cont);
        printcont("2 - Issue Book to Student",2,cont);
        printcont("3 - Return Book",3,cont);
        st=choice();
        switch(st)
        {
            case '1' :
                {
                    showissue();
                    break;
                }
            case '2' :
                {
                    issue();
                    break;
                }
            case '3' :
                {
                    returnbook();
                    break;
                }
            case 27 : mainmenu();
            default :
                {
                    printins("Wrong Key! Please try again, sir!",0);
                    Sleep(500);break;
                }
        }

    }while(st!=27);
}
int loadbook()
{
    int i,n;
    Stark=fopen("Book_Data.txt", "r");
    for(i=0,n=0;i<500;i++,n++)
    {
        fscanf(Stark,"%d\t%s\t%s\t%s",&b[i].b_id,&b[i].b_title,&b[i].b_genre,&b[i].b_author);
        if(b[i].b_id == NULL || b[i].b_id <= 0 || b[i].b_id > 500)break;
        //printf("%d\t%s\n",b[i].b_id,b[i].b_title);
    }
    fclose(Stark);
    return n;
}

int loadstu()
{
    int i,nst;
    Stark=fopen("Stu_Data.txt", "r");
    for(i=0,nst=0;i<500;i++,nst++)
    {
        fscanf(Stark,"%d\t%s\t%s\t%s\t%s",&s[i].s_id,&s[i].s_name,&s[i].s_sex,&s[i].s_department,&s[i].s_phone);
        if(s[i].s_id == NULL || s[i].s_id <= 0 || s[i].s_id > 500)break;
        //printf("%d\t%s\n",b[i].b_id,b[i].b_title);
    }
    fclose(Stark);
    return nst;
}

void delbook()
{
    int i,j,n,id,s=0;
    char title[50];
    clrscr();
    for(i=0;i<500;i++)b[i].b_id=0;
    n=loadbook();
    printitle("STARK LIBRARY");
    printcont("1 - Delete By ID",1,2);
    printcont("2 - Delete By Title",2,2);
    switch(choice())
    {
    case '1' :
        {
            clrscr();
            printitle("STARK LIBRARY");
            printline();
            gotoxy(3,3);
            printf(" Enter Book ID: ");scanf("%d",&id);
            break;
        }
    case '2' :
        {
            clrscr();
            printitle("STARK LIBRARY");
            printline();
            gotoxy(3,3);
            printf(" Enter Book Title: ");fflush(stdin);gets(title);
            break;
        }
    }
    for(i=0;i<n;i++)
    {
        if((id==b[i].b_id) || (strcmp(title,b[i].b_title)==0))
        {
            printf("\n%10s%40s%25s%20s\n","ID","Title","Genre","Author");
            printf("%10d%40s%25s%20s\n",b[i].b_id,b[i].b_title,b[i].b_genre,b[i].b_author);
            if(choice()==27)break;
            else
            {
                Stark=fopen("Bin.txt", "a");
                fprintf(Stark,"%05d\t%s\t%s\t%s\n",b[i].b_id,b[i].b_title,b[i].b_genre,b[i].b_author);
                fclose(Stark);

                n--;
                for(j=i;j<n;j++)
                {
                    b[j]=b[j+1];
                }
                //i--;
                s=1;
            }
        }
        Stark=fopen("Book_Data.txt", "w");
        tobookfile(n-1);
        for(i=0;i<500;i++)b[i].b_id=0;
        if(s==0)printf("Book Not Found!");
        else if(s==1)printf("Deleted Successful!");
        printins("Press 'a' to delete more!\t\tPress any keys to go back to Menu!",0);
        switch(choice())
        {
            case 'a' : delbook();break;
            default : mainmenu();
        }
    }
}

void delstu()
{
    int i,j,nst,id,s1=0;
    char name[50];
    clrscr();
    for(i=0;i<500;i++)s[i].s_id=0;
    nst=loadstu();
    printitle("STARK LIBRARY");
    printcont("1 - Delete By ID",1,2);
    printcont("2 - Delete By Name",2,2);

    switch(choice())
    {
    case '1' :
        {
            clrscr();
            printitle("STARK LIBRARY");
            printline();
            gotoxy(3,3);
            printf(" Enter Student ID: ");scanf("%d",&id);
            break;
        }
    case '2' :
        {
            clrscr();
            printitle("STARK LIBRARY");
            printline();
            gotoxy(3,3);
            printf(" Enter Student Name: ");fflush(stdin);gets(name);
            break;
        }
    }
    for(i=0;i<nst;i++)
    {
        if((id==s[i].s_id) || (strcmp(name,s[i].s_name)==0))
        {
            printf("\n%10s%20s%10s%30s%20s\n","ID","Name","Sex","Department","Phone");
            printf("%10d%20s%10s%30s%20s\n",s[i].s_id,s[i].s_name,s[i].s_sex,s[i].s_department,s[i].s_phone);
            if(choice()==27)break;
            else
            {
                Stark=fopen("Bin.txt", "a");
                fprintf(Stark,"%10d%20s%10s%30s%20s\n",s[i].s_id,s[i].s_name,s[i].s_sex,s[i].s_department,s[i].s_phone);
                fclose(Stark);

                nst--;
                for(j=i;j<nst;j++)
                {
                    s[j]=s[j+1];
                }
                //i--;
                s1=1;
            }
        }
        Stark=fopen("Stu_Data.txt", "w");
        for(i=0;i<=nst-1;i++)
        fprintf(Stark,"%d\t%s\t%s\t%s\t%s\n",s[i].s_id,s[i].s_name,s[i].s_sex,s[i].s_department,s[i].s_phone);
        fclose(Stark);

        for(i=0;i<500;i++)s[i].s_id=0;
        if(s1==0)printf("Student Not Found!");
        else if(s1==1)printf("Deleted Successful!");
        printins("Press 'a' to delete more!\t\tPress any keys to go back to Menu!",0);
        switch(choice())
        {
            case 'a' : delstu();break;
            default : mainmenu();
        }
    }
}

void tobookfile(int n)
{
    int i;
    Stark=fopen("Book_Data.txt", "w");
    for(i=0;i<=n;i++)
    {
        fprintf(Stark,"%05d\t%s\t%s\t%s\n",b[i].b_id,b[i].b_title,b[i].b_genre,b[i].b_author);
    }
    fclose(Stark);
}

void issue()
{
    int i,n,nst,id,ns,j,stuid,k;
    clrscr();
    n=loadbook();
    ns=viewissue();
    puts("ID\tTitle");
    for(i=0;i<n;i++)
    printf("%05d\t%s\n",b[i].b_id,b[i].b_title);
    printf("Enter Book ID: ");scanf("%d",&id);
    for(i=0;i<n;i++)
    {
        if(id==b[i].b_id)
        {
            struct dosdate_t da;
            _dos_getdate(&da);
            is[i].issued.dd=da.day;
            is[i].issued.mm=da.month;
            is[i].issued.yyyy=da.year;

            is[i].due.dd=is[i].issued.dd+15;
            is[i].due.mm=is[i].issued.mm;
            is[i].due.yyyy=is[i].issued.yyyy;
            if(is[i].due.dd>30)
            {
            is[i].due.mm+=is[i].due.dd/30;
            is[i].due.dd-=30;
            }
            if(is[i].due.mm>12)
            {
            is[i].due.yyyy+=is[i].due.mm/12;
            is[i].due.mm-=12;
            }

            nst=loadstu();
            printf("Enter Student ID: ");scanf("%d",&stuid);
            for(j=0;j<nst;j++)
                if(stuid==s[j].s_id)
                {
                    printf("%d\n%s\n",s[j].s_id,s[j].s_name);

                    for(k=ns-1;k>=0;k--)
                    {
                        is[k+1].record=is[k].record;
                        is[k+1].s_id=is[k].s_id;
                        strcpy(is[k+1].s_name,is[k].s_name);
                        strcpy(is[k+1].b_title,is[k].b_title);
                        is[k+1].b_id = is[k].b_id;
                        is[k+1].issued.dd=is[k].issued.dd;
                        is[k+1].issued.mm=is[k].issued.mm;
                        is[k+1].issued.yyyy=is[k].issued.yyyy;
                    }

                    is[0].record++;
                    is[0].s_id=s[j].s_id;
                    strcpy(is[0].s_name,s[j].s_name);
                    strcpy(is[0].b_title,b[i].b_title);
                    is[0].b_id = b[i].b_id;
                    is[0].issued.dd=is[i].issued.dd;
                    is[0].issued.mm=is[i].issued.mm;
                    is[0].issued.yyyy=is[i].issued.yyyy;
                }
        }
    }


    Stark=fopen("Issue.txt", "w");
    for(i=0;i<=ns;i++)
    {
    fprintf(Stark,"%d\t%d\t%s\t%s\t%02d-%02d-%02d\t%d\n",is[i].record,is[i].s_id,is[i].s_name,is[i].b_title,is[i].issued.dd,is[i].issued.mm,is[i].issued.yyyy,is[i].b_id);
    }
    fclose(Stark);
    /*for(i=0;i<500;i++)is[i].s_id=0;
    ns=viewissue();
    for(i=0;i<ns;i++)
    printf("%d\t%d\t%s\t%s\t%d-%d-%d\n",is[i].record,is[i].s_id,is[i].s_name,is[i].b_title,is[i].issued.dd,is[i].issued.mm,is[i].issued.yyyy);
    choice();*/
}

void returnbook()
{
    int i,id,ns,stuid,k;
    clrscr();
    loadbook();
    ns=viewissue();
    //viewissue();
    printf("Enter Student ID: ");scanf("%d",&stuid);
    printf("Enter Book ID: ");scanf("%d",&id);
        for(i=0;i<ns;i++)

                if(stuid==is[i].s_id && id==is[i].b_id)
                {
                    //printf("%d\n%s\n",s[j].s_id,s[j].s_name);
                    puts("Record#\tStudent ID\tName\tTitle\tIssued-Date\tDue-Date");
                    printf("%d\t\t%d\t%s\t%s\t%d-%d-%d\t%d-%d-%d\t%d\n",is[i].record,is[i].s_id,is[i].s_name,is[i].b_title,is[i].issued.dd,is[i].issued.mm,is[i].issued.yyyy,is[i].due.dd,is[i].due.mm,is[i].due.yyyy);
                    getch();
                    Stark=fopen("Return.txt", "a");

                    fprintf(Stark,"%d\t%d\t%s\t%s\t%02d-%02d-%02d\n",is[i].record,is[i].s_id,is[i].s_name,is[i].b_title,is[i].issued.dd,is[i].issued.mm,is[i].issued.yyyy);

                    fclose(Stark);
                    ns--;
                    for(k=i;k<=ns;k++)
                    {
                        is[k].record=is[k+1].record;
                        is[k].s_id=is[k+1].s_id;
                        strcpy(is[k].s_name,is[k+1].s_name);
                        strcpy(is[k].b_title,is[k+1].b_title);
                        is[k].issued.dd=is[k+1].issued.dd;
                        is[k].issued.mm=is[k+1].issued.mm;
                        is[k].issued.yyyy=is[k+1].issued.yyyy;
                    }
                    Stark=fopen("Issue.txt", "w");
                    for(i=0;i<=ns;i++)
                    {
                    fprintf(Stark,"%d\t%d\t%s\t%s\t%02d-%02d-%02d\n",is[i].record,is[i].s_id,is[i].s_name,is[i].b_title,is[i].issued.dd,is[i].issued.mm,is[i].issued.yyyy);
                    }
                    fclose(Stark);
                    break;
                }





}

void student()
{
    int i,nst,id,x,y;
    char department,sex;
    clrscr();
    printitle("STARK LIBRARY");
    nst=loadstu();
    printf("\n ===== Enter Student Information! =====\n");
    printf("\n \xDB\xDB\xB2 Student ID: ");scanf("%d",&id);
    if(checksid(id)==1)
    {
        printf("ID already existed! Please try again!");
        Sleep(500);
        student();
    }
    for(i=nst-1;i>=0;i--)
    {
        s[i+1]=s[i];
    }
    s[0].s_id=id;
    printf(" \xDB\xDB\xB2 Name: ");fflush(stdin);gets(s[0].s_name);
    printf(" \xDB\xDB\xB2 Department: ");x=wherex();y=wherey();
    printside("1 - Information Technology",1,4);
    printside("2 - Computer Science",2,4);
    printside("3 - Computer Engineer",3,4);
    printside("4 - Others",4,4);
    gotoxy(x,y);scanf("%c",&department);

    switch(department)
    {
        case '1' :
            {
                strcpy(s[0].s_department,"Information_Technology");
                gotoxy(x,y);clreol();printf("Information Technology");
                break;
            }
        case '2' :
            {
                strcpy(s[0].s_department,"Computer_Science");
                gotoxy(x,y);clreol();printf("Computer Science");
                break;
            }
        case '3' :
            {
                strcpy(s[0].s_department,"Computer_Engineer");
                gotoxy(x,y);clreol();printf("Computer Engineer");
                break;
            }
        case '4':
            {
                strcpy(s[0].s_department,"Others");
                gotoxy(x,y);clreol();printf("Others");
                break;
            }
    }
    printf("\n \xDB\xDB\xB2 Phone Number: ");fflush(stdin);gets(s[0].s_phone);
    printf(" \xDB\xDB\xB2 Sex: ");x=wherex();y=wherey();
    cleanside();
    printside("M - Male",1,2);
    printside("F - Female",2,2);
    gotoxy(x,y);scanf("%c",&sex);

    switch(sex)
    {
        case 'm' :
            {
                strcpy(s[0].s_sex,"Male");
                gotoxy(x,y);clreol();printf("Male");
                break;
            }
        case 'f' :
            {
                strcpy(s[0].s_sex,"Female");
                gotoxy(x,y);clreol();printf("Female");
                break;
            }
    }

    Stark=fopen("Stu_Data.txt", "w");
    for(i=0;i<=nst;i++)
    fprintf(Stark,"%d\t%s\t%s\t%s\t%s\n",s[i].s_id,s[i].s_name,s[i].s_sex,s[i].s_department,s[i].s_phone);
    fclose(Stark);
    printins("Press 'x' to Exit!",0);
    printins("Press 'a' to Add more!",1);
    printins("Press any key to go back to Menu!",2);
    switch(choice())
    {
    case 'x' :
        {
            exit(0);
            break;
        }
    case 'a' :
        {
            student();
            break;
        }
    default :
        {
            mainmenu();
            break;
        }
    }
}

int viewissue()
{
    int i,ns;
    Stark=fopen("Issue.txt", "r");
    for(i=0,ns=0;i<500;i++,ns++)
    {
        fscanf(Stark,"%d\t%d\t%s\t%s\t%d\t%d\t%d\t%d\n",&is[i].record,&is[i].s_id,&is[i].s_name,&is[i].b_title,&is[i].issued.dd,&is[i].issued.mm,&is[i].issued.yyyy,&is[i].b_id);
        if(is[i].s_id == NULL || is[i].s_id <=0 || is[i].s_id > 500 )break;
    }
    fclose(Stark);
    return ns;
}
int checkid(int id)
{
    int i,n,re=0;
    n=loadbook();
    for(i=0;i<n;i++)
        if(b[i].b_id==id)re=1;
    return re;
}

int checksid(int id)
{
    int i,n,re=0;
    n=loadstu();
    for(i=0;i<n;i++)
        if(s[i].s_id==id)re=1;
    return re;
}

void findbook(int c)
{
    int i,n,s=0,id;
    char title[50];
    clrscr();
    n=loadbook();
    switch(c)
    {
    case 0 :
        {
            printitle("STARK LIBRARY");
            printline();
            gotoxy(1,30);
            printf(" Enter Book Title: ");fflush(stdin);gets(title);
            break;
        }
    case 1 :
        {
            printitle("STARK LIBRARY");
            printline();
            gotoxy(1,30);
            printf("Enter Book ID: ");scanf("%d",&id);
            break;
        }
    }
    printitle("STARK LIBRARY");
    for(i=0;i<120;i++)printf("%c",205);
    printf("%10s%40s%25s%20s\n","ID","Title","Genre","Author");
    for(i=0;i<120;i++)printf("%c",205);
    for(i=0;i<n;i++)
        if((c==0 && strcmp(b[i].b_title,title)==0) || (c==1 && b[i].b_id==id))
        {
            s=1;
            printf("%10d%40s%25s%20s\n",b[i].b_id,b[i].b_title,b[i].b_genre,b[i].b_author);
        }
        if(s==0)printf("Not Found");
}

void findstu(int c)
{
    int i,nst,s1=0,id;
    char name[50];
    clrscr();
    nst=loadstu();
    switch(c)
    {
    case 0 :
        {
            printitle("STARK LIBRARY");
            printline();
            gotoxy(1,30);
            printf(" Enter Student Name: ");fflush(stdin);gets(name);
            break;
        }
    case 1 :
        {
            printitle("STARK LIBRARY");
            printline();
            gotoxy(1,30);
            printf("Enter Student ID: ");scanf("%d",&id);
            break;
        }
    }
    printitle("STARK LIBRARY");
    for(i=0;i<120;i++)printf("%c",205);
    printf("%10s%20s%10s%30s%20s\n","ID","Name","Sex","Department","Phone");
    for(i=0;i<120;i++)printf("%c",205);
    for(i=0;i<nst;i++)
        if((c==0 && strcmp(s[i].s_name,name)==0) || (c==1 && s[i].s_id==id))
        {
            s1=1;
            printf("%10d%20s%10s%30s%20s\n",s[i].s_id,s[i].s_name,s[i].s_sex,s[i].s_department,s[i].s_phone);
        }
        if(s1==0)printf("Not Found");
}

void sortbook(int c)
{
    int i,j,n;
    n=loadbook();
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
            if((c==2 && strcmp(b[i].b_title,b[j].b_title)>0) || (c==1 && b[i].b_id>b[j].b_id) || (c==3 && strcmp(b[i].b_genre,b[j].b_genre)>0) || (c==4 && strcmp(b[i].b_author,b[j].b_author)>0))
            {
                tmp1=b[i];
                b[i]=b[j];
                b[j]=tmp1;
            }
}

void sortstu(int c)
{
    int i,j,n;
    n=loadstu();
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
            if((c==2 && strcmp(s[i].s_name,s[j].s_name)>0) || (c==1 && s[i].s_id>s[j].s_id) || (c==3 && strcmp(s[i].s_sex,s[j].s_sex)>0) || (c==4 && strcmp(s[i].s_department,s[j].s_department)>0))
            {
                tmp1=s[i];
                s[i]=s[j];
                s[j]=tmp1;
            }
}

void viewstu()
{
    int i,nst,j,k,s1;
    int st;

    for(i=0;i<500;i++)s[i].s_id=0;
    nst=loadstu();
    clrscr();

    j=0;
    s1=0;
    do{

        clrscr();
        printitle("STARK LIBRARY BOOKS");
        for(i=0;i<120;i++)printf("%c",205);
        if(s1==0)printf("%10s%20s%10s%30s%20s\n","ID","Name","Sex","Department","Phone");
        else if(s1==1)
        {
            textcolor(4);
            cprintf("%10s","ID");
            printf("%20s%10s%30s%20s\n","Name","Sex","Department","Phone");
            sortstu(1);
        }
        else if(s1==2)
        {
            textcolor(4);
            printf("%10s","ID");
            cprintf("%20s","Name");
            printf("%10s%30s%20s\n","Sex","Department","Phone");
            sortstu(2);
        }
        else if(s1==3)
        {
            textcolor(4);
            printf("%10s%20s","ID","Name");
            cprintf("%10s","Sex");
            printf("%30s%20s\n","Department","Phone");
            sortstu(3);
        }
        else if(s1==4)
        {
            textcolor(4);
            printf("%10s%20s%10s","ID","Name","Sex");
            cprintf("%30s","Department");
            printf("%20s\n","Phone");
            sortstu(4);
        }
        for(i=0;i<120;i++)printf("%c",205);
        k=(nst<20) ? nst : 20;
        for(i=j;i<j+k;i++)
        {
            printf("%10d%20s%10s%30s%20s\n",s[i].s_id,s[i].s_name,s[i].s_sex,s[i].s_department,s[i].s_phone);
        }

        printins("Press arrow key to sort and scroll",0);
        printins("Press 'd' to delete student.",1);
        st=getch();
        if(st==72 && j>0) j--;
        if(st==80 && j+20<=nst) j++;
        if(st==75 && s1>0) { s1--; if(s1==0)viewstu();}
        if(st==77 && s1<4) s1++;
        if(st=='d')delbook();
    }while(st!=27);
}

void viewbooks()
{
    int i,n,j,k,s;
    int st;

    for(i=0;i<500;i++)b[i].b_id=0;
    n=loadbook();
    clrscr();

    j=0;
    s=0;
    do{

        clrscr();
        printitle("STARK LIBRARY BOOKS");
        for(i=0;i<120;i++)printf("%c",205);
        if(s==0)printf("%10s%40s%25s%20s\n","ID","Title","Genre","Author");
        else if(s==1)
        {
            textcolor(4);
            cprintf("%10s","ID");
            printf("%40s%25s%20s\n","Title","Genre","Author");
            sortbook(1);
        }
        else if(s==2)
        {
            textcolor(4);
            printf("%10s","ID");
            cprintf("%40s","Title");
            printf("%25s%20s\n","Genre","Author");
            sortbook(2);
        }
        else if(s==3)
        {
            textcolor(4);
            printf("%10s%40s","ID","Title");
            cprintf("%25s","Genre");
            printf("%20s\n","Author");
            sortbook(3);
        }
        else if(s==4)
        {
            textcolor(4);
            printf("%10s%40s%25s","ID","Title","Genre");
            cprintf("%20s","Author");
            puts("");
            sortbook(4);
        }
        for(i=0;i<120;i++)printf("%c",205);
        k=(n<20) ? n : 20;
        for(i=j;i<j+k;i++)
        {
            printf("%10d%40s%25s%20s\n",b[i].b_id,b[i].b_title,b[i].b_genre,b[i].b_author);
        }

        printins("Press arrow key to sort and scroll",0);
        printins("Press 'd' to delete book.",1);
        st=getch();
        if(st==72 && j>0) j--;
        if(st==80 && j+20<=n) j++;
        if(st==75 && s>0) { s--; if(s==0)viewbooks();}
        if(st==77 && s<4) s++;
        if(st=='d')delbook();
    }while(st!=27);
}

void addbook()
{
    int i,n,id,x,y;
    char genre;
    clrscr();
    printitle("STARK LIBRARY");
    n=loadbook();
    printf("\n ===== Enter Book Information! =====\n");
    printf("\n \xDB\xDB\xB2 Book ID: ");scanf("%d",&id);
    if(checkid(id)==1)
    {
        printf("ID already existed! Please try again!");
        Sleep(500);
        addbook();
    }
    for(i=n-1;i>=0;i--)
    {
        b[i+1]=b[i];
    }
    b[0].b_id=id;
    printf(" \xDB\xDB\xB2 Title: ");fflush(stdin);gets(b[0].b_title);
    printf(" \xDB\xDB\xB2 Genre: ");x=wherex();y=wherey();
    printside("1 - Programming",1,4);
    printside("2 - Computer",2,4);
    printside("3 - English",3,4);
    printside("4 - Others",4,4);
    gotoxy(x,y);scanf("%c",&genre);

    switch(genre)
    {
        case '1' :
            {
                strcpy(b[0].b_genre,"Programming");
                gotoxy(x,y);clreol();printf("Programming");
                break;
            }
        case '2' :
            {
                strcpy(b[0].b_genre,"Computer");
                gotoxy(x,y);clreol();printf("Computer");
                break;
            }
        case '3' :
            {
                strcpy(b[0].b_genre,"English");
                gotoxy(x,y);clreol();printf("English");
                break;
            }
        case '4':
            {
                strcpy(b[0].b_genre,"Others");
                gotoxy(x,y);clreol();printf("Others");
                break;
            }
    }
    printf("\n \xDB\xDB\xB2 Author: ");fflush(stdin);gets(b[0].b_author);
    tobookfile(n);
    printins("Press 'x' to Exit!",0);
    printins("Press 'a' to Add more!",1);
    printins("Press any key to go back to Menu!",2);
    switch(choice())
    {
    case 'x' :
        {
            exit(0);
            break;
        }
    case 'a' :
        {
            addbook();
            break;
        }
    default :
        {
            mainmenu();
            break;
        }
    }
}
/*
void restorebook()
{
    int i,n,id,nb;
    int Id[500];
    char title[500][50];
    char ch;
    clrscr();
    printitle("STARK LIBRARY");
    n=loadbook();
    Stark=fopen("Bin.txt", "r");
    puts("ID\tTitle");
    for(i=0,nb=0;i<500;i++,nb++)
    {
        fscanf(Stark,"%d\t%s",&Id[i],&title[i]);
        if(Id[i] == NULL || Id[i] <= 0 || Id[i] > 500)break;
        printf("%05d\t%s\n",Id[i],title[i]);
    }
    fclose(Stark);

    printf("Book ID: ");scanf("%d",&id);
    for(i=n-1;i>=0;i--)
    {
        b[i+1].b_id=b[i].b_id;
        strcpy(b[i+1].b_title,b[i].b_title);
    }
    for(i=0;i<nb;i++)
        if(Id[i]==id)
        {
            b[0].b_id=Id[i];
            strcpy(b[0].b_title,title[i]);
        }
    tobookfile(n);
    printins("Press 'x' to Exit!",0);
    printins("Press 'r' to restore more!",1);
    printins("Press any key to go back to Menu!",2);
    switch(choice())
    {
    case 'x' :
        {
            exit(0);
            break;
        }
    case 'r' :
        {
            restorebook();
            break;
        }
    default :
        {
            mainmenu();
            break;
        }
    }
}*/

void showissue()
{
    int i,ns;
    clrscr();
    for(i=0;i<500;i++)is[i].s_id=0;
    ns=viewissue();

    puts("Record#\tStudent ID\tName\tTitle\tIssued-Date\tDue-Date");
    for(i=0;i<ns;i++)
    {
        printf("%d\t\t%d\t%s\t%s\t%d-%d-%d\t%d-%d-%d\t%d\n",is[i].record,is[i].s_id,is[i].s_name,is[i].b_title,is[i].issued.dd,is[i].issued.mm,is[i].issued.yyyy,is[i].due.dd,is[i].due.mm,is[i].due.yyyy);
    }
}

