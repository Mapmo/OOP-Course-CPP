#include <iostream>
int * ptrReturn(int& a)
{
	return &a;
}
int main()
{
	int a = 5;
	int b = 4;
	int * pb = &b;

	//ptrReturn(a) = pb; //error "Expression must be a modifiable lvalue"

	//pointer is an object, and the result of a function call is always an rvalue if the return type is an object type.


	//Dereferencing the pointer will give an lvalue denoting the object it points to.

	*ptrReturn(a) = b;//correct when working with dynamic memory
	

	int * tmp = ptrReturn(a);//using a tmp object to contain the rvalue
	*tmp = *pb;//also correct, but now as tmp is a pointer, not a static data, it will point to pb and thus will change its value

	std::cout << a;
    return 0;
}

