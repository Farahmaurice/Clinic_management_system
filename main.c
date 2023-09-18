#include<stdio.h>
#include<stdlib.h>
#include"linked_list.h"
#include"program_modes.h"
#include"admin_mode.h"
#include"user.h"
newNode head;
res slot1;
extern int size;
int main()
{
	initial_reservations();
	int exitFlag=0;
	while(exitFlag==0)
	{
		startProgram();
		printf("To exit Enter 1\n");
		printf("To continue Enter 0\n");
		scanf("%d",&exitFlag);
	}
}