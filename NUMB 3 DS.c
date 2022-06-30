#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct studentInfo{
        char regno[15];
        char fname[15];
        char secname[15];
        char sex[6];
        int age;
        int yearofStudy;
        char dProgram[25];
        struct studentInfo *link;
}STUDENT;

STUDENT *head=NULL;

//function declaration
void homePage();

void addRecord();
void addFirstEnd();
void addMiddle();

void modifyRecord();
void deleteRecord();

void printAll();
void printOnce();


//main function
int main(){
    //call home page function
    homePage();
    
    system("pause");    
}


//homepage function
void homePage(){
      
        printf("\n\nSTUDENT INFORMATION SYSTEM (SIS)\n\n");
        
        printf("1. Add new record at the start of a list.\n");
        printf("2. Add new record at the end of a list.\n");
        printf("3. Add new record at the middle of a list.\n");
        printf("4. Modify a record.\n");
        printf("5. Delete a record.\n");
        printf("6. Print all records.\n");
        printf("7. Print particular record.\n");
        printf("choose q or Q to quit a program.\n\n");  
        
        printf("Enter your choice: ");
        
        char choice;
        scanf("%s",&choice);
       
        switch(choice){
             case '1':
             case '2':addFirstEnd();break;
             case '3':addMiddle();break;
             case '4':modifyRecord();break;
             case '5':deleteRecord();break;
             case '6':printAll();break;
             case '7':printOnce();break;
             case 'q':
             case 'Q':printf("Enjoy the system.\n\n");exit(0);break;
             default:printf("Invalid choice, please enter again.\n\n");
                     homePage();
                     break;
        }
}


//add first
void addFirstEnd(){
    
    STUDENT *stds;
    if(head==NULL){
         stds=(STUDENT *)malloc(sizeof(STUDENT));
         stds->link=head;
         head=stds; 
    }
    else{
         STUDENT *current=head;
         stds=(STUDENT *)malloc(sizeof(STUDENT));
        
         while(current->link!=NULL){current=current->link;}
         current->link=stds;
         stds->link=NULL;      
    }   
    
         printf("\nProvide student information:\n\n");
         printf("Registration number: "); scanf("%s",&stds->regno);
         STUDENT *check=head;
         while(check->link!=NULL){
               if(strcmp(check->regno,stds->regno)==0){
                  printf("Registration number already exist.\n\n");
                  free(stds);
                  addFirstEnd();
                  break;
               }
               check=check->link;
         }
         printf("First name: ");          scanf("%s",&stds->fname);
         printf("Second name: ");         scanf("%s",&stds->secname);
         printf("sex: ");                 scanf("%s",&stds->sex);
         printf("Age: ");                 scanf("%d",&stds->age);
         printf("Year of study: ");       scanf("%d",&stds->yearofStudy);
         printf("Degree program: ");      scanf("%s",&stds->dProgram);
         
         
         printf ( "\nStudent record successfully inserted.\n" );
         homePage(); 

}



//add at the middle
void addMiddle(){
    
    if(head==NULL){
        printf("List is empty.");
        homePage(); 
    }
    else {
         
         char regnum[15];
    
         printf("\n\nEnter registration number that new student will be inserted after: ");
         scanf("%s",&regnum);
     
         STUDENT *current=head;
         STUDENT *std=(STUDENT *)malloc(sizeof(STUDENT));
        
         while(current!=NULL){
             if(strcmp(current->regno,regnum)==0){
                                                  
                 printf("\nProvide student information:\n\n");
                 printf("Registration number: "); scanf("%s",&std->regno);
                 STUDENT *check2=head;
                 while(check2!=NULL){
                       if(strcmp(check2->regno,std->regno)==0){
                          printf("Registration number already exist.\n\n");
                          free(std);
                          homePage();
                          break;
                       }
                       check2=check2->link;
                 }
                 printf("First name: ");          scanf("%s",&std->fname);
                 printf("Second name: ");         scanf("%s",&std->secname);
                 printf("sex: ");                 scanf("%s",&std->sex);
                 printf("Age: ");                 scanf("%d",&std->age);
                 printf("Year of study: ");       scanf("%d",&std->yearofStudy);
                 printf("Degree program: ");      scanf("%s",&std->dProgram);
                 
                 std->link=current->link;
                 current->link=std; 
            
                 printf ( "\nStudent record successfully inserted.\n" );
                 homePage(); 
                 break;            
             }
             current=current->link;
         }
         
     }  
}


//function to modify records
void modifyRecord(){

	char regNum[15];
	printf("Enter registration number you want to modify: ");
	scanf("%s",&regNum);
	
    STUDENT *temp= head ;

	while(temp!=NULL)
	{	
		if ( strcmp(temp->regno,regNum)==0 )
		{
                 printf("First name: ");          scanf("%s",&temp->fname);
                 printf("Second name: ");         scanf("%s",&temp->secname);
                 printf("sex: ");                 scanf("%s",&temp->sex);
                 printf("Age: ");                 scanf("%d",&temp->age);
                 printf("Year of study: ");       scanf("%d",&temp->yearofStudy);
                 printf("Degree program: ");      scanf("%s",&temp->dProgram);
             
    			homePage();
    			return ;
	    }
	    else{
	
        printf ( "\nRegistration number %s is not in the list\n", regNum ) ;
	    modifyRecord();
    }
  }
}



//function to delete records
void deleteRecord(){
	char num[15];
	char dltcmf;
	
	printf("Are you sure you want to delete?\n");
	printf("press Y to delete, N to cancel.\n");
	scanf("%s",&dltcmf);
	
	if(dltcmf=='Y' || dltcmf=='y'){
        
        printf("Enter registration number you want to delete: ");
    	scanf("%s",&num);
    	
        STUDENT *old, *temp ;
    
    	temp = head ;
    	while ( temp != NULL ){
    		if ( strcmp(temp->regno,num)==0 ){
    			if ( temp == head )
    				head = temp -> link ;
    			else
    				old -> link = temp -> link ;
    
        			free ( temp ) ;
        			printf ( "\nStudent record successfully deleted.\n" );
        			homePage();
        			return ;
    		}
    		else{
    			old = temp ;  
    			temp = temp -> link ;  
    		 }
    	}
    	printf ( "\nStudent record not found.\n" ) ;
    	homePage();
}
    else if(dltcmf=='N' || dltcmf=='n'){
         homePage();
    }
    else{
        printf ( "\nWrong selection\n" ) ; 
        deleteRecord();
    }
}


//print all records
void printAll(){
     if(head==NULL){
        printf("List is empty.");
        homePage(); 
     }
     else{
         STUDENT *load =head;
         printf("\n\nStudent information:\n\n");
         while(load!=NULL){
             printf("Registration number\t: %s\n",load->regno);
             printf("Full name\t\t: %s %s\n",load->fname,load->secname);
             printf("sex\t\t\t: %s\n",load->sex);
             printf("Age\t\t\t: %d\n",load->age);
             printf("Year of study\t\t: %d\n",load->yearofStudy);
             printf("Degree program\t\t: %s\n\n\n",load->dProgram);
             load=load->link;
         }
         homePage(); 
     }      
     
}


//print particular record
void printOnce(){
     if(head==NULL){
        printf("List is empty.");
        homePage(); 
      }
     else{
          
         char reg[15];
         printf("Enter registration number: ");
         scanf("%s",&reg);
                 
         STUDENT *load =head;
         printf("\n\nStudent information:\n\n");
         while(load!=NULL){
            if(strcmp(load->regno,reg)==0){ 
             printf("Registration number\t: %s\n",load->regno);
             printf("Full name\t\t: %s %s\n",load->fname,load->secname);
             printf("sex\t\t\t: %s\n",load->sex);
             printf("Age\t\t\t: %d\n",load->age);
             printf("Year of study\t\t: %d\n",load->yearofStudy);
             printf("Degree program\t\t: %s\n\n\n",load->dProgram);
             
             homePage();
             break;
            }
             load=load->link;
        }
        printf("Student record not found.\n");
        homePage();      
     } 
}

