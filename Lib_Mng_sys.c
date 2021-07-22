#include<stdio.h>
#include<string.h>
#include<conio.h>
void write();            //funtcion to write into the FILE
void read();             //funtcion to write into the FILE
void search_menu();      //function to calll search menu
void searching_with_code(); //function to search with CODE
void searching_with_name(); //function to search with NAME
void searching_with_genre();//function to search with GENRE
void delete_rcrd();        //function to delte RECORD
int i;                     //used in FOR loop
struct book{
	int book_code;
	char book_name[500];
	char book_genre[500];
}b1;

void main()

{       int a;
	clrscr();
	

	printf("\n10011111000011001010101001010101010100101010101010101001010101010101001011101111");
	printf("\n\n\t\t------------[ A PROJECT ON LIBRARY MANAGEMENT BY  ]------------\n");
	printf("\t\t\t-----------------------------------\t\n\n");
    printf("\n\n\n");
    printf("\n\t\t\t\t   T. Jahnavi");
    printf("\n\t\t\t\t ______");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tPRESS ENTER TO MOVE AHEAD....");
    getch();

	clrscr();
	do{                //do while to repeat MAIN MENU again & again
	printf("____________________________");

	printf("\n\n\t\tSELECT AN OPTION\n\n");
	printf("\t\t1.write\n\t\t2.read\n");
	printf("\t\t3.Search for a book \n\t\t4.EXIT\n\t\t5.Delete");
	printf("\n\n\n\t\t  Your Choice::::::");
	scanf("%d",&a);
	switch(a)
		{
			case 1:write();  break;
			case 2:read();   break;
			case 3:search_menu(); break;
			case 4:break;
			case 5:delete_rcrd();break;
		}
	}while(a!=4);
   clrscr();
   printf("\n\n\n\n\n\n\n\n\n\t\t!!!!!!! THANKS FOR VISITING US !!!");
   printf("\n\n\n\t........LOOKING FORWARD TO YOUR NEXT VISIT........");
   printf("\n\n\n\n\n\n\n\n\n\n\n\nPRESS ENTER TO EXIT...");


       getch();
}


void read()   //function to READ DATA FROM FILE
{
	FILE *fp;
	clrscr();
	fp=fopen("file_one","r");
	if(fp==NULL)
	{
		puts("EMPTY FILE");
		getch();
		return 1;

	}
	while(fscanf(fp,"%d %s %s",&b1.book_code,b1.book_name,b1.book_genre)!=EOF)
	{
	 //this block is to convert "_" into SPACE after reading
	 //the data from the FILE
		for(i=0;i<strlen(b1.book_name);i++)
		{
			if (b1.book_name[i]=='_')
			    {
				b1.book_name[i]=' ';
			    }
		}
		for(i=0;i<strlen(b1.book_genre);i++)
		{
			if (b1.book_genre[i]=='_')
			    {
				b1.book_genre[i]=' ';
			    }
		}

	delay(300);
	printf("................................................................................");
	printf("\n\n\t\t   Book Code----------::%d",b1.book_code);
	printf("delay aanevala");
	delay(1000);
	printf("delay aagya");
	printf("\n\n\t\t   Book Name----------::%s",b1.book_name);
	delay(100);
	printf("\n\n\t\t   Book Genre---------::%s\n",b1.book_genre);
	delay(200);
	}
	fclose(fp);
	getch();
}



void write()             //function to WRITE DATA into the FILE
{
	FILE *fp;
	char a='y';
	clrscr();
	printf("\n10011111000011001010101001010101010100101010101010101001010101010101001011101111\n\n");
	fp=fopen("file_one","a");
	while(a=='y' || a=='Y')
	{
	delay(100);
	printf("\n\t-----------------------Enter Book Details-------------------");
	delay(100);
	printf("\n\n\t\t\tEnter Book Code:::::::::::");
	scanf("%d",&b1.book_code);
	delay(100);
	printf("\n\t\t\tEnter Book Name:::::::::::");
	fflush(stdin);
	gets(b1.book_name);
	 //this block is to convert  SPACE into "_" after getting
	 //the data from the USER
	for(i=0;i<strlen(b1.book_name);i++)
		{
			if (b1.book_name[i]==' ')
			    {
				b1.book_name[i]='_';
			    }
		}
	delay(100);
	printf("\n\t\t\tEnter Book Genre::::::::::");
	fflush(stdin);
	gets(b1.book_genre);
	//this block is to convert  SPACE into "_" after getting
	 //the data from the USER
		for(i=0;i<strlen(b1.book_genre);i++)
		{
			if (b1.book_genre[i]==' ')
			    {
				b1.book_genre[i]='_';
			    }
		}

	fprintf(fp,"%d %s %s\n",b1.book_code,b1.book_name,b1.book_genre);

	printf("\n\n\t\t\t-----Data Saved!!!-----\n");
	printf("\n================================================================================");
	printf("\t\t If you want to enter More Book Details press Y  ");
	fflush(stdin);
	a=getche();
	}
	fclose(fp);
	delay(100);
}


void searching_with_code()  //function to SEARCH with help of CODE
{       int v,cap=0;
	FILE *fp;
	clrscr();
	printf("\n10011111000011001010101001010101010100101010101010101001010101010101001011101111\n\n");
	printf("\n\tEnter BOOK CODE:::::::::::::");
	scanf("%d",&v);
	fp=fopen("file_one","r");
	if(fp==NULL)
	{
		puts("EMPTY FILE");
		getch();
		return 1;

	}
	while(fscanf(fp,"%d %s %s",&b1.book_code,b1.book_name,b1.book_genre)!=EOF)
   {     //this block is to convert "_" into SPACE after reading
	 //the data from the FILE

		for(i=0;i<strlen(b1.book_name);i++)
		{
			if (b1.book_name[i]=='_')
			    {
				b1.book_name[i]=' ';
			    }
		}
		for(i=0;i<strlen(b1.book_genre);i++)
		{
			if (b1.book_genre[i]=='_')
			    {
				b1.book_genre[i]=' ';
			    }
		}

	delay(100);
	if(b1.book_code==v)
   {
	printf("\n\n\t\t   Book Code----------::%d",b1.book_code);
	delay(100);
	printf("\n\n\t\t   Book Name----------::%s",b1.book_name);
	delay(100);
	printf("\n\n\t\t   Book Genre---------::%s",b1.book_genre);
	delay(100);
	printf("\n................................................................................");
	cap=1;
   }

   }
	if(cap==0)
	{
	printf("\n\t\t-----Book Code Not Found!!-----\n");
	}
	fclose(fp);
}




void searching_with_name()  //function to SEARCH using NAME
{       int v=-1,cap=0;
	char sea[100];
	FILE *fp;
	clrscr();
	printf("\n10011111000011001010101001010101010100101010101010101001010101010101001011101111\n\n");
	printf("\n\tEnter BOOK NAME:::::::::::::");
	fflush(stdin);
	gets(sea);
	fp=fopen("file_one","r");
	if(fp==NULL)
	{
		puts("EMPTY FILE");
		getch();
		return 1;

	}
	while(fscanf(fp,"%d %s %s",&b1.book_code,b1.book_name,b1.book_genre)!=EOF)
   { //while loop to READ data FROM the FILE
	 //this block is to convert "_" into SPACE after reading
	 //the data from the FILE

		for(i=0;i<strlen(b1.book_name);i++)
		{
			if (b1.book_name[i]=='_')
			    {
				b1.book_name[i]=' ';
			    }
		}
		for(i=0;i<strlen(b1.book_genre);i++)
		{
			if (b1.book_genre[i]=='_')
			    {
				b1.book_genre[i]=' ';
			    }
		}

	delay(100);
	v=strcmpi(b1.book_name,sea);

	if(v==0)       //DATA will be shown only if it matches the user
	//required data and IF ges executed else it is just skipped
   {
	printf("\n\n\t\t   Book Code----------::%d",b1.book_code);
	delay(100);
	printf("\n\n\t\t   Book Name----------::%s",b1.book_name);
	delay(100);
	printf("\n\n\t\t   Book Genre---------::%s",b1.book_genre);
	delay(100);
	printf("\n................................................................................");
	cap=1;
   }

   }
	if(cap==0)
	{
	printf("\t\t---Book Name Not Found!!\n");
	}
	fclose(fp);
}

void searching_with_genre()  //function used to SEARCH using GENRE
{       int v=-1,cap=0;
	char sea[100];
	FILE *fp;
	clrscr();
	printf("\n10011111000011001010101001010101010100101010101010101001010101010101001011101111");
	printf("\n\t\tEnter BOOK GENRE:::::::::::::");
	fflush(stdin);
	gets(sea);
	fp=fopen("file_one","r");
	if(fp==NULL)
	{
		puts("EMPTY FILE");
		getch();
		return 1;

	}
	while(fscanf(fp,"%d %s %s",&b1.book_code,b1.book_name,b1.book_genre)!=EOF)
       //WHILE is used to read DATA from FILE
   {
    //this block is to convert "_" into SPACE after reading
	 //the data from the FILE

		for(i=0;i<strlen(b1.book_name);i++)
		{
			if (b1.book_name[i]=='_')
			    {
				b1.book_name[i]=' ';
			    }
		}
		for(i=0;i<strlen(b1.book_genre);i++)
		{
			if (b1.book_genre[i]=='_')
			    {
				b1.book_genre[i]=' ';
			    }
		}

	delay(300);
	v=strcmpi(b1.book_genre,sea);

	if(v==0)
   {
	printf("\n\n\t\t   Book Code----------::%d",b1.book_code);
	delay(100);
	printf("\n\n\t\t   Book Name----------::%s",b1.book_name);
	delay(100);
	printf("\n\n\t\t   Book Genre---------::%s",b1.book_genre);
	delay(100);
	printf("\n................................................................................");
	cap=1;
   }

   }
	if(cap==0)
	{
	printf("\t\t---Book Genre Not Found!!\n");
	}
	fclose(fp);
}

void search_menu()          //function to SHOW search menu
{       int v;
	clrscr();
	printf("------------------------------------------------------------------------------");
	printf("\t\tSearch By::::::::::::::");
	printf("\n\t\t1.Book CODE\n\t\t2.Book NAME\n\t\t3.Book GENRE\n\n");
	printf("\n\n\n\t\t  Your Choice::::::");
	scanf("%d",&v);
	switch(v)
	{
	case 1:	searching_with_code();break;
	case 2:	searching_with_name();break;
	case 3:	searching_with_genre();break;

	}

}

void delete_rcrd()         //function to delete record
{
	FILE *fp,*fnew;
	int v;
	char c;
	clrscr();
	printf("\n10011111000011001010101001010101010100101010101010101001010101010101001011101111");
	printf("\n\nEnter the Book CODE you want to DELETE::");
	scanf("%d",&v);
	fp=fopen("file_one","r");
	fnew=fopen("file_two","w");
	if(fp==NULL)
	{
		puts("EMPTY FILE");
		getch();
		return 1;

	}
	while(fscanf(fp,"%d %s %s",&b1.book_code,b1.book_name,b1.book_genre)!=EOF)

   {
	delay(100);
	if(b1.book_code==v)
	continue;
	fprintf(fnew,"%d %s %s\n",b1.book_code,b1.book_name,b1.book_genre);


   }
	printf("\n\n\t\t\t\t-----FILE DELETED-----\n");
	fclose(fp);
	fclose(fnew);
	remove("file_one");
	rename("file_two","file_one");
}
