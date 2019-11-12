#ifndef CAR_H
#define CAR_H


#include "vehicle.h"

class car : public vehicle {

	private :
	char* car_name;

	public :
		car();
		explicit car(int a , int b);
		explicit car(int a , int b, char* c);
		explicit car(int a, int b, char* c, bool d);
		
		char* get_car_name();
		const char* get_class_name();
		void set_car_name(char* c );

};
#endif
