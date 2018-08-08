#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>


int i;
struct phonebook* searchelementname(struct phonebook *start);
struct phonebook
{
    char name[100];
    char phone[5][15];
    char address[5][50];
    char email[5][50];
    char group[5][50];
    struct phonebook* next;
};
typedef struct phonebook phonebook;


struct phonebook* addelement(struct phonebook *start)
{
    char str[100]={0};
    char ch;
    struct phonebook *newe,*cur;
    newe= (phonebook*)calloc(1,sizeof(phonebook));

    printf("Enter your name:");
    scanf(" %[^\n]",newe->name);
    system("cls");
    printf("Do you want to add phone numbers(y/n)");
    for(i=0;i<5;i++)
    {
        ch=getch();
        if(ch=='y')
        {

            printf("\nEnter number:");
            scanf(" %[^\n]",newe->phone[i]);
            system("cls");
            printf("Do you want to add more:(y/n)");
        }
        else
        {
            system("cls");
            break;
        }

    }

    system("cls");

    printf("Do you want to add address(y/n)");
    for( i=0;i<5;i++)
    {
        ch=getch();
        if(ch=='y')
        {
            printf("\nEnter address:");
            scanf(" %[^\n]",newe->address[i]);
            system("cls");
            printf("Do you want to add more:(y/n)");
        }
        else
        {
            system("cls");
            break;
        }

    }

    system("cls");

    printf("Do you want to add email(y/n)");
    for( i=0;i<5;i++)
    {
        ch=getch();
        if(ch=='y')
        {
            printf("\nEnter email:");
            scanf(" %[^\n]",newe->email[i]);
            system("cls");
            printf("Do you want to add more:(y/n)");
        }
        else
        {
            system("cls");
            break;
        }

    }

    system("cls");

    printf("Do you want to add group(y/n)");
    for( i=0;i<5;i++)
    {
        ch=getch();
        if(ch=='y')
        {
            printf("\nEnter group:");
            scanf(" %[^\n]",newe->group[i]);
            system("cls");
            printf("Do you want to add more:(y/n)");
        }
        else
        {
            system("cls");
            break;
        }

    }


    newe->next = NULL;

    if(start == NULL)
    {

        start = newe;
    }
    else
    {

        cur = start;
        while(cur->next != NULL)
            cur = cur->next;
        cur->next = newe;
    }

    //printf("done3");

    //printf("%d",start);
    //getch();

    return start;

};

void printelement (struct phonebook *start)
{
    system("cls");

    struct phonebook *cur=start;
    while(cur!=NULL)
    {
        printf("NAME: ");
        printf("%s\n",cur->name);
        printf("PHONE NUMBERS: \n");
        for( i=0;i<5;i++)
        {
            if(cur->phone[i][0]=='\0')
                break;
            printf("%s\n",cur->phone[i]);
        }

        printf("ADDRESS: \n");

        for( i=0;i<5;i++)
        {
             if(cur->address[i][0]=='\0')
                break;
            printf("%s\n",cur->address[i]);
        }

        printf("EMAIL: \n");

        for( i=0;i<5;i++)
        {
             if(cur->email[i][0]=='\0')
                break;
            printf("%s\n",cur->email[i]);
        }
        printf("GROUPS: \n");
        for( i=0;i<5;i++)
        {
             if(cur->group[i][0]=='\0')
                break;
            printf("%s\n",cur->group[i]);
        }

        for( i=0;i<120;i++)
            printf("-");

        cur=cur->next;
    }

    getch();

}

void searchprint(int cur)
{
    printf("\t\t\t\tMENU\n");
    if(cur==1)
    {
        printf("==>\t 1.SEARCH BY NAME\n");
        printf("   \t 2.search by group\n");
        printf("   \t 3.back\n");
    }
    else if(cur==2)
    {
        printf("   \t 1.add new\n");
        printf("==>\t 2.SEARCH BY GROUP\n");
        printf("   \t 3.back\n");
    }
    else if(cur==3)
    {
        printf("   \t 1.add new\n");
        printf("   \t 2.search by group\n");
        printf("==>\t 3.BACK\n");

    }



    printf("\n   Enter up or down arrow to navigate\n");

}



struct phonebook* searchelement(struct phonebook *start)
{
    system("cls");

    int flag=0;
    struct phonebook *cur = start;
    char inp[100]={0};
    int val=1;
    char ch;
    searchprint(val);
    while(1)
    {
        ch=getch();
        if(ch==80)
        {
            val++;
            if(val==4)
                val=1;
            system("cls");
            searchprint(val);
        }
        else if(ch==72)
        {
            val--;
            if(val==0)
                val=3;
                system("cls");
            searchprint(val);

        }
        else if(ch==13)
        {
            if(val==1)
            {
                system("cls");
                start=searchelementname(start);
                printf("  %d",start);
                getch();
            }
            else if(val==2)
            {
                system("cls");
                searchelementgroup(start);
            }
            else if(val==3)
                return start;
        }
    }
    return start;

}

struct phonebook* searchelementname(struct phonebook *start)
{
    struct phonebook *prev=NULL;
    int flag=0;
    char str[100]={0};
    printf("ENTER NAME:");
    scanf(" %[^\n]",str);
    struct phonebook *cur = start;
    while(cur!=NULL)
    {
        if(strcmp(cur->name,str)==0)
        {


                flag=1;

                printf("NAME: ");
                printf("%s\n",cur->name);
                printf("PHONE NUMBERS: \n");
                for( i=0;i<5;i++)
                {
                    if(cur->phone[i][0]=='\0')
                        break;
                    printf("%s\n",cur->phone[i]);
                }

                printf("ADDRESS: \n");

                for( i=0;i<5;i++)
                {
                    if(cur->address[i][0]=='\0')
                        break;
                    printf("%s\n",cur->address[i]);
                }

                printf("EMAIL: \n");

                for( i=0;i<5;i++)
                {
                    if(cur->email[i][0]=='\0')
                        break;
                    printf("%s\n",cur->email[i]);
                }
                printf("GROUPS: \n");
                for( i=0;i<5;i++)
                {
                    if(cur->group[i][0]=='\0')
                        break;
                    printf("%s\n",cur->group[i]);
                }

                for( i=0;i<120;i++)
                    printf("-");

                    //getch();

                    break;

            }
            //struct phonebook *cur = start;
                prev=cur;
                cur=cur->next;
    }

    printf("%d",start);

     printf("DO U WANT TO DELETE THE CONTACT:(y/n)");


    char choice=getch();


    if(choice=='y')
    {
         printf("%d",start);
        if(start == cur)
        {
            printf("in if");
            prev=NULL;
            start = cur->next;
            free(cur);
            printf("after freeing");
            printf(" %d",start);
            printf("%s",start->name);
        }
        else
        {
            printf("in else");
            prev->next = cur->next;
            free(cur);

        }
        printf("dltd");
    }
   // printf(" %d",start);



    if(flag==0)
        printf("NOT FOUND\n");

        getch();
        return start;

}


void searchelementgroup(struct phonebook *start)
{
    int flag=0;
    char str[100]={0};
    struct phonebook *cur = start;
    printf("ENTER GROUP:");
    scanf(" %[^\n]",str);
    while(cur!=NULL)
    {
        if(strcmp(cur->group,str)==0)
        {

                flag=1;

                printf("NAME: ");
                printf("%s\n",cur->name);
                printf("PHONE NUMBERS: \n");
                for( i=0;i<5;i++)
                {
                    if(cur->phone[i][0]=='\0')
                        break;
                    printf("%s\n",cur->phone[i]);
                }

                printf("ADDRESS: \n");

                for( i=0;i<5;i++)
                {
                    if(cur->address[i][0]=='\0')
                        break;
                    printf("%s\n",cur->address[i]);
                }

                printf("EMAIL: \n");

                for( i=0;i<5;i++)
                {
                    if(cur->email[i][0]=='\0')
                        break;
                    printf("%s\n",cur->email[i]);
                }
                printf("GROUPS: \n");
                for( i=0;i<5;i++)
                {
                    if(cur->group[i][0]=='\0')
                        break;
                    printf("%s\n",cur->group[i]);
                }

                for( i=0;i<120;i++)
                    printf("-");

                    //getch();

            }
            //struct phonebook *cur = start;
                cur=cur->next;
    }

    if(flag==0)
        printf("NOT FOUND\n");

        getch();
        return ;

}






void menuprint(int cur)
{
    printf("\t\t\t\tMENU\n");
    if(cur==1)
    {
        printf("==>\t 1.ADD NEW\n");
        printf("   \t 2.view all contact\n");
        printf("   \t 3.search contact\n");
        printf("   \t 4.exit");

    }
    else if(cur==2)
    {
        printf("   \t 1.add new\n");
        printf("==>\t 2.VIEW ALL CONTACTS\n");
        printf("   \t 3.search contact\n");
        printf("   \t 4.exit");

    }
    else if(cur==3)
    {
        printf("   \t 1.add new\n");
        printf("   \t 2.view all contact\n");
        printf("==>\t 3.SEARCH CONTACT\n");
        printf("   \t 4.exit");

    }

    else if(cur==4)
    {
        printf("   \t 1.add new\n");
        printf("   \t 2.view all contact\n");
        printf("   \t 3.search contact\n");
        printf("==>\t 4.EXIT");

    }

    printf("\n   Enter up or down arrow to navigate\n");

}



void store(struct phonebook *start)
{
    FILE *fp;
    struct phonebook *cur = start;
    fp=fopen("lolbook.txt","wb");
    if(fp==NULL)
    {
        printf("Error in writing the file\n");
        exit(1);
    }
    while(cur!=NULL)
    {
        fwrite(cur,sizeof(struct phonebook),1,fp);

        cur=cur->next;

    }

    return ;
}


struct phonebook *load(struct phonebook *start)
{
    struct phonebook *newe,*cur;

    FILE *fp;
    fp=fopen("lolbook.txt","rb");
    if(fp!=NULL)
    {
        while(1)
        {
            newe= (phonebook*)calloc(1,sizeof(phonebook));
            //printf("%s",newe->name);
            //printf("%s",newe->phone[0]);
            if(fread(newe,sizeof(struct phonebook),1,fp)!=1)    break;

            newe->next = NULL;

            if(start == NULL)
            {

                start = newe;
            }
            else
            {

                cur = start;
                while(cur->next != NULL)
                    cur = cur->next;
                cur->next = newe;
            }
        }
    }
    else
        printf("File opening error");

    return start;
}





int main()
{
    system("cls");
    struct phonebook *start=NULL;
    int cur;

    char choice;

    start=load(start);
    cur=1;
    menuprint(cur);
    getch();
    while(1)
    {
     //   menuprint(cur);
        choice=getch();
        //printf("%d\n",choice);

        if(choice==13)
        {
            //printf("inside if!");
            if(cur == 1)
            {
                system("cls");
                start=addelement(start);
            }
            else if(cur ==2)
                printelement(start);
            else if(cur == 3)
                start=searchelement(start);
            else if(cur ==4)
                break;
        }

        else
        {
            if(choice == 80)
            {
                system("cls");
                cur++;
                if(cur==5)
                    cur=1;
                menuprint(cur);
            }
            else if(choice == 72)
            {
                system("cls");
                cur--;
                if(cur==0)
                    cur=4;
                menuprint(cur);
            }
        }


    }
    store(start);
    system("cls");
    printf("terminated the program!");

    return 0;
}

