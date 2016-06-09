#include "Pich.h"
#include "DFunc.h"
#include "DStruct.h"

void addbook();
int loadbook();
void mainmenu();
void viewbooks();
void sortbook(int);
void findbook(int);
int checkid(int);
void delbook(int);
void tobookfile(int);
void restorebook();
void issue();
int viewissue();
int checksid(int);
void student();
int loadstu();
void viewstu();
void showissue();
void issuemenu();
void bookmenu();
void stumenu();

FILE *Stark;



void mainmenu()
{
    int cont=5;
    a:
    clrscr();
    printitle("STARK LIBRARY");
    printcont("1 - Books",1,cont);
    printcont("2 - Students",2,cont);
    printcont("3 - Issue Books",3,cont);
    printcont("4 - Exit",4,cont);
    printins("Press 'x' to Exit!",0);
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
    int cont=5;
    a:
    clrscr();
    printitle("STARK LIBRARY");
    printcont("1 - Add Students",1,cont);
    printcont("2 - View Students",2,cont);
    printcont("3 - Delete Student",3,cont);
    printcont("4 - Search Student",4,cont);
    switch(choice())
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

            break;
        }
    case '4' :
        {

        }
    }
    getch();
    goto a;
}

void bookmenu()
{
    int cont=5;
    a:
    clrscr();
    printitle("STARK LIBRARY");
    printcont("1 - Add Book",1,cont);
    printcont("2 - View Book",2,cont);
    printcont("3 - Delete Book",3,cont);
    printcont("4 - Search Book",4,cont);
    switch(choice())
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
            delbook(1);
            break;
        }
    case '4' :
        {
            c:
            clrscr();
            printcont("1 - Search By ID",1,2);
            printcont("2 - Search By Title",2,2);
            switch(choice())
            {
            case '1' : {findbook(1);break;}
            case '2' : {findbook(0);break;}
            }
            printins("Press 'a' to search again!",0);
            printins("Press any keys to go back to Menu!",1);
            if(choice()=='a')goto c;else mainmenu();
        }
    }
    getch();
    goto a;
}

void issuemenu()
{
    int cont=5;
    a:
    clrscr();
    printitle("STARK LIBRARY");
    printcont("1 - View Issued Book",1,cont);
    printcont("2 - Issue Book to Student",2,cont);
    printcont("3 - Return Book (Unavailable)",3,cont);
    switch(choice())
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
    }
    choice();
    goto a;
}
int loadbook()
{
    int i,n;
    Stark=fopen("Book_Data.txt", "r");
    for(i=0,n=0;i<500;i++,n++)
    {
        fscanf(Stark,"%d\t%s",&b[i].b_id,&b[i].b_title);
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
        fscanf(Stark,"%d\t%s",&s[i].s_id,&s[i].s_name);
        if(s[i].s_id == NULL || s[i].s_id <= 0 || s[i].s_id > 500)break;
        //printf("%d\t%s\n",b[i].b_id,b[i].b_title);
    }
    fclose(Stark);
    return nst;
}

void delbook(int c)
{
    int i,j,n,id,s=0;
    clrscr();
    n=loadbook();
    switch(c)
    {
    case 1 :
        {
            printf("Enter Book ID: ");scanf("%d",&id);
        }
    }
    for(i=0;i<n;i++)
    {
        if(id==b[i].b_id)
        {
            Stark=fopen("Bin.txt", "a");
            fprintf(Stark,"%05d\t%s\n",b[i].b_id,b[i].b_title);
            fclose(Stark);

            n--;
            for(j=i;j<n;j++)
            {
                b[j].b_id=b[j+1].b_id;
                strcpy(b[j].b_title,b[j+1].b_title);
            }
            i--;
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
        case 'a' : delbook(1);break;
        default : mainmenu();
    }
}

void tobookfile(int n)
{
    int i;
    Stark=fopen("Book_Data.txt", "w");
    for(i=0;i<=n;i++)
    {
        fprintf(Stark,"%05d\t%s\n",b[i].b_id,b[i].b_title);
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
                        is[k+1].issued.dd=is[k].issued.dd;
                        is[k+1].issued.mm=is[k].issued.mm;
                        is[k+1].issued.yyyy=is[k].issued.yyyy;
                    }

                    is[0].record++;
                    is[0].s_id=s[j].s_id;
                    strcpy(is[0].s_name,s[j].s_name);
                    strcpy(is[0].b_title,b[i].b_title);
                    is[0].issued.dd=is[i].issued.dd;
                    is[0].issued.mm=is[i].issued.mm;
                    is[0].issued.yyyy=is[i].issued.yyyy;
                }
        }
    }


    Stark=fopen("Issue.txt", "w");
    for(i=0;i<=ns;i++)
    {
    fprintf(Stark,"%d\t%d\t%s\t%s\t%02d-%02d-%02d\n",is[i].record,is[i].s_id,is[i].s_name,is[i].b_title,is[i].issued.dd,is[i].issued.mm,is[i].issued.yyyy);
    }
    fclose(Stark);
    /*for(i=0;i<500;i++)is[i].s_id=0;
    ns=viewissue();
    for(i=0;i<ns;i++)
    printf("%d\t%d\t%s\t%s\t%d-%d-%d\n",is[i].record,is[i].s_id,is[i].s_name,is[i].b_title,is[i].issued.dd,is[i].issued.mm,is[i].issued.yyyy);
    choice();*/
}

void student()
{
    int i,nst,id;
    char ch;
    clrscr();
    printitle("STARK LIBRARY");
    nst=loadstu();
    printf("Enter Student Information!\n");
    printf("Student ID: ");scanf("%d",&id);
    if(checksid(id)==1)
    {
        printf("ID already existed! Please try again!");
        Sleep(500);
        student();
    }
    for(i=nst-1;i>=0;i--)
    {
        s[i+1].s_id=s[i].s_id;
        strcpy(s[i+1].s_name,s[i].s_name);
    }
    s[0].s_id=id;
    printf("Name: ");fflush(stdin);gets(s[0].s_name);
    Stark=fopen("Stu_Data.txt", "w");
    for(i=0;i<=nst;i++)
    fprintf(Stark,"%d\t%s\n",s[i].s_id,s[i].s_name);
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
        fscanf(Stark,"%d\t%d\t%s\t%s\t%d\t%d\t%d\n",&is[i].record,&is[i].s_id,&is[i].s_name,&is[i].b_title,&is[i].issued.dd,&is[i].issued.mm,&is[i].issued.yyyy);
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
            printf("Enter Book Title: ");fflush(stdin);gets(title);
            break;
        }
    case 1 :
        {
            printf("Enter Book ID: ");scanf("%d",&id);
            break;
        }
    }
    for(i=0;i<n;i++)
        if((c==0 && strcmp(b[i].b_title,title)==0) || (c==1 && b[i].b_id==id))
        {
            s=1;
            printf("ID: %d\nTitle: %s\n",b[i].b_id,b[i].b_title);
        }
        if(s==0)printf("Not Found");
}

void sortbook(int c)
{
    char temp[50],tmp[20];
    int i,qt,j,n;
    float pr;
    n=loadbook();
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
            if((c==0 && strcmp(b[i].b_title,b[j].b_title)>0) || (c==1 && b[i].b_id>b[j].b_id))
            {
                qt=b[i].b_id;
                b[i].b_id=b[j].b_id;
                b[j].b_id=qt;

                strcpy(temp,b[i].b_title);
                strcpy(b[i].b_title,b[j].b_title);
                strcpy(b[j].b_title,temp);
            }
    /*puts("ID\tTitle\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t%s\n",b[i].b_id,b[i].b_title);
    }*/
}

void viewstu()
{
    int i,nst;
    for(i=0;i<500;i++)s[i].s_id=0;
    nst=loadstu();
    review:
    clrscr();
    puts("ID\tName");
    for(i=0;i<nst;i++)printf("%d\t%s\n",s[i].s_id,s[i].s_name);
    printins("Press '1' to sort by ID.\t\tPress '2' to sort by Name.",0);
    printins("Press 'm' to go back to Menu.\t\t Press 'x' to Exit.",1);
    printins("Press any keys to unsorted.",2);
    switch(choice())
    {
    case '1' :
        {

            sortbook(1);
            goto review;
        }
    case '2' :
        {

            sortbook(0);
            goto review;
        }
    case 'm' :
        {
            mainmenu();
        }
    case 'x' :
        {
            exit(0);
        }
    default :
        {
            viewbooks();
            //break;
        }
    }
}

void viewbooks()
{
    int i,n;
    for(i=0;i<500;i++)b[i].b_id=0;
    n=loadbook();
    review:
    clrscr();
    puts("ID\tTitle");
    for(i=0;i<n;i++)printf("%d\t%s\n",b[i].b_id,b[i].b_title);
    printins("Press '1' to sort by ID.\t\tPress '2' to sort by Name.",0);
    printins("Press 'm' to go back to Menu.\t\t Press 'x' to Exit.",1);
    printins("Press any keys to unsorted.",2);
    switch(choice())
    {
    case '1' :
        {

            sortbook(1);
            goto review;
        }
    case '2' :
        {

            sortbook(0);
            goto review;
        }
    case 'm' :
        {
            mainmenu();
        }
    case 'x' :
        {
            exit(0);
        }
    default :
        {
            viewbooks();
            //break;
        }
    }
}

void addbook()
{
    int i,n,id;
    char ch;
    clrscr();
    printitle("STARK LIBRARY");
    n=loadbook();
    printf("Enter Book Information!\n");
    printf("Book ID: ");scanf("%d",&id);
    if(checkid(id)==1)
    {
        printf("ID already existed! Please try again!");
        Sleep(500);
        addbook();
    }
    for(i=n-1;i>=0;i--)
    {
        b[i+1].b_id=b[i].b_id;
        strcpy(b[i+1].b_title,b[i].b_title);
    }
    b[0].b_id=id;
    printf("Title: ");fflush(stdin);gets(b[0].b_title);
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

void restorebook()
{
    int i,n,id,nb;
    int Id[500];
    char title[50][500];
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
}

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
