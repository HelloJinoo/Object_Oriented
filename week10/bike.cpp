
#include "bike.h"

bike::bike(){
}

bike::bike(int a, int b){
	this->set_wheel_number(a);
	this->set_max_speed(b);

}

bike::bike(int a, int b , char* c){
	this->set_wheel_number(a);
	this->set_max_speed(b);
	this->bike_name = c;
}

bike::bike(int a, int b, char* c , int d){
	this->set_wheel_number(a);
	this->set_max_speed(b);
	this->bike_name = c;
	this->bike_number = d;
}

bike::bike(int a , int b ,char* c , int d, bool e){
	this->set_wheel_number(a);
	this->set_max_speed(b);
	this->bike_name = c;
	this->bike_number = d;
	this->set_has_name(e);
}


int bike::get_bike_number(){
	return this->bike_number;
}
char* bike::get_bike_name(){
	return this->bike_name;
}

const char* bike::get_class_name(){
	return "bike";
}

void bike::set_bike_name(char* c){
	this->bike_name = c;
}


void bike::set_bike_number(int a){
	this->bike_number = a;
}
