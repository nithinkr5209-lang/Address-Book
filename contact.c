#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

void listContacts(AddressBook *addressBook, int sortCriteria) 
{
    // Sort contacts based on the chosen criteria

    printf("In which order you want to print the contacts : ");
    printf("\n1.name\n2.phone\n3.email\n");

    int choice;
    printf("Enter the choice : ");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1 : 
    {

    Contact temp;

    for(int i=0;i<addressBook->contactCount;i++)
    {
      for(int j=0;j<addressBook->contactCount-1;j++)
      {
        if(strcmp(addressBook ->contacts[j].name,addressBook -> contacts[j+1].name) > 0 )
        {
        temp = addressBook->contacts[j];
        addressBook->contacts[j] = addressBook->contacts[j+1];
        addressBook->contacts[j+1] = temp;
        }
    }
    }
      

        for(int i = 0; i < addressBook->contactCount; i++)
       {
    printf("%s \t %s \t %s\n",addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
       }
        

    
    break;
}

    case 2 : 
    {

    Contact temp;

    for(int i=0;i<addressBook->contactCount-1;i++)
    {
      for(int j=0;j<addressBook->contactCount-i-1;j++)
      {
        if(strcmp(addressBook ->contacts[j].phone,addressBook -> contacts[j+1].phone) > 0 )
        {
        temp = addressBook->contacts[j];
        addressBook->contacts[j] = addressBook->contacts[j+1];
        addressBook->contacts[j+1] = temp;
        }
    }
    }
    
      for(int i = 0; i < addressBook->contactCount; i++)
       {
    printf("%s\t%s\t%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
       }

    
    break;
      }

 
 case 3 : 
    {

    Contact temp;

    for(int i=0;i<addressBook->contactCount-1;i++)
    {
      for(int j=0;j<addressBook->contactCount-i-1;j++)
      {
        if(strcmp(addressBook ->contacts[j].email,addressBook -> contacts[j+1].email) > 0 )
        {
        temp = addressBook->contacts[j];
        addressBook->contacts[j] = addressBook->contacts[j+1];
        addressBook->contacts[j+1] = temp;
        }
    }
    }
    
    for(int i = 0; i < addressBook->contactCount; i++)
       {
    printf("%s\t%s\t%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
       }
    break;
      }


    default :
    {
    printf("Enter valid number 1, 2,  3");
    }
    }

}


void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    //populateAddressBook(addressBook);
    
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)
{
	/* Define the logic to create a Contacts*/
char name[50];
 int flag;
 int index = addressBook->contactCount;

 while(1)
 {
flag = 1;
printf("enter the name of the contact that u want to create : ");
scanf(" %[^\n]",name);


for(int i=0;name[i]!='\0';i++)
{
if(!((name[i] >= 'a' && name[i] <= 'z')||(name[i] >= 'A' && name[i] <= 'Z')||(name[i] == ' ')))
{
  flag = 0;
  break;
}
}



if(flag==0)
{
  printf("Give a valid name\n");
  
}
else
{
  strcpy(addressBook -> contacts[index].name,name);
  break;
}

 }


char phone[50];
while(1)
{
printf("enter the phone number : ");
scanf(" %[^\n]",phone);
flag = 1;

if(strlen(phone)!=10)
{
  flag =0;
}



else
{
for(int i=0;phone[i]!='\0';i++)
{
if(phone[i] < '0' || phone[i] > '9')
{
 flag = 0;
 break;
}
}
}

if(flag)
{
  strcpy(addressBook -> contacts[index].phone,phone);
  break;
}
else
{
  printf("Give a valid phone number\n");
  
}
}



char email[50];
while(1)
{
printf("enter the email ID : ");
scanf(" %[^\n]",email);

flag = 1;

//int emaillen = strlen(email);
for(int i=0;email[i]!='\0';i++)
{
if(!((email[i] >= 'a' && email[i] <= 'z') ||(email[i] > '0' && email[i] < '9')||(email[i] == '@')||(email[i] == '.')))
{
  flag = 0;
}
}

if(flag)
{
  strcpy(addressBook -> contacts[index].email,email);
  printf("contact created successfully\n");
  addressBook->contactCount++;  
  return;
}
else
{
  printf("enter a valid email\n");
  
}
}

}

void searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
     printf("Search by : \n1.name\n2.phone\n3.email\n");

     int choice;
     printf("enter your choice : ");
     scanf("%d",&choice);
     int flag=0;
     switch(choice)
     {
       case 1 :
       char name[100];
       printf("enter the name : ");
       scanf(" %[^\n]",name);
    
    for(int i=0;i< addressBook->contactCount;i++)
    {  
   
      if((strstr(addressBook -> contacts[i].name,name) != NULL))
      {
        printf("%s\t%s\t%s\n",addressBook -> contacts[i].name,addressBook -> contacts[i].phone,addressBook -> contacts[i].email);
        flag =1;
      }
     
    }


    if(flag == 0)
    {
         printf("No contact found");
    }
    break;
   

case 2 :
char phone[200];
printf("enter the phone number : ");
 scanf(" %[^\n]",phone);

 for(int i=0;i< addressBook->contactCount;i++)
    {  
   
      if((strcmp(addressBook -> contacts[i].phone,phone) == 0))
      {
        
        printf("%s\t%s\t%s\n",addressBook -> contacts[i].name,addressBook -> contacts[i].phone,addressBook -> contacts[i].email);
        flag =1;
      }
     
    }

    if(flag == 0)
    {
         printf("No contact found");
    }
    break;

    case 3 :
char email[200];
printf("enter the email : ");
 scanf(" %[^\n]",email);

 for(int i=0;i< addressBook->contactCount;i++)
    {  
   
      if((strcmp(addressBook -> contacts[i].email,email) == 0))
      {
         
        printf("%s\t%s\t%s\n",addressBook -> contacts[i].name,addressBook -> contacts[i].phone,addressBook -> contacts[i].email);
        flag =1;
      }
     
    }

    if(flag == 0)
    {
         printf("No contact found");
    }
    break;



    default :
    printf("invalid input ");










    }
}


int validateName(char *name)
{
    for(int i = 0; name[i] != '\0'; i++)
    {
        if(!((name[i] >= 'a' && name[i] <= 'z') ||
             (name[i] >= 'A' && name[i] <= 'Z') ||
             (name[i] == ' ')))
        {
            return 0;
        }
    }
    return 1;
}

int validatePhone(char *phone)
{
    if(strlen(phone) != 10)
        return 0;

    for(int i = 0; phone[i] != '\0'; i++)
    {
        if(phone[i] < '0' || phone[i] > '9')
            return 0;
    }
    return 1;
}


int validateEmail(char *email)
{
    for(int i = 0; email[i] != '\0'; i++)
    {
        if(!((email[i] >= 'a' && email[i] <= 'z') ||
             (email[i] >= '0' && email[i] <= '9') ||
             (email[i] == '@') ||
             (email[i] == '.')))
        {
            return 0;   
        }
    }
    return 1;           
}














void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
int i;
 

   printf("search by  : \n1.name\n2.phone\n3.email\n");

     int choice;
     printf("enter your choice : ");
     scanf("%d",&choice);
     int flag=0;
     int index;
     int ind[addressBook->contactCount];
     switch(choice)
     {
       case 1 :
       {
       char name[100];
       printf("enter the name : ");
       scanf(" %[^\n]",name);
       int count = 0;
   //---------------------------------------------------------------------------------- 
    for(int i=0;i< addressBook->contactCount;i++)
    {  

      if((strcmp(addressBook -> contacts[i].name,name) == 0))
      {
      flag = 1;
      ind[count]= i;
      count++;
      }
    }


if(count==1)
{
  i=ind[0];
     
    printf("%s\t%s\t%s\n",addressBook -> contacts[i].name,addressBook -> contacts[i].phone,addressBook -> contacts[i].email);
    printf("what u want to edit\n");
    printf("1.Name\n2.phone\n3.email\n");

    int c;
    printf("enter the choice : ");
    scanf("%d",&c);

    switch(c)
    {
      case 1 :
      {
      char newname[200];
      while(1)
      {
      printf("enter the new name : ");
      scanf(" %[^\n]",newname);



      if(validateName(newname))
      {
      strcpy(addressBook -> contacts[i].name,newname);
      printf("eding name is successful\n");
      return;
      
      }

      else
      {
        printf("Give a valid name\n");
      }
      
    }
    break;
  }
      

     case 2 :
     {
     char newphone[200];
     while(1)
     {
      printf("enter the new phone number : ");
      scanf(" %[^\n]",newphone);

      if(validatePhone(newphone))
      {
      strcpy(addressBook -> contacts[i].phone,newphone);
      printf("eding phone number is successful\n");
      return;
      }

      else
      {
        printf("Give a valid phone number\n");
      }
    }
      break;
    }



      case 3 :
      {
       char newemail[200];
       while(1)
       {
      printf("enter the new email ID : ");
      scanf(" %[^\n]",newemail);

      if(validateEmail(newemail))
      {
      strcpy(addressBook -> contacts[i].email,newemail);
      printf("eding email ID is successful\n");
      }
      else
      {
        printf("Give a valid email\n");
      }
    }
      break;
      
    }
    



    default :
    printf("Invalid input ");

    }
    }
  

    else if(count > 1)
    {

    for(int j = 0; j < count ; j++)
    {
        printf("Serial NO %d :%s\t%s\t%s\n",j,addressBook -> contacts[ind[j]].name,addressBook -> contacts[ind[j]].phone,addressBook -> contacts[ind[j]].email);
    }
    


    printf("which index u want to edit : ");
    int u;
    scanf("%d",&u);


    printf("what u want to edit\n");
    printf("1.Name\n2.phone\n3.email\n");

    int c;
    printf("enter the choice : ");
    scanf("%d",&c);

    switch(c)
    {
      case 1 :
      {
      char newname[200];
      while(1)
      {
      printf("enter the new name : ");
      scanf(" %[^\n]",newname);
      if(validateName(newname))
      {
      strcpy(addressBook -> contacts[ind[u]].name,newname);
      printf("editing successful\n");
      return;
      }
      else
      {
        printf("Give a valid name \n");
      }
      }
      break;
      }

     case 2 :
     {
     char newphone[200];
     while(1)
     {
      printf("enter the new phone number : ");
      scanf(" %[^\n]",newphone);

       if(validatePhone(newphone))
      {
      strcpy(addressBook -> contacts[ind[u]].phone,newphone);
      printf("Editing of phone is successful");
      return;
      }
      else
      {
        printf("Give a valid phone number \n");
      }
      
    }
    break;
    }

      case 3 :
      {
       char newemail[200];
       while(1)
       {
      printf("enter the new email ID : ");
      scanf(" %[^\n]",newemail);

      if(validateEmail(newemail))
      {
      strcpy(addressBook -> contacts[ind[u]].email,newemail);
      printf("Editing of email is successful");
      return;
      }
      else
      {
        printf("Give a valid email id \n");
      }
      }
      break;
      }



    default :
    printf("Invalid input ");

    }
}

if(flag == 0)
    {
         printf("No contact found\n");
    }
    break;

 }


case 2 :
{
    char phone[100];
       printf("enter the phone : ");
       scanf(" %[^\n]",phone);
    
    for(int i=0;i< addressBook->contactCount;i++)
    {  
   
      if((strcmp(addressBook -> contacts[i].phone,phone) == 0))
      {
        printf("%s\t%s\t%s\n",addressBook -> contacts[i].name,addressBook -> contacts[i].phone,addressBook -> contacts[i].email);
        flag =1;
        index = i;
      }
    }
    

   if(flag)
   {
    printf("what u want to edit\n");
    printf("1.Name\n2.phone\n3.email\n");

    int c;
    printf("enter the choice : ");
    scanf("%d",&c);

    switch(c)
    {
      case 1 :
      {
      char newname[200];
      while(1)
      {
      printf("enter the new name : ");
      scanf(" %[^\n]",newname);
      if(validateName(newname))
      {
      strcpy(addressBook -> contacts[index].name,newname);
      printf("Editing of name is successsful\n");
      return;
      }
      else
      {
       printf("Give a valid name\n");
      }
      }
     break;
    }

     case 2 :
     {
     char newphone[200];
     while(1)
     {
      printf("enter the new phone number : ");
      scanf(" %[^\n]",newphone);
      if(validatePhone(newphone))
      {
      strcpy(addressBook -> contacts[index].phone,newphone);
      printf("Editing of phone number is successful\n");
      return;
      }
      else
      {
       printf("Give a valid name\n");
      }
     }
      break;
    }

      case 3 :
      {
       char newemail[200];
       while(1)
       {
      printf("enter the new email ID : ");
      scanf(" %[^\n]",newemail);
      if(validateEmail(newemail))
      {
      strcpy(addressBook -> contacts[index].email,newemail);
      printf("Editing of email id is successful\n");
      return;
      }
      else
      {
        printf("Give a valid email ID\n");
      }
       }
      break;
      }



    default :
    printf("Invalid input ");

    }
    
  }

 if(flag == 0)
    {
         printf("No contact found\n");
    }

    break;

}
    case 3 :

    {

      char email[100];
       printf("enter the email : ");
       scanf(" %[^\n]",email);
    
    for(int i=0;i< addressBook->contactCount;i++)
    {  
   
      if((strcmp(addressBook -> contacts[i].email,email) == 0))
      {
        printf("%s\t%s\t%s\n",addressBook -> contacts[i].name,addressBook -> contacts[i].phone,addressBook -> contacts[i].email);
        flag =1;
        index = i;
      }
    }
    

   if(flag)
   {
    printf("what u want to edit\n");
    printf("1.Name\n2.phone\n3.email\n");

    int c;
    printf("enter the choice : ");
    scanf("%d",&c);

    switch(c)
    {
      case 1 :
      {
      char newname[200];
      while(1)
      {
      printf("enter the new name : ");
      scanf(" %[^\n]",newname);
      if(validateName(newname))
      {
      strcpy(addressBook -> contacts[index].name,newname);
      printf("Editing of name is successful\n");
      return;
      }
      else
      {
      printf("Give a valid name\n");
      }
      }
     break;
      }

     case 2 :
     {
     char newphone[200];
     while(1)
     {
      printf("enter the new phone number : ");
      scanf(" %[^\n]",newphone);
      if(validatePhone(newphone))
      {
      strcpy(addressBook -> contacts[index].phone,newphone);
      printf("Editing of phone number is successful\n");
      return;
      }
      else
      {
        printf("Give a valid phone number\n");
      }
     }
      break;
    }

      case 3 :
      {
       char newemail[200];
       while(1)
       {
      printf("enter the new email ID : ");
      scanf(" %[^\n]",newemail);
      if(validateEmail(newemail))
       {
      strcpy(addressBook -> contacts[index].email,newemail);
      printf("Email id is successfully edited\n");
      return;
       }

      else
      {
       printf("Give a valid email\n");
      }
    }
      break;
      }



    default :
    printf("Invalid input ");

    }
    
  }

 if(flag == 0)
    {
         printf("No contact found\n");
    }

    break;
    }

    default :
    printf("invalid");
     }
}







void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */

    printf("search by  : \n1.name\n2.phone\n3.email\n");

     int choice;
     printf("enter your choice : ");
     scanf("%d",&choice);
     int flag=0;
     int count =0;
     int i;
     int index;
     int ind[addressBook->contactCount];
     switch(choice)
     {
       case 1 :
       {
       char name[100];
       printf("enter the name : ");
       scanf(" %[^\n]",name);
    
    for(int i=0;i< addressBook->contactCount;i++)
    {  
   
      if((strcmp(addressBook -> contacts[i].name,name) == 0))
      {
        flag = 1;
        ind[count]=i;
        count++;
      }
      
  
      }

      if(flag == 0)
            {
              printf("Contact not found");
              return ;
            }


      if(count == 1)
      {
        int i = ind[0];
        printf("%s\t%s\t%s\n",addressBook -> contacts[i].name,addressBook -> contacts[i].phone,addressBook -> contacts[i].email);
          
          printf("Are you sure you want delete\n yes - y \n No - n \n");
          char c;
          scanf(" %c",&c);

        // shift contacts
        if(c=='y'|| c=='Y')
        {
            for(int j = i; j < addressBook->contactCount - 1; j++)
            {
                addressBook->contacts[j] = addressBook->contacts[j + 1];
            }

            addressBook->contactCount--;

            printf("Contact deleted successfully\n");
        }

        else if(c=='N'||c=='n')
        {
          printf("The contact is not deleted");
          
        }

        else
        {
           printf("Give valid input Y or N");
        }
      }



      else if(count > 1)
      {
           for(int k = 0 ; k < count ; k++)
           {
          printf("serial no : %d,%s\t%s\t%s\n",k,addressBook -> contacts[ind[k]].name,addressBook -> contacts[ind[k]].phone,addressBook -> contacts[ind[k]].email);
           }
      
      printf("Enter the serial number that u want delete : ");
      int u;
      scanf("%d",&u);



       printf("Are you sure you want delete\n yes - y \n No - n \n");
          char c;
          scanf(" %c",&c);

       
        if(c=='y'|| c=='Y')
        {
            // shift contacts
            for(int j = ind[u]; j < addressBook->contactCount - 1; j++)
            {
                addressBook->contacts[j] = addressBook->contacts[j + 1];
            }

            addressBook->contactCount--;

            printf("Contact deleted successfully\n");

        }

        else if(c=='N' || c=='n')
        {
          printf("The contact is not deleted");
        }

        else
        {
          printf("Give valid input Y or N");
        }
      }
            break;
       }

   case 2 :
   {
       char phone[100];
       printf("enter the phone : ");
       scanf(" %[^\n]",phone);
       int index ;
       
    
    for(int i=0;i< addressBook->contactCount;i++)
    {  
   
      if((strcmp(addressBook -> contacts[i].phone,phone) == 0))
      {
       
        printf("%s\t%s\t%s\n",addressBook -> contacts[i].name,addressBook -> contacts[i].phone,addressBook -> contacts[i].email);
        flag = 1;  
        index = i;
      }
      
  
      }

      if(flag == 0)
            {
              printf("Contact not found");
              return ;
            }

    printf("Are you sure you want delete\n yes - y \n No - n \n");
          char c;
          scanf(" %c",&c);

        // shift contacts
        if(c=='y'|| c=='Y')
        {
            // shift contacts
            for(int j = index; j < addressBook->contactCount - 1; j++)
            {
                addressBook->contacts[j] = addressBook->contacts[j + 1];
            }

            addressBook->contactCount--;

            printf("Contact deleted successfully\n");
        }

        else if(c=='N' || c=='n')
        {
          printf("The contact is not deleted");
        }

        else
        {
          printf("Give valid input Y or N");
        }

            break;
   }



  case 3 :
  {
       char email[100];
       printf("enter the email : ");
       scanf(" %[^\n]",email);
       int index;
       
    
    for(int i=0;i< addressBook->contactCount;i++)
    {  
   
      if((strcmp(addressBook -> contacts[i].email,email) == 0))
      {
       
        printf("%s\t%s\t%s\n",addressBook -> contacts[i].name,addressBook -> contacts[i].phone,addressBook -> contacts[i].email);
        flag = 1;
        index = i;
      }
      
  
      }

      if(flag == 0)
            {
              printf("Contact not found");
              return ;
            }

         printf("Are you sure you want delete\n yes - y \n No - n \n");
          char d;
          scanf(" %c",&d);

        // shift contacts
        if(d=='y'|| d=='Y')
        {
            // shift contacts
            for(int j = index; j < addressBook->contactCount - 1; j++)
            {
                addressBook->contacts[j] = addressBook->contacts[j + 1];
            }

            addressBook->contactCount--;

            printf("Contact deleted successfully\n");
        }



       else if(d=='N' || d=='n')
        {
          printf("The contact is not deleted");
        }

        else
        {
          printf("Give valid input Y or N");
        }

            break;
  }

            default :
            printf("Invalid number , enter only 1 2 3");
}
}

