typedef struct reservations res;
struct reservations
{
	int slotNumber;
	char time_slot[100];
	int patient_id;
	res* next_res;
};
void initial_reservations();
void print_available_res();
void reserve_slot();
void cancel_reservation();
void view_reserved_slots();
void user_mode();
