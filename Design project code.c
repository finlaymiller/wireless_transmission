#include <studio.h>

int main(void){

	DDRA = 0x000 //configures portA as input. A.1=switch, A.2= button1, A.3=button2
	DDRB = 0xFF //configures PortB as output, display.
	int display {00000001, 01001111, 00010010, 00000110, 01001100, 00100100, 00100000, 00001111, 00000000, 00000100} //gives common cathode display
	int cid, uid = 11 // defines command ID and User ID. user ID should not automatically be 0 for check later
	int anum;	//defines assignment number
		while (PINA.1==1){ //while switch on
			PORTB = display[0];
			cid = 0,  uid=0; //sets command ID and User ID to 0
				
				if (PINA.2 ==1 ){ //if button 1 pressed
				uid++;
					if(uid==10) uid=0;
				PORTB = display[uid];
				break;
				}
				if (PINA.3 ==1 ){ //if button 2 pressed
				cid++;
					if(cid==10) cid=0;
				PORTB = display[cid];
				break;
				}
		}
	if (uid == 0){	//if it is admin
		 if(cid<=4){ //assignments only go up to 4 so admin wants to open assignment submision
		 	anum = cid; //assignmnt number set to  command ID
		}else{
			anum = 11; //assignment submission closed as maximum command ID is 9
		}
	}else{
		if (cid==anum){	//if student is submitting correct assignment
		//// we will send the signal here
		}
		
	}
	Return 0;
}
