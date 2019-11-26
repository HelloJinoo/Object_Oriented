
#include "String.h"


String::String(const std::string &str){
	set_val(str);
}

std::string String::val(){

	return _val;
}

void String::set_val(const std::string& str){

	_val = str;
}

json_object::_type String::type(){
	return json_object::_type(3);  //STRING;
}

std::string String::to_string(){
	std::string str("'");
	str.append(_val);
	str.append("'");
	return str;
}


json_object *String::parse(const char* c, int length, char base){
	char ch;
	_index++; //' ->
	int start_idx = _index;  

	while(base != c[_index] ){
		_index++;
	}
	int end_idx = _index;  //<-'

	std::string str = std::string(c).substr(start_idx, end_idx-start_idx);
	return new String(str);


}



