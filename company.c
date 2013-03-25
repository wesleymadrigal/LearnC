#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

struct Company	{
	char *name;
	char *product;
	char *location;
	int unit_price;
	int units_sold;
	int revenue;
};

struct Company Company_create(char *name, char *product, char *location, int unit_price, int units_sold, int revenue)
{
	/*
	struct Company *me = malloc(sizeof(struct Company));
	assert(me != NULL);

	me->name = strdup(name);
	me->product = strdup(product);
	me->location = strdup(location);
	me->unit_price = unit_price;
	me->units_sold = units_sold;
	me->revenue = revenue;
	*/
	struct Company me;
	me.name = name;
	me.product = product;
	me.location = location;
	me.unit_price = unit_price;
	me.units_sold = units_sold;
	me.revenue = revenue;

	
	

	return me;
}
/*
void Company_destroy(struct Company me)
{
	assert(me != NULL);
		
	free(me.name);
	free(me.product);
	free(me.location);
	free(me);
	
	delete[] me;
}
*/
void Company_print(struct Company me)
{
	printf("My company's name is: %s.\n", me.name);
	printf("\tMy company's product is: %s.\n", me.product);
	printf("\tMy company is located in %s.\n", me.location);
	printf("\tThis year we've been selling our products at %d per unit.\n", me.unit_price);
	printf("\tThis year we sold %d units at a profit of %d.\n", me.units_sold, me.revenue);
}

int main(int argc, char *argv[])
{
	
	struct Company mycomp = Company_create(
		"Devengsoft", "Web Applications", "Chicago, IL", 10000, 8, 80000);

	//printf("My company is at memory location %p:\n", mycomp);
	Company_print(mycomp);

	return 0;
}
	
	
