#include <stdio.h>
#include <stdlib.h>
#include "myfunctions.h"

void catalog_init(product catalog[], int size, int stock){
	for(int i=0; i<size; i++){
	sprintf(catalog[i].description, "item%d", i+1);
	catalog[i].price = (rand() % 9000 + 1000)/100.0; //random price between 10.00-100.00
	catalog[i].item_count = stock;
	catalog[i].requests = 0;
	catalog[i].fails = 0;}
}