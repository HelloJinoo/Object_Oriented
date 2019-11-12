
#ifndef VEHICLE_H
#define VEHICLE_H
class vehicle{
 
	private :
	bool has_name;
	int wheel_number;
	int max_speed;


	public :
		vehicle();
		explicit vehicle(int a, int b );
		explicit vehicle(int a , int b, bool c);
		void set_wheel_number(int a);
		void set_max_speed(int a);
		void set_has_name(bool a);

		int get_wheel_number();
		int get_max_speed();
		bool get_has_name();
		virtual const char* get_class_name();



};

#endif
