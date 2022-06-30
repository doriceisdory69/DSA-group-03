#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Insert_Word();
void Display_Words();
void Search_Word();
struct node
{
	char Eng[20];
	char Sw[20];
	struct node* link;
};
struct node* START = NULL;
int flag;
int main()
{
	int choice;
	while(1)
	{
		printf("Enter the choice of operation\n");
		printf("1. Insert words\n");
		printf("2. Display available words\n");
		printf("3. Search word in the dictionary\n");
		printf("4. Quit program\n");
		scanf("%d", &choice);
	
		
		switch(choice)
		{
	case 1: Insert_Word();
		        break;
			      
	case 2: Display_Words();
		        break;
					
	case 3: Search_Word();
		        break;
					
	    case 4: exit(1);
		        break;
	default : printf("Invalid choice\n");							        
		}
	}
}
void Insert_Word()
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	
	printf("Enter the english word\n");
	scanf("%s", &temp->Eng);
	printf("Enter the meaning\n");
	scanf("%s", &temp->Sw);
	temp->link = NULL;
	
	if(START == NULL)
	{
		START = temp;
	}
	else
	{
		struct node* p;
		p = START;
		
		while(p->link != NULL)
		{
			p = p->link;
		}
		p->link = temp;
	}
	printf("\nWord entered succesifully\n");
		printf("\n\n");
}
void Display_Words()
{
	struct node* t;
	t = START;
	if(t == NULL)
	{
		printf("\n\nThe dictionary has no words\n\n");
	}
	else{
	printf("The available words are: \n");
	while(t != NULL)
	{
		printf("%s----->%s\n", t->Eng, t->Sw);
		t = t->link;
	}
	printf("\n\n");
}
}
void Search_Word()
{
	int ch, n = 0;
	char search[20];
	while(n<5)
	{
		printf("Enter the choice of dictionary\n");
		printf("1. English-Swahili\n");
		printf("2. Swahili-English\n");
		scanf("%d", &ch);
		
		switch(ch)
		{
			case 1: printf("Welcome to english dictionary\n\n");
			        printf("Enter the word to search\n");
			        scanf("%s", &search);
			        struct node* temp;
			        temp = START;
			       	if(temp == NULL)
	                {
          printf("\n\nThe dictionary has no words\n\n");
             exit(1);
	                }
                   	else{
	        flag = 0;
	        while(temp != NULL)
			        {
	        	if(strcmpi(search, temp->Eng) == 0)
			        	{
	        		flag++;
        		printf("The meaning is: \t%s---->%s\n", temp->Eng, temp->Sw);
						}
			temp = temp->link;
					}
			if(flag == 0)
					{
			printf("Word is not found\n");
					}
				}
					break;
				
					
	    case 2: printf("Karibu kwenye kamusi ya Kiswahili\n\n");			
		printf("Ingiza neno la kutafuta\n");
			scanf("%s", &search);
			flag = 0;
			struct node* s;
			s = START;
			if(s == NULL)
				{
		printf("\n\nKamusi haina maneno\n\n");
			exit(1);
				}
				else{
			while(s != NULL)
				{
		if(strcmpi(search, s->Sw) == 0)
			{
			flag++;
		printf("Maana ni: \t%s------>%s\n", s->Sw, s->Eng);
						}
			 s = s->link;
					} 
		if(flag == 0)
					
		printf("Neno halipo\n");
					} 
					
		}
			break;
					
		    default : printf("invalid choice\n");						
		
		}
		n++;
	}
}

