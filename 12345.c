#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct person                   //structured by a use a one person in more data
{
    char fname[35];
    char lname[50];
    long int mble_no;
    char sex[8];
    };

void addrecord();               //declaration of the function
void listrecord();
void modifyrecord();
void deleterecord();
void searchrecord();

void main()
{
    printf("\t|******************************************************************************|\n");
    printf("\t|                            WELCOME TO PHONEBOOK                              |\n");
    printf("\t|______________________________________________________________________________|\n");
    printf("\n\t\t\t\t\t1.Add New Contact  \n\t\t\t\t\t2.View All Contact  \n\t\t\t\t\t3.Modify Contact \n\t\t\t\t\t4.Search Contact \n\t\t\t\t\t5.Delete Contact\n\t\t\t\t\t6.Exit\n");

switch(getch())
{
    case '1':addrecord();                   //call the relevant function using switch case statement
    break;
   case '2': listrecord();
    break;
    case '3': modifyrecord();
    break;
    case '4': searchrecord();
    break;
    case '5': deleterecord();
    break;
    case '6': exit(0);
    break;
    default :printf("Invalid record press any key to continue");
    getch();
    system("cls");
    main();
}
}
void addrecord()                    //that's a contact adding function
{
        FILE *f;
        struct person p;
        f=(fopen("contact.txt","a"));               //saving data in contact.txt file that file is in a same folder

        printf("\nEnter First name : ");
        scanf("%s",&p.fname);
        printf("\nEnter Last name: ");
        scanf("%s",&p.lname);
        printf("\nEnter phone no.:");
        scanf("%ld",&p.mble_no);
        printf("\nEnter sex (M/F):");
        scanf("%s",&p.sex);
        fwrite(&p,sizeof(p),1,f);

        printf("\nCONTACT SAVED ");

fclose(f);                      //close the file
getch();                        //waiting for a getting a char in keyboard
system("cls");                  //clear the system mod in cmd
main();                         //call the main function
}
void listrecord()                   //that's view all contact function
{
    struct person p;
    FILE *f;
    f=fopen("contact.txt","rb");        //rb is Open for reading in binary mode in contact.txt
    rewind(f);
    if(f==NULL)
    {
    printf("\nfile opening error in listing :");
    }
while(fread(&p,sizeof(p),1,f)==1)
{
     printf("\n\n\n YOUR RECORD IS\n\n ");
        printf("\nFirst Name=%s\nLast Name=%s\nMobile no=%ld\nSex(M/F)=%s\n",p.fname,p.lname,p.mble_no,p.sex);

}
getch();
system("cls");
main();
}
void searchrecord()                 //that's search your contact using this function
{
    struct person p;
    FILE *f;
    char name[100];

    f=fopen("contact.txt","rb");
    rewind(f);
    if(f==NULL)
    {
    printf("\n error in opening\a\a\a\a");
    exit(1);

    }
    printf("\nEnter name of person to search\n");
    scanf("%s",&name);
    while(fread(&p,sizeof(p),1,f)==1)
{
    if(strcmp(p.fname,name)==0)             //strcmp keyword using a compares two strings character by character
    {
        printf("\n\tDetail Information About %s",name);
        printf("\nFirst Name:%s\nLast Name:%s\nMobile no:%ld\nsex(M/F):%s\n",p.fname,p.lname,p.mble_no,p.sex);
    }
    else{
        printf("No Contact Is Found");
    }


}
 fclose(f);
getch();
system("cls");
main();
}
void deleterecord()             //that's function delete  a contact
{

    struct person p;
    FILE *f,*ft;
	char name[100];
	int flag;
	f=fopen("contact.txt","rb+");           //Open for both reading and writing in binary mode in contact.txt
    rewind(f);                      // sets the file position to the beginning of the f file .
	if(f==NULL)
		{
			printf("CONTACT'S DATA NOT ADDED YET.");
		}
	else
	{
		ft=fopen("temp.txt","wb+");     // Open for both reading and writing in binary mode in temp.data file
		if(ft==NULL)

            printf("file opening error");
		else

        {
		printf("Enter CONTACT'S NAME:");
		scanf("%s",&name);



		while(fread(&p,sizeof(p),1,f)==1)
		{
			if(strcmp(p.fname,name)!=0)
				fwrite(&p,sizeof(p),1,ft);
			if(strcmp(p.fname,name)==0)
                flag=1;
		}

	if(flag!=1)
	{
		printf("NO CONACT'S RECORD TO DELETE.");
		remove("temp.txt");
	}
		else
		{
			remove("contact.txt");
			rename("temp.txt","contact.txt");
			printf("RECORD DELETED SUCCESSFULLY.");

		}
	}
}
fclose(f);
fclose(ft);
getch();
system("cls");
main();
}

void modifyrecord()         //this function using a edit your contact
{
    int c;
    FILE *f;
    int flag=0;
    struct person p;
	char  name[50];
	f=fopen("contact.txt","rb+");
	if(f==NULL)
		{
			printf("CONTACT'S DATA NOT ADDED YET.");
		}
	else
	{
		printf("\nEnter CONTACT'S NAME TO MODIFY:\n");
            scanf("%s",&name);
            while(fread(&p,sizeof(p),1,f)==1)
            {
                if(strcmp(name,p.fname)==0)     //strcmp keyword using a compares two strings character by character
                {



                    printf("\n Enter First name:");
                    scanf("%s",&p.fname);
                    printf("\nEnter the Last Name:");
                    scanf("%s",&p.lname);
                    printf("\nEnter phone no:");
                    scanf("%ld",&p.mble_no);
                    printf("\nEnter sex(M/F):");
                    scanf("%s",&p.sex);
                    fseek(f,-sizeof(p),SEEK_CUR);       //set of the curser inside a file *f
                    fwrite(&p,sizeof(p),1,f);
                    flag=1;
                    break;



                }


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
getch();
system("cls");
main();
}
