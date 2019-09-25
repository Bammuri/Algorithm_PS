// fill algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::fill
#include <vector>       // std::vector

int main() {


	// vector

	std::vector<int> myvector(8);								// myvector: 0 0 0 0 0 0 0 0

	std::fill(myvector.begin(), myvector.begin() + 4, 5);		// myvector: 5 5 5 5 0 0 0 0

	std::fill(myvector.begin() + 3, myvector.end() - 2, 8);		// myvector: 5 5 5 8 8 8 0 0

	std::cout << "myvector contains:";
	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';


	// array

	int myarray[8] = { 0, }; 													//myarray: 0 0 0 0 0 0 0 0

	std::fill(myarray, myarray + 4, 7);											//myarray: 7 7 7 7 0 0 0 0

	std::fill(myarray + 3, myarray + sizeof(myarray) / sizeof(int) - 1, 2);		//myarray: 7 7 7 2 2 2 2 0

	printf("myarray contains :");
	for (int i = 0; i < sizeof(myarray) / sizeof(int); i++)
		printf(" %d", myarray[i]);
	printf("\n");


	// 2D array

	int my2darray[2][8] = { 0, }; 												//my2darray: {{0 0 0 0 0 0 0 0},  {0 0 0 0 0 0 0 0}}

	std::fill(my2darray[0] + 4 , my2darray[0] + 8 + 6 , 3);						//my2darray: {{0 0 0 0 3 3 3 3},  {3 3 3 3 3 3 0 0}}

	std::fill(my2darray[0] + 7, my2darray[0] + 8 + 1 , 2);						//my2darray: {{0 0 0 0 3 3 3 2},  {2 3 3 3 3 3 0 0}}

	printf("my2darray contains :");
	for (int i = 0; i < sizeof(my2darray) / sizeof(my2darray[0]); i++)
		for (int j = 0; j < sizeof(my2darray[0]) / sizeof(int); j++)
			printf(" %d", my2darray[i][j]);
	printf("\n");

	return 0;

}