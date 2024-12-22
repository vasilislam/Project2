#include <stdio.h>
#include "myfunctions.h"
#include <unistd.h>
#include <stdlib.h>

void serverside(product catalog[], int orders, int p1, int p2, double *totalsum){
		char intbuffer[4], message[75];
		double sum=0;
		int tmp = 0; // temp for products sold per client
		for(int j=0; j<orders; j++){
			
			read(p1, intbuffer, sizeof(intbuffer)); //read id
			int id=atoi(intbuffer);  				//string to int
			
			catalog[id].requests++;
			sleep(0.5);
			if(catalog[id].item_count<=0){
				catalog[id].fails++;
				sprintf(message, "Order %d: product \"%s\" unavailable, request failed", j+1, catalog[id].description);
				write(p2, message , sizeof(message)); //write faild response
			}
			else{
				tmp++;
				catalog[id].item_count--;
				sprintf(message, "Order %d: product \"%s\" available, price: %.2lf euro", j+1, catalog[id].description, catalog[id].price); 
				write(p2, message, sizeof(message));  //write success response
				sum+=catalog[id].price;
			}
		}
		*totalsum+=sum;
		sprintf(message, "purchase complete, %d products, TOTAL: %.2lf euro\n", tmp, sum); 
		write(p2, message, sizeof(message));
}