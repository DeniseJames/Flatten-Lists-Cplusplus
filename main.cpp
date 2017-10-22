#include <iostream>
#include "flatten_list.h"

// ***************************
// * The  test program *
// ***************************

int main()
{
	typedef std::list<boost::any> anylist;
	flatten_list flist;
	std::cout << "The initial input list is: " << std::endl;
	anylist mylist = flist.create_anylist("[[1], 2, [[3,4], 5], [[[]]], [[[6]]], 7, 8, []]");
	anylist returned_list;
	flist.print_list(mylist);
	std::cout << std::endl;
	returned_list = flist.flatten(mylist);
	std::cout << " The flattened output list is: " << std::endl;
	flist.print_list(returned_list);
	std::cout << std::endl;
}
// Below is the output to the screen
// The initial input list is :
// [[1], 2, [[3, 4], 5], [[[]]], [[[6]]], 7, 8, []]
// The flattened output list is :
// [1, 2, 3, 4, 5, 6, 7, 8]