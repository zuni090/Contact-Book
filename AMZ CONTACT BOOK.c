//********INCLUDING LIBRARIES********
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>


//********STRUCTURE FOR CONTACT'S DETAILS***********
typedef struct
{

char stnumber[10];
char name[20];
char lname[20];
char num[20];
char email[30];
char address[50];
char gender[8];
}student;


//***FUNCTIONS FOR SEARCH , CLEAN , AND MAIN MENU DISPLAYER*******
int search(student st[],char id[], int itemcount);
void clean(student st[],int deleteitem);
void displayheading();


//********MAIN MENU***********
void displaymenu(){
	
	system("color 3");

	printf("\n\t\t  ================================================");
	printf("\n\n\t\t |    *****WELCOME TO OUR AMZ CONTACT BOOK*****   |");
	printf("\n\n\t\t  ================================================");
	
	//*****ALGORITHM ADDED FOR DISPALYING CURRENT DATE AND TIME********
  char cur_time[128];
  
  time_t      t;
  struct tm*  ptm;
  
  t = time(NULL);
  ptm = localtime(&t);
    
  strftime(cur_time, 128, "%d-%b-%Y  %H:%M:%S", ptm);
  printf("\nDate : time : %s", cur_time);
  printf("\n\n");
  // DATE PART ENDED
  
  
  //*********OPTIONS / FEATURES DISPLAYER OF WHOLE PROGRAM
  printf("===============\n");
  printf(" MENU \n");
  printf("===============\n");
  printf(" 0. To exit the program\n");
  printf(" 1. Add records  in Phonebook\n");
  printf(" 2. View all records in Phonebook\n");
  printf(" 3. Update records in Phonebook\n");
  printf(" 4. Search records in Phonebook\n");
  printf(" 5. Delete the records in Phonebook\n");

}
//DISPLAY MENU ENDED

//********FUNCTION FOR ADDING RECORD OF CONTACT**************
void add_rec(student st[],int *itemcount)
{
	system("CLS");   //USED FOR CLEARING SCREEN BEFORE ANY FURTHER SUBSITUTION OR ADDING
	
	printf("\n\t\t  ================================================");
	printf("\n\n\t\t |    *****WELCOME TO OUR AMZ CONTACT BOOK*****   |");
	printf("\n\n\t\t  ================================================\n\n");
	

	again:       //******CREATED AS SUB FUNCTION SO THAT CAN BE CALLED AGAIN AND AGAIN WHEN REQUIRED BY USING "GOTO" BUILT-IN FUNCTION*****
	
	printf("Enter ID: ");    //ID - this is taken as primary key throughout program**********
  	scanf("%s",&st[*itemcount].stnumber);
  	if(search(st,st[*itemcount].stnumber,*itemcount)!=-1)       //checker if same ID already exist , display following message or else ask for further details
	{
	    printf("\nThis ID already exists\n");
		goto again;
	}


	printf("Enter First Name: ");
	fflush(stdin);     //this function is used to flush out before stream execution
  	gets(st[*itemcount].name);
  	printf("Enter Last Name: ");
  	fflush(stdin);
  	gets(st[*itemcount].lname);    //**using "GETS'" to include words after spaces as well 
   	printf("Enter phone number: ");
   	fflush(stdin);
   	scanf("%s",&st[*itemcount].num);
   	printf("Enter email: ");
   	fflush(stdin);
   	scanf("%s",&st[*itemcount].email);
   	printf("Enter address: ");
   	fflush(stdin);
   	gets(st[*itemcount].address);
   	printf("Enter Gender: ");
   	fflush(stdin);
   	scanf("%s",&st[*itemcount].gender);
   	FILE *fptr=fopen("contact.txt","a");
   	if (fptr==NULL)
	{
		exit(2);
	}
	else
	{
		fwrite(&st[*itemcount],sizeof(student),1,fptr);
	}
	fclose(fptr);
   	++(*itemcount);
   	printf("\nContact added successfully\n\n");
   }
   //*********ADDING function ended************//
   
   
   //****************FUNCTION FOR SEARCHING OF CONTACT****************//
   int search(student st[], char id[],int itemcount){
  int found =-1,i;

  for (i = 0; i < itemcount && found==-1; i++)
  {

    if (strcmp(st[i].stnumber,id)==0) found=i;        //searching contact by using ID ,(primary key) and comapring it with all added contacts
                                                       //if contacts found it will display its details else display suitable message
    else found=-1 ;
  }

return found;
}


//***************FUNCTION FOR LISTING OF CONTACTS************
void viewall(student st[], int itemcount)
{
	system("cls");	
	
	printf("\n\t\t  ================================================");
	printf("\n\n\t\t |    *****WELCOME TO OUR AMZ CONTACT BOOK*****   |");
	printf("\n\n\t\t  ================================================\n\n");
	
 	int i=0,j;
	for (j=0;j<itemcount;j++)
	{
		if (strcmp(st[j].name,"")==0)
   		{
   			continue;	
		}
   		else
		{ 	printf("\t\tDETAILS OF CONTACT %d",i+1);
			printf("\n\t\t=====================");
   			fflush(stdin);
   			printf("\n\n\nID: %s",st[j].stnumber);
   			printf("\nFirst Name: %s",st[j].name);
   			printf("\nLast Name: %s",st[j].lname);
   			printf("\nContact Number: %s",st[j].num);
   			printf("\nEmail ID: %s",st[j].email);
   			printf("\nAddress: %s",st[j].address);
   			printf("\nGender: %s",st[j].gender);
     		printf("\n");
     		i++;
   		}
   		
   		

}
system("PAUSE");    //used to hold and stop the program temporarily until new key is pressed


}
//****LISTING part ended***********//

//**********FUNCTION FOR UPDATING CONTACT'S DETAIL(S)*********//
void update_rec(student st[],int itemcount){
system("cls");	
	printf("\n\t\t  ================================================");
	printf("\n\n\t\t |    *****WELCOME TO OUR AMZ CONTACT BOOK*****   |");
	printf("\n\n\t\t  ================================================\n\n");
	
char id[10];
int column_index;
printf("Enter student's ID:");           //scanning ID of contact you want to update//
scanf("%s",&id);
printf("\n1. First name\n2. Last Name\n3. Number\n4. Email\n5. Address\n");
printf("Which field you want to update(1-5)?:"); //asking that which particular domain you want to update of contact
scanf("%d",&column_index);

//***searching for that contact in list*****//
int index = search(st, id,itemcount);

if (index != -1)
{
if (column_index == 1)    //for updating first name
{
printf("Enter student's First Name:");
fflush(stdin);
gets(st[index].name);
printf("\nField updated successfully!\n");   //messagge displayer as indicator
}
else if (column_index == 2)   //for updating last name
{
printf("Enter Last name : ");
fflush(stdin);
gets(st[index].lname);
printf("\nField updated successfully!\n");
}
else if (column_index == 3)      //for updating cell #
{
printf("Enter phone number :");
scanf("%s",&st[index].num);
printf("\nField updated successfully!\n");
}
else if (column_index == 4)        //for updating email - ID
{
printf("Enter email :");
scanf("%s",&st[index].email);
printf("\nField updated successfully!\n");
}
else if (column_index == 5)     //for updating residential address
{
printf("Enter address : ");
gets(st[index].address);
printf("\nField updated successfully!\n");
}

else printf("Invalid column index");    //if user enter other than that number mentioned , display this message
}
else printf("The record deosn't exits.Check the ID and try again.");    //if user enter a ID that doesn't exist in list, display this message

}
//****UPDATING part ended*******//

//***********FUNCTION FOR SEARCHING PART ************//
void find(student st[], int itemcount)
{
system("cls");	

	printf("\n\t\t  ================================================");
	printf("\n\n\t\t |    *****WELCOME TO OUR AMZ CONTACT BOOK*****   |");
	printf("\n\n\t\t  ================================================\n\n");
		
char id[10];
printf("Enter student's ID:");     //asking user to enter ID you want to search
scanf("%s",&id);

int index=search(st,id,itemcount);    //making it as a parameter and equating to searchh function to find that particular contact
if (index != -1)
{
                                        //***********if ID exist , dsiplay following details********//
	printf("\t\tDETAILS OF CONTACT");
	printf("\n\t\t==================");
   	fflush(stdin);
   	printf("\n\n\nID: %s",st[index].stnumber);
   	printf("\nFirst Name: %s",st[index].name);
   	printf("\nLast Name: %s",st[index].lname);
   	printf("\nContact Number: %s",st[index].num);
   	printf("\nEmail ID: %s",st[index].email);
   	printf("\nAddress: %s",st[index].address);
   	printf("\nGender: %s",st[index].gender);
    printf("\n");
	
	 
}
else printf("The record doesn't exits.\n");      //***else display this message*****//



}
//******SEARCHING part ended**********//


//*************FUNCTION FOR DELETING PART***************//
void delete_rec(student st[], int *itemcount){
system("cls");	

	printf("\n\t\t  ================================================");
	printf("\n\n\t\t |    *****WELCOME TO OUR AMZ CONTACT BOOK*****   |");
	printf("\n\n\t\t  ================================================\n\n");

char id[10];
int index,i;
if (*itemcount > 0)
{
printf("Enter student's ID:"); 
fflush(stdin);      //asking to enter ID you want to delete
gets(id);
index = search(st, id,*itemcount);       //seaching for that ID

if ((index!=-1) && (*itemcount != 0))
{
//if (index == (*itemcount-1)) //  comparing   record

	clean(st, index);   //if found clean it from memory
//--(*itemcount);

printf("The record was deleted.\n");

/*else 
{
for (i = index; i < *itemcount-1; i++)
{
st[i] = st[i + 1];
clean(st, *itemcount);
--(*itemcount) ;
}
    */
}



else if (index==-1)
{
	printf("The record doesn't exist.Check the ID and try again.\n");	
} 
}
else if (itemcount<=0)
{
	printf("No record to delete\n");
}
}



  //if all records are deleted or none is available in list , display this message


//*******DELETE part ended***********//

//****clean function  algorithm used in deleting part**********//
void clean(student st[],int index)
{
strcpy(st[index].stnumber,"");
strcpy(st[index].name,"");
strcpy(st[index].lname,"");
strcpy(st[index].num ,"");
strcpy(st[index].email,"");
strcpy(st[index].address, "");
strcpy(st[index].gender,"");


}

//******************************************MAIN DRIVER CODE********************************************//
int main(){
	int i;
	student st[25];
	
int itemcount=3;

FILE *fptr=fopen("contact.txt","a");
if (fptr==NULL)
{
	printf("File not found exiting\n");
	exit(1);
}
else
{
	for (i=0;i<3;i++)
	{
		fread(&st[i],sizeof(student),1,fptr);
	}
}

printf( "\n\n\n\n\n\n\n\n\n\n    WW   WW   WW  EEEEEEE   LL       CCCCCCC   OOOOOOO  MMMMMMMMMMMM  EEEEEEE  \n");
	sleep(1);
	printf( "    WW   WW   WW  EE        LL       CC        OO   OO  MM   MM   MM  EE       \n");
	sleep(1);
	printf("    WW   WW   WW  EEEEEEE   LL       CC        OO   OO  MM   MM   MM  EEEEEEE  \n");
	sleep(1);
	printf("    WW   WW   WW  EE        LL       CC        OO   OO  MM   MM   MM  EE       \n");
	sleep(1);
	printf("    WW   WW   WW  EE        LL       CC        OO   OO  MM   MM   MM  EE       \n");
	sleep(1);
	printf("    WWWWWWWWWWWW  EEEEEEE   LLLLLLL  CCCCCCC   OOOOOOO  MM   MM   MM  EEEEEEE  \n");
	sleep(3);
	
	system("cls");
	
	printf("\n\n\n\t\t\t\tTEAM MEMBERS\n\t\t\t\t============");
	printf("\n\n\n\n\t\t\t\t\tName\t     ||\tRoll #\n\t\t\t\t=====================================\n");
	printf("\n\t\t\t\t1)Muhammad Zunique   ||  20K-0145");
	sleep(1);
	printf("\n\t\t\t\t2)Ammar Siddiqui     ||  20K-0177");
	sleep(1);
	printf("\n\t\t\t\t3)Muaz Zaffar        ||  20K-0363");
	sleep(1);
	printf("\n\n\t\t\t\tCourse Co-ordinator  : Miss Atiya Jokhio");
	printf("\n\n\t\t\t\tLab Instructor -> E1 : Sir Hamza Ahmed");
	printf("\n\n\t\t\t\tLab Instructor -> E2 : Miss Rahemeen");
	sleep(3);
	system("cls");
	


displaymenu();
int yourchoice;
char confirm;
do
{
printf("Enter your choice(0-5): ");
scanf("%d",&yourchoice);
if (yourchoice==0)   //*****EXITING CHOICE**********//
{
	printf("\t\t\t\tTHANK YOU!!\n\n");  
	break;
}

//****SWITCH CASE made for approaching all functions******//
switch(yourchoice){
case 1:add_rec(st, &itemcount);break;
case 2:viewall(st, itemcount);break;
case 3:update_rec(st, itemcount);break;
case 4:find(st, itemcount);break;
case 5:delete_rec(st, &itemcount);break;

default:printf("invalid input\n");    //default case
}

printf("Press y or Y to continue:");
fflush(stdin);
scanf("%c",&confirm);
system("CLS");
printf("\n0. To exit the program\n");
printf("1. Add records  in Phonebook\n");
printf("2. View all records in Phonebook\n");
printf("3. Update records in Phonebook\n");
printf("4. Search records in Phonebook\n");
printf("5. Delete the records in Phonebook\n");
}while(confirm=='y'||confirm=='Y');
return EXIT_SUCCESS;
}

//*************MAIN DRIVER CODE ENDED *************//

                                               //**********PROGRAM ENDED*************//   Thank you .......!!!!
