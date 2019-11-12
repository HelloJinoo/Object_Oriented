#ifndef BIKE_H
#define BIKE_H


#include "vehicle.h"


class bike : public vehicle {
	private :
	char* bike_name;
	int bike_number;

	public :
		bike();
		explicit bike(int a, int b);
		explicit bike(int a , int b , char* c);
		explicit bike(int a, int b, char* c, int d);
		explicit bike(int a, int b, char* c , int d , bool e);

		int get_bike_number();
		char* get_bike_name();
		const char* get_class_name();	
		void set_bike_name(char* c);
		void set_bike_number(int a);

};
#endif
