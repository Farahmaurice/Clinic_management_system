#include<stdio.h>
#include<stdlib.h>
#include"admin_mode.h"
#include"linked_list.h"
#include"user.h"
void StartAdminMode()
{
	int process;
	printf("To add new patient record press 1\n");
	printf("To edit patient record press 2\n");
	printf("To reserve a slot with a doctor press 3\n");
	printf("To cancel reservation press 4\n");
	printf("Your Choice: ");
	scanf("%d",&process);
	switch(process)
	{
		case 1:
		addNewPatient();
		break;
		case 2:
		editPatientRecord();
		break;
		case 3:
		reserve_slot();
		break;
		case 4:
		cancel_reservation();
		break;
		default:
		printf("Invalid Choice!\n");
	}
}
void addNewPatient()
{
	char name[100];
	int age,id;
	char gender;
	printf("New patient name: ");
	scanf("%s",&name);fflush(stdin);
	printf("New patient age: ");
	scanf("%d",&age);fflush(stdin);
	printf("New patient gender: ");
	scanf("%c",&gender);
	printf("New patient ID: ");
	scanf("%d",&id);
	while(exists(id))
	{
		printf("This ID is already recorded to another user\n");
		printf("New patient ID: ");
	    scanf("%d",&id);
	}
	insertAtLast(name,age,gender,id);
	printf("New patient has been added successfully\n");
}
