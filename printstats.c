#include <stdio.h>
#include "myfunctions.h"

void printstats(product catalog[], int stock, double *totalsum){
	int successsum = 0, failsum = 0;
	printf("Description\tRequests Sold\tFailed\n");
	for(int i=0; i<20; i++){
		printf(" %s\t\t%d\t %d\t%d\n",catalog[i].description,catalog[i].requests,stock-catalog[i].item_count,catalog[i].fails);
		successsum+= stock-catalog[i].item_count;
		failsum += catalog[i].fails;
	}
	int ordersum = failsum + successsum;
	printf("\n%d Total orders, %d succeed, %d failed, %.2lf € total earnings\n", ordersum, successsum, failsum, *totalsum);
}