#include <stdio.h>
#include "stdlib.h"
#include "user.h"
#include "linked_list.h"

extern res slot1;
void initial_reservations()
{
	char time1[]="2pm to 2:30pm";
	char time2[]="2:30pm to 3pm";
	char time3[]="3pm to 3:30pm";
	char time4[]="4pm to 4:30pm";
	char time5[]="4:30pm to 5pm";
	//res* slot1=(res*)malloc(sizeof(res));
	res* slot2=(res*)malloc(sizeof(res));
	res* slot3=(res*)malloc(sizeof(res));
	res* slot4=(res*)malloc(sizeof(res));
	res* slot5=(res*)malloc(sizeof(res));
	
	slot1.slotNumber=1;
	storeName(time1,slot1.time_slot);
	slot1.patient_id=-1;
	slot1.next_res=slot2;
	
	slot2->slotNumber=2;
	storeName(time2,slot2->time_slot);
	slot2->patient_id=-1;
	slot2->next_res=slot3;
	
	slot3->slotNumber=3;
	storeName(time3,slot3->time_slot);
	slot3->patient_id=-1;
	slot3->next_res=slot4;
	
	slot4->slotNumber=4;
	storeName(time4,slot4->time_slot);
	slot4->patient_id=-1;
	slot4->next_res=slot5;
	
	slot5->slotNumber=5;
	storeName(time5,slot5->time_slot);
	slot5->patient_id=-1;
	slot5->next_res=NULL;
}
void print_available_res()
{
	res* last=&slot1;
	printf("Available time slots:\n");
	if(last->patient_id==-1)
	{
		printf("%d : %s\t",last->slotNumber,last->time_slot);
	}
	while(last->next_res!=NULL)
	{
		last=last->next_res;
		if(last->patient_id==-1)
		{
			printf("%d : %s\t",last->slotNumber,last->time_slot);
		}
		else
			continue;
	}
	printf("\n");
}
void reserve_slot()
{
	int slot;
	int pid;
	print_available_res();
	printf("choose slot to reserve: ");
	scanf("%d",&slot);
	printf("Enter Patient ID: ");
	scanf("%d",&pid);
	if(!exists(pid))
	{
		printf("Invalid ID!\n");
	}
	else
	{
		res* last=&slot1;
		switch(slot)
		{
			case 1:
			last->patient_id=pid;
			break;
			
			case 2:
			while(last->next_res!=NULL)
			{
				last=last->next_res;
				if(last->slotNumber==2)
				{
					last->patient_id=pid;
				}
				else
					continue;
			}
			break;
			
			case 3:
			while(last->next_res!=NULL)
			{
				last=last->next_res;
				if(last->slotNumber==3)
				{
					last->patient_id=pid;
				}
				else
					continue;
			}
			break;
			
			case 4:
			while(last->next_res!=NULL)
			{
				last=last->next_res;
				if(last->slotNumber==4)
				{
					last->patient_id=pid;
				}
				else
					continue;
			}
			break;
			
			case 5:
			while(last->next_res!=NULL)
			{
				last=last->next_res;
				if(last->slotNumber==5)
				{
					last->patient_id=pid;
				}
				else
					continue;
			}
			break;
			default:
			printf("Invalid Choice!\n");
			
		}
	}
}
void cancel_reservation()
{
	int slot;
	printf("Choose slot to cancel reservation: ");
	scanf("%d",&slot);
    if((slot==1) && (slot1.patient_id!=-1))
	{
		slot1.patient_id=-1;
	}
	else
	{
		res *last=&slot1;
	    while(last->next_res!=NULL)
	   {
		   last=last->next_res;
		   if((last->slotNumber==slot) &&(last->patient_id!=-1))
		   {
			  last->patient_id=-1;
			  break;
		   }
		  else
		   {
			 continue;
		   }
	   }
	}
}
void user_mode()
{
	int choice;
	int pid;
	printf("Welcome To User Mode:\n");
	printf("To view your data Press 1\n");
	printf("To view today's reservations press 2\n");
	printf("Your Choice: ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
		printf("Enter your ID: ");
		scanf("%d",&pid);
		printRecord(pid);
		break;
		case 2:
		view_reserved_slots();
		break;
		default:
		printf("Invalid Choice!\n");
	}
}
void view_reserved_slots()
{
	res* last=&slot1;
	if(last->patient_id!=-1)
	{
		printf("%d : ",last->slotNumber);
		printf("%s : ",last->time_slot);
		printf("%d  \n",last->patient_id);
	}
	while(last->next_res!=NULL)
	{
		last=last->next_res;
		if(last->patient_id!=-1)
		{
			printf("%d : ",last->slotNumber);
		    printf("%s : ",last->time_slot);
		    printf("%d  \n",last->patient_id);
		}
		else
		  continue;
	}
}