typedef struct node_type newNode;
struct node_type
{
	char patient_name[100];
	int patient_age;
	char patient_gender;
	int patient_id;
	newNode *next_patient;
};
int isEmpty();
int exists(int id);
void storeName(char *name,char *p_name);
void insertAtLast(char *name,int age,char gender,int id);
void editPatientRecord();
void printRecord(int id);