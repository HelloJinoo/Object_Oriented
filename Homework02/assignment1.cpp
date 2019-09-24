#include <iostream>

static int data =1; //,static Variable -> Data area
int bss; //noninit global Variable -> BSS area
static const char* rodata = "Hello World"; //const static -> Rodata area

int main(){
	
	
	int stack = 3; //local variable -> stack area
	int *heap = new int[4]; //heap area
	heap[0] = 1;	

	std::cout << "code\t" << (void *)main << std::endl;
	std::cout << "Rodata\t" << (void *)rodata << std::endl;
	std::cout << "data\t" << &data << std::endl;
	std::cout << "BSS\t" << &bss << std::endl;
	std::cout << "HEAP\t" << &heap[0] << std::endl;
	std::cout << "Stack\t" << &stack << std::endl;
	
	return 0;

}


