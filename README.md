# clinic_management_system
Clinic Management System Devolovped in C programming

At the beginning the system asks the user to choose between admin mode and user mode

In admin mode:

fisrt the system asks for password, the default password is 1234. the system allows 3 trails for the password entery, if the entered password was incorrect for 3 consecutive times the system will close.
After login in the admin mode the system provides the following features:

1-Add new patient record:
   To add a new patient the admin enters the patient's basic information :name, age, gender and ID.
   The ID shall be unique for the patient , if the entered ID is already exists , the system will reject this entery.

2-Edit patient record:
  By entering patient ID the system will check if the ID exists, then allows the admin to edit the patient information , if not, the 
  system  will display "Incorrect ID" message to the user.

3-Reserve a slot with the doctor:
  By default there are 5 available slots 2:00 PM to 2:30 PM , 3:00 PM to 3:30 PM , 4:00 PM to 4:30 PM and 4:30 PM to 5:00 PM.
  when the user chooses this window, the system will display the available time slots , the admin shall enter patient ID and desired time 
  slot, the reserved slot will not appear again in the next patient reservation.

4-Cancel reservation:
  the admin can cancel a reservation by entering the patient ID, this reservation will be shown again with the available time slots.

In user mode:

The system allows the following features:

1-View patient record:
  By entering the patient ID, the system will check if this ID exists, the system will show the basic information for the patient, if not 
  the system will display "Incorrect ID" message.

2-View resirvations:
  the system will print all reservations with the patient ID attached to each reservation slot. 

