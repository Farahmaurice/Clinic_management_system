#include<stdio.h>
#include<stdlib.h>
#include"linked_list.h"
extern newNode head;
int size=0;
void storeName(char *name,char *p_name)
{
	int i=0;
	while(*(name+i)!='\0')
	{
		*(p_name+i)=*(name+i);
		i++;
	}
	*(p_name+i)='\0';
}
int isEmpty()
{
	int flag;
	if (size==0)
		flag=1;
	else
		flag=0;
	return flag;
}
void insertAtLast(char *name,int age,char gender,int id)
{
	if(isEmpty())
	{
		storeName(name,(head.patient_name));
		//head.patient_name=name;
		head.patient_age=age;
		head.patient_gender=gender;
		head.patient_id=id;
		head.next_patient=NULL;
	}
	else
	{
		newNode *last=&head;
		newNode *node=(newNode*)malloc(sizeof(newNode));
		//node->patient_name=name;
		storeName(name,node->patient_name);
		node->patient_age=age;
		node->patient_gender=gender;
		node->patient_id=id;
		node->next_patient=NULL;
		while((last->next_patient)!=NULL)
		{
			last=last->next_patient;
		}
		last->next_patient=node;
	}
	size++;
}
int exists(int id)
{
	int flag=0;
	newNode *last=&head;
	if(isEmpty())
	{
		flag=0;
	}
	else
	{
		if (size==1 && last->patient_id==id)
		{
			flag=1;
		}
		else
		{
			while(last->next_patient!=NULL)
			{
				last=last->next_patient;
				if(last->patient_id==id)
				{
					flag=1;
					break;
				}
				else
					continue;
			}
		}
	}
	return flag;
}
void printRecord(int id)
{
	newNode *last=&head;
	if(!exists(id))
	{
		printf("Invalid ID\n");
	}
	else if(isEmpty())
	{
		printf("No records yet\n");
	}
	else
	{
		if(size==1 && last->patient_id==id)
		{
			printf("Name: %s\n",last->patient_name);
			printf("Age: %d\n",last->patient_age);
			printf("Gender: %c\n",last->patient_gender);
			printf("ID: %d\n",last->patient_id);
				
		}
		while((last->next_patient)!=NULL)
		{
			last=last->next_patient;
			if(last->patient_id==id)
			{
				printf("Name: %s\n",last->patient_name);
				printf("Age: %d\n",last->patient_age);
				printf("Gender: %c\n",last->patient_gender);
				printf("ID: %d\n",last->patient_id);
				break;
			}
			else
			{
				continue;
			}
			
		}
	}
}
void editPatientRecord()
{
	int id;
	printf("Enter patient id to edit: ");
	scanf("%d",&id);
	if(!exists(id))
	{
		printf("Invalid ID\n");
	}
	else
	{
		printf("Data before editing: \n");
		printRecord(id);
		printf("Data after editing: \n");
		newNode *last=&head;
		if(last->patient_id==id)
		{
		   printf("New patient name: ");
		   scanf("%s",&(last->patient_name));fflush(stdin);
	       printf("New patient age: ");
	       scanf("%d",&(last->patient_age));fflush(stdin);
	       printf("New patient gender: ");
	       scanf("%c",&(last->patient_gender));
	       printf("New patient ID: ");
		   //fflush(stdin);
	       scanf("%d",&(last->patient_id));
		}
		else
		{
			while(last->next_patient!=NULL)
			{
				last=last->next_patient;
				if(last->patient_id==id)
		        {
		            printf("New patient name: ");
		            scanf("%s",&(last->patient_name));fflush(stdin);
	                printf("New patient age: ");
	                scanf("%d",&(last->patient_age));fflush(stdin);
	                printf("New patient gender: ");
	                scanf("%c",&(last->patient_gender));
	                printf("New patient ID: ");
	                scanf("%d",&(last->patient_id));
		        }
				
			}
		}
	}
	
}