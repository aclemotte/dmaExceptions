//============================================================================
// Name        : Dynamic.cpp
// Author      : aclemotte
// Version     : 1.0
// Copyright   : My copyright
// Description : DMA exception. Based on: http://www.cplusplus.com/doc/tutorial/dynamic/
//============================================================================

#include <iostream>
#include <new>
using namespace std;

int main() {

	int i,n;
	int * p;
	cout << "How many numbers would you like to type? ";
	cin >> i;

//	p= new (nothrow) int[i];
//
//	if (p == nullptr)
//	{
//		cout << "Error: memory could not be allocated";
//		return 0;
//	}

	try
	{
		p= new int[i];
	}
	catch(const std::bad_array_new_length &e)
	{
		cerr << e.what() << '\n';
		return 0;
	}
	catch (const std::exception& e) // older compilers may throw other exceptions:
	{
		cerr << "some other standard exception caught: " << e.what() << '\n';
		return 0;
	}


	//solo se llega aqui si no hubo ningun error al pedir memoria
	for (n=0; n<i; n++)
	{
	  cout << "Enter number: ";
	  cin >> p[n];
	}
	cout << "You have entered: ";
	for (n=0; n<i; n++)
	  cout << p[n] << ", ";
	delete[] p;
	return 0;
}
