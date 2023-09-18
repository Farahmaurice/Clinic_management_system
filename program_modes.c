#include<stdio.h>
#include"program_modes.h"
#include"admin_mode.h"
#include"user.h"
void startProgram()
{
	int mode;
	int pass;
	printf("For Admin Mode Press 1\n");
	printf("For User Mode Press 2\n");
	printf("Please Enter Your Choice: ");
	scanf("%d",&mode);
	switch(mode)
	{
		case 1:
		printf("Enter Password: ");
		scanf("%d",&pass);
		if(pass==PASSWORD)
		{
			StartAdminMode();
		}
		else
		{
			int i=3;
			do{
				printf("Wrong password, %d trials left\n",i);
				i--;
				printf("Enter Password: ");
		        scanf("%d",&pass);
				if(pass==PASSWORD)
				{StartAdminMode();break;}
				else
					continue;
			}while(i>0);
			
		}
		break;
		case 2:
		user_mode();
		break;
		default:
		printf("Invalid choice");
	}
}