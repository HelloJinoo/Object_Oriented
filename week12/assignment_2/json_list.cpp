


#include "json_list.h"
#include "data/String.h"
#include "data/Integer.h"
json_list::json_list(){
	
}

json_object* json_list::operator[](int key) const {
	return	v[key] ;
}

json_object::_type json_list::type(){
	return json_object::_type(1); //List
}

std::string json_list::to_string(){
	std::string str("[");
	
	for(auto iter = v.begin(); iter != v.end(); iter++){
		
		str.append((*iter)->to_string());
		if(iter != v.end() -1) {
			str.append(",");
		}

	}
	str.append("]");
	return str;

}

json_object* json_list::parse(const char *c, int length){

	
	json_list* j_list = new json_list();
	_index++; // [ ->

	while( c[_index] != ']' ){			
		json_object* j_obj = json_object::parse(c, length);
	        j_list->v.push_back(j_obj);
		if(c[_index] == ']'){
			break;
		}
		_index++;		
	}
	_index++;  
	
	return j_list;

}


