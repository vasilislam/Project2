
typedef struct{
	char description[15];
	double price;
	int item_count;
	int requests;
	int fails;
}product;


void catalog_init(product catalog[], int size, int stock);
void serverside(product catalog[], int orders, int p1, int p2, double *totalsum);
void clientside(int orders, int p1, int p2);
void printstats(product catalog[], int stock, double *totalsum);