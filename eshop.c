#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <time.h>
#include "myfunctions.h"

#define CLIENTS 5
#define ORDERS 10
#define PRODUCTS 20
#define STOCK 2

int main(){
	
int p1[2],p2[2];	
double totalsum = 0;
product catalog[20];

catalog_init(catalog, PRODUCTS, STOCK);

for(int i=0; i<CLIENTS; i++){
	srand(time(0));
	pipe(p1);
	pipe(p2);
	printf("Client %d:\n", i+1);
	pid_t pid = fork();
	if ( pid > 0){
		//parent process
		close(p1[1]); //close pipe1 write
		close(p2[0]); //close pipe2 read
		serverside(catalog, ORDERS, p1[0], p2[1], &totalsum);
		wait(NULL);
		close(p1[0]);
		close(p2[1]);
	}
	else{
		//child process
		close(p1[0]); //close pipe1 read
		close(p2[1]); //close pipe2 write
		clientside(ORDERS, p1[1], p2[0]);
		close(p1[1]);
		close(p2[0]);
		exit(0);
	}
}
printstats(catalog, STOCK, &totalsum);
}
