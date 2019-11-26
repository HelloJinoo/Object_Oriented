#include "Integer.h"

#include <iostream>
Integer::Integer(int val){
	set_val(val);
}


int Integer::val(){
	return _val;
}


void Integer::set_val(const int &value){

	_val = value;
}

json_object::_type Integer::type(){
	return json_object::_type(2); //INT; 
}

std::string Integer::to_string(){
	
	return std::to_string(_val);

}


json_object* Integer::parse(const char* c, int length){
	
	int start_idx = _index;
	while(('0' <= c[_index] && c[_index] <= '9')){
		_index++;
	}
	std::string str = std::string(c);
	
	int value = std::stoi(str.substr(start_idx, _index-start_idx));

	return new Integer(value);
	



}


