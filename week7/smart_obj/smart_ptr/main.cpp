#include <iostream>
#include "object.h"
#include "shared_mut.h"
#include "unique_immut.h"
using namespace ptr;


int main() {
    std::cout << "Shared Mutable Pointer" << std::endl;
    {
        shared_mut p(new Object(3));
        shared_mut q(new Object(5));
	
       	shared_mut r = p + q;	
        std::cout << "Hello, Unique_immut! " <<  r->get() << std::endl;
    
    }
    std::cout << "\n\nUnique Immutable Pointer" << std::endl;
    {
        unique_immut p(new Object(3));
        unique_immut q(new Object(5));
        unique_immut r = p + q;
        std::cout << "Hello, Unique_immut! " <<  r->get() << std::endl;
    }

	std::cout<< "\n\n\n\n" << std::endl;
     unique_immut a(new Object(30));
    {
	    int result =1;
        unique_immut c(new Object(30));
        if (a->get() != c->get()) {
           result = 0;
	    std::cout << result << std::endl;
        }
	std::cout << result << std::endl;
    }

    return 0;
}
