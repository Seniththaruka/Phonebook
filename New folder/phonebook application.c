#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
struct person
{
    char fname[35];
    char lname[50];
    long int mble_no;
    char sex[8];
    };

void addrecord();
void listrecord();
void modifyrecord();
void deleterecord();
void searchrecord();

void main()
{
    printf("\t \n_______________WELCOME TO CONTACT MANAGEMENT LIST____________\n\n");

    printf("\t1.Add New Contact  \n \t2.View All Contact  \n\t3.Modify Contact \n\t4.Search Contact \n\t5.Delete Contact\n");

switch(getch())
{
    case '1':addrecord();
    break;
   case '2': listrecord();
    break;
    case '3': modifyrecord();
    break;
    case '4': searchrecord();
    break;
    case '5': deleterecord();
    break;
}
}
void addrecord()
{
        FILE *f;
        struct person p;
        f=(fopen("student.txt","a"));
        printf("\n\t Enter First name : ");
        gets(p.fname);
        printf("\nEnter Last name: ");
        gets(p.lname);
        printf("\nEnter phone no.:");
        scanf("%ld",&p.mble_no);
        printf("Enter sex (M/F):");
        got(p.sex);
        fwrite(&p,sizeof(p),1,f);

      fflush(stdin);
        printf("\nrecord saved");

fclose(f);
}
void listrecord()
{
    struct person p;
    FILE *f;
    f=fopen("student.txt","rb");
    if(f==NULL)
    {
    printf("\nfile opening error in listing :");
    }
while(fread(&p,sizeof(p),1,f)==1)
{
     printf("\n\n\n YOUR RECORD IS\n\n ");
        printf("\nFirst Name=%s\nLast Name=%s\nMobile no=%ld\nSex(M/F)=%s\n",p.fname,p.lname,p.mble_no,p.sex);

}

}
void searchrecord()
{
    struct person p;
    FILE *f;
    char name[100];

    f=fopen("student.txt","rb");
    if(f==NULL)
    {
    printf("\n error in opening\a\a\a\a");
    exit(1);

    }
    printf("\nEnter name of person to search\n");
    got(name);
    while(fread(&p,sizeof(p),1,f)==1)
{
    if(strcmp(p.fname,name)==0)
    {
        printf("\n\tDetail Information About %s",name);
        printf("\nFirst Name:%s\nLast Name:%s\nMobile no:%ld\nsex(M/F):%s\n",p.fname,p.lname,p.mble_no,p.sex);
    }

}
 fclose(f);
}
void deleterecord()
{
    struct person p;
    FILE *f,*ft;
	int flag;
	char name[100];
	f=fopen("student.txt","rb");
	if(f==NULL)
		{

			printf("CONTACT'S DATA NOT ADDED YET.");

		}
	else
	{
		ft=fopen("temp","wb+");
		if(ft==NULL)

            printf("file opaning error");
		else

        {
		printf("\nEnter CONTACT'S NAME:");
		got(name);

		fflush(stdin);
		while(fread(&p,sizeof(p),1,f)==1)
		{
			if(strcmp(p.fname,name)!=0)
				fwrite(&p,sizeof(p),1,ft);
			if(strcmp(p.fname,name)==0)
                flag=1;
		}
	fclose(f);
	fclose(ft);
	if(flag!=1)
	{
		printf("\nNO CONACT'S RECORD TO DELETE.");
		remove("temp.txt");
	}
		else
		{
			remove("project");
			rename("temp.txt","project");
			printf("\nRECORD DELETED SUCCESSFULLY.");

		}
	}
}
}

void modifyrecord()
{
    int c;
    FILE *f;
    int flag=0;
    struct person p,s;
	char  name[50];
	f=fopen("student.txt","rb+");
	if(f==NULL)
		{
			printf("CONTACT'S DATA NOT ADDED YET.");
		}
	else
	{
		printf("\nEnter CONTACT'S NAME TO MODIFY:\n");
            got(name);
            while(fread(&p,sizeof(p),1,f)==1)
            {
                if(strcmp(name,p.fname)==0)
                {



                    printf("\n Enter First name:");
                    got(s.fname);
                    printf("\nEnter the Last Name:");
                    got(s.lname);
                    printf("\nEnter phone no:");
                    scanf("%ld",&s.mble_no);
                    printf("\nEnter sex(M/F):");
                    got(s.sex);
                    fseek(f,-sizeof(p),SEEK_CUR);
                    fwrite(&s,sizeof(p),1,f);
                    flag=1;
                    break;



                }
                fflush(stdin);


            }
            if(flag==1)
            {
                printf("\n your data id modified");

            }
            else
            {
                    printf(" \n data is not found");

            }
            fclose(f);
	}

}
void got(char *name)
{

   int i=0,j;
    char c,ch;
    do
    {
        c=getch();
                if(c!=8&&c!=13)
                {
                    *(name+i)=c;
                        putch(c);
                        i++;
                }
                if(c==8)
                {
                    if(i>0)
                    {
                        i--;
                    }
                    for(j=0;j<i;j++)
                    {
                        ch=*(name+j);
                        putch(ch);

                    }

                }
    }while(c!=13);
      *(name+i)='\0';
}
