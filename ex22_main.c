#include "ex22.h"
#include "dbg.h"


// make a const which stants for constant that is an alternative to using define to create a constant variable
const char *MY_NAME = "Wesley D. Madrigal";

// a function demonstrating more scope issues in a function
void scope_demo(int count)
{
	log_info("count is: %d", count);
	// starts a new scope block and has anther count variable in it.
	// this version of count is a whole new variable
	if(count > 10)	{
		int count = 100;  // bug

		log_info("count in this scope is %d", count);
	}

	log_info("count is at exit: %d", count);
	count = 3000;
	log_info("count after assign: %d", count);
}

int main(int argc, char *argv[])
{
	// test out THE_AGE accessors
	log_info("My name: %s, age: %d", MY_NAME, get_age());
	set_age(200);
	log_info("My age is now: %d", get_age());
	// test out THE_SIZE extern
	log_info("THE_SIZE is: %d", THE_SIZE);
	print_size();

	THE_SIZE = 9;

	log_info("The SIZE is now: %d", THE_SIZE);
	print_size();

	// test the ratio function static
	log_info("Ratio at first: %f", update_ratio(2.0));
	log_info("Ratio again: %f", update_ratio(10.0));
	log_info("Ratio once more: %f", update_ratio(300.0));

	// test the scope demo
	int count = 4;
	scope_demo(count);
	scope_demo(count * 20);

	log_info("count after calling scope_demo: %d", count);
	log_info("The ratio is: %f", ratio);	
	return 0;
}
	
