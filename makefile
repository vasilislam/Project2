project2: eshop.o catalog_init.o serverside.o clientside.o printstats.o myfunctions.h
			gcc eshop.o catalog_init.o serverside.o clientside.o printstats.o -o project2
eshop.o: myfunctions.h
catalog_init.o: myfunctions.h
serverside.o: myfunctions.h
clientside.o: myfunctions.h
printstats.o: myfunctions.h
clean:
	rm *.o project2