#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "myfunctions.h"

void clientside(int orders, int p1, int p2){
	char intbuffer[4], message[75];
	for(int i=0; i<orders+1; i++){
			int id = rand() % 20;  		// random number between 0-19
			sprintf(intbuffer, "%d", id); 	//number to string
			write(p1, intbuffer, sizeof(intbuffer)); //write id
			read(p2, message, sizeof(message)); //read response message
			printf("%s\n", message);
			sleep(1);
		}
}